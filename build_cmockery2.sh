##########################################################
# File Name		: build_cmockery2.sh
# Author		: winddoing
# Created Time	: 2018年11月29日 星期四 20时16分37秒
# Description	:
##########################################################
#!/bin/bash

PWD=`pwd`


cd cmockery2

./autogen.sh
./configure --prefix=$PWD/../lib_cmockery2/ --enable-static

make
make install

cd -
