#! /usr/bin/env python

import rospy
from geometry_msgs.msg import PoseWithCovarianceStamped


initialpose = rospy.Publisher('/initialpose', PoseWithCovarianceStamped, queue_size=10)
rospy.init_node('pub_init_pose', anonymous=True)
rate = rospy.Rate(1)
rate.sleep()
msg = PoseWithCovarianceStamped()
msg.header.stamp = rospy.Time.now()
msg.header.frame_id = 'map'
msg.pose.pose.position.x = 1.30993247032
msg.pose.pose.position.y = -0.241903960705
msg.pose.pose.orientation.z = -0.648065977381
msg.pose.pose.orientation.w = 0.77438996506


while initialpose.get_num_connections() < 1:
    pass
initialpose.publish(msg)
