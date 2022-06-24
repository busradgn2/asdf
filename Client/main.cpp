#include <QCoreApplication>
#include <random>
#include "tcpclient.h"
#include "udpclient.h"
#include <thread>

inline double dRand(double d_max);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    srand(time(NULL));


    TcpClient m_tcp_client;
    UdpClient m_udp_client;
    VehicleData m_data;

    m_data.setLatittude(dRand(100));
    m_data.setLongitude(dRand(100));
    m_data.setVelocity(dRand(100));
    m_data.setAcceleration(dRand(100));


    //std::thread thread(m_tcp_client.run());





    //while(true)
    //{
        m_data.setLatittude(dRand(100));
        m_data.setLongitude(dRand(100));
        m_data.setVelocity(dRand(100));
        m_data.setAcceleration(dRand(100));
        m_tcp_client.setData(m_data);
        m_tcp_client.run();


        m_data.setLatittude(dRand(100));
        m_data.setLongitude(dRand(100));
        m_data.setVelocity(dRand(100));
        m_data.setAcceleration(dRand(100));
        m_udp_client.setData(m_data);
        m_udp_client.sendData();
    //}



    return a.exec();
}

/*!
 * \brief dRand
 * \param d_max
 * \return
 */
inline double dRand(double d_max)
{

    double random = (double)rand() / RAND_MAX; // 0 ile 1 arası
    return random * d_max;
}
