#include <ros/ros.h>
#include <geometry_msgs/Vector3Stamped.h>
#include <PUTM_EV_GPS_LAPTIMER/time.h>

#include "../include/Point.hpp"
#include "../include/GPS.hpp"
#include "../include/Track.hpp"
#include "../include/FSM/FSM.hpp"

GPS::Position current_position;
connection_fsm FSM;

void PositionCallback(const geometry_msgs::Vector3Stamped& location)
{
    ROS_INFO("Current position: %f, %f", location.vector.x, location.vector.y);
    current_position.latitude = location.vector.x;
    current_position.longitude = location.vector.y;
    // if(StartFinishLine->Exists()){
    //     StartFinishLine = new Point(location.vector.x, location.vector.y);
    //     return;
    // }
    // else
    // {
    //     Point new_position(location.vector.x, location.vector.y);
    //     // if(new_position.IsInCircle(*(StartFinishLine))){
    //     //     ROS_INFO("Crossed Point");
    //     //}
    // }
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "PUTM_LapTimer");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("/filter/positionlla", 100, PositionCallback);

    //Algorithm:
    //1. Get run from user
    //2. Get all expected points.
    //3. Wait for Start crossing.
    //4. if crossed - start time measurement (or get current time as m:s:ms)
    //5. check position in relation to points every 1 ms.
    //6. Send times if start finish crossed, and start over.
    //7.  Stop if time exceded expected time.

    Track track();


    while(true){
        ros::Duration(0.001).sleep();
        ros::spinOnce();
    }
    return 0;
} 