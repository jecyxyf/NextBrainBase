cmake_minimum_required(VERSION 3.10.0)
project(RoboticsMathBasic VERSION 0.1.0 LANGUAGES C CXX)

add_library(RoboticsMathBasic 
RoboticsMathBasic.h RoboticsMathBasic.cpp
)

target_include_directories(ObjectBase PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}

)