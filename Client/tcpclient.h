#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include "vehicledata.h"


class TcpClient : public QObject
{
    Q_OBJECT
public:
    explicit TcpClient(QObject *parent = nullptr);

    void run();
    void setData(VehicleData data_values);
    VehicleData getData();

public slots:
    void connectedd();
    void disconnectedd();
    void bytesWrittenn(qint64 bytes);
    void readyReadd();
private:
    QTcpSocket* socket;
    VehicleData data;
signals:

};

#endif // TCPCLIENT_H
