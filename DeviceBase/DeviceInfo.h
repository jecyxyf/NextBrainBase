#pragma once

#include "../Common/GUID.h"
#include "../Common/LogClass.h"
#include "../DummyBase/DummyInfo.h"

#include <string>
#include <functional>


/// @brief 对象信息类.用于存储和管理对象的基本信息.
class DeviceInfo : public DummyInfo
{
private:
    
    /// @brief 是否为虚拟设备
    bool isVirtualDevice;

    /// @brief 品牌
    std::string brand;

    /// @brief 型号
    std::string model;

    /// @brief 设备类型
    const std::string classType = "SO0002";

public:
    DeviceInfo() = default;
    ~DeviceInfo() = default;


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