#pragma once 
#include "GPS.hpp"
constexpr float  BOLID_RADIUS = 0.000015;   // Radius of point around bolid in seconds.

class Point{
    private:
    float latitude;
    float longitude;
    float radius;
    public:

    Point(float _latitude, float _longitude) : latitude(_latitude) ,longitude(_longitude), radius(BOLID_RADIUS){}
    template <typename T>
    inline bool IsInBounds(const T& value, const T& low, const T& high) 
    {
        return !(value < low) && (value < high);
    }
    inline bool IsEmpty()
    {
        return (latitude == 0) || (longitude == 0);
    }
    bool IsInCircle(const GPS::Position raw_position)
    {
        if(IsInBounds(latitude, raw_position.latitude-radius, raw_position.latitude+radius) && IsInBounds(longitude, raw_position.longitude-radius, raw_position.longitude+radius))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool Exists()
    {
        return (this == 0x0 ? true : false);
    }
};