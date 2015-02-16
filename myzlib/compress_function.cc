/*************************************************************
 *
 *  Soft Name   :   myzlib
 *  License     :   GPLv3
 *  Author      :   LiuYun
 *  Mail        :   <liuyun01@kylinos.com.cn>
 *
 ************************************************************/
 
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <put_header.h>
#include <compress_function.h>
#include <defined.h>
#include <stdio.h>
#include <stdlib.h>

namespace threads_zlib
{

size_t compress_function(unsigned char *in, unsigned char *out, size_t size,int level )
{
    size_t got;
    size_t out_size;
    unsigned long head;
    unsigned long tail;
    unsigned long check;
    unsigned long ulen;
    unsigned long clen;
    int form = 0;
    z_stream *strm = NULL;

    got = size;
    out_size = BLOCK_SIZE * 2;
    
    strm = new z_stream;

    strm->zfree = Z_NULL;
    strm->zalloc = Z_NULL;
    strm->opaque = Z_NULL;

    if(deflateInit2(strm, level, Z_DEFLATED, -15, 8,
                Z_DEFAULT_STRATEGY) != Z_OK)
    {
        return -1;
    }

    head = put_header(out);
    out += head;

    (void)deflateReset(strm);
    (void)deflateParams(strm, level, Z_DEFAULT_STRATEGY);
    
    ulen = clen = 0;
    check = CHECK(0L, Z_NULL, 0);
    
    ulen += (unsigned long)got;
    strm->next_in = static_cast<Bytef *>(in);
    strm->avail_in = size;

    check = CHECK(check, strm->next_in, strm->avail_in);

    strm->avail_out = out_size;
    strm->next_out = static_cast<Bytef *>(out);
    (void)deflate(strm, Z_FINISH);
    clen = out_size - strm->avail_out;
    
    if(strm->avail_out ==0) {
        fprintf(stderr, "块大小不够，请扩大块大小并重新编译\n");
        ::exit(-1);
    }

    out += clen;
    tail = put_tailer(out, ulen, clen, check, head);

    (void)deflateEnd(strm);
    delete (strm);
    return head + clen + tail;

}

}
