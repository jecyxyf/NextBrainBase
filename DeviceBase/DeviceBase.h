#pragma once

#include "../DummyBase/DummyBase.h"
#include "DeviceShape.h"
#include "DeviceJoint.h"

/// @brief 通用性设备描述基类
class DeviceBase : public DummyBase
{

public:

    /// @brief 类型
    const std::string classType = "SO0003";

    /// @brief 设备数模信息
    DeviceShape shape;

    /// @brief 设备关节列表
    std::vector<DeviceJoint> joints;

    /// @brief 设备基础对象列表
    std::shared_ptr<ObjectBase> baseObjects = nullptr;

    /// @brief 是否为虚拟设备
    bool isVirtualDevice = true;

    /// @brief 品牌
    std::string brand;

    /// @brief 型号
    std::string model;
};