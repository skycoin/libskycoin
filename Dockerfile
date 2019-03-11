FROM balenalib/armv7hf-ubuntu-golang

ADD . $GOPATH/src/github.com/skycoin/libskycoin/

RUN [ "cross-build-start" ]

RUN apt-get update
RUN apt-get install check gcc-6 g++-6 curl wget -y
RUN go get github.com/gz-c/gox
RUN go get -t ./...
ENV CGO_ENABLED=1
RUN cd $GOPATH/src/github.com/skycoin/libskycoin && rm -rfv build
RUN cd $GOPATH/src/github.com/skycoin/libskycoin && make test-libc 

RUN [ "cross-build-end" ]  

WORKDIR $GOPATH/src/github.com/skycoin

VOLUME $GOPATH/src/