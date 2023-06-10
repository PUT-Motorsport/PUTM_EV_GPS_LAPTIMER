#pragma once 

constexpr float  BOLID_RADIUS = 0.000015;   // Radius of point around bolid in seconds.

class Point{
    private:
    float latitude;
    float longitude;
    float radius;
    public:

    Point(float _latitude, float _longitude) : latitude(_latitude) ,longitude(_longitude){}
    template <typename T>
    inline bool IsInBounds(const T& value, const T& low, const T& high) 
    {
        return !(value < low) && (value < high);
    }
    inline bool IsEmpty()
    {
        return (latitude == 0) || (longitude == 0);
    }
    bool IsInCircle(const std::pair<float, float> raw_position, const Point);

};