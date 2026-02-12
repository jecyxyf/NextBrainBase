#pragma once

#include <vector>
#include "Pose.h"

class RobotPointData
{
public:
    /// @brief 点位名称
    std::string name;
    
    // 目标位置
    Pose target;
    // 关节角度
    std::vector<double> jointAngles;
    // 外部轴关节值
    std::vector<double> externalAxisAngles;
};