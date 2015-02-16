/*************************************************************
 *
 *  Soft Name   :   myzlib
 *  License     :   GPLv3
 *  Author      :   LiuYun
 *  Mail        :   <liuyun01@kylinos.com.cn>
 *
 ************************************************************/
 
#ifndef  _PUT_HEADER_H_
#define _PUT_HEADER_H_

namespace threads_zlib 
{

#define CHECK(a,b,c) (form == 1 ? adler32(a,b,c) : crc32(a, b, c))

/*  往一段缓冲区中填写gzip头    */
extern unsigned long put_header(unsigned char *);

/*  往一段缓冲区中填写gzip尾    */
extern unsigned long  put_tailer(unsigned char * ,unsigned long, unsigned long,unsigned long, unsigned long );

}

#endif
