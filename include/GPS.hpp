#pragma once
#include <cmath>

constexpr double EARTH_RADIUS = 6371000.0;  // Radius of the Earth in meters.

namespace GPS{

struct Position
{
   float latitude;
   float longitude;
};

double degreesToRadians(double degrees) {
    return degrees * M_PI / 180.0;
}

// FIXME: Position instead of values.
double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    double dLat = degreesToRadians(lat2 - lat1);
    double dLon = degreesToRadians(lon2 - lon1);

    double a = std::sin(dLat / 2) * std::sin(dLat / 2) +
               std::cos(degreesToRadians(lat1)) * std::cos(degreesToRadians(lat2)) *
               std::sin(dLon / 2) * std::sin(dLon / 2);
    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));
    double distance = EARTH_RADIUS * c;

    // Convert distance to millimeters
    distance *= 1000;

    return distance;
}

}