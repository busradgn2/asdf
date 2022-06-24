#include "guiinterface.h"

GuiInterface::GuiInterface()
{
    srand(time(NULL));
    m_data = new VehicleData();
    m_tcp_client = new TcpClient();
    m_udp_client = new UdpClient();
}
GuiInterface::~GuiInterface(){
    delete m_tcp_client;
    delete m_udp_client;
    delete m_data;
}
inline double GuiInterface::dRand(double d_max)
{

    double random = (double)rand() / RAND_MAX; // 0 ile 1 arası
    return random * d_max;
}
void GuiInterface::setVehicleData(){
    m_data->setLatittude(dRand(100));
    m_data->setLongitude(dRand(100));
    m_data->setVelocity(dRand(100));
    m_data->setAcceleration(dRand(100));
}
