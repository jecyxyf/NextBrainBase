#pragma once

#include "RobotArmBaseShape.h"
#include "RobotArmBaseKinematic.h"
#include "RobotArmBaseFunc.h"
#include "RobotArmBaseIO.h"

#include "../DeviceBase/DeviceBase.h"

class RobotArmBase : public DeviceBase
{

public:

    /// @brief 机械臂类型
    const std::string classType = "SO0004";

    /// @brief 机械臂数模信息
    RobotArmBaseShape shape;

    /// @brief 机械臂运动学信息
    RobotArmBaseKinematic kinematic;

    /// @brief 机械臂功能函数
    RobotArmBaseFunc func;

    /// @brief 机械臂输入输出接口
    RobotArmBaseIO io;

};