#pragma once
#include <vector>
#include "../Common/Pose.h"
#include "../DeviceBase/DeviceJoint.h"
#include "RobotArmBaseProgram.h"

class TcpPose
{
    std::string name;
    Pose pose;
};

class RobotArmBaseFunc
{
private:

    /// @brief 机械臂激活状态
    bool robActive = false;

    /// @brief 机械臂夹持类型,True机器人夹持工件,False机器人夹持工具
    bool robHold = false;

    /// @brief 机械臂末端位姿集合, 不包含Tool0
    std::vector<std::pair<TcpPose,DeviceBase>> robTools;

    /// @brief 机械臂工件坐标系集合,不包含Wobj0
    std::vector<std::pair<TcpPose,DeviceBase>> robWobjs;

    /// @brief 当前选中的Tool0和Wobj0
    std::pair<TcpPose,DeviceBase> currentTcp;
    std::pair<TcpPose,DeviceBase> currentWobj;

    /// @brief 机械臂外部轴关联
    /// @note 此处有3个外部轴绑定来源, RobotArmBaseShape中的toolShapes,WObjShapes,externalShape
    std::vector<std::pair<DeviceBase,int>> robExternalAxis;

    /// @brief 存储的是机器人轨迹
    std::vector<RobotArmBaseProgram> robProgram;  

public:
    
    RetStatus setRobActive(bool active);
    RetStatus getRobActive(bool& active) const;

    RetStatus setRobHold(bool hold);
    RetStatus getRobHold(bool& hold) const;

    RetStatus setRobTools(const std::vector<Pose>& tools);
    RetStatus getRobTools(std::vector<Pose>& tools) const;
    RetStatus clearRobTools();
    RetStatus addRobTool(const Pose& tool);
    RetStatus removeRobTool(int index);
    RetStatus getRobTool(int index, Pose& tool) const;

    RetStatus setRobWobjs(const std::vector<Pose>& wobjs);
    RetStatus getRobWobjs(std::vector<Pose>& wobjs) const;
    RetStatus clearRobWobjs();
    RetStatus addRobWobj(const Pose& wobj);
    RetStatus removeRobWobj(int index);
    RetStatus getRobWobj(int index, Pose& wobj) const;

    RetStatus setRobExternalAxis(const std::vector<std::pair<DeviceBase,int>>& externalAxis);
    RetStatus getRobExternalAxis(std::vector<std::pair<DeviceBase,int>>& externalAxis) const;
    RetStatus clearRobExternalAxis();
    RetStatus addRobExternalAxis(const std::pair<DeviceBase,int>& externalAxis);
    RetStatus removeRobExternalAxis(int index);
    RetStatus getRobExternalAxis(int index, std::pair<DeviceBase,int>& externalAxis) const;

    RetStatus setRobProgram(const std::vector<RobotArmBaseProgram>& program);
    RetStatus getRobProgram(std::vector<RobotArmBaseProgram>& program) const;
    RetStatus clearRobProgram();
    RetStatus addRobProgram(const RobotArmBaseProgram& program);
    RetStatus removeRobProgram(int index);
    RetStatus getRobProgram(int index, RobotArmBaseProgram& program) const;

    RetStatus executeRobProgram();
    RetStatus executeRobProgram(std::string name);

    /// @brief 机械臂轨迹后处理程序,从Main开始
    /// @note 内部调用的后处理功能块进行处理
    RetStatus postProcessProgram();

    /// @brief 机械臂轨迹前处理程序,从指定轨迹开始
    RetStatus preProcessProgram(std::string name);
};