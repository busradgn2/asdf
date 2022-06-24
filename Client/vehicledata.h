#ifndef VEHICLEDATA_H
#define VEHICLEDATA_H


class VehicleData
{
public:
    VehicleData();

    void setLatittude(double lat);
    void setLongitude(double longi);
    void setVelocity(double velo);
    void setAcceleration(double acce);

    double getLatittude();
    double getLongitude();
    double getVelocity();
    double getAcceleration();

private:
    double m_latittude;
    double m_longitude;
    double m_velocity;
    double m_acceleration;
};

#endif // VEHICLEDATA_H
