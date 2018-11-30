##########################################################
# File Name		: clean.sh
# Author		: winddoing
# Created Time	: 2018年11月30日 星期五 09时44分29秒
# Description	:
##########################################################
#!/bin/bash

dirs_array=`ls -d */`
clean_file=(*.out *.xml)
PWD=`pwd`

function each_clean()
{
    local cnt=${#clean_file[@]}
    local self_dir=$1

    for file in ${clean_file[@]}
    do
        if [ -f "$file" ]; then
            rm $file
            cnt=$(($cnt-1))
        fi
    done

    if [ $cnt -eq 0 ]; then
        return 0;
    else
        return 1;
    fi
}

function clean()
{
    for dir in ${dirs_array}
    do
        if [[ x"$dir" = x"cmockery2/" || x"$dir"  = x"lib_cmockery2/" ]]; then
            continue;
        fi
        (echo -n "entry $dir clean ... "; cd $dir; each_clean && echo "OK" || echo "ignore")
    done
}

#main

clean
