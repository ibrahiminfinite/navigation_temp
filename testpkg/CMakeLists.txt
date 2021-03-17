cmake_minimum_required(VERSION 3.0.2)
project(testpkg)
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  sampler
  graph
  kdtree
  rrt
  visualizer
)

# Geenerated executable will not be linked without this
# and will result in executable not found.
catkin_package(
   INCLUDE_DIRS include
)

# <ros/ros.h> not found error if this is not added
include_directories(
  # include
  ${catkin_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME}_node src/testpkg_node.cpp)
target_link_libraries(${PROJECT_NAME}_node
  ${catkin_LIBRARIES}
)

