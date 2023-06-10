#include <ros/ros.h>
#include <sensor_msgs/NavSatFix.h>
#include <PUTM_EV_GPS_LAPTIMER/time.h>

#include "../include/Point.hpp"
#include "../include/GPS.hpp"

Point *StartFinishLine;

void PositionCallback(const sensor_msgs::NavSatFixPtr& location)
{
    ROS_INFO("Current position: %f, %f", location->latitude, location->longitude);
    if(StartFinishLine->Exists()){
        StartFinishLine = new Point(location->latitude, location->longitude);
        return;
    }
    else
    {
        Point new_position(location->latitude, location->longitude);
        if(new_position.IsInCircle(*(StartFinishLine)));
    }
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