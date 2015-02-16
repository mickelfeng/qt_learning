/**
 *
 *  功能描述：ffmpeg封装库
 *  作者    ：LiuYun
 *  邮箱    ：wolf_coming@sina.cn
 *
 */

#include "mp_ffmpeg.h"
#include "mp_errno.h"

#include <string.h>
#include <assert.h>

using namespace mp;

void FFmpeg::set_filename(const char filename[])
{   
    assert(filename != NULL);
    memcpy(m_filename, filename, strlen(filename));
}

u32 FFmpeg::open()
{
    return SUCCESS;
}

u32 FFmpeg::close()
{
    return SUCCESS;
}

u32 FFmpeg::play()
{

    return SUCCESS;
}

u32 FFmpeg::suspend()
{
    return SUCCESS;
}

u32 FFmpeg::recover()
{

    return SUCCESS;
}

u32 FFmpeg::stop()
{

    return SUCCESS;
}
