#include "mythread.h"

MyThread::MyThread()
{
    data = 0;
}

void MyThread::run()
{
    // Some expensive task
    for(int i=0;i<5;i++)
    {
        emit dataReady(data++);
        QThread::msleep(1000);
    }
    qDebug() << "MyThread stopped";
    return;
}
