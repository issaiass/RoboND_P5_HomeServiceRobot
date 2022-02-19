#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

int main(int argc, char** argv){
  // Initialize the simple_navigation_goals node
  ros::init(argc, argv, "add_markers");

  // markers publisher node
  ros::NodeHandle n;
  ros::Rate r(1);
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

  // Set our initial shape type to be a cube
  uint32_t shape = visualization_msgs::Marker::CUBE;


  visualization_msgs::Marker marker;
  // Set the frame ID and timestamp.  See the TF tutorials for information on these.
  marker.header.frame_id = "map";
  marker.header.stamp = ros::Time::now();

  // Set the namespace and id for this marker.  This serves to create a unique ID
  // Any marker sent with the same namespace and id will overwrite the old one
  marker.ns = "basic_shapes";
  marker.id = 0;

  // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
  marker.type = shape;

  // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
  marker.action = visualization_msgs::Marker::ADD;

  // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
  marker.pose.position.x = -1.2;
  marker.pose.position.y = 0;
  marker.pose.position.z = 0;
  marker.pose.orientation.x = 0.0;
  marker.pose.orientation.y = 0.0;
  marker.pose.orientation.z = 0.0;
  marker.pose.orientation.w = 0.707;

  // Set the scale of the marker -- 1x1x1 here means 1m on a side
  marker.scale.x = 0.2;
  marker.scale.y = 0.2;
  marker.scale.z = 0.2;

  // Set the color -- be sure to set alpha to something non-zero!
  marker.color.r = 0.2f;
  marker.color.g = 0.0f;
  marker.color.b = 0.8f;
  marker.color.a = 0.9;

  marker.lifetime = ros::Duration();

  ROS_INFO("Adding the Object to Grasp");
  sleep(1);
  // Publish the marker
  marker_pub.publish(marker);

  ROS_INFO("Waiting 5 secods for grasping sequence");
  ros::Duration t(5,0);
  t.sleep();

  // delete de marker
  marker.action = visualization_msgs::Marker::DELETE;
  // publish the marker
  marker_pub.publish(marker);

  ROS_INFO("Object Deleted, waiting another 5 sec");

  t.sleep();
 
  marker.pose.position.x = 3.2;
  marker.pose.position.y = 0;
  marker.action = visualization_msgs::Marker::ADD;
  marker_pub.publish(marker);

  ROS_INFO("Object Delivered to the next zone");
  sleep(3);
 
  return 0;
}
