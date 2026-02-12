cmake_minimum_required(VERSION 3.10.0)
project(ObjectBase VERSION 0.1.0 LANGUAGES C CXX)

add_library(ObjectBase 
ObjectBase.h ObjectBase.cpp
ObjectShape.h 
)

target_include_directories(ObjectBase PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../Common
)

