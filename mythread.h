#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QObject>
#include <QDebug>

class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread();
    void run() override;

signals:
    void dataReady(int i);

private:
    int data;
};

#endif // MYTHREAD_H
