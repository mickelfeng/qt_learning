/*************************************************************
 *
 *  Soft Name   :   myzlib
 *  License     :   GPLv3
 *  Author      :   LiuYun
 *  Mail        :   <liuyun01@kylinos.com.cn>
 *
 ************************************************************/
 
#ifndef _WORKER_H_
#define _WORKER_H_

#include <unistd.h>

#ifdef  DEBUG
    #include <sys/syscall.h>
    #include <stdio.h>
#endif

#ifdef  HAVE_CPP11
    #include <memory>
#else
    #include <boost/shared_ptr.hpp>
#endif

#include <buffer.h>
#include <compress_function.h>

namespace threads_zlib
{

class Worker 
{
public:
    Worker(InBuffer *in_buffer, OutBuffer *out_buffer) 
        :   m_inbuffer(in_buffer),
            m_outbuffer(out_buffer)
    {}

    /**
     *  @func   threads will run this function 
     */
    void process()
    {
        int len = compress_function(m_inbuffer->data(), m_outbuffer->data(), m_inbuffer->getLen());

#ifdef  DEBUG
        printf("compress success data len = %d\n", len);
#endif
        delete (m_inbuffer);

        m_outbuffer->setLen(len);
        m_outbuffer->setFinish(true);
    }

private:
    InBuffer        *m_inbuffer;
    OutBuffer       *m_outbuffer;
};

#ifdef  HAVE_CPP11
    typedef std::shared_ptr<Worker> WorkerPtr;
#else
    typedef boost::shared_ptr<Worker> WorkerPtr;
#endif
}

#endif
