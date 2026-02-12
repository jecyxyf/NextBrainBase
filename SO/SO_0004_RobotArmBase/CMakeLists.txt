cmake_minimum_required(VERSION 3.10.0)
project(RobotArmBase VERSION 0.1.0 LANGUAGES C CXX)

add_library(RobotArmBase RobotArmBase.h RobotArmBase.cpp

RobotArmBaseShape.h
RobotArmBaseKinematic.h
RobotArmBaseFunc.h
RobotArmBaseProgram.h
RobotArmBaseCMD.h
RobotArmBaseIO.h
)

target_include_directories(RobotArmBase PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Common
    ${CMAKE_CURRENT_SOURCE_DIR}/../SO_0001_DummyBase
    ${CMAKE_CURRENT_SOURCE_DIR}/../SO_0002_ObjectBase
    ${CMAKE_CURRENT_SOURCE_DIR}/../SO_0003_DeviceBase
)

target_link_libraries(RobotArmBase PUBLIC DummyBase ObjectBase DeviceBase)
