/**
 *
 *  功能描述：测试使用
 *  作者    ：LiuYun
 *  邮箱    ：wolf_coming@sina.cn
 *
 */
#include "player.h"

using namespace mp;

int main(int argc, char *argv[])
{
    Player play("/root/1.txt");
    play.play();

    play.stop();
    
    play.get_progress();
    while(1);
}
