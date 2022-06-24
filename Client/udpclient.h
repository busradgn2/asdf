#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <QObject>
#include <QUdpSocket>
#include "vehicledata.h"

class UdpClient : public QObject
{
    Q_OBJECT
public:
    explicit UdpClient(QObject *parent = nullptr);
    void sendData();
    void setData(VehicleData data_values);
    VehicleData getData();
signals:

public slots:


/*!
* \brief socket
*/
private:
    QUdpSocket *socket;
    VehicleData data;
};


#endif // UDPCLIENT_H
