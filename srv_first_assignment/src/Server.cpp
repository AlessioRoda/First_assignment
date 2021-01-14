#include "ros/ros.h"
#include "srv_first_assignment/Server.h"

/**Function to calculate the random number in the given interval*/
double randMToN(double M, double N)
{     return M + (rand() / ( RAND_MAX / (N-M) ) ) ; }

/**Get the interval in wich to calculate the random number, then pass it to randMToN to generate the random number*/
bool myrandom (srv_first_assignment::Server::Request &req, srv_first_assignment::Server::Response &res){
	res.x = randMToN(req.min, req.max);
        res.y = randMToN(req.min, req.max);
        ROS_INFO("Position values: x[%f] y[%f]", res.x, res.y);
    return true;
}



int main(int argc, char **argv)
{
   ros::init(argc, argv, "Server");
   ros::NodeHandle n;
   ros::ServiceServer service= n.advertiseService("/random_position", myrandom);
   ROS_INFO("Server activated");
   ros::spin();

   return 0;
}
