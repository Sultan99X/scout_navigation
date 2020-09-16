#ifndef SCOUT_WEBOTS_RUNNER_HPP
#define SCOUT_WEBOTS_RUNNER_HPP

#include "scout_webots_extension.hpp"
#include <std_msgs/String.h>
#include <memory>
#include <ros/ros.h>


#include <webots_ros/set_int.h>




namespace westonrobot
{
    class ScoutWebotsRunner
    {
    public:
        ScoutWebotsRunner();
        int Run(int argc, char *argv[]);
        void AddExtension(WebotsExtension* extension_pointer);
        void InitExtensions();

    private:      

        void Quit(int sig);
        void ControllerNameCallback(const std_msgs::String::ConstPtr &name); 

        std::vector<WebotsExtension*> extensions_;
        int controller_count_ = 0;
        ros::ServiceClient time_step_client_;
        webots_ros::set_int time_step_srv_;        
        std::vector<std::string> controller_list_;


    };

} // namespace westonrobot
#endif