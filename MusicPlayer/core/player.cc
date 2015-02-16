/**
 *
 *  功能描述：播放模块，播放、暂停、停止功能
 *  作者    ：LiuYun
 *  邮箱    ：wolf_coming@sina.cn
 *  
 */
#include "player.h"
#include "player_thread.h"

#include <string.h>
#include <strings.h>
#include <assert.h>
#include <sys/types.h>  
#include <sys/socket.h>

using namespace mp;

static int fd[2];

extern void * thread_cb (void *arg);

Player::Player() : m_status(STOPED)
{
    bzero(m_filename, sizeof(m_filename));
    
    int rc = socketpair(AF_UNIX, SOCK_STREAM, 0, fd);
    if(rc != 0) {
        handle_error("创建管道失败\n");
    }
    /*设置播放线程回调函数*/
    m_thread.set_func(thread_cb);
    m_thread.start_thread((void *)fd[0]);
}

Player::Player(const char* filename) :  m_status(STOPED)
{
    set_filename(filename);
    
    int rc = socketpair(AF_UNIX, SOCK_STREAM, 0, fd);
    if(rc != 0) {
        handle_error("创建管道失败\n");
    }
    /*设置播放线程回调函数*/
    m_thread.set_func(thread_cb);
    m_thread.start_thread((void *)fd[0]);
}

u32 Player::play()
{
    assert(m_filename != NULL);

    set_status(PLAYING);

    Cmd_Player cmd(CMD_PLAY);
    memcpy(cmd.filename, m_filename, sizeof(m_filename));

    write(fd[1], &cmd, sizeof(cmd));
}

u32 Player::play(const char *filename) 
{
    set_filename(filename);
    return play();
}

u32 Player::play(u8 &progress) 
{
    return play();
}

u32 Player::play(const char *filename, u8 &progress) 
{
    set_filename(filename);
    return play();
}

u32 Player::stop()
{
    set_status(STOPED);

    Cmd_Player cmd(CMD_STOP);

    write(fd[1], &cmd, sizeof(cmd));
}

u32 Player::suspend()
{
    if(m_status != PLAYING) 
        return -ENOPLAYING;
    set_status(SUSPEND);
    
    Cmd_Player cmd(CMD_SUSPEND);

    write(fd[1], &cmd, sizeof(cmd));
}   

u32 Player::recover()
{
    if(m_status != SUSPEND)
        return -ENOSUSPEND;
    set_status(PLAYING);

    Cmd_Player cmd(CMD_RECOVER);

    write(fd[1], &cmd, sizeof(cmd));
}

void Player::set_filename(const char* filename) 
{
    assert(filename != NULL);
    bzero(m_filename, sizeof(m_filename));
    memcpy(m_filename, filename, strlen(filename));
}

void Player::set_status(Status st)
{
    m_status = st;
}

u8 Player::get_progress()
{
    Cmd_Player cmd(CMD_PROGRESS);

    write(fd[1], &cmd, sizeof(cmd));
    
    u8 val = 0;
    read(fd[1], &val, sizeof(u8));
    return val;
}

Status Player::get_status()
{
    return m_status;
}
