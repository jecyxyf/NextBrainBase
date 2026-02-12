cmake_minimum_required(VERSION 3.10.0)
project(NextBrainBase VERSION 0.1.0 LANGUAGES C CXX)

add_subdirectory(Dummy)
add_subdirectory(ObjectBase)
add_subdirectory(DeviceBase)

add_executable(NextBrainBase NextBrainBase.cpp)

target_link_libraries(NextBrainBase PRIVATE 
DummyBase 
ObjectBase 
DeviceBase
)

target_include_directories(NextBrainBase PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/Dummy
    ${CMAKE_CURRENT_SOURCE_DIR}/ObjectBase
    ${CMAKE_CURRENT_SOURCE_DIR}/DeviceBase
    ${CMAKE_CURRENT_SOURCE_DIR}/Common
)