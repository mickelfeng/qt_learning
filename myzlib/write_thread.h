/*************************************************************
 *
 *  Soft Name   :   myzlib
 *  License     :   GPLv3
 *  Author      :   LiuYun
 *  Mail        :   <liuyun01@kylinos.com.cn>
 *
 ************************************************************/
 
#ifndef _WRITE_THREAD_H_
#define _WRITE_THREAD_H_

#include <thread.h>

#ifdef  HAVE_CPP11
    #include <memory>
#else
    #include <boost/shared_ptr.hpp>
#endif

namespace threads_zlib
{

class WriteThread 
{
public:
    WriteThread(int outfd);

    void join();

private:
    void write_data();

private:
    int     m_outfd;

    ThreadPtr   m_thread;
};

#ifdef  HAVE_CPP11
    typedef std::shared_ptr<WriteThread> WriteThreadPtr;
#else
    typedef boost::shared_ptr<WriteThread> WriteThreadPtr;
#endif

}

#endif
