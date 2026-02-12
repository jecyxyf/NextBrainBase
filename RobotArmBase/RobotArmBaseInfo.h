#pragma once
#include "../DeviceBase/DeviceInfo.h"

class RobotArmBaseInfo : public DeviceInfo
{
    
private:
    /// @brief 机械臂类型
    const std::string deviceType = "SO0003";
};