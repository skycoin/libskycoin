mkdir -p build
cd build
#echo "brew --prefix curl"
#brew --prefix curl
#echo "brew ls --verbose curl"
#brew ls --verbose curl
# for normal install use following command
cmake -D CMAKE_C_COMPILER=gcc -D CMAKE_CXX_COMPILER=g++ ..
make
sudo make install

cd ../..
