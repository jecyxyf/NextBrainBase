#pragma once
#include "../Common/GUID.h"
#include "InterfaceClass.h"
#include "ParamClass.h"

/// @brief 不包含数模的类,一切的基类
class DummyBase 
{
public:

    /// @brief 对象名称
    std::string name;

    /// @brief 对象GUID号
    const GUID id = GUID();

    const std::string classType = "SO0001";

    /// @brief 对象交互接口
    InterfaceClass interface;

    /// @brief 对象参数信息
    ParamClass param;

};