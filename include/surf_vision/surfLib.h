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

class SurfLib{
  private:
  	cv::Mat img_object;
  	cv::Mat img_scene;
  public:
	SurfLib(){}
  	SurfLib(std::string nameObject);
    void setObject(const cv::Mat object);
  	void setScene(const cv::Mat scene);
  	cv::Mat getScene() const;
    bool intersection(cv::Point2f , cv::Point2f, cv::Point2f, cv::Point2f, cv::Point2f &);
	  int surfROS();
	~SurfLib(){}
};

#endif
