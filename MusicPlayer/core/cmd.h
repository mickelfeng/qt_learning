/**
 *
 *  功能描述：线程通信命令格式
 *  作者    ：LiuYun
 *  邮箱    ：wolf_coming@sina.cn
 *
 */
#ifndef __CMD_H__
#define __CMD_H__

#include "types.h"

namespace mp {

/*发送命令*/
struct Cmd_Player {
    Cmd_Player() : magic_num(0xfefefefe), size(sizeof(struct Cmd_Player)) {}
    Cmd_Player(u32 t) : magic_num(0xfefefefe), size(sizeof(struct Cmd_Player)) { type = t; }
    /*命令魔数*/
    u32 magic_num;
    /*命令大小*/
    u32 size;
    /*命令类型*/
    u32 type;
    /*播放文件名*/
    char filename[200];
    /*命令解析*/
    u32 analy_cmd( char *buffer, ssize_t n);
};

/*应答数据*/
struct Ack_Player {
    Ack_Player() : magic_num(0xfefeffff), size(sizeof(struct Ack_Player)) {}
    Ack_Player(u32 t, u32 d) : magic_num(0xfefeffff), size(sizeof(struct Ack_Player)) { type = t; data = d ;}
    /*应答魔数*/
    u32 magic_num;
    /*应答大小*/
    u32 size;
    /*应答类型*/
    u32 type;
    /*应答数据*/
    u32 data;
    /*应答解析*/
    u32 analy_ack( char *buffer, ssize_t n);
};

};

#endif
