cmake_minimum_required(VERSION 2.8.3)
project(nanoflann_eigen)

set(CMAKE_CXX_STANDARD 14)

find_package(Eigen3 REQUIRED)

include_directories(include
  ${EIGEN3_INCLUDE_DIRS})

add_library(nanoflann_eigen INTERFACE)


option (BUILD_TESTS "Build Tests" OFF)
if (BUILD_TESTS)
	find_package(GTest)
	include_directories(${GTEST_INCLUDE_DIRS})
	add_executable(nanoflann_eigen_test
	  src/test.cpp
	)
	target_link_libraries(nanoflann_eigen_test gtest gtest_main ${GTEST_LIBRARIES} pthread)
endif()

# install
set(LIB_DEST lib/${PROJECT_NAME})
set(INCLUDE_DEST include)

install(TARGETS ${PROJECT_NAME}
  EXPORT ${PROJECT_NAME}-targets
  ARCHIVE DESTINATION ${LIB_DEST}
  LIBRARY DESTINATION ${LIB_DEST}
)
install(DIRECTORY include/${PROJECT_NAME}
  DESTINATION ${INCLUDE_DEST}
  FILES_MATCHING 
  	PATTERN "*.h"
  	PATTERN "*.hpp"
)

# install CMake package configuration
install(EXPORT ${PROJECT_NAME}-targets DESTINATION ${LIB_DEST})
install(FILES ${PROJECT_NAME}-config.cmake DESTINATION ${LIB_DEST})
