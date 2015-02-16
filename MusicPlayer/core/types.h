/**
 *  
 *  功能描述：常用定义
 *  作者    ：LiuYun
 *  邮箱    ：wolf_coming@sina.cn
 *
 */

#ifndef __TYPES_H__
#define __TYPES_H__

#include <stdio.h>
#include <errno.h>

namespace mp {

enum Status {PLAYING, STOPED, SUSPEND} ;

typedef unsigned char       u8;
typedef unsigned short      u16;
typedef unsigned int        u32;   
typedef unsigned long long  u64;

#define handle_error_no(msg, errno) \
               do { perror(msg); return(errno); } while (0)

#define handle_error(msg) \
               do { perror(msg); return ;} while (0)

#define CMD_PLAY        0x10    
#define CMD_SUSPEND     0x11
#define CMD_STOP        0x12
#define CMD_PROGRESS    0x13 
#define CMD_RECOVER     0x14

#define ACK_DATA        0x22
#define ACK_RET         0x23

#if defined(__sparc) 
    #define BIG_ENDIAN
#else
    #define LITTLE_ENDIAN
#endif

#if defined(__arch64__) || defined(__x86_64__) || defined(AMD64)
    #define ARCH64
#endif


};

#endif
