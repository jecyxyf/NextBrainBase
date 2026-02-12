#pragma once

#include "../DummyBase/DummyBase.h"
#include "DeviceShape.h"
#include "DeviceJoint.h"

/// @brief 通用性设备描述基类
class DeviceBase : public DummyBase
{
protected:
    /// @brief 是否为虚拟设备
    bool isVirtualDevice = true;

    /// @brief 品牌
    std::string brand;

    /// @brief 型号
    std::string model;

    /// @brief 设备数模信息
    DeviceShape shape;

    /// @brief 设备关节列表
    std::vector<DeviceJoint> joints;

    /// @brief 设备基础对象列表
    std::shared_ptr<ObjectBase> baseObjects = nullptr;

public:

    /// @brief 类型
    const std::string classType = "SO0003";

    /// @brief 设置是否为虚拟设备
    /// @param isVirtualDevice_
    RetStatus setIsVirtualDevice(bool isVirtualDevice_) { isVirtualDevice = isVirtualDevice_; }

    /// @brief 获取是否为虚拟设备
    bool getIsVirtualDevice() const { return isVirtualDevice; }

    /// @brief 设置品牌
    /// @param brand_
    RetStatus setBrand(const std::string& brand_) { brand = brand_; }

    /// @brief 获取品牌
    std::string getBrand() const { return brand; }

    /// @brief 设置型号
    /// @param model_
    RetStatus setModel(const std::string& model_) { model = model_; }

    /// @brief 获取型号
    std::string getModel() const { return model; }
};