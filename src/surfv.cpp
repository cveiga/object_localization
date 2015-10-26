#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>

#include "surf_vision/surfLib.h"


static const std::string OPENCV_WINDOW = "Image Window";

SurfLib _sl;
std::string nameDistinct = "";

class SurfVision{
	ros::NodeHandle nh_;
	image_transport::ImageTransport it_;
	image_transport::Subscriber image_sub_;
	//image_transport::Publisher corners_pub_;
	ros::Publisher corners_pub_;

	std::string nameImg_;
	std::string topic_param_;

  public:
  	SurfVision(): it_(nh_){
  		//image_sub_ = it_.subscribe("/panTilt/image_raw", 1, &SurfVision::surfCallBack, this);
		nh_.getParam("probando", topic_param_);
  		image_sub_ = it_.subscribe(topic_param_, 1, &SurfVision::surfCallBack, this);
  		corners_pub_ = nh_.advertise<std_msgs::Float32MultiArray>("surf/corners_object", 1);
  	}

  	SurfVision(std::string name_img): it_(nh_), nameImg_(name_img){
  		//image_sub_ = it_.subscribe("/panTilt/image_raw", 1, &SurfVision::surfCallBack, this);
		nh_.getParam("probando", topic_param_);
  		image_sub_ = it_.subscribe(topic_param_, 1, &SurfVision::surfCallBack, this);
  		corners_pub_ = nh_.advertise<std_msgs::Float32MultiArray >("surf/corners_object", 1);
  	}


	void surfCallBack(const sensor_msgs::ImageConstPtr& msg){
		cv_bridge::CvImagePtr cv_ptr;
		try{
			cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
		}catch(cv_bridge::Exception& e){
			ROS_ERROR("cv_bridge exception: %s", e.what());
			return;
		}

		cv::Mat imgObject = cv::imread(nameImg_, CV_LOAD_IMAGE_GRAYSCALE);
		cv::Mat imgScene = cv_ptr->image;

		_sl.setObject(imgObject);
		_sl.setScene(imgScene);
		int value = _sl.surfROS();

		//cv::imshow("WEBCAM", _sl.getScene());	//imgScene);
		//cv::waitKey(1);		//el argumento que recibe waitKey es un delay, necesita 1 para refresco

		corners_pub_.publish(_sl.getCorners());
	}

	~SurfVision(){ /*cv::destroyWindow("WEBCAM");*/ }
};


int main(int argc, char** argv){
	ros::init(argc, argv, "surfv");

	SurfVision sv("/home/usuario/catkin_ws/src/object_localization/IMG/birk_small.jpg");	
	//SurfVision sv;
	ros::spin();

	return 0;
}
