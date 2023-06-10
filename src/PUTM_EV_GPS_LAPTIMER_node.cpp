#include <ros/ros.h>
#include <sensor_msgs/NavSatFix.h>
#include <PUTM_EV_GPS_LAPTIMER/time.h>

#include "../include/Point.hpp"
#include "../include/GPS.hpp"

Point StartFinishLine(0,0);

void PositionCallback(const sensor_msgs::NavSatFixPtr& location)
{
    ROS_INFO("Current position: %f, %f", location->latitude, location->longitude);
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "PUTM_LapTimer");

    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("gnss", 100, PositionCallback);

    while(true){
        ros::Duration(0.5).sleep();
        ros::spin();
    }

    return 0;
} 