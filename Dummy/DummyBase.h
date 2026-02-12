#pragma once
#include "DummyInfo.h"
#include "DummyInterface.h"
#include "DummyParam.h"

/// @brief 不包含数模的类,一切的基类
class DummyBase 
{
public:
    
    /// @brief 对象基础信息
    DummyInfo info;

    /// @brief 对象仿真接口
    DummyInterface interface;

    /// @brief 对象参数信息
    DummyParam param;
};