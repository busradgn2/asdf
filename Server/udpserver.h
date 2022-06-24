#ifndef UDPSERVER_H
#define UDPSERVER_H

#include <QObject>
#include <QUdpSocket>
#include"vehicledata.h"
#include "mythread.h"


/*!
 * \brief The UdpServer class
 */
class UdpServer : public QObject
{
    Q_OBJECT
public:

    explicit UdpServer(QObject *parent = nullptr);
    VehicleData data;
    void run();
signals:

public slots:
    void readReady();
private:
     QUdpSocket* socket;

};

#endif // UDPSERVER_H
