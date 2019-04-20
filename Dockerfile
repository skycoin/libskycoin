ARG QEMU_OS
ARG QEMU_PLATFORM
FROM balenalib/${QEMU_PLATFORM}-${QEMU_OS}-golang
ARG QEMU_OS
ADD . $GOPATH/src/github.com/skycoin/libskycoin/

RUN [ "cross-build-start" ]
RUN sh $GOPATH/src/github.com/skycoin/libskycoin/ci-scripts/docker_install_${QEMU_OS}.sh
RUN go get github.com/gz-c/gox
RUN go get -t ./...
ENV CGO_ENABLED=1
RUN cd $GOPATH/src/github.com/skycoin/libskycoin && make clean-libc
RUN cd $GOPATH/src/github.com/skycoin/libskycoin && make test-libc 

RUN [ "cross-build-end" ]  

WORKDIR $GOPATH/src/github.com/skycoin

VOLUME $GOPATH/src/