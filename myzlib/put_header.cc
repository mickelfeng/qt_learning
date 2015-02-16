/*************************************************************
 *
 *  Soft Name   :   myzlib
 *  License     :   GPLv3
 *  Author      :   LiuYun
 *  Mail        :   <liuyun01@kylinos.com.cn>
 *
 ************************************************************/
 
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <error.h>
#include <errno.h>
#include <zlib.h>
#include <sys/stat.h>
#include <put_header.h>

namespace threads_zlib
{

int form = 0;	/* We use gzip format in here    */
unsigned long check;	/*	check value for input data	*/
time_t mtime;   /*  time stamp from input file for gzip header  */
int level;  /*  compress level  */

#if defined(MSDOS) || defined(OS2) || defined(WIN32) || defined(__CYGWIN__)
#include <io.h>

#define SET_BINARY_MODE(fd) setmode(fd, O_BINARY)
#else
#define SET_BINARY_MODE(fd)
#endif


#define PUT2L(a,b)  (*(a)=(b)&0xff,(a)[1]=(b)>>8)
#define PUT4L(a,b)  (PUT2L(a,(b)&0xffff),PUT2L((a)+2,(b)>>16))
#define PUT4M(a,b)  (*(a)=(b)>>24,(a)[1]=(b)>>16,(a)[2]=(b)>>8,(a)[3]=(b))
#define COMB(a,b,c) (form == 1)

#define BASE 65521U

#define LOW16 0xffff



void get_mtime(int ind)
{
    struct stat st;
    mtime = fstat(ind, &st) ? time(NULL) : st.st_mtime;
}

unsigned long time2dos(time_t t)
{
    struct tm *tm;
    unsigned long dos;

    if (t == 0)
        t = time(NULL);
    tm = localtime(&t);
    if (tm->tm_year < 80 || tm->tm_year > 207)
        return 0;
    dos = (tm->tm_year - 80) << 25;
    dos += (tm->tm_mon + 1) << 21;
    dos += tm->tm_mday << 16;
    dos += tm->tm_hour << 11;
    dos += tm->tm_min << 5;
    dos += (tm->tm_sec + 1) >> 1;   /* round to double-seconds */
    return dos;
}

unsigned long gf2_matrix_times(unsigned long *mat, unsigned long vec)
{
    unsigned long sum;

    sum = 0;
    while (vec) {
        if (vec & 1)
            sum ^= *mat;
        vec >>= 1;
        mat++;
    }
    return sum;
}

void gf2_matrix_square(unsigned long *square, unsigned long *mat)
{
    int n;

    for (n = 0; n < 32; n++)
        square[n] = gf2_matrix_times(mat, mat[n]);
}


unsigned long adler32_comb(unsigned long adler1, unsigned long adler2,size_t len2)
{
    unsigned long sum1;
    unsigned long sum2;
    unsigned rem; 

    rem = (unsigned)(len2 % BASE);
    sum1 = adler1 & LOW16; 
    sum2 = (rem * sum1) % BASE;
    sum1 += (adler2 & LOW16) + BASE - 1;
    sum2 += ((adler1 >> 16) & LOW16) + ((adler2 >> 16) & LOW16) + BASE -        rem;
    if (sum1 >= BASE) sum1 -= BASE;
    if (sum1 >= BASE) sum1 -= BASE;
    if (sum2 >= (BASE << 1)) sum2 -= (BASE << 1);
    if (sum2 >= BASE) sum2 -= BASE;
    return sum1 | (sum2 << 16);
}

unsigned long crc32_comb(unsigned long crc1, unsigned long crc2,
        size_t len2)
{
    int n;
    unsigned long row;
    unsigned long even[32];     /* even-power-of-two zeros operator */
    unsigned long odd[32];      /* odd-power-of-two zeros operator */

    /* degenerate case */
    if (len2 == 0)
        return crc1;

    /* put operator for one zero bit in odd */
    odd[0] = 0xedb88320UL;          /* CRC-32 polynomial */
    row = 1;
    for (n = 1; n < 32; n++) {
        odd[n] = row;
        row <<= 1;
    }

    /* put operator for two zero bits in even */
    gf2_matrix_square(even, odd);

    /* put operator for four zero bits in odd */
    gf2_matrix_square(odd, even);

    /* apply len2 zeros to crc1 (first square will put the operator for one
       zero byte, eight zero bits, in even) */
    do {
        /* apply zeros operator for this bit of len2 */
        gf2_matrix_square(even, odd);
        if (len2 & 1)
            crc1 = gf2_matrix_times(even, crc1);
        len2 >>= 1;

        /* if no more bits set, then done */
        if (len2 == 0)
            break;

        /* another iteration of the loop with odd and even swapped */
        gf2_matrix_square(odd, even);
        if (len2 & 1)
            crc1 = gf2_matrix_times(odd, crc1);
        len2 >>= 1;

        /* if no more bits set, then done */
    } while (len2 != 0);

    /* return combined crc */
    crc1 ^= crc2;
    return crc1;
}




unsigned long put_header(unsigned char *out)
{
    unsigned long len;
    unsigned char head[30];
    char *name = NULL;


    head[0] = 31;
    head[1] = 139;
    head[2] = 8;                /* deflate */
    head[3] = name != NULL ? 8 : 0;
    PUT4L(head + 4, mtime);
    head[8] = level == 9 ? 2 : (level == 1 ? 4 : 0);
    head[9] = 3;                /* unix */
    //writen(outd, head, 10);
    memcpy(out, head, 10);
    len = 10;


    return len;

}

unsigned long put_tailer(unsigned char *out,unsigned long ulen, unsigned long clen, unsigned long check, unsigned long head)
{
    unsigned char tail[46];
    unsigned long len;

    PUT4L(tail, check);
    PUT4L(tail + 4, ulen);
    memcpy(out, tail, 8);

    len = 8;
    return len;
}

}
