ARG QEMU_PLATFORM
FROM balenalib/${QEMU_PLATFORM}-debian-golang
# FIXME: If not repeated here build fails.
# See https://travis-ci.org/simelo/libskycoin/jobs/529481211#L649-L653

ADD . $GOPATH/src/github.com/skycoin/libskycoin/

RUN [ "cross-build-start" ]

RUN ls -oa $GOPATH/src/github.com/skycoin/libskycoin/
RUN sh $GOPATH/src/github.com/skycoin/libskycoin/ci-scripts/docker_install_debian.sh
RUN make -C $GOPATH/src/github.com/skycoin/libskycoin dep
RUN go get github.com/gz-c/gox
RUN go get -t ./...
ENV CGO_ENABLED=1
ENV VERSION=0.25.1
RUN make -C $GOPATH/src/github.com/skycoin/libskycoin build
RUN go get github.com/tcnksm/ghr
RUN ghr -t ${GITHUB_OAUTH_TOKEN} -u ${CIRCLE_PROJECT_USERNAME} -r ${CIRCLE_PROJECT_REPONAME} -c ${CIRCLE_SHA1} -delete ${VERSION} ./artifacts/

RUN [ "cross-build-end" ]
