#include <QCoreApplication>
#include "tcpserver.h"
#include "vehicledata.h"
#include "udpserver.h"



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    VehicleData m_data;


    UdpServer m_udp_server;
    TcpServer m_tcp_server;

    m_udp_server.run();
    m_tcp_server.startServer();

    return a.exec();
}
