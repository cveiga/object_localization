#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>

//#include "../include/surf_vision/surfLib.h"
#include "surf_vision/surfLib.h"

#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/calib3d/calib3d.hpp"
//#include <opencv/cv.h>
//#include <opencv/highgui.h>
//#include <cv_bridge/CvBridge.h>
//#include <cvaux.h>
//#include <math.h>
//#include <cxcore.h>
//#include <highgui.h>


static const std::string OPENCV_WINDOW = "Image Window";

//SurfLib _sl("../img/vox_small.jpg");
SurfLib _sl;
std::string nameDistinct = "";

class SurfVision{
	ros::NodeHandle nh_;
	image_transport::ImageTransport it_;
	image_transport::Subscriber image_sub_;

	std::string nameImg;
	std::string prueba;

  public:
  	SurfVision(): it_(nh_){
  		//image_sub_ = it_.subscribe("sensor_msgs/Image", 1, &SurfVision::surfCallBack, this);
		nh_.getParam("probando", prueba);
  		image_sub_ = it_.subscribe(prueba, 1, &SurfVision::surfCallBack, this);
  	}

  	SurfVision(std::string name_img): it_(nh_), nameImg(name_img){
  		//image_sub_ = it_.subscribe("sensor_msgs/Image", 1, &SurfVision::surfCallBack, this);
		nh_.getParam("probando", prueba);
  		image_sub_ = it_.subscribe(prueba, 1, &SurfVision::surfCallBack, this);
  	}


	void surfCallBack(const sensor_msgs::ImageConstPtr& msg){

		//SurfLib sl(nameImg);

  		/*cv::Mat img_object = cv::imread(nameImg, CV_LOAD_IMAGE_GRAYSCALE);

  		if (!img_object.data){
  			std::cerr << "Could not open or find the image" << std::endl;
  		}*/

		cv_bridge::CvImagePtr cv_ptr;
		try{
			cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
		}catch(cv_bridge::Exception& e){
			ROS_ERROR("cv_bridge exception: %s", e.what());
			return;
		}

		cv::Mat imgObject = cv::imread(nameImg, CV_LOAD_IMAGE_GRAYSCALE);
		//cv_bridge::CvImagePtr cv_imgObject; //= cv_bridge::imread(nameImg, CV_LOAD_IMAGE_GRAYSCALE);
		/*cv_bridge::CvImagePtr cv_ptr2(new cv_bridge::CvImage);
		cv_ptr2->image = cv::imread(nameImg, CV_LOAD_IMAGE_COLOR);
		cv::Mat imgObject = cv_ptr2->image;*/
		cv::Mat imgScene = cv_ptr->image;

		//cv::imshow("PATRON", cv_ptr2->image);
		//cv::waitKey(1);
		//cv_imgObject = cv_bridge::toCvCopy(nameImg, sensor_msgs::image_encodings::BGR8);
		//if(cv_imgObject->image.data)
      		//std::cout <<  "Could not open or find the image_OBJECT" << std::endl;

		//cv::KeyPoint p1 = surfROS(imgScene);
		_sl.setObject(imgObject);
		_sl.setScene(imgScene);
		int value = _sl.surfROS();

		cv::imshow("WEBCAM", _sl.getScene());	//imgScene);
		cv::waitKey(1);		//el argumento que recibe waitKey es un delay, necesita mínimo un 1 para refresco
	}

	~SurfVision(){ cv::destroyWindow("WEBCAM");}
};


int main(int argc, char** argv){
	ros::init(argc, argv, "surfv");

	//cv::initModule_nonfree();
	//SurfLib sl("../img/vox_small.jpg");

	SurfVision sv("/home/carlos/catkin_ws/src/surf_vision/img/vox_small.jpg");	
	//SurfVision sv;
	ros::spin();

	return 0;
}
