#include <ros/ros.h>
#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include <image_transport/image_transport.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/nonfree/nonfree.hpp"
#include <cv_bridge/cv_bridge.h>
//#include <opencv2/legacy/legacy.hpp>	//-- Need for cvtColor


int main(int argc, char **argv){
	ros::init(argc, argv, "webCam");
	ros::NodeHandle n;
	ros::Rate loop_rate(5.0);

	image_transport::ImageTransport it(n);
	image_transport::Publisher camImage = it.advertise("sensor_msgs/Image", 1);

	cv::VideoCapture cam(0);

	cv::Mat scene;
	sensor_msgs::ImagePtr msg;
	while(n.ok()){
		cam.read(scene);

		msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", scene).toImageMsg();

		camImage.publish(msg);
		ros::spinOnce();
		loop_rate.sleep();
	
		/*if(cv::waitKey(15) == 27){	//wait for 'esc' key for 30ms. If 'esc' key is pressed, break loop
			std::cout << "esc key is pressed by user" << std::endl;
			break;
		}

		cv::imshow("WEBCAM", scene);*/
	}

	return 0;
}
