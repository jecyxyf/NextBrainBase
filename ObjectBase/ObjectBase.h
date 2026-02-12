#pragma once
#include "../Common/GUID.h"
#include "../DummyBase/DummyBase.h"
#include "ObjectShape.h"
#include <vector>
#include <memory>

/// @brief 对象基类.面向仿真环境内的单个数模对象.
class ObjectBase : public DummyBase
{

public:
    
    /// @brief 类型
    const std::string classType = "SO0002";

    /// @brief 对象位姿
    ObjectShape shape;

    /// @brief 父对象指针
    std::shared_ptr<ObjectBase> parentObject = nullptr;
    
    /// @brief 子对象指针列表
    std::vector<std::shared_ptr<ObjectBase>> childObjects;

};