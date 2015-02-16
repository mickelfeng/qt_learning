/*************************************************************
 *
 *  Soft Name   :   myzlib
 *  License     :   GPLv3
 *  Author      :   LiuYun
 *  Mail        :   <liuyun01@kylinos.com.cn>
 *
 ************************************************************/
 
#ifndef _COMPRESS_FUNCTION_H_
#define _COMPRESS_FUNTION_H_

#include <zlib.h>

namespace threads_zlib
{

/*  压缩in缓冲区中的数据,将结果写入out缓冲区中  */
extern size_t compress_function(unsigned char *in ,unsigned char *out, size_t size, int level = Z_DEFAULT_COMPRESSION);

}

#endif
