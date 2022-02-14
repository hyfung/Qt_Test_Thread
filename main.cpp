#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include <QObject>

#include "mythread.h"

void foo()
{
    qDebug() << "Helloworld from thread";
}

void on_dataReady(int i)
{
    qDebug() << "[on_dataReady] " << i;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread *myThread = QThread::create(foo);

    MyThread *myCustomThread = new MyThread;

    QObject::connect(myCustomThread, &MyThread::dataReady, &a, &on_dataReady);

    myThread->start();
    myCustomThread->start();
//    myCustomThread->wait();
    return a.exec();
}
