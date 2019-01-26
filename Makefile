.DEFAULT_GOAL := help
.PHONY: test-libc test-lint build-libc check
.PHONY: install-linters format

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

# Source files
LIB_FILES = $(shell find ./lib/cgo -type f -name "*.go")
HEADER_FILES = $(shell find ./include -type f -name "*.h")

# Compilation output for libskycoin
BUILD_DIR = build
BUILDLIB_DIR = $(BUILD_DIR)/libskycoin
LIB_DIR = lib
BIN_DIR = bin
DOC_DIR = docs
INCLUDE_DIR = include
LIBSRC_DIR = lib/cgo
LIBDOC_DIR = $(DOC_DIR)/libc

# Compilation flags for libskycoin
CC_VERSION = $(shell $(CC) -dumpversion)
STDC_FLAG = $(python -c "if tuple(map(int, '$(CC_VERSION)'.split('.'))) < (6,): print('-std=C99'")
LIBC_LIBS = -lcriterion
LIBC_FLAGS = -I$(LIBSRC_DIR) -I$(INCLUDE_DIR) -I$(BUILD_DIR)/usr/include -L $(BUILDLIB_DIR) -L$(BUILD_DIR)/usr/lib
# Platform specific checks
OSNAME = $(TRAVIS_OS_NAME)

ifeq ($(shell uname -s),Linux)
  LDLIBS=$(LIBC_LIBS) -lpthread
  LDPATH=$(shell printenv LD_LIBRARY_PATH)
  LDPATHVAR=LD_LIBRARY_PATH
  LDFLAGS=$(LIBC_FLAGS) $(STDC_FLAG)
ifndef OSNAME
  OSNAME = linux
endif
else ifeq ($(shell uname -s),Darwin)
ifndef OSNAME
  OSNAME = osx
endif
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
	git submodule init || true
	git submodule update
	ln -nsf ../$(LIBSRC_VENDORREL_PATH)/$(SKYVENDOR_REL_PATH)/golang.org $(LIBVENDOR_REL_PATH)/golang.org
	ln -nsf ../$(LIBSRC_VENDORREL_PATH)/$(SKYVENDOR_REL_PATH)/gopkg.in $(LIBVENDOR_REL_PATH)/gopkg.in
	ls -1 $(SKYVENDOR_REL_PATH)/github.com | grep -v '^skycoin$$' | xargs -I NAME ln -nsf ../$(LIBSRC_VENDORREL_PATH)/$(SKYVENDOR_REL_PATH)/github.com/NAME $(LIBVENDOR_REL_PATH)/github.com/NAME
	dep ensure

$(BUILDLIB_DIR)/libskycoin.so: $(LIB_FILES) $(SRC_FILES) $(HEADER_FILES)
	rm -Rf $(BUILDLIB_DIR)/libskycoin.so
	go build -buildmode=c-shared  -o $(BUILDLIB_DIR)/libskycoin.so $(LIB_FILES)
	mv $(BUILDLIB_DIR)/libskycoin.h $(INCLUDE_DIR)/

$(BUILDLIB_DIR)/libskycoin.a: $(LIB_FILES) $(SRC_FILES) $(HEADER_FILES)
	rm -Rf $(BUILDLIB_DIR)/libskycoin.a
	go build -buildmode=c-archive -o $(BUILDLIB_DIR)/libskycoin.a  $(LIB_FILES)
	mv $(BUILDLIB_DIR)/libskycoin.h $(INCLUDE_DIR)/

## Build libskycoin C static library
build-libc-static: $(BUILDLIB_DIR)/libskycoin.a

## Build libskycoin C shared library
build-libc-shared: $(BUILDLIB_DIR)/libskycoin.so

## Build libskycoin C client libraries
build-libc: configure-build build-libc-static build-libc-shared

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
	$(LDPATHVAR)="$(LDPATH):$(BUILD_DIR)/usr/lib"                 $(BIN_DIR)/test_libskycoin_static

docs-libc:
	doxygen ./.Doxyfile
	moxygen -o $(LIBDOC_DIR)/API.md $(LIBDOC_DIR)/xml/

docs: docs-libc

lint: ## Run linters. Use make install-linters first.
	vendorcheck ./...
	# lib/cgo needs separate linting rules
	golangci-lint run -c .golangci.libcgo.yml ./lib/cgo/...
	# The govet version in golangci-lint is out of date and has spurious warnings, run it separately
	go vet -all ./...

check: lint test-libc ## Run tests and linters

install-linters: ## Install linters
	go get -u github.com/FiloSottile/vendorcheck
	# For some reason this install method is not recommended, see https://github.com/golangci/golangci-lint#install
	# However, they suggest `curl ... | bash` which we should not do
	go get -u github.com/golangci/golangci-lint/cmd/golangci-lint

install-deps-libc: configure-build ## Install locally dependencies for testing libskycoin
	git clone --recursive https://github.com/skycoin/Criterion $(BUILD_DIR)/usr/tmp/Criterion
	mkdir $(BUILD_DIR)/usr/tmp/Criterion/build
	cd    $(BUILD_DIR)/usr/tmp/Criterion/build && cmake .. && cmake --build .
	mv    $(BUILD_DIR)/usr/tmp/Criterion/build/libcriterion.* $(BUILD_DIR)/usr/lib/
	cp -R $(BUILD_DIR)/usr/tmp/Criterion/include/* $(BUILD_DIR)/usr/include/

format: ## Formats the code. Must have goimports installed (use make install-linters).
	goimports -w -local github.com/skycoin/skycoin ./lib

help:
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'
