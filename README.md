# First_assignment

##Introduction 

In this repository there are two packages: first_assignment and srv_first_assignment.
The first one contains a subfolder /src in wich there is the program robot_controller.cpp. It contains the publisher and the subscriber of the process to permit to the robot to move by following the position that it receives from the server.

The second package contains:
1) A subfolder /Srv in wich there are the params that the Server requires and the params it returns
2) A subfolder /Src with the Server.cpp code. This code provides to generate a random position in a generic interval that it receives as an input and returns to the 

As it's represented in the folowing image, that's the way in wich nodes comunicate to eachothers.
![github-small](https://user-images.githubusercontent.com/48511957/101025417-74aaf380-356d-11eb-8549-9952303d6bf4.png)


