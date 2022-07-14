#pragma once

#include <string.h>
#include <sensor_msgs/LaserScan.h>
#include <nav_msgs/Odometry.h>
#include <sensor_msgs/Imu.h>
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <vector>

#ifndef FLAT_WORLD_IMU_NODE_H_
#define FLAT_WORLD_IMU_NODE_H_
#define GRAVITY 9.8

namespace smb_highlevel_controller {

	class SmbHighlevelController {
		public:
			//Constructor.
			SmbHighlevelController(ros::NodeHandle& nodeHandle);
			//Destructor.
			~SmbHighlevelController() = default;

			bool inicio();

		private:	
			ros::NodeHandle nh_;
  			ros::Time last_published_time_;
  			ros::Publisher publisher_;
  			ros::Subscriber subscriber_;
			void msgCallback(const sensor_msgs::ImuConstPtr msg);	
	};
} /* namespace */

#endif // FLAT_WORLD_IMU_NODE_H_