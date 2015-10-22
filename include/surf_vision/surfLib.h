#ifndef __SURFLIB_H__
#define __SURFLIB_H__

#include <stdio.h>
#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/nonfree/features2d.hpp"
#include "opencv2/nonfree/nonfree.hpp"
#include <opencv2/legacy/legacy.hpp>	//-- Need for cvtColor
#include "std_msgs/Float32MultiArray.h"

class SurfLib{
  private:
  	cv::Mat img_object;
  	cv::Mat img_scene;
	std_msgs::Float32MultiArray corners;
  public:
	SurfLib(){}
  	SurfLib(std::string nameObject);
    	void setObject(const cv::Mat object);
  	void setScene(const cv::Mat scene);
  	cv::Mat getScene() const;
	std_msgs::Float32MultiArray getCorners() const;
    	bool intersection(cv::Point2f , cv::Point2f, cv::Point2f, cv::Point2f, cv::Point2f &);
	int surfROS();	//std::vector<cv::Point2f> &);
	~SurfLib(){}
};

#endif
