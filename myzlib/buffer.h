/*************************************************************
 *
 *  Soft Name   :   myzlib
 *  License     :   GPLv3
 *  Author      :   LiuYun
 *  Mail        :   <liuyun01@kylinos.com.cn>
 *
 ************************************************************/
 
#ifndef _BUFFER_H_
#define _BUFFER_H_

#include <string>
#include <vector>

#ifdef  HAVE_CPP11
    #include <memory>
#else
    #include <boost/shared_ptr.hpp>
#endif

#ifdef  DEBUG
    #include <stdio.h>
#endif

#include <locker.h>
#include <condition.h>
#include <list>
#include <string.h>
#include <defined.h>

#define _BLOCK_SIZE (BLOCK_SIZE > 1024 ? BLOCK_SIZE : 1024)

namespace threads_zlib
{

class InBuffer 
{
public:
    InBuffer() 
    {
        memset(m_data, 0, _BLOCK_SIZE);
    }

    unsigned char * data()
    {
        return m_data;
    }

    void setLen(int len)
    {
        m_len = len;
    }

    int getLen() const 
    {
        return m_len;
    }

private:
    unsigned char m_data[_BLOCK_SIZE];

    int m_len;
};

#ifdef HAVA_CPP11  
    typedef std::shared_ptr<InBuffer>   InBufferPtr;
#else
    typedef boost::shared_ptr<InBuffer> InBufferPtr;
#endif

extern int max_seq ;

class OutBuffer 
{
public:
    OutBuffer()
        :   m_finish(false),
            m_isLast(false),
            m_seq(-1)
    {
        memset(m_data, 0, _BLOCK_SIZE * 2);
    }

    unsigned char *data()
    {
        return m_data;
    }

    void setLen(int len)
    {
        m_len = len;
    }

    int getLen()
    {
        return m_len;
    }

    int getSeq()
    {
        return m_seq;
    }

    void setSeq(int seq)
    {
        m_seq = seq;
    }

    bool isUsed()
    {
        return m_isUsed;
    }

    void setUsed(bool b)
    {
        m_isUsed = b;
    }

    void setFinish(bool finish)
    {
        m_finish = finish; 
        if(finish) {
            m_cond.notifyAll();        /*  Wakeup write thread */
        }
    }

    void wait_finish() 
    {
        if(m_finish) {
           return;
        }
#ifdef  DEBUG
        printf("正在等待数据块序号\n");
#endif
        m_cond.wait();          /* wait data compress finish */
    }

    bool isLast()
    {
        return m_isLast;
    }

    void setLast(bool isLast)
    {
        m_isLast = isLast;
    }

private:
    unsigned char        m_data[_BLOCK_SIZE * 2];

    int         m_len;

    Condition   m_cond;

    bool        m_finish;

    int  m_seq;

    bool        m_isUsed;

    bool        m_isLast;
};


class OutBufferPool
{
public:
    OutBufferPool()
    {}

    OutBuffer * get_space(bool isLast)
    {
        MutexLock   lock(m_mutex);
        while(1) {
            for(int i = 0; i < MAX_BUFFER_SIZE; i ++) {
                if(m_chunks[i].isUsed()) {
                    i ++;   
                    continue;
                }
                m_chunks[i].setUsed(true);
                m_chunks[i].setFinish(false);
                m_chunks[i].setLast(isLast);
                m_chunks[i].setSeq(max_seq ++);
                return &m_chunks[i];
            }
            m_cond.wait();
        }
    }

    void drop_space(OutBuffer *p) 
    {
        p->setUsed(false);
        m_cond.notify();
    }

    OutBuffer* get_buffers()
    {
        MutexLock lock(m_mutex);
        return  m_chunks;
    }

private:
    OutBuffer   m_chunks[MAX_BUFFER_SIZE];

    Condition   m_cond;

    MutexLock   m_mutex;
};

extern OutBufferPool    OutBufferList;

}

#endif
