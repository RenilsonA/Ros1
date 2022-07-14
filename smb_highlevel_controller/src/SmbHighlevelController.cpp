#include <smb_highlevel_controller/SmbHighlevelController.hpp>

namespace smb_highlevel_controller {

	SmbHighlevelController::SmbHighlevelController(ros::NodeHandle& nodeHandle) {
	  	bool resultadoIni = inicio();
	    ROS_ASSERT(resultadoIni);
	}

	bool SmbHighlevelController::inicio(){
		publisher_  = nh_.advertise<sensor_msgs::Imu>("/scan", 10);
  		subscriber_ = nh_.subscribe("/scan", 150, &SmbHighlevelController::msgCallback, this);

  		return true;
	}

	void SmbHighlevelController::msgCallback(const sensor_msgs::ImuConstPtr imu_in) {
	    if (last_published_time_.isZero() || imu_in->header.stamp > last_published_time_) {
			last_published_time_ = imu_in->header.stamp;
		    sensor_msgs::Imu imu_out = *imu_in;
		    imu_out.linear_acceleration.x = 0.0;
		    imu_out.linear_acceleration.y = 0.0;
		    imu_out.linear_acceleration.z = GRAVITY;
		    publisher_.publish(imu_out);
		}
	}
} /* namespace */
