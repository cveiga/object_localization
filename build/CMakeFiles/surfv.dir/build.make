# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/carlos/catkin_ws/src/surf_vision

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/carlos/catkin_ws/src/surf_vision/build

# Include any dependencies generated for this target.
include CMakeFiles/surfv.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/surfv.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/surfv.dir/flags.make

CMakeFiles/surfv.dir/src/surfv.cpp.o: CMakeFiles/surfv.dir/flags.make
CMakeFiles/surfv.dir/src/surfv.cpp.o: ../src/surfv.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/carlos/catkin_ws/src/surf_vision/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/surfv.dir/src/surfv.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/surfv.dir/src/surfv.cpp.o -c /home/carlos/catkin_ws/src/surf_vision/src/surfv.cpp

CMakeFiles/surfv.dir/src/surfv.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/surfv.dir/src/surfv.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/carlos/catkin_ws/src/surf_vision/src/surfv.cpp > CMakeFiles/surfv.dir/src/surfv.cpp.i

CMakeFiles/surfv.dir/src/surfv.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/surfv.dir/src/surfv.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/carlos/catkin_ws/src/surf_vision/src/surfv.cpp -o CMakeFiles/surfv.dir/src/surfv.cpp.s

CMakeFiles/surfv.dir/src/surfv.cpp.o.requires:
.PHONY : CMakeFiles/surfv.dir/src/surfv.cpp.o.requires

CMakeFiles/surfv.dir/src/surfv.cpp.o.provides: CMakeFiles/surfv.dir/src/surfv.cpp.o.requires
	$(MAKE) -f CMakeFiles/surfv.dir/build.make CMakeFiles/surfv.dir/src/surfv.cpp.o.provides.build
.PHONY : CMakeFiles/surfv.dir/src/surfv.cpp.o.provides

CMakeFiles/surfv.dir/src/surfv.cpp.o.provides.build: CMakeFiles/surfv.dir/src/surfv.cpp.o

# Object files for target surfv
surfv_OBJECTS = \
"CMakeFiles/surfv.dir/src/surfv.cpp.o"

# External object files for target surfv
surfv_EXTERNAL_OBJECTS =

devel/lib/surf_vision/surfv: CMakeFiles/surfv.dir/src/surfv.cpp.o
devel/lib/surf_vision/surfv: CMakeFiles/surfv.dir/build.make
devel/lib/surf_vision/surfv: /opt/ros/indigo/lib/libcv_bridge.so
devel/lib/surf_vision/surfv: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.2.4.8
devel/lib/surf_vision/surfv: /usr/lib/x86_64-linux-gnu/libopencv_video.so.2.4.8
devel/lib/surf_vision/surfv: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.2.4.8
devel/lib/surf_vision/surfv: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.2.4.8
devel/lib/surf_vision/surfv: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.2.4.8
devel/lib/surf_vision/surfv: /usr/lib/x86_64-linux-gnu/libopencv_ocl.so.2.4.8
devel/lib/surf_vision/surfv: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.2.4.8
devel/lib/surf_vision/surfv: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.2.4.8
devel/lib/surf_vision/surfv: /usr/lib/x86_64-linux-gnu/libopencv_legacy.so.2.4.8
devel/lib/surf_vision/surfv: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.2.4.8
devel/lib/surf_vision/surfv: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.2.4.8
devel/lib/surf_vision/surfv: /usr/lib/x86_64-linux-gnu/libopencv_gpu.so.2.4.8
devel/lib/surf_vision/surfv: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.2.4.8
devel/lib/surf_vision/surfv: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.2.4.8
devel/lib/surf_vision/surfv: /usr/lib/x86_64-linux-gnu/libopencv_core.so.2.4.8
devel/lib/surf_vision/surfv: /usr/lib/x86_64-linux-gnu/libopencv_contrib.so.2.4.8
devel/lib/surf_vision/surfv: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.2.4.8
devel/lib/surf_vision/surfv: /opt/ros/indigo/lib/libimage_transport.so
devel/lib/surf_vision/surfv: /opt/ros/indigo/lib/libmessage_filters.so
devel/lib/surf_vision/surfv: /usr/lib/x86_64-linux-gnu/libtinyxml.so
devel/lib/surf_vision/surfv: /opt/ros/indigo/lib/libclass_loader.so
devel/lib/surf_vision/surfv: /usr/lib/libPocoFoundation.so
devel/lib/surf_vision/surfv: /usr/lib/x86_64-linux-gnu/libdl.so
devel/lib/surf_vision/surfv: /opt/ros/indigo/lib/libroslib.so
devel/lib/surf_vision/surfv: /opt/ros/indigo/lib/libroscpp.so
devel/lib/surf_vision/surfv: /usr/lib/x86_64-linux-gnu/libboost_signals.so
devel/lib/surf_vision/surfv: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
devel/lib/surf_vision/surfv: /opt/ros/indigo/lib/librosconsole.so
devel/lib/surf_vision/surfv: /opt/ros/indigo/lib/librosconsole_log4cxx.so
devel/lib/surf_vision/surfv: /opt/ros/indigo/lib/librosconsole_backend_interface.so
devel/lib/surf_vision/surfv: /usr/lib/liblog4cxx.so
devel/lib/surf_vision/surfv: /usr/lib/x86_64-linux-gnu/libboost_regex.so
devel/lib/surf_vision/surfv: /opt/ros/indigo/lib/libxmlrpcpp.so
devel/lib/surf_vision/surfv: /opt/ros/indigo/lib/libroscpp_serialization.so
devel/lib/surf_vision/surfv: /opt/ros/indigo/lib/librostime.so
devel/lib/surf_vision/surfv: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
devel/lib/surf_vision/surfv: /opt/ros/indigo/lib/libcpp_common.so
devel/lib/surf_vision/surfv: /usr/lib/x86_64-linux-gnu/libboost_system.so
devel/lib/surf_vision/surfv: /usr/lib/x86_64-linux-gnu/libboost_thread.so
devel/lib/surf_vision/surfv: /usr/lib/x86_64-linux-gnu/libpthread.so
devel/lib/surf_vision/surfv: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so
devel/lib/surf_vision/surfv: CMakeFiles/surfv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable devel/lib/surf_vision/surfv"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/surfv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/surfv.dir/build: devel/lib/surf_vision/surfv
.PHONY : CMakeFiles/surfv.dir/build

CMakeFiles/surfv.dir/requires: CMakeFiles/surfv.dir/src/surfv.cpp.o.requires
.PHONY : CMakeFiles/surfv.dir/requires

CMakeFiles/surfv.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/surfv.dir/cmake_clean.cmake
.PHONY : CMakeFiles/surfv.dir/clean

CMakeFiles/surfv.dir/depend:
	cd /home/carlos/catkin_ws/src/surf_vision/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/carlos/catkin_ws/src/surf_vision /home/carlos/catkin_ws/src/surf_vision /home/carlos/catkin_ws/src/surf_vision/build /home/carlos/catkin_ws/src/surf_vision/build /home/carlos/catkin_ws/src/surf_vision/build/CMakeFiles/surfv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/surfv.dir/depend
