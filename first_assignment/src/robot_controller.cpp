#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "nav_msgs/Odometry.h"
#include "srv_first_assignment/Server.h"

/*
Initialize the publisher and the client
*/
ros::Publisher pub;
ros::ServiceClient client;

/*
To connect to the server in srv_first_package/src/Server.cpp
*/
srv_first_assignment::Server rec_pos;

//Values of te position received from the server
float position_x=0;
float position_y=0;

/*
The positionCallback has to check if the current position of the robot is the same as the one that it's received from the Server.
If the distance between the robot is less than 0.1 the position that Server gave is catched, otherwise the velocity of the robot is set 
proportionally respect to the remaining distance.
*/
void positionCallback(const nav_msgs::Odometry::ConstPtr& msg)
{
     position_x=rec_pos.response.x;
     position_y=rec_pos.response.y;
	
     ROS_INFO("Values current position: x[%f] y[%f]", msg->pose.pose.position.x, msg->pose.pose.position.y);

     if (((abs(msg->pose.pose.position.x - position_x) < 0.1) && (abs(msg->pose.pose.position.y - position_y) < 0.1)))

     {
       ROS_INFO("Catched the position");
       /*Since the position is catched, now it asks for a new position. 
         The position is always between the values -6.0 to 6.0 either for
         the x both for y */
       rec_pos.request.min=-6.0;
       rec_pos.request.max=6.0;
       client.call(rec_pos);

     }

     else
     {
          ROS_INFO("Position received: x[%f] y[%f]", position_x, position_y);
          /*From the topic geometry_msgs we get the velocity to set in the robot */
          geometry_msgs::Twist vel;
          vel.linear.x = 100*(position_x-msg->pose.pose.position.x);
          vel.linear.y = 100*(position_y-msg->pose.pose.position.y);
          pub.publish(vel);
          ROS_INFO("Values published: x[%f] y[%f]", vel.linear.x, vel.linear.y);
     }

}

int main(int argc, char **argv)
{
   ros::init(argc, argv, "robot_controller");
   ros::NodeHandle n;

   pub = n.advertise<geometry_msgs::Twist>("/cmd_vel", 1000); 
   client = n.serviceClient<srv_first_assignment::Server>("/random_position");

   /*Make the request to the server by setting the maximun and minimum values in wich 
    there must be the position to catch */
   rec_pos.request.min=-6.0;
   rec_pos.request.max=6.0;
   client.call(rec_pos);
   ros::Subscriber sub = n.subscribe("/odom", 1000, positionCallback);
   ros::spin();

   return 0;
}
