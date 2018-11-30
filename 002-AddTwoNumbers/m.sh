##########################################################
# File Name		: m.sh
# Author		: winddoing
# Created Time	: 2018年11月29日 星期四 20时36分57秒
# Description	:
##########################################################
#!/bin/bash

gcc solution.c -static -lcmockery  -I./../lib_cmockery2/include/ -L./../lib_cmockery2/lib/

astyle --style=linux --indent=spaces=4 --convert-tabs --pad-oper --unpad-paren --break-blocks=all -n ./*.c ./*.h
