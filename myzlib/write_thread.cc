/*************************************************************
 *
 *  Soft Name   :   myzlib
 *  License     :   GPLv3
 *  Author      :   LiuYun
 *  Mail        :   <liuyun01@kylinos.com.cn>
 *
 ************************************************************/
 
#include <write_thread.h>
#include <buffer.h>
#include <pthread.h>
#include <unistd.h>

#ifdef  HAVE_CPP11
    #include <memory>
#else
    #include <boost/bind.hpp>
#endif

#ifdef  DEBUG
    #include <stdio.h>
#endif

using namespace threads_zlib;

WriteThread::WriteThread(int outfd) 
    :   m_outfd(outfd)
{
#ifdef  HAVE_CPP11
    m_thread.reset(new Thread(std::bind(&WriteThread::write_data, this), "Write Thread"));
#else
    m_thread.reset(new Thread(boost::bind(&WriteThread::write_data, this), "Write Thread"));
#endif
}

void WriteThread::join()
{
    m_thread->join();
}

void WriteThread::write_data()
{
    int local_seq = 1;
    for(;;) {
        OutBuffer *bf = NULL;
        OutBuffer *bf_head = OutBufferList.get_buffers();
        for(int i = 0; i < MAX_BUFFER_SIZE; i ++ ) {
            if(bf_head[i].getSeq() == local_seq) {
                bf = &bf_head[i];
                break;
            }
        }
        
        if(bf == NULL)  continue;

        if(bf->isLast()) {
            break;
        }

        bf->wait_finish();                          /* wait block data finish */
        write(m_outfd, bf->data(), bf->getLen());   /* write into file */
#ifdef  DEBUG
        printf("写完一段数据\n");
#endif  
        OutBufferList.drop_space(bf);   /* pop block data */

        local_seq ++;
    }
}
