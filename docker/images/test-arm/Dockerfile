ARG PATH_ROOT
ARG IMAGE_FROM=balenalib/armv7hf-ubuntu-golang
FROM $IMAGE_FROM
ARG PATH_ROOT

ADD $PATH_ROOT $GOPATH/src/github.com/skycoin/libskycoin/

RUN [ "cross-build-start" ]

RUN ls -oa $GOPATH/src/github.com/skycoin/libskycoin/
RUN apt-get update
RUN apt-get install gcc-6 g++-6 curl wget -y
RUN go get github.com/gz-c/gox
RUN go get -t ./...
ENV CGO_ENABLED=1
RUN rm -rfv $GOPATH/src/github.com/skycoin/libskycoin/build
RUN make -C $GOPATH/src/github.com/skycoin/libskycoin install-deps-libc-linux
RUN make -C $GOPATH/src/github.com/skycoin/libskycoin test-libc 

RUN [ "cross-build-end" ]  

WORKDIR $GOPATH/src/github.com/skycoin

VOLUME $GOPATH/src/
