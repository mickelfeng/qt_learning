#!/bin/sh
#删除不需要的文件
PWD=`pwd`
MYNAME=`basename $PWD`
rm -rvf `find -name "*.o"` a.out test
#压缩本目录
tar -zcf /tmp/$MYNAME.tar.gz ../$MYNAME 2>/dev/null
#发送到ftp
lftp 172.19.5.52 -u ly,123123 -e "cd personal/ly/My\\ docment/ ; put /tmp/$MYNAME.tar.gz ; exit "
#删除本地文件
rm -rf /tmp/$MYNAME.tar.gz
