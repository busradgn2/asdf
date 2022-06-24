#include "vehicledata.h"



/*!
 * \brief Data::Data
 */
VehicleData::VehicleData()
{

}


/*!
 * \brief Data::setLatittude
 * \param lat
 */
void VehicleData::setLatittude(double lat)
{
    m_latittude = lat;
}


/*!
 * \brief Data::setLongitude
 * \param longi
 */
void VehicleData::setLongitude(double longi)
{
    m_longitude = longi;
}


/*!
 * \brief Data::setVelocity
 * \param velo
 */
void VehicleData::setVelocity(double velo)
{
    m_velocity = velo;
}


/*!
 * \brief Data::setAcceleration
 * \param acce
 */
void VehicleData::setAcceleration(double acce)
{
    m_acceleration = acce;
}


/*!
 * \brief Data::getLatittude
 * \return
 */
double VehicleData::getLatittude()
{
    return m_latittude;
}


/*!
 * \brief Data::getLongitude
 * \return
 */
double VehicleData::getLongitude()
{
    return m_longitude;
}


/*!
 * \brief Data::getVelocity
 * \return
 */
double VehicleData::getVelocity()
{
    return m_velocity;
}


/*!
 * \brief Data::getAcceleration
 * \return
 */
double VehicleData::getAcceleration()
{
    return m_acceleration;
}
