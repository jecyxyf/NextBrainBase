#pragma once
#include "../DeviceBase/DeviceShape.h"
#include "../DeviceBase/DeviceBase.h"
#include "../ObjectBase/ObjectBase.h"
class RobotArmBaseShape : public DeviceShape
{
protected:

    /// @brief 机械臂夹具对象信息
    std::vector<DeviceBase> toolShapes;

    /// @brief 机械臂联动工装对象信息
    std::vector<DeviceBase> wobjShapes;

    /// @brief 机械臂外部对象信息,此处外部轴指的是会影响机器人Base位置的轴
    DeviceBase externalShape;

    /// @brief 机械臂拾取对象信息,此处拾取对象指的是会被机器人Base拾取的对象
    std::vector<ObjectBase> pickShapes;

    /// @brief 机械臂末端对象
    ObjectBase tool0Object;

    /// @brief 机械臂基坐标系对象
    ObjectBase base0OBject;

public:
    RetStatus getToo0Pose(Pose& pose);
    RetStatus getBase0Pose(Pose& pose);
};