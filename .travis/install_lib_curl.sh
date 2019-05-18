cd lib/curl

mkdir -p build
cd build
# for normal install use following command
cmake ..
make
sudo make install

cd ../..
