#include "udpclient.h"


/*!
 * \brief UdpClient::UdpClient
 * \param parent
 */
UdpClient::UdpClient(QObject *parent)
    : QObject{parent}
{

}

/*!
 * \brief UdpClient::sendData
 */
void UdpClient::sendData()
{
    this->socket = new QUdpSocket(this);

    qDebug() << "Starting...";

    QString latittude = QString::number(data.getLatittude());

    QString longitude = QString::number(data.getLongitude());

    QString velocity = QString::number(data.getVelocity());

    QString acceleration = QString::number(data.getAcceleration());

    QByteArray data {latittude.toUtf8()};
    data.append(" " + longitude.toUtf8() + " " + velocity.toUtf8() + " " + acceleration.toUtf8());

    socket->writeDatagram(data,QHostAddress("127.0.0.1"),1235);
    qDebug() << "Sent data:" << data;
}

/*!
 * \brief UdpClient::setData
 * \param data_values
 */
void UdpClient::setData(VehicleData data_values)
{
    this->data = data_values;
}

/*!
 * \brief UdpClient::getData
 * \return
 */
VehicleData UdpClient::getData()
{
    return this->data;
}
