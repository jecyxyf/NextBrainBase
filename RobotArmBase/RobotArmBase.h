#pragma once

#include "RobotArmBaseInfo.h"
#include "RobotArmBaseInterface.h"
#include "../DeviceBase/DeviceJoint.h"
#include "RobotArmBaseParam.h"
#include "RobotArmBaseShape.h"
#include "RobotArmBaseKinematic.h"
#include "RobotArmBaseFunc.h"
#include "RobotArmBaseIO.h"

class RobotArmBase
{

private:

    /// @brief 机械臂基础对象信息
    RobotArmBaseInfo info;

    /// @brief 机械臂数模信息
    RobotArmBaseShape shape;

    /// @brief 机械臂参数
    RobotArmBaseParam param;

    /// @brief 机械臂交互接口
    RobotArmBaseInterface interface;

    /// @brief 机械臂关节列表
    std::vector<DeviceJoint> joints;

    /// @brief 机械臂基础对象列表
    std::shared_ptr<ObjectBase> baseObjects = nullptr;

    /// @brief 机械臂运动学信息
    RobotArmBaseKinematic kinematic;

    /// @brief 机械臂功能函数
    RobotArmBaseFunc func;

    /// @brief 机械臂输入输出接口
    RobotArmBaseIO io;

};