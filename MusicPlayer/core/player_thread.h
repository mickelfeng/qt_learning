/**
 *
 *  功能描述：播放模块线程库函数，包括回调等操作函数
 *  作者    ：LiuYun
 *  邮箱    ：wolf_coming@sina.cn
 *
 */

#ifndef __PLAY_THREAD_H__
#define __PLAY_THREAD_H__

#include "types.h"
#include "cmd.h"
#include "eventloop.h"

#include <strings.h>

namespace mp {

static u32 do_work(int );

static u32 do_play(char []);
static u32 do_suspend();
static u32 do_stop();
static u32 do_stop();
static u32 do_progress(int);
static u32 do_recover();

void * thread_cb(void *arg)
{
#ifdef  ARCH64
    long long f = (long long)arg;
    int fd = f;
#else
    int fd = (int)arg;
#endif
    /*事件循环主类*/
    EventLoop eloop;
    Event *event = new Event();
    event->fd = fd;
    event->m_event_cb = do_work;
    /*注册事件*/
    eloop.add_event(event);
    
    /*循环*/
    eloop.loop();

    delete event;
    close(fd);
    return 0;
}

/*真正的播放函数，包含播放器的所有动作*/
u32 do_work(int fd)
{
    int rc = -1;
    char buffer[1024];
    bzero(buffer, sizeof(buffer));
    /*获取命令*/
    ssize_t n = read(fd, buffer, sizeof(buffer));

    struct Cmd_Player cmd;
    char * p = buffer;
    while(cmd.analy_cmd( p, n ) == 0) {
        printf("aaaaaaaa\n");
        u32 cmd_type = cmd.type;
 
        switch(cmd_type) {
            case CMD_PLAY:
                rc = do_play(cmd.filename);
                break;
            case CMD_SUSPEND:
                rc = do_suspend();
                break;
            case CMD_STOP:
                rc = do_stop();
                break;
            case CMD_PROGRESS:
                rc = do_progress(fd);
                break;
            case CMD_RECOVER:
                rc = do_recover();
                break;
            default:
                break;
        }
        p += cmd.size;
        n -= cmd.size;
    }
    
    return 0;

fail:
    return rc;
}

u32 do_play(char filename[]) 
{

    printf("1112222222222222222222222111\n");
    return 0;
}

u32 do_suspend()
{
    printf("133333333333333331111\n");
    return 0;
}

u32 do_stop()
{
    printf("11444444444444444444444444\n");
    return 0;
}

u32 do_progress(int fd)
{
    printf("111555555555555555555551\n");
    u8 val = 0;

    struct Ack_Player ack(ACK_DATA, val);

    write(fd, &ack, ack.size);
    return 0;
}

u32 do_recover()
{
    return 0;
}   

};
#endif
