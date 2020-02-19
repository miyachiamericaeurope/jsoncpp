#!/bin/bash 
mkdir -p build/debug
cd build/debug
cmake -DCMAKE_BUILD_TYPE=release -DCMAKE_INSTALL_INCLUDEDIR=include/jsoncpp -DBUILD_STATIC_LIBS=ON -DBUILD_SHARED_LIBS=OFF -DARCHIVE_INSTALL_DIR=. -G "Unix Makefiles" ../..
make
cd build/debug
sudo make install
cd ../../include
sudo cp -r json /usr/local/include

