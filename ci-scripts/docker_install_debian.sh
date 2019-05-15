#!/usr/bin/env bash

apt-get update
apt-get install gcc-6 g++-6 curl wget -y

wget -c https://github.com/libcheck/check/releases/download/0.12.0/check-0.12.0.tar.gz
tar -xzf check-0.12.0.tar.gz
cd check-0.12.0 && ./configure --prefix=/usr --disable-static && make && sudo make install