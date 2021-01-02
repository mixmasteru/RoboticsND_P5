//
// Created by mixmasteru on 02.01.21.
//

#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <move_base_msgs/MoveBaseAction.h>
#include "std_msgs/String.h"

visualization_msgs::Marker getMarker(float x, float y, float w, ros::Duration duration, uint32_t shape = visualization_msgs::Marker::CUBE) {
    visualization_msgs::Marker marker;
    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker.header.frame_id = "map";
    marker.header.stamp = ros::Time::now();

    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    marker.ns = "add_markers";
    marker.id = 0;

    // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
    marker.type = shape;

    // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
    marker.action = visualization_msgs::Marker::ADD;

    // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
    marker.pose.position.x = x;
    marker.pose.position.y = y;
    marker.pose.position.z = 0.25;
    marker.pose.orientation.x = 0;
    marker.pose.orientation.y = 0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = w;

    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker.scale.x = 0.25;
    marker.scale.y = 0.25;
    marker.scale.z = 0.25;

    // Set the color -- be sure to set alpha to something non-zero!
    marker.color.r = 0.0f;
    marker.color.g = 1.0f;
    marker.color.b = 0.0f;
    marker.color.a = 1.0;

    marker.lifetime = duration;

    return marker;
}

void goalCallback(const move_base_msgs::MoveBaseActionGoal::ConstPtr &msg) {
    ros::NodeHandle n;
    ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);
    float x = msg->goal.target_pose.pose.position.x;
    float y = msg->goal.target_pose.pose.position.y;
    float w = msg->goal.target_pose.pose.orientation.w;

    //ROS_INFO("x: [%f]", x);
    visualization_msgs::Marker marker = getMarker(x, y, w, ros::Duration());
    marker_pub.publish(marker);
}

void callbackResult(const move_base_msgs::MoveBaseActionResult::ConstPtr &msg){
    ros::NodeHandle n;
    ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

    visualization_msgs::Marker marker;
    marker.header.frame_id = "map";
    marker.header.stamp = ros::Time::now();
    marker.ns = "add_markers";
    marker.id = 0;
    marker.action = visualization_msgs::Marker::DELETEALL;
    marker_pub.publish(marker);
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "basic_shapes");
    ros::NodeHandle n;
    ros::Rate r(1);
    ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

    ros::Subscriber subgoal = n.subscribe("/move_base/goal", 10, goalCallback);
    ros::Subscriber subres = n.subscribe("/move_base/result", 10, callbackResult);

    while (ros::ok()) {
        ros::spin();
    }
}

//visualization_msgs::Marker marker1 = getMarker(0.0, 3.0, 1.0, ros::Duration(5));
//marker_pub.publish(marker1);
//sleep(5)
//visualization_msgs::Marker marker2 = getMarker(0.5, -4.0, 1.0, ros::Duration(5));
//marker_pub.publish(marker2);
