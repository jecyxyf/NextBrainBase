#pragma once

#include "../ObjectBase/ObjectBase.h"

enum DeviceJointType
{
    Revolute,   // 旋转关节
    Linear,  // 平移关节
};

/// @brief 设备关节类.用于存储和管理设备的关节信息.
class DeviceJoint
{
private:

    /// @brief 关节轴信息,决定了围绕哪个关节轴旋转
    std::shared_ptr<ObjectBase> jointAxis;

    /// @brief 关节类型
    DeviceJointType jointType;

    /// @brief 运动轴,第一个X轴,第二个Y轴,第三个Z轴,正数为正向旋转,负数为反向旋转
    std::array<float, 3> moveAxis;

    /// @brief 是否正转
    bool moveReversed = false; // 是否反向旋转

    /// @brief 关节最大速度
    double maxSpeed = 1.0;

    /// @brief 关节加速度
    double maxAcceleration = 1.0;

    /// @brief 关节加加速度
    double maxJerk = 1.0;
    
    /// @brief 关节值
    double value = 0.0f;

    /// @brief 最大范围
    double maxRange = 360.0;

    /// @brief 最小范围
    double minRange = -360.0;

    /// @brief 质量
    double mass = 0.1;

    /// @brief 重心
    std::array<double, 3> centerOfMass = {0.0, 0.0, 0.0};

    /// @brief 转动惯量
    std::array<double, 3> inertiaTensor = {0.0, 0.0, 0.0};

public:

    DeviceJoint() = default;
    ~DeviceJoint() = default;

    /// @brief 设置关节轴信息
    /// @param axis 关节轴对象
    RetStatus setJointAxis(const std::shared_ptr<ObjectBase> axis) { jointAxis = axis; return RetStatus(); }

    /// @brief 获取关节轴信息
    /// @return 关节轴对象
    std::shared_ptr<ObjectBase> getJointAxis() const { return jointAxis; }

    /// @brief 设置关节类型
    /// @param type 关节类型
    RetStatus setJointType(DeviceJointType type) { jointType = type; }

    /// @brief 获取关节类型
    /// @return 关节类型
    DeviceJointType getJointType() const { return jointType; }

    /// @brief 设置运动轴    
    RetStatus setMoveAxis(const std::array<float, 3>& axis) { moveAxis = axis; }

    /// @brief 获取运动轴
    std::array<float, 3> getMoveAxis() const { return moveAxis; }

    /// @brief 设置是否反向运动
    RetStatus setMoveReversed(bool reversed) { moveReversed = reversed; }

    /// @brief 获取是否反向运动
    bool getMoveReversed() const { return moveReversed; }

    /// @brief 设置关节最大速度
    RetStatus setMaxSpeed(double speed) { maxSpeed = speed; }
    /// @brief 获取关节最大速度
    double getMaxSpeed() const { return maxSpeed; }

    /// @brief 设置关节加速度
    RetStatus setMaxAcceleration(double acceleration) { maxAcceleration = acceleration; }
    /// @brief 获取关节加速度
    double getMaxAcceleration() const { return maxAcceleration; }

    /// @brief 设置关节加加速度
    RetStatus setMaxJerk(double jerk) { maxJerk = jerk; }
    /// @brief 获取关节加加速度
    double getMaxJerk() const { return maxJerk; }

    /// @brief 获取关节当前值
    double getValue() const { return value; }

    /// @brief 设置关节值 关键函数
    RetStatus setValue(double val);

    /// @brief 设置关节最大范围
    RetStatus setMaxRange(double range) { maxRange = range; }

    /// @brief 获取关节最大范围
    double getMaxRange() const { return maxRange; }
    
    /// @brief 设置关节最小范围
    RetStatus setMinRange(double range) { minRange = range; }
    
    /// @brief 获取关节最小范围
    double getMinRange() const { return minRange; }

    /// @brief 设置质量
    RetStatus setMass(double m) { mass = m; }

    /// @brief 获取质量
    double getMass() const { return mass; }

    /// @brief 设置重心
    RetStatus setCenterOfMass(const std::array<double, 3>& com) { centerOfMass = com; }

    /// @brief 获取重心
    std::array<double, 3> getCenterOfMass() const { return centerOfMass; }

    /// @brief 设置转动惯量
    RetStatus setInertiaTensor(const std::array<double, 3>& it) { inertiaTensor = it; }

    /// @brief 获取转动惯量
    std::array<double, 3> getInertiaTensor() const { return inertiaTensor; }
};