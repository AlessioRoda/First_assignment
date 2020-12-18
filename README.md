
# First_assignment

In this repository there are two packages: first_assignment and srv_first_assignment.
The first one contains a subfolder /src in wich there is the program robot_controller.cpp. It contains the publisher and the subscriber of the process to permit to the robot to move by following the position that it receives from the server.

The second package contains:

1) A subfolder /srv in wich there are the params that the Server requires and the params it returns
2) A subfolder /src with the Server.cpp code. This code provides to generate a random position in a generic interval that it receives as an input and returns it to the /robot_controller node.

The /stageros node provides to give the actual position of the robot by giving a topic odom, by using a nav_msgs/Odometry


As it's represented in the folowing image, that's the way in wich nodes comunicate to eachothers.

![github-small](https://user-images.githubusercontent.com/48511957/101025417-74aaf380-356d-11eb-8549-9952303d6bf4.png)

## How to run the code

First of all to run the code correctly download this package inside your ROS workspace. Then follow the following commands inside your ROS workspace:

* roscore &
* catkin_make
* rosrun srv_first_assignment Server
* rosrun stage_ros stageros $(rospack find assignment1)/world/exercise.world
* rosrun first_assignment robot_controller

Then you should see the robot who moves to catch the position it receives from Server (you can see the position by having a look to the logs the /Server node provides).

ora spero bene




