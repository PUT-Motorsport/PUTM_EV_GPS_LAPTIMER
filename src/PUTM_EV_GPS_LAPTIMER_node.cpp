#include <ros/ros.h>
#include <geometry_msgs/Vector3Stamped.h>
#include <PUTM_EV_GPS_LAPTIMER/time.h>

#include "../include/Point.hpp"
#include "../include/GPS.hpp"

Point *StartFinishLine;

void PositionCallback(const geometry_msgs::Vector3Stamped& location)
{
    ROS_INFO("Current position: %f, %f", location.vector.x, location.vector.y);
    if(StartFinishLine->Exists()){
        StartFinishLine = new Point(location.vector.x, location.vector.y);
        return;
    }
    else
    {
        Point new_position(location.vector.x, location.vector.y);
        if(new_position.IsInCircle(*(StartFinishLine))){
            ROS_INFO("Crossed Point");
        }
    }
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "PUTM_LapTimer");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("/filter/positionlla", 100, PositionCallback);

    while(true){
        ros::Duration(0.1).sleep();
        ros::spin();
    }
    return 0;
} 