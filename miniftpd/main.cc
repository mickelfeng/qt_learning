#include <net/ftpserver.h>
#include <lib/eventloop.h>
#include <net/inetaddress.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <getopt.h>

using namespace miniftp;

void show_help()
{
    printf("Usage : miniftp [options]\n\n"
            "Options:\n"
            "\t-h, --help\t\tShow this help.\n"
            "\t-v, --version\t\tShow Version.\n"
            "\t-d, --daemon\t\tAs a Daemon program.\n\n"
            "Report Bug. <liuyun01@kylinos.com.cn>\n");
}

void show_version()
{
    printf("Miniftp Version 1.0.1\n");
}

int main(int argc, char *argv[])
{
    for(;;) {
        int options_index = -1;
        static const struct option long_options[] = {
            {"help", no_argument, 0, 'h'},
            {"version", no_argument, 0, 'v'},
            {"daemon", no_argument, 0, 'd'},
            {0, 0, 0, 0},
        };
        static const char *short_options = "hvd";
        int c = getopt_long(argc, argv, short_options, long_options, &options_index);
        if(c < 0) {
            break;
        }

        switch(c) {
            case 'h':
                show_help();
                exit(0);
            case 'v':
                show_version();
                exit(0);
            case 'd':
                daemon(0, 0);
                break;
            default:
                exit(0);
        }
    }
    
    signal(SIGPIPE, SIG_IGN);

    InetAddress listenAddr(21);
    EventLoop baseLoop;
    FtpServer server(&baseLoop, listenAddr);

    server.start();

    baseLoop.loop();
}
