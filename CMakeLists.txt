cmake_minimum_required(VERSION 2.8.3)
project(surf_vision)

find_package(catkin REQUIRED COMPONENTS
  cv_bridge
  image_transport
  roscpp
  sensor_msgs
  std_msgs
  opencv_candidate
)

#find_package(OpenCV REQUIRED)
catkin_package(
  INCLUDE_DIRS
	include
  CATKIN_DEPENDS 
	cv_bridge 
	image_transport 
	roscpp 
	sensor_msgs 
	std_msgs
	opencv_candidate
)

include_directories(include ${catkin_INCLUDE_DIRS})
#link_directories(src) #src/opencv2)

add_executable(surfv src/surfv.cpp src/surfLib.cpp)
target_link_libraries(surfv ${catkin_LIBRARIES} opencv_nonfree) #opencv3)

add_executable(webCam src/webCam.cpp)
target_link_libraries(webCam ${catkin_LIBRARIES})

add_executable(carga_imagen src/carga_imagen.cpp)
target_link_libraries(carga_imagen ${catkin_LIBRARIES})
