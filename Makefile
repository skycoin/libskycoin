.DEFAULT_GOAL := help
.PHONY: test-libc test-lint build-libc check build build-skyapi test-skyapi
.PHONY: install-linters format clean-libc format-libc lint-libc docs

COIN ?= skycoin

# Resource paths
# --- Absolute path to repository root
LIBSRC_ABS_PATH        = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
# --- Relative path to repository root
LIBSRC_REL_PATH        = .
# --- Relative path to repository root from local vendor directory
LIBSRC_VENDORREL_PATH  = ..
# --- Relative path to repository root from Skycoin source root directory
LIBSRC_SKYSRCREL_PATH  = ../../../..
# --- Relative path to libskycoin vendor directory
LIBVENDOR_REL_PATH     = vendor
# --- Relative path to Skycoin source code submodule
SKYSRC_REL_PATH        = $(LIBVENDOR_REL_PATH)/github.com/skycoin/skycoin
# --- Relative path to Skycoin vendor directory
SKYVENDOR_REL_PATH     = $(SKYSRC_REL_PATH)/vendor

# Compilation output for libskycoin
BUILD_DIR = build
BUILDLIB_DIR = $(BUILD_DIR)/libskycoin
BUILDLIBSKYAPI_DIR = $(BUILD_DIR)/libskyapi
LIBNAME_Linux = libskyapi.so
LIBNAME_Darwin = libskyapi.dylib
LIBNAME_Static = libskyapiStatic.a
LIB_DIR = lib
BIN_DIR = bin
DOC_DIR = docs
INCLUDE_DIR = include
LIBSRC_DIR = lib/cgo
LIBSKYDOC_DIR = $(DOC_DIR)/libc
LIBCURLDOC_DIR = $(DOC_DIR)/curl
SWAGGER_SPEC_DIR = lib/swagger
SWAGGER_CLIENT_DIR = lib/curl

# Source files
LIB_FILES = $(shell find $(LIBSRC_DIR) -type f -name "*.go")
HEADER_FILES = $(shell find $(INCLUDE_DIR) -type f -name "*.h")
SWAGGER_FILES += skycoin.v0.25.1.openapi.v2.json
SWAGGER_FILES += skycoin.v0.25.1.openapi.v2.yml

# Compilation flags for libskycoin
CC_VERSION = $(shell $(CC) -dumpversion)
STDC_FLAG = $(python -c "if tuple(map(int, '$(CC_VERSION)'.split('.'))) < (6,): print('-std=C99'")
LIBC_LIBS = `pkg-config --cflags --libs check`
LIBC_FLAGS = -I$(LIBSRC_DIR) -I$(INCLUDE_DIR) -I$(BUILD_DIR)/usr/include -L $(BUILDLIB_DIR) -L$(BUILD_DIR)/usr/lib
# Platform specific checks
OSNAME  = $(TRAVIS_OS_NAME)
UNAME_S = $(shell uname -s)
CGO_ENABLED=1

PKG_CLANG_FORMAT = clang-format
PKG_CLANG_LINTER = clang-tidy
PKG_LIB_TEST = check

ifeq ($(UNAME_S),Linux)
  LDLIBS=$(LIBC_LIBS) -lpthread
  LDPATH=$(shell printenv LD_LIBRARY_PATH)
  LDPATHVAR=LD_LIBRARY_PATH
  LDFLAGS=$(LIBC_FLAGS) $(STDC_FLAG)
  OSNAME ?= linux
else ifeq ($(UNAME_S),Darwin)
  OSNAME ?= osx
  LDLIBS = $(LIBC_LIBS)
  LDPATH=$(shell printenv DYLD_LIBRARY_PATH)
  LDPATHVAR=DYLD_LIBRARY_PATH
  LDFLAGS=$(LIBC_FLAGS) -framework CoreFoundation -framework Security
else
  LDLIBS = $(LIBC_LIBS)
  LDPATH=$(shell printenv LD_LIBRARY_PATH)
  LDPATHVAR=LD_LIBRARY_PATH
  LDFLAGS=$(LIBC_FLAGS)
endif

configure-build:
	mkdir -p $(BUILD_DIR)/usr/tmp $(BUILD_DIR)/usr/lib $(BUILD_DIR)/usr/include
	mkdir -p $(BUILDLIB_DIR) $(BIN_DIR) $(INCLUDE_DIR)

## Update links to dependency packages
dep:
	git submodule update --init --recursive
	ln -nsf ../$(LIBSRC_VENDORREL_PATH)/$(SKYVENDOR_REL_PATH)/golang.org $(LIBVENDOR_REL_PATH)/golang.org
	ln -nsf ../$(LIBSRC_VENDORREL_PATH)/$(SKYVENDOR_REL_PATH)/gopkg.in $(LIBVENDOR_REL_PATH)/gopkg.in
	ls -1 $(SKYVENDOR_REL_PATH)/github.com | grep -v '^skycoin$$' | xargs -I NAME ln -nsf ../$(LIBSRC_VENDORREL_PATH)/$(SKYVENDOR_REL_PATH)/github.com/NAME $(LIBVENDOR_REL_PATH)/github.com/NAME

$(BUILDLIB_DIR)/libskycoin.so: $(LIB_FILES) $(SRC_FILES) $(HEADER_FILES)
	rm -Rf $(BUILDLIB_DIR)/libskycoin.so
	go build -buildmode=c-shared  -o $(BUILDLIB_DIR)/libskycoin.so $(LIB_FILES)
	mv $(BUILDLIB_DIR)/libskycoin.h $(INCLUDE_DIR)/

$(BUILDLIB_DIR)/libskycoin.a: $(LIB_FILES) $(SRC_FILES) $(HEADER_FILES)
	rm -Rf $(BUILDLIB_DIR)/libskycoin.a
	go build -buildmode=c-archive -o $(BUILDLIB_DIR)/libskycoin.a  $(LIB_FILES)
	mv $(BUILDLIB_DIR)/libskycoin.h $(INCLUDE_DIR)/

build-libc-static: $(BUILDLIB_DIR)/libskycoin.a ## Build libskycoin C static library

build-libc-shared: $(BUILDLIB_DIR)/libskycoin.so ## Build libskycoin C shared library

build-libc: configure-build build-libc-static build-libc-shared ## Build libskycoin C client libraries

build-skyapi: ## Build skyapi(libcurl based) library
	(cd lib/curl && bash ./install_lib_curl.sh)
	mkdir -p ./build/libskyapi
	cp lib/curl/build/$(LIBNAME_$(UNAME_S)) ./build/libskyapi
	cp lib/curl/build/$(LIBNAME_Static) ./build/libskyapi

build: build-libc build-skyapi ## Build libraries

## Build libskycoin C client library and executable C test suites
## with debug symbols. Use this target to debug the source code
## with the help of an IDE
build-libc-dbg: configure-build build-libc-static build-libc-shared
	$(CC) -g -o $(BIN_DIR)/test_libskycoin_shared $(LIB_DIR)/cgo/tests/*.c -lskycoin                    $(LDLIBS) $(LDFLAGS)
	$(CC) -g -o $(BIN_DIR)/test_libskycoin_static $(LIB_DIR)/cgo/tests/*.c $(BUILDLIB_DIR)/libskycoin.a $(LDLIBS) $(LDFLAGS)

test-libc: build-libc ## Run tests for libskycoin C client library
	echo "Compiling with $(CC) $(CC_VERSION) $(STDC_FLAG)"
	$(CC) -o $(BIN_DIR)/test_libskycoin_shared $(LIB_DIR)/cgo/tests/*.c $(LIB_DIR)/cgo/tests/testutils/*.c -lskycoin                    $(LDLIBS) $(LDFLAGS)
	$(CC) -o $(BIN_DIR)/test_libskycoin_static $(LIB_DIR)/cgo/tests/*.c $(LIB_DIR)/cgo/tests/testutils/*.c $(BUILDLIB_DIR)/libskycoin.a $(LDLIBS) $(LDFLAGS)
	$(LDPATHVAR)="$(LDPATH):$(BUILD_DIR)/usr/lib:$(BUILDLIB_DIR)" $(BIN_DIR)/test_libskycoin_shared
	$(LDPATHVAR)="$(LDPATH):$(BUILD_DIR)/usr/lib"         $(BIN_DIR)/test_libskycoin_static

test-skyapi: build-skyapi ## Run test for skyapi(libcurl based) library

test: test-libc test-skyapi ## Run all test for libskycoin

docs-skyapi: ## Generate SkyApi (libcurl) documentation
	openapi-generator generate -g html2 -i lib/swagger/skycoin.v0.25.1.openapi.v2.yml -o $(LIBCURLDOC_DIR)

docs-libc: ## Generate libskycoin documentation
	doxygen ./.Doxyfile
	moxygen -o $(LIBSKYDOC_DIR)/API.md $(LIBSKYDOC_DIR)/xml/

docs: docs-libc docs-skyapi ## Generate documentation for all libraries

lint: ## Run linters. Use make install-linters first.
	vendorcheck ./...
	# lib/cgo needs separate linting rules
	golangci-lint run -c .golangci.libcgo.yml ./lib/cgo/...
	# The govet version in golangci-lint is out of date and has spurious warnings, run it separately
	go vet -all ./...

lint-libc: format-libc
	# Linter LIBC
	clang-tidy  lib/cgo/tests/*.c -- $(LIBC_FLAGS) -Wincompatible-pointer-types


check: lint test-libc lint-libc test-skyapi ## Run tests and linters

install-linters-Linux: ## Install linters on GNU/Linux
	sudo apt-get update
	sudo apt-get install $(PKG_CLANG_FORMAT)
	sudo apt-get install $(PKG_CLANG_LINTER)

install-linters-Darwin: ## Install linters on Mac OSX
	# brew install $(PKG_CLANG_FORMAT)
	brew install llvm
	ln -s "/usr/local/opt/llvm/bin/clang-format" "/usr/local/bin/clang-format"
	ln -s "/usr/local/opt/llvm/bin/clang-tidy" "/usr/local/bin/clang-tidy"

install-deps-Linux: ## Install deps on GNU/Linux
	sudo apt-get install $(PKG_LIB_TEST)

install-deps-Darwin: ## Install deps on Mac OSX
	brew install $(PKG_LIB_TEST)

install-linters: install-linters-$(UNAME_S) ## Install linters
	go get -u github.com/FiloSottile/vendorcheck
	cat ./ci-scripts/install-golangci-lint.sh | sh -s -- -b $(GOPATH)/bin v1.10.2

install-deps-skyapi-Linux:
	mkdir -p deps
	sudo add-apt-repository ppa:george-edison55/cmake-3.x -y
	sudo apt-get update
	sudo apt-get install cmake
	sudo apt-get install libcurl3-gnutls
	sudo apt remove curl
	(cd deps && wget http://curl.haxx.se/download/curl-7.58.0.tar.gz && tar -xvf curl-7.58.0.tar.gz && cd curl-7.58.0/ && ./configure && make && sudo make install)
	(cd deps && git clone https://github.com/uncrustify/uncrustify.git && cd uncrustify && mkdir build && cd build && cmake .. && make && sudo make install)

install-deps-skyapi-Darwin:
	export LDFLAGS="-L/usr/local/opt/curl/lib"
	export CPPFLAGS="-I/usr/local/opt/curl/include"
	mkdir -p deps
	brew update
	brew install openssl curl uncrustify || true
	(cd deps && wget http://curl.haxx.se/download/curl-7.58.0.tar.gz && tar -xf curl-7.58.0.tar.gz && cd curl-7.58.0/ && mkdir build && cd build && cmake -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -DOPENSSL_ROOT_DIR=/usr/local/opt/openssl .. && make && sudo make install)

install-deps-libc: install-deps-libc-$(UNAME_S) ## Install deps for libc

install-deps-skyapi: install-deps-skyapi-$(UNAME_S) ## Install skyapi(libcurl based) library.

install-deps-libc-Linux: configure-build ## Install locally dependencies for testing libskycoin
	wget -c https://github.com/libcheck/check/releases/download/0.12.0/check-0.12.0.tar.gz
	tar -xzf check-0.12.0.tar.gz
	cd check-0.12.0 && ./configure --prefix=/usr --disable-static && make && sudo make install

install-deps-libc-Darwin: configure-build ## Install locally dependencies for testing libskycoin
	brew install check

install-deps: install-deps-libc install-deps-skyapi ## Install deps for libc and skyapi

format: ## Formats the code. Must have goimports installed (use make install-linters).
	goimports -w -local github.com/skycoin/skycoin ./lib

clean-libc: ## Clean files generated by libc
	rm -rfv $(BUILDLIB_DIR)
	rm -rfv bin
	rm -rfv qemu_test_libskycoin*
	rm -rfv include/libskycoin.h

clean-skyapi: ## Clean files generated by skyapi
	rm -rfv $(BUILDLIBSKYAPI_DIR)

clean: clean-libc clean-skyapi ## Clean all files generated by libraries

format-libc:
	$(PKG_CLANG_FORMAT) -sort-includes -i -assume-filename=.clang-format lib/cgo/tests/*.c
	$(PKG_CLANG_FORMAT) -sort-includes -i -assume-filename=.clang-format include/*.h

help:
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'
