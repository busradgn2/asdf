#include "tcpserver.h"



/*!
 * \brief TcpServer::TcpServer
 * \param parent
 */
TcpServer :: TcpServer (QObject *parent) : QTcpServer(parent)
{

}


/*!
 * \brief TcpServer::startServer
 */
void TcpServer::startServer()
{
    if(!this->listen(QHostAddress("127.0.0.1"),1234))
    {
        qDebug() << "Could not start server!";
    }else
    {
        qDebug() << "Listening...";
    }
}



/*!
 * \brief TcpServer::incomingConnection
 * \param socket_descriptor
 */
void TcpServer::incomingConnection(qintptr socket_descriptor)
{
    qDebug() << socket_descriptor << "Connecting...";

    MyThread* thread = new MyThread(socket_descriptor,this);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}
