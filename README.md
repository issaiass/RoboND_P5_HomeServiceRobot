# RoboND_P5_HomeServiceRobot


<details open>
<summary> <b>Brief Review<b></summary>

This is the final project of the Robotics Software Nanodegree from Udacity Program.  During the program we localized robots, map enviroments and plan trajectories for robotics navigation.  This put all the knowledge of the nanodegree together to demonstrate a simulated application of a Home Service/Delivery Robot.

The purpose of this project is to map an enviroment using SLAM, save the map and use this map to navigate and pick up and drop virtual objects

First, we will build a model in gazebo for the enviroment. Later, we will interface SLAM with the teleoperation key to map the environment.  After building the map we will test the robot abilities in reaching multiple goals and orient itself using the ros navigation stack.  Finally we will use virtual markers to navigate to them and but also draw on rviz.

Below and examples of the outcome

### <b>Home Service Robot</b>
<p align="center">
<img src = "doc/gif/homeservice.GIF?raw=true" center=true width="85%"/>
</p>

#### These are some of the parts of the project

### <b>Using the SLAM Package</b>
<p align="center">
<img src = "doc/gif/slam.GIF?raw=true" center=true width="85%"/>
</p>

### <b>Using the Navigation Package</b>
<p align="center">
<img src = "doc/gif/navigation.GIF?raw=true" center=true width="85%"/>
</p>

### <b>Picking Objects</b>
<p align="center">
<img src = "doc/gif/pickobjects.GIF?raw=true" center=true width="85%"/>
</p>

### <b>Adding Markers</b>
<p align="center">
<img src = "doc/gif/addmarkers.GIF?raw=true" center=true width="85%"/>
</p>


The project is now divided in several scripts to help you experiment each part.

</details>

<details open>
<summary> <b>Using The Package <b></summary>

NOTE:  *Sometimes some nodes crash at the beginning, consider to close all windows and test again everything*.

- Follow the next steps to replicate the outcome
~~~
    cd ~
    mkdir -p catkin_ws/src
    cd catkin_ws
~~~
- Clone this repo in the `~/catkin_ws/src` folder by typing:
~~~ 
    cd ~/catkin_ws/src
    git clone https://github.com/issaiass/RoboND_P5_HomeServiceRobot.git
    cd ~/catkin_ws
~~~
- Next compile and source the repository
~~~
    catkin_make
    source ~/catkin_ws/devel/setup.bash
~~~

#### <b>SLAM Testing</b>
- For SLAM testing, launch the shell script localized in `~/catkin_ws/src/RoboND_P5_HomeServiceRobot/src/scripts`
~~~
    ./test_slam.sh
~~~
- Later a window for teleoperation will open, feel free to move through the environment to map it
- At the end, when you are done with mapping, save the map using the next command in the folder you want to save the map
~~~
    rosrun map_server map_saver -f <path_of_map_file>
~~~

#### <b>Navigation Testing</b>
- For Navigation testing, launch the shell script localizad in `~/catkin_ws/src/RoboND_P5_HomeServiceRobot/src/scripts`
~~~
    ./test_navigation.sh
~~~
- Localize the openend rviz window and take on the top bar click on the navigation/goal pose buton.
- Maintain the Left click button of the mouse on any known position on the map and move it to the desired orientation.
- Finally release the left click button and wait the robot to navigate its new goal.

#### <b>Pick/Release Objects Testing</b>
- For Picking up objects testing, launch the shell script localizad in `~/catkin_ws/src/RoboND_P5_HomeServiceRobot/src/scripts`
~~~
    ./pick_objects.sh
~~~
- Wait a moment and you will see that the robot navigates to two goals at different times completing the task

#### <b>Add Markers Testing</b>
- For adding markers test, launch the shell script localizad in `~/catkin_ws/src/RoboND_P5_HomeServiceRobot/src/scripts`
~~~
    ./add_markers.sh
~~~
- Wait and you will see that in rviz will appear some cubes at different positions in a lapse of 5 seconds or a little more.

#### <b>Home Service Robot Testing<b>
- For testing the full robot package, launch the shell script localizad in `~/catkin_ws/src/RoboND_P5_HomeServiceRobot/src/scripts`
~~~
    ./home_service.sh
~~~

<details open>
<summary> <b>Results<b></summary>

We will made a youtube video later

<p align="center"> </p>
</details>



<details open>
<summary> <b>Issues<b></summary>

- As mentioned before, sometimes you will probably experiment a crach of the node, just close everything, wait some seconds and launch again everything
- If you experience some missing packages i will leave you here some hints of prepare your workspace
~~~
    mkdir -p ~/catkin_ws/src
    cd ~/catkin_ws/src
    catkin_init_workspace
    cd ..
    catkin_make
    sudo apt-get update
    cd ~/catkin_ws/src
    git clone https://github.com/ros-perception/slam_gmapping
    git clone https://github.com/turtlebot/turtlebot
    git clone https://github.com/turtlebot/turtlebot_interactions
    git clone https://github.com/turtlebot/turtlebot_simulator
    cd ~/catkin_ws/
    source devel/setup.bash
    rosdep -i install gmapping
    rosdep -i install turtlebot_teleop
    rosdep -i install turtlebot_rviz_launchers
    rosdep -i install turtlebot_gazebo
    catkin_make
    source devel/setup.bash
~~~
</details>

<details open>
<summary> <b>Future Work<b></summary>

- Make different approaches to solve the problem.

</details>

<details open>
<summary> <b>Contributing<b></summary>

Your contributions are always welcome! Please feel free to fork and modify the content but remember to finally do a pull request.

</details>

<details open>
<summary> :iphone: <b>Having Problems?<b></summary>

<p align = "center">

[<img src="https://img.shields.io/badge/linkedin-%230077B5.svg?&style=for-the-badge&logo=linkedin&logoColor=white" />](https://www.linkedin.com/in/riawa)
[<img src="https://img.shields.io/badge/telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/>](https://t.me/issaiass)
[<img src="https://img.shields.io/badge/instagram-%23E4405F.svg?&style=for-the-badge&logo=instagram&logoColor=white">](https://www.instagram.com/daqsyspty/)
[<img src="https://img.shields.io/badge/twitter-%231DA1F2.svg?&style=for-the-badge&logo=twitter&logoColor=white" />](https://twitter.com/daqsyspty) 
[<img src ="https://img.shields.io/badge/facebook-%233b5998.svg?&style=for-the-badge&logo=facebook&logoColor=white%22">](https://www.facebook.com/daqsyspty)
[<img src="https://img.shields.io/badge/linkedin-%230077B5.svg?&style=for-the-badge&logo=linkedin&logoColor=white" />](https://www.linkedin.com/in/riawe)
[<img src="https://img.shields.io/badge/tiktok-%23000000.svg?&style=for-the-badge&logo=tiktok&logoColor=white" />](https://www.linkedin.com/in/riawe)
[<img src="https://img.shields.io/badge/whatsapp-%23075e54.svg?&style=for-the-badge&logo=whatsapp&logoColor=white" />](https://wa.me/50766168542?text=Hello%20Rangel)
[<img src="https://img.shields.io/badge/hotmail-%23ffbb00.svg?&style=for-the-badge&logo=hotmail&logoColor=white" />](mailto:issaiass@hotmail.com)
[<img src="https://img.shields.io/badge/gmail-%23D14836.svg?&style=for-the-badge&logo=gmail&logoColor=white" />](mailto:riawalles@gmail.com)

</p

</details>

<details open>
<summary> <b>License<b></summary>
<p align = "center">
<img src= "https://mirrors.creativecommons.org/presskit/buttons/88x31/svg/by-sa.svg" />
</p>
</details>
