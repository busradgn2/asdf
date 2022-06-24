#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QObject>
#include <QTcpSocket>
#include<QDebug>
#include "vehicledata.h"


/*!
 * \brief The MyThread class
 */
class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(qintptr ID, QObject *parent = 0);
    void run();
    void setData(VehicleData data_values);
    VehicleData getData();
signals:

public slots:   
    void readyRead();
    void disconnected();

private:
    QTcpSocket* socket;
    VehicleData data;
    qintptr socket_descriptor;
};

#endif // MYTHREAD_H
