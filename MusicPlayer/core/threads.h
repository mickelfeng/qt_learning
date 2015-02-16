/**
 *  
 *  功能描述：线程封装包
 *  作者    ：LiuYun  
 *  邮箱    ：wolf_coming@sina.cn
 *
 */

#ifndef __THREADS_H__
#define __THREADS_H__

#include "types.h"
#include "mp_errno.h"

#include <pthread.h>
#include <boost/noncopyable.hpp>

namespace mp {

typedef void * ( *ThreadFunc ) (void *) ;

class Threads : public boost::noncopyable
{
private:
    /*线程回调函数*/
    ThreadFunc m_func;
    /*线程ID*/
    pthread_t m_id;

public :
    /*默认构造函数*/
    Threads() {}
    /*带回调函数的构造函数*/
    Threads(ThreadFunc &func);
    /*开始线程*/
    u32 start_thread(void *arg);
    /*线程退出函数*/
    void stop();
    /*设置回调函数*/
    void set_func(ThreadFunc func);
};

};
#endif
