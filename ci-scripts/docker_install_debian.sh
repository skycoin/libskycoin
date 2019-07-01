#!/usr/bin/env bash

apt-get update
apt-get install gcc-6 g++-6 curl wget cmake libcurl3-gnutls -y

sudo apt-get remove curl -y
(cd deps && wget http://curl.haxx.se/download/curl-7.58.0.tar.gz && tar -xvf curl-7.58.0.tar.gz && cd curl-7.58.0/ && ./configure && make && sudo make install)
(cd deps && git clone https://github.com/uncrustify/uncrustify.git && cd uncrustify && mkdir build && cd build && cmake .. && make && sudo make install)

wget -c https://github.com/libcheck/check/releases/download/0.12.0/check-0.12.0.tar.gz
tar -xzf check-0.12.0.tar.gz
cd check-0.12.0 && ./configure --prefix=/usr --disable-static && make && sudo make install