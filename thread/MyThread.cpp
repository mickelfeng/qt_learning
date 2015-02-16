/**************MyThread.cpp*****************/

#include "MyThread.h"
#include <iostream>

MyThread::MyThread(QPushButton *pb) : QThread()
{
    this->pb=pb;
}

void MyThread::run(){
    int i=1;
    while(true){
        std::cout<<"the number is:"<<i<<std::endl;
        QThread::msleep(1000);
        i+=10;
        pb->move(i,i);
    }
}

MyThread::~MyThread()
{

}

