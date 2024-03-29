#include "ros/ros.h"
#include "performance_test/SuperAwesome.h"


/*
 * @brief: Subscriber callback
*/
void callback(const performance_test::SuperAwesome::ConstPtr& msg) {
    // Extracts timestamps from publisher at the time the message was created and when it is read
    double subscriber_time = std::stod(std::to_string(ros::Time::now().toNSec()).substr(0,13));
    double publisher_time = std::stod(msg->content.substr(0,13));
    // Calculate diff (in ms)
    double diff = subscriber_time - publisher_time;
    // Print time diff between pub/sub
    ROS_INFO("cpp_subscriber time diff: %lf ms\n", diff);
}

int main(int argc, char **argv) {
  // Node, handler and subscriber init
  ros::init(argc, argv, "cpp_subscriber");
  ros::NodeHandle n;

  ros::Subscriber subscriber = n.subscribe("performance_test", 1000, callback);

  ros::spin();

  return 0;
}