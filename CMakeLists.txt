cmake_minimum_required(VERSION 3.10.0)
project(NextBrainBase VERSION 0.1.0 LANGUAGES C CXX)

add_subdirectory(SO/SO_0001_DummyBase)
add_subdirectory(SO/SO_0002_ObjectBase)
add_subdirectory(SO/SO_0003_DeviceBase)
add_subdirectory(SO/SO_0004_RobotArmBase)

add_subdirectory(SA/SA_0001_RoboticsMathBasic)

add_executable(NextBrainBase NextBrainBase.cpp)

target_link_libraries(NextBrainBase PRIVATE 
DummyBase 
ObjectBase 
DeviceBase
RobotArmBase

RoboticsMathBasic
)

target_include_directories(NextBrainBase PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/Common/
    ${CMAKE_CURRENT_SOURCE_DIR}/SO/SO_0001_DummyBase/
    ${CMAKE_CURRENT_SOURCE_DIR}/SO/SO_0002_ObjectBase/
    ${CMAKE_CURRENT_SOURCE_DIR}/SO/SO_0003_DeviceBase/
    ${CMAKE_CURRENT_SOURCE_DIR}/SO/SO_0004_RobotArmBase/
)