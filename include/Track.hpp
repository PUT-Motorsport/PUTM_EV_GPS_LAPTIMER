#include "Point.hpp"
#include <vector>

extern GPS::Position current_position; 

class Track{
    private:
        std::vector<Point> Points;
        std::string run;
    public:
    Track()
    {
        std::cin >> run;
        if(run == "lap")
        {
            for(int i = 0; i<3; i++)
            {
                std::string get;
                std::cin >> get;
                Point new_point(current_position.latitude, current_position.longitude);
                    Points.push_back(new_point);}
            }
        } 
        else if(run == "acc")
        {
            
        }
        else if(run == "skidpad")
        {

        }
        else{
            ROS_INFO("Invalid run name!");
        }
    }

    void CreatePointOnTrack(Point new_point);

};