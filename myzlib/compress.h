/*************************************************************
 *
 *  Soft Name   :   myzlib
 *  License     :   GPLv3
 *  Author      :   LiuYun
 *  Mail        :   <liuyun01@kylinos.com.cn>
 *
 ************************************************************/
 
#ifndef _COMPRESS_H_
#define _COMPRESS_H_

#include <defined.h>

namespace threads_zlib
{

/**
 *  @enum   CP_SUCCESS  compress success
 *          CP_FAILURE  compress failure
 */
typedef enum { CP_SUCCESS, CP_FAILURE } COMRPESS_STATUS;

extern COMRPESS_STATUS my_compress(int infd, int outfd, int thread_num);

}

#endif
