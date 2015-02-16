/*
该文件保存游戏配置信息
*/
#ifndef CONFIG_H
#define CONFIG_H

#include <QTextStream>
#include <QPainter>

//输入输出流控制
static QTextStream cout(stdout, QIODevice::WriteOnly);
static QTextStream cin(stdin,QIODevice::ReadOnly);
extern QPainter *p;

//#define MAX_BULLETS 4
//#define SHOW_FPS true

#define SCALE 0.8

#define SWIDTH (480 * SCALE)
#define SHEIGHT (850 * SCALE)

#define FPS 30

//#define START_POS_X 140
//#define START_POS_Y 560

#endif // CONFIG_H
