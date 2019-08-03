#!/usr/bin/env bash

set -x

git --version

export VERSION="$(git describe --tags --exact-match HEAD)"

if [[ "$VERSION" ]]; then
	docker build  --build-arg SHA1=$CIRCLE_SHA1 --build-arg GITHUB_OAUTH_TOKEN --build-arg PROJECT_USERNAME=$CIRCLE_PROJECT_USERNAME --build-arg PROJECT_REPONAME=$CIRCLE_PROJECT_REPONAME --build-arg QEMU_PLATFORM=armv7hf --build-arg VERSION  --file $GOPATH/src/github.com/skycoin/libskycoin/docker/images/deploy-arm/Dockerfile  $GOPATH/src/github.com/skycoin/libskycoin -t skydev-deploy
	docker build  --build-arg SHA1=$CIRCLE_SHA1 --build-arg GITHUB_OAUTH_TOKEN --build-arg PROJECT_USERNAME=$CIRCLE_PROJECT_USERNAME --build-arg PROJECT_REPONAME=$CIRCLE_PROJECT_REPONAME --build-arg QEMU_PLATFORM=aarch64 --build-arg VERSION  --file $GOPATH/src/github.com/skycoin/libskycoin/docker/images/deploy-arm/Dockerfile  $GOPATH/src/github.com/skycoin/libskycoin -t skydev-deploy
fi