/*************************************************************
 *
 *  Soft Name   :   myzlib
 *  License     :   GPLv3
 *  Author      :   LiuYun
 *  Mail        :   <liuyun01@kylinos.com.cn>
 *
 ************************************************************/
 
#include <compress.h>
#include <defined.h>

#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

using namespace threads_zlib;

void print_usage()
{
    printf("Usage myzlib [options] <filename> [outputfilename]\n\n");
    printf("Options:\n"
            "\t-h, --help\t\tShow this help.\n"
            "\t-v, --version\t\tShow version.\n"
            "\t-p, --process\t\tProcess num.\n"
            "Report Bug. <liuyun01@kylinos.com.cn>\n");
}

void print_version()
{
    printf("Version 1.0.0\n");
}

/**
 *  @define THREAD_NUM  how many threads do you have.
 */
#define THREAD_NUM  16

/**
 *  @text   UNKNOW_FILE     open file err, maybe can't find file.
 *          CREATE_FILE     create file err, maybe access error or file exist.
 */
typedef enum {UNKNOW_FILE_ERR, CREATE_FILE_ERR, COMPRESS_ERR} STATUS_ERR;
void print_err(STATUS_ERR status) 
{
    switch(status) {
        case UNKNOW_FILE_ERR:
            fprintf(stderr, "Can't find file.\n");
            break;
        case CREATE_FILE_ERR:
            fprintf(stderr, "Create file failure. Maybe permission denied or File exist.\n");
            break;
        case COMPRESS_ERR:
            fprintf(stderr, "Compress file error happend.\n");
            break;
        default:
            break;
    }
}

int main(int argc, char *argv[]) 
{
    int thread_num = 0;
    int args = argc;    /* real args. skip options */

    for(;;) {
        int options_index = -1;
        static const struct option long_options[] = {
            {"help", no_argument, 0, 'h'},
            {"version", no_argument, 0, 'v'},
            {"process", required_argument, 0, 'p'},
            {0, 0, 0, 0},
        };
        static const char *short_options = "hvp:";
        int c = getopt_long(argc, argv, short_options, long_options, &options_index);
        if(c < 0) {
            break;
        }
        
        switch(c) {
            case 'h':
                print_usage();
                exit(0);
            case 'v':
                print_version();
                exit(0);
            case 'p':
                thread_num = atoi(optarg);
                args -= 2;
                break;
            default:
                exit(0);
        }
    }

    if(args < 2) {
        /* we need a file to compress. */
        print_usage();
        exit(-1);
    }

    thread_num = thread_num > 0 ? thread_num : THREAD_NUM;  /* set thread num */

    const char *in_filename = (args > 2) ? argv[argc - 2] : argv[argc - 1];
    char *out_filename = NULL;

    if(args > 2) {
        out_filename = argv[argc - 1];
    } else {
        /* unknow outfilename, create it <outfilename = infilename + '.gz'> */
        char *str = (char *)malloc(MAX_NAME_LEN);
        const char *filename = basename(in_filename);
        strncpy(str, filename, strlen(filename));
        out_filename =  strcat(str, ".gz");
    }   

    /* open compress file */
    int in_fd = open(in_filename, O_RDONLY);
    if(in_fd < 0) {
        print_err(UNKNOW_FILE_ERR);
        exit(-1);
    }

    int out_fd = creat(out_filename, 0644);
    if(out_fd < 0) {
        print_err(CREATE_FILE_ERR);
        exit(-1);
    }

    /* Compress File */
    COMRPESS_STATUS st = CP_FAILURE;
    if((st = my_compress(in_fd, out_fd, thread_num)) != CP_SUCCESS) {
        print_err(COMPRESS_ERR);
        exit(-1);
    }

    /* free out_filename str memory. */
    if(args <= 2) {
        free(out_filename);
    }

    /* close file description */
    close(in_fd);
    close(out_fd);
    
    return 0;
}
