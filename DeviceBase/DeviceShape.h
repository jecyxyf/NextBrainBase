#pragma once
#include "../Common/TopoDS_Shape.h"
#include <array>
#include "../Common/Pose.h"
#include "../Common/LogClass.h"
#include <functional>
#include <string>

/// @brief 对象姿态类.用于存储和管理对象的位姿信息.
class DeviceShape
{

protected:

    /// @brief 是否可交互
    bool isInteractive = false;

    /// @brief 是否可见
    bool isVisible = true;

    /// @brief 本地坐标系是否可见
    bool isLocalAxisVisible = false;

    /// @brief 是否被选中
    bool isSelected = true;

    /// @brief 是否触发碰撞检测
    bool isCollisionEnabled = false;

    /// @brief 父类坐标系下数模位置
    Pose parentPose;

    /// @brief 世界坐标系下数模位置
    Pose worldPose;

public:
    DeviceShape() = default;
    ~DeviceShape() = default;

    /// @brief 设置是否可交互
    /// @param interactive
    RetStatus setIsInteractive(bool interactive) { isInteractive = interactive; }

    /// @brief 获取是否可交互
    bool getIsInteractive() const { return isInteractive; }

    /// @brief 设置是否可见
    /// @param visible
    RetStatus setIsVisible(bool visible) { isVisible = visible; }

    /// @brief 获取是否可见
    bool getIsVisible() const { return isVisible; }

    /// @brief 设置是否被选中
    /// @param selected
    RetStatus setIsSelected(bool selected) { isSelected = selected; }

    /// @brief 获取是否被选中
    bool getIsSelected() const { return isSelected; }

    /// @brief 设置是否启用碰撞检测
    /// @param collisionEnabled
    RetStatus setIsCollisionEnabled(bool collisionEnabled) ;

    /// @brief 获取是否启用碰撞检测
    bool getIsCollisionEnabled() const;

    /// @brief 设置父类坐标系下数模位置
    /// @param pose
    RetStatus setParentPose(const Pose& pose);

    /// @brief 获取父类坐标系下数模位置
    /// @return 位置
    Pose getParentPose() const;

    /// @brief 设置世界坐标系下数模位置
    /// @param pose
    RetStatus setWorldPose(const Pose& pose) ;

    /// @brief 获取世界坐标系下数模位置
    /// @return 位置
    Pose getWorldPose() const;

    /***************************** 补充一下方法 ********************************** */

    /// @brief 设置本地原点坐标系
    RetStatus setLocalOriginAxis(const Pose& pose);

    /// @brief 设置在本地坐标系下数模位置
    /// @return
    RetStatus setLocalPose(const Pose& pose);

    /// @brief 围绕某个空间位姿旋转一个角度
    /// @param pose 空间位姿,可以是世界坐标系,父类坐标系或本地坐标系下的位姿
    /// @param axis 轴 第一位为X轴,第二位为Y轴,第三位为Z轴,正向为正方向
    /// @param angle 旋转角度
    /// @return 
    RetStatus rotateAroundAxis(Pose pose, std::array<int,3> axis, double angle);

    /// @brief 围绕某个空间位姿平移一个距离
    /// @param pose 空间位姿,可以是世界坐标系,父类坐标系或本地坐标系下的位姿
    /// @param axis 轴 第一位为X轴,第二位为Y轴,第三位为Z轴,正向为正方向
    /// @param distance 移动距离
    /// @return 
    RetStatus translateAlongAxis(Pose pose, std::array<int,3> axis, double distance);
};