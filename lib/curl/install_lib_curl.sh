mkdir -p build
cd build
#echo "brew --prefix curl"
#brew --prefix curl
#echo "brew ls --verbose curl"
#brew ls --verbose curl
# for normal install use following command
cmake -DCURL_ROOT_DIR="/usr/local" ..
exit 1
make
sudo make install

cd ../..
