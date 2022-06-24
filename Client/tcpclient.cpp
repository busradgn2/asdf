#include "tcpclient.h"

TcpClient::TcpClient(QObject *parent)
    : QObject{parent}
{

}


/*!
 * \brief ClientSocket::run
 */
void TcpClient::run(){
    this->socket = new QTcpSocket(this);


    connect(this->socket,SIGNAL(connected()),this,SLOT(connectedd()));
    connect(this->socket,SIGNAL(disconnected()),this,SLOT(disconnectedd()));
    connect(this->socket,SIGNAL(readyRead()),this,SLOT(readyReadd()));
    connect(this->socket,SIGNAL(bytesWritten(qint64)),this,SLOT(bytesWrittenn(qint64)));

    qDebug() << "Connecting...";
    this->socket->connectToHost("127.0.0.1",1234);
  //this->socket->connectToHost("192.168.0.2",1234);

    if(!this->socket->waitForConnected(3000)){
        qDebug() << "Error: " << this->socket->errorString();
    }

}


/*!
 * \brief ClientSocket::connectedd
 */
void TcpClient::connectedd(){

    QString latittude = QString::number(data.getLatittude());
    QByteArray lat = latittude.toUtf8();

    QString longitude = QString::number(data.getLongitude());

    QString velocity = QString::number(data.getVelocity());

    QString acceleration = QString::number(data.getAcceleration());


    lat.append(" " + longitude.toUtf8() + " " + velocity.toUtf8() + " " + acceleration.toUtf8());

    qDebug() << "Connected";

    if(-1 == this->socket->write(lat)){
        qDebug() << "Error: " << this->socket->errorString();
    }


}


/*!
 * \brief ClientSocket::disconnectedd
 */
void TcpClient::disconnectedd(){

    this->socket->deleteLater();
    qDebug() << "Disonnected";
}


/*!
 * \brief ClientSocket::bytesWrittenn
 * \param bytes
 */
void TcpClient::bytesWrittenn(qint64 bytes){
    qDebug() << "We wrote:" << bytes;
}


/*!
 * \brief ClientSocket::readyReadd
 */
void TcpClient::readyReadd(){
    qDebug() << "Reading...";
    qDebug() << this->socket->readAll();
}


/*!
 * \brief ClientSocket::setData
 * \param data_values
 */
void TcpClient::setData(VehicleData data_values)
{
    this->data = data_values;
}


/*!
 * \brief ClientSocket::getData
 * \return
 */
VehicleData TcpClient::getData()
{
    return this->data;
}
