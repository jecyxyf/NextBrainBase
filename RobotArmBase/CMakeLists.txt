cmake_minimum_required(VERSION 3.10.0)
project(RobotArmBase VERSION 0.1.0 LANGUAGES C CXX)

add_library(RobotArmBase RobotArmBase.h RobotArmBase.cpp
RobotArmBaseInfo.h 
RobotArmBaseInterface.h
RobotArmBaseParam.h
RobotArmBaseShape.h
RobotArmBaseKinematic.h
RobotArmBaseFunc.h
RobotArmBaseProgram.h
RobotArmBaseCMD.h
RobotArmBaseIO.h
)

target_include_directories(ObjectBase PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../Common
)
