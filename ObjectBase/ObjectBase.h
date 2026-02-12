#pragma once
#include "../Common/GUID.h"
#include "ObjectInfo.h"
#include "ObjectInterface.h"
#include "ObjectParam.h"
#include "ObjectShape.h"
#include <vector>
#include <memory>

/// @brief 对象基类.面向仿真环境内的单个数模对象.
class ObjectBase
{
public:
    ObjectBase() = default;
    ~ObjectBase() = default;

    /// @brief  对象信息
    ObjectInfo info;

    /// @brief 对象位姿
    ObjectShape shape;

    /// @brief 对象参数
    ObjectParam param; 

    /// @brief 对象交互接口
    ObjectInterface interface;

    /// @brief 父对象指针
    std::shared_ptr<ObjectBase> parentObject = nullptr;
    
    /// @brief 子对象指针列表
    std::vector<std::shared_ptr<ObjectBase>> childObjects;

};