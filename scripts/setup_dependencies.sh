#!/bin/bash

# 安装系统依赖
sudo apt-get update && sudo apt-get install -y \
    build-essential \
    cmake \
    git \
    libgmp3-dev \
    libprocps-dev \
    python3-markdown \
    libboost-program-options-dev \
    libssl-dev \
    pkg-config

# 克隆并构建libfqfft
git clone https://github.com/scipr-lab/libfqfft.git
cd libfqfft && mkdir build && cd build
cmake .. && make -j$(nproc)
sudo make install
cd ../..

# 克隆并构建libff
git clone https://github.com/scipr-lab/libff.git
cd libff && mkdir build && cd build
cmake .. -DWITH_PROCPS=OFF
make -j$(nproc)
sudo make install
cd ../..

# 克隆并构建libsnark
git clone https://github.com/scipr-lab/libsnark.git
cd libsnark && mkdir build && cd build
cmake .. -DWITH_SUPERCOP=OFF
make -j$(nproc)
sudo make install
cd ../..

echo "所有依赖安装完成!"