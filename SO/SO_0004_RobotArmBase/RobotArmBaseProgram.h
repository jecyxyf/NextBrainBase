#pragma once
#include <RobotArmBaseCMD.h>

/// @brief 机械臂轨迹类,用于存储和管理机械臂的轨迹信息,包括若干组指令
/// @note 可能需要继承ObjectBase类,以便于批量渲染路径坐标系
class RobotArmBaseProgram
{
private:
    /// @brief 轨迹名称
    std::string programName; 

    /// @brief 轨迹点位数据集合
    std::vector<RobotPointData> points; 

    /// @brief 指令集合
    std::vector<std::shared_ptr<RobotArmBaseCMD>> cmds; 

    /// @brief 轨迹姿态优化
    RetStatus optimizeProgramPose();
};


