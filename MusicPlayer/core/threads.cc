/**
 *  
 *  功能描述：线程封装包
 *  作者    ：LiuYun  
 *  邮箱    ：wolf_coming@sina.cn
 *
 */

#include "threads.h"
#include <assert.h>

using namespace mp;

Threads::Threads(ThreadFunc &func) 
{
    set_func(func);
}

u32 Threads::start_thread( void *arg )
{
    printf("1111122334\n");
    int rc = pthread_create(&m_id, NULL, m_func, arg); 
    if( rc != 0 ) {
        handle_error_no("Create Thread Failure! \n", ETHREAD);
    }
    return 0;
}

void Threads::stop()
{
    pthread_exit(NULL);
}

void Threads::set_func(ThreadFunc func)
{
    assert(func != NULL);
    m_func = func;
}

