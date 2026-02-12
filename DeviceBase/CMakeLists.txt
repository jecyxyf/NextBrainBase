cmake_minimum_required(VERSION 3.10.0)
project(DeviceBase VERSION 0.1.0 LANGUAGES C CXX)

add_library(DeviceBase DeviceBase.h DeviceBase.cpp
DeviceShape.h
DeviceJoint.h
)

target_include_directories(ObjectBase PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../Common
)
