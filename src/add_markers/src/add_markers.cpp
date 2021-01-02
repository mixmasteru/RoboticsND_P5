//
// Created by mixmasteru on 02.01.21.
//

#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <move_base_msgs/MoveBaseAction.h>
#include "std_msgs/String.h"

class AddMarker {
public:

    AddMarker() {
        marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);
        subgoal = n.subscribe("/move_base/goal", 10, &AddMarker::goalCallback, this);
        subres = n.subscribe("/move_base/result", 10, &AddMarker::callbackResult, this);
        state = 0;
    }

    visualization_msgs::Marker getMarker(float x, float y, float w, ros::Duration duration) {
        visualization_msgs::Marker marker;
        // Set the frame ID and timestamp.  See the TF tutorials for information on these.
        marker.header.frame_id = "map";
        marker.header.stamp = ros::Time::now();

        // Set the namespace and id for this marker.  This serves to create a unique ID
        // Any marker sent with the same namespace and id will overwrite the old one
        marker.ns = "add_markers";
        marker.id = 0;

        // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
        marker.type = this->shape;

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
        float x = msg->goal.target_pose.pose.position.x;
        float y = msg->goal.target_pose.pose.position.y;
        float w = msg->goal.target_pose.pose.orientation.w;
        if(state == 0){
            //ROS_INFO("x: [%f]", x);
            visualization_msgs::Marker marker = getMarker(x, y, w, ros::Duration());
            marker_pub.publish(marker);
        }
        if(state == 1){
            final_marker = getMarker(x, y, w, ros::Duration(5));
        }
        state++;
    }

    void callbackResult(const move_base_msgs::MoveBaseActionResult::ConstPtr &msg) {
        if(state == 1){
            visualization_msgs::Marker marker;
            marker.header.frame_id = "map";
            marker.header.stamp = ros::Time::now();
            marker.ns = "add_markers";
            marker.id = 0;
            marker.action = visualization_msgs::Marker::DELETEALL;
            marker_pub.publish(marker);
        }
        if(state == 2){
            marker_pub.publish(final_marker);
        }
    }

    void demo(){
        ros::Duration(5.0).sleep();//somehow it needs some time before the first publish
        marker_pub.publish(getMarker(0.0, 3.0, 1.0, ros::Duration(5)));
        ros::Duration(10.0).sleep();
        marker_pub.publish(getMarker(0.5, -4.0, 1.0, ros::Duration(5)));
    }

private:
    ros::NodeHandle n;
    ros::Publisher marker_pub;
    ros::Subscriber subgoal;
    ros::Subscriber subres;

    uint32_t shape = visualization_msgs::Marker::CUBE;

    int state;
    visualization_msgs::Marker final_marker;
};

int main(int argc, char **argv) {
    ros::init(argc, argv, "add_markers");
    AddMarker addMarker;

    if(argc > 1){
        ROS_INFO("DEMO");
        while (ros::ok()) {
            addMarker.demo();
            break;
        }
    }
    else{
        while (ros::ok()) {
            ros::spin();
        }
    }
}
