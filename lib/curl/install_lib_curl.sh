mkdir -p build
cd build
# for normal install use following command
cmake -D CMAKE_C_COMPILER=gcc -D CMAKE_CXX_COMPILER=g++ ..
make
sudo make install

cd ../..
