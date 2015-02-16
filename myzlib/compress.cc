/*************************************************************
 *
 *  Soft Name   :   myzlib
 *  License     :   GPLv3
 *  Author      :   LiuYun
 *  Mail        :   <liuyun01@kylinos.com.cn>
 *
 ************************************************************/
 
#include <compress.h>
#include <thread_pool.h>
#include <write_thread.h>

namespace threads_zlib 
{

/**
 *  @func   compress function
 *  @parm1  infd    input file description
 *  @parm2  outfd   output file description
 */
COMRPESS_STATUS my_compress(int infd, int outfd, int thread_num)
{
    ThreadPool pool(thread_num);    /* init read threads */

    /* New Write Thread */
    WriteThreadPtr write_thread(new WriteThread(outfd));     /* start thread */

    for(;;) {
#ifdef  DEBUG
        printf("获取一块输入缓冲区\n");
#endif
        InBuffer* inbuff = new InBuffer();
        /* read data from fd */
        int len = 0;
        if((len = read(infd, inbuff->data(), BLOCK_SIZE)) == 0) {
            OutBufferList.get_space(true);
            break;
        }
        inbuff->setLen(len);

#ifdef  DEBUG
        printf("获取一块输出缓冲区\n");
#endif
        pool.append(WorkerPtr(new Worker(inbuff, OutBufferList.get_space(false))));
    }

    write_thread->join();                   /* wait write thread quit */
#ifdef  DEBUG
    printf("写线程退出\n");
#endif
    return CP_SUCCESS;
}

}
