所有的包全部都需要重新下载，并且要重新构造，
git clone https://github.com/scipr-lab/libfqfft.git
git clone https://github.com/scipr-lab/libff.git
git clone https://github.com/scipr-lab/libsnark.git
克隆成功的话，进行编译安装
cd libfqfft
mkdir build && cd build
cmake ..
make -j$(nproc)
sudo make install
cd ../..

cd libff
mkdir build && cd build
cmake ..
make -j$(nproc)
sudo make install
cd ../..

cd libsnark
mkdir build && cd build
cmake ..
make -j$(nproc)
sudo make install
cd ../..
