/*************************************************************
 *
 *  Soft Name   :   myzlib
 *  License     :   GPLv3
 *  Author      :   LiuYun
 *  Mail        :   <liuyun01@kylinos.com.cn>
 *
 ************************************************************/
 
#ifndef _THREAD_H_
#define _THREAD_H_

#ifdef  HAVE_CPP11
    #include <memory>
#else
    #include <boost/function.hpp>
    #include <boost/shared_ptr.hpp>
#endif

#include <string>

namespace threads_zlib 
{

#ifdef  HAVE_CPP11
    typedef std::function<void()> ThreadFunc;
#else
    typedef boost::function<void()> ThreadFunc;
#endif

class Thread 
{
public:
    Thread(const ThreadFunc &, const std::string &);

    void join();
private:
    /* local thread callback */
    static void * thread_callback(void *);

    /* Run Func */
    void runFunc();

private:
    /* Thread name */
    std::string     m_threadname;

    /* Thread Callback Function */
    ThreadFunc      m_func;

    pthread_t       m_tid;
};

#ifdef  HAVE_CPP11
    typedef std::shared_ptr<Thread> ThreadPtr;
#else
    typedef boost::shared_ptr<Thread> ThreadPtr;
#endif

}
#endif
