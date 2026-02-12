#pragma once

#include "DeviceInfo.h"
#include "DeviceShape.h"
#include "DeviceParam.h"
#include "DeviceInterface.h"
#include "DeviceJoint.h"

/// @brief 通用性设备描述基类
class DeviceBase
{
public:
    /// @brief  设备信息
    DeviceInfo info;

    /// @brief 设备数模信息
    DeviceShape shape;

    /// @brief 设备参数
    DeviceParam param; 

    /// @brief 设备交互接口
    DeviceInterface interface;

    /// @brief 设备关节列表
    std::vector<DeviceJoint> joints;

    /// @brief 设备基础对象列表
    std::shared_ptr<ObjectBase> baseObjects = nullptr;
};