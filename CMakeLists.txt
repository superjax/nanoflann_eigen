cmake_minimum_required(VERSION 2.8.3)
project(nanoflann_sandbox)

set(CMAKE_CXX_STANDARD 14)

find_package(GTest REQUIRED)
find_package(Eigen3 REQUIRED)

include_directories(include
  ${GTEST_INCLUDE_DIRS}
  ${EIGEN3_INCLUDE_DIRS})
add_executable(nanoflann_sandbox_test
  src/test.cpp
)
target_link_libraries(nanoflann_sandbox_test gtest gtest_main ${GTEST_LIBRARIES} pthread)
