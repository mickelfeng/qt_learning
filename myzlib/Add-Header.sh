#!/bin/sh

HEADER="/*************************************************************
 *
 *  Soft Name   :   myzlib
 *  License     :   GPLv3
 *  Author      :   LiuYun
 *  Mail        :   <liuyun01@kylinos.com.cn>
 *
 ************************************************************/
 "

for name in $@
do
    echo "$HEADER" | cat /dev/fd/0 $name > $name.1
    \mv $name.1 $name
done


