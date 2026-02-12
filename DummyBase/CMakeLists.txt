cmake_minimum_required(VERSION 3.10.0)
project(DummyBase VERSION 0.1.0 LANGUAGES C CXX)

add_library(DummyBase 
DummyBase.h DummyBase.cpp
DummyInterface.h
DummyParam.h
)
