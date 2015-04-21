#include "../include/surf_vision/surfLib.h"

SurfLib::SurfLib(std::string nameObject){
  img_object = cv::imread(nameObject, CV_LOAD_IMAGE_GRAYSCALE);

  if( !img_object.data ) {
      std::cerr <<  "Could not open or find the image" << std::endl ;
  }
}



void SurfLib::setObject(const cv::Mat object){
  img_object = object;
}



void SurfLib::setScene(const cv::Mat scene){
  img_scene = scene;
}



cv::Mat SurfLib::getScene() const{
  return img_scene;
}


//-- Points for Line1 = (o1, p1), points for Line2 = (o2, p2)
bool SurfLib::intersection(cv::Point2f o1, cv::Point2f p1, cv::Point2f o2, cv::Point2f p2, cv::Point2f &r){
    cv::Point2f x = o2 - o1;
    cv::Point2f d1 = p1 - o1;
    cv::Point2f d2 = p2 - o2;

    float cross = d1.x*d2.y - d1.y*d2.x;

    if (abs(cross) < /*EPS*/1e-8)
        return false;

    double t1 = (x.x * d2.y - x.y * d2.x)/cross;
    r = o1 + d1 * t1;

    return true;
}



int SurfLib::surfROS()
{  
  //cv::initModule_nonfree();

  if(!img_scene.data) 
    	std::cerr <<  "Could not open or find the image_SCENE" << std::endl;
  if(!img_object.data) 
      std::cerr <<  "Could not open or find the image_OBJECT" << std::endl;

	cv::Mat gray_scene(img_scene.rows, img_scene.cols, img_scene.depth());
	cv::cvtColor(img_scene, gray_scene, CV_BGR2GRAY);

  cv::SurfFeatureDetector detector(800);

  //cv::SURF detector(800);

  std::vector<cv::KeyPoint> keypoints_obj, keypoints_sce;

  detector.detect(img_object, keypoints_obj);
  detector.detect(gray_scene, keypoints_sce);
  
  //-- Step 2: Calculate descriptors (feature vectors)
  cv::SurfDescriptorExtractor extractor;
  //cv::SURF extractor;

  cv::Mat descriptors_object, descriptors_scene;

  extractor.compute(img_object, keypoints_obj, descriptors_object);
  extractor.compute(gray_scene, keypoints_sce, descriptors_scene);

  //-- Step 3: Matching descriptor vectors using FLANN matcher
  cv::FlannBasedMatcher matcher;
  std::vector<cv::DMatch> matches;
  matcher.match(descriptors_object, descriptors_scene, matches);

  double max_dist = 0; double min_dist = 100;

  //-- Quick calculation of max and min distances between keypoints
  for(int i = 0; i < descriptors_object.rows; i++){
  	double dist = matches[i].distance;
  	if(dist < min_dist) min_dist = dist;
  	if(dist > max_dist) max_dist = dist;
  }

  std::vector< cv::DMatch > good_matches;

  for( int i = 0; i < descriptors_object.rows; i++){
  	if( matches[i].distance < 6*min_dist )
     		{ good_matches.push_back( matches[i]); }
  }

  //-- Localize the object
  std::vector<cv::Point2f> obj;
  std::vector<cv::Point2f> scene;

  for( int i = 0; i < good_matches.size(); i++){
    //-- Get the keypoints from the good matches
  	obj.push_back( keypoints_obj[ good_matches[i].queryIdx ].pt );
  	scene.push_back( keypoints_sce[ good_matches[i].trainIdx ].pt );
  }
		
  //-- We avoid to have less than four matches, in this way we avoid launched exception by findHomography
  if(good_matches.size() >= 4){
  	cv::Mat H = findHomography(obj, scene, CV_RANSAC);

  	//-- Get the corners from the image_1 ( the object to be "detected" )
  	std::vector<cv::Point2f> obj_corners(4);
  	obj_corners[0] = cvPoint(0,0); 
  	obj_corners[1] = cvPoint( img_object.cols, 0 );
  	obj_corners[2] = cvPoint( img_object.cols, img_object.rows ); 
  	obj_corners[3] = cvPoint( 0, img_object.rows );
  	std::vector<cv::Point2f> scene_corners(4);

  	perspectiveTransform( obj_corners, scene_corners, H);

  	//-- Draw lines between the corners (the mapped object in the scene - image_2 )
  	line(img_scene,scene_corners[0], scene_corners[1], cv::Scalar(0, 255,0),4);
  	line(img_scene,scene_corners[1], scene_corners[2], cv::Scalar(0, 255,0),4);
  	line(img_scene,scene_corners[2], scene_corners[3], cv::Scalar(0, 255,0),4);
  	line(img_scene,scene_corners[3], scene_corners[0], cv::Scalar(0, 255,0),4);
      //circle(img_scene, scene_corners[0], 5, cv::Scalar(255, 0, 0), 4);   //SUP-IZQ
      //circle(img_scene, scene_corners[3], 5, cv::Scalar(255, 0, 0), 4);   //INF-IZQ

      //-- It marks the central point if the object is vertical
      cv::Point2f centro;
      /*centro.x = (scene_corners[1].x) / 2 + (scene_corners[0].x) / 2;
      centro.y = (scene_corners[0].y) / 2 + (scene_corners[3].y) / 2;
      circle(img_scene, centro, 5, cv::Scalar(0, 0, 255), 4);*/

      /*line(img_scene, scene_corners[0], scene_corners[2], cv::Scalar(255, 0, 0), 4);
      line(img_scene, scene_corners[1], scene_corners[3], cv::Scalar(255, 0, 0), 4);*/
      if (intersection(scene_corners[0], scene_corners[2], scene_corners[1], scene_corners[3], centro))
        circle(img_scene, centro, 5, cv::Scalar(0, 0, 255), 4);
  }

  //double x = scene_corners[0] - scene_corners[1]

  //cv::KeyPoint = position();

  return 1;
}
