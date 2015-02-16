/**
 *
 *  功能描述：线程通信命令格式
 *  作者    ：LiuYun
 *  邮箱    ：wolf_coming@sina.cn
 *
 */

#include "cmd.h"
#include "mp_errno.h"

#include <string.h>

using namespace mp;

/*命令解析器*/
u32 Cmd_Player::analy_cmd( char *buffer, ssize_t n)
{
    if(n == 0) {
        return ECMD;
    }
    char *start, *p = buffer;
    u32 start_num = 0xfefefefe;
    while(memcmp(p, &start_num, sizeof(u32)) != 0 || p >= buffer + n) {
        p ++;
    }

    if(p >= buffer + n) {
        return ECMD;
    }
    /*保存头节点*/
    start = p;
    memcpy(this, start, sizeof(struct Cmd_Player));
    return 0;
}

/*应答解析器*/
u32 Ack_Player::analy_ack( char *buffer, ssize_t n)
{
    if(n == 0) {
        return EACK;
    }
    char *start, *p = buffer;
    u32 start_num = 0xfefeffff;
    while(memcmp(p, &start_num, sizeof(u32)) != 0 || p >= buffer + n) {
        p ++;
    }

    if(p >= buffer + n) {
        return EACK;
    }
    /*保存头节点*/
    start = p;
    memcpy(this, start, sizeof(struct Ack_Player));
    return 0;
}
