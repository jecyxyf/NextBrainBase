#pragma once
#include <LogClass.h>
#include <RobotPointData.h>

struct axisMDH
{
    const double alpha;  // twist angle
    double a;      // link length
    const double theta; // joint angle
    double d;      // link offset
};

class RobotArmBaseKinematic
{
private:

    /// @brief 机械臂MDH参数
    std::vector<axisMDH> mdhParams;

    
public:

    /// @brief 设置MDH参数
    /// @param params 参数
    /// @return 
    RetStatus setMDHParams(const std::vector<axisMDH>& params);
    
    /// @brief 获取MDH参数,需要遍历没有关节节点计算出MDH参数
    /// @return 
    std::vector<axisMDH> getMDHParams() const;

    /// @brief 正解计算
    /// @param joints 输入关节值
    /// @param tool 工具坐标系
    /// @param wobj 工件坐标系
    /// @param pointData 正解计算结果
    /// @return 
    virtual RetStatus forwardKinematics(const std::vector<DeviceJoint> joints, Pose tool,Pose wobj, RobotPointData& pointData) const ;

    /// @brief 逆解计算,解析解
    /// @param pointData 目标位姿
    /// @param tool 工具坐标系
    /// @param wobj 工件坐标系
    /// @param joints 遍历出来的所有逆解结果,每个逆解结果包含所有关节的值
    /// @return 
    virtual RetStatus inverseKinematics(const RobotPointData& pointData, Pose tool, Pose wobj, std::vector<std::vector<DeviceJoint>>& joints) const;

    /// @brief 逆解计算,变化最小的一组解
    /// @param pointData 目标位姿
    /// @param tool 工具坐标系
    /// @param wobj 工件坐标系
    /// @param joints 逆解计算结果,包含变化最小的一组解
    /// @return
    virtual RetStatus inverseKinematics(const RobotPointData& pointData, Pose tool, Pose wobj, std::vector<DeviceJoint>& joints) const;

    /// @brief 关节运动
    /// @param pointData 
    /// @param tool 
    /// @param wobj 
    /// @param joints 
    /// @return 
    virtual RetStatus moveJoint(const RobotPointData& pointData, Pose tool, Pose wobj, std::vector<std::vector<DeviceJoint>>& joints) const ;

    /// @brief 直线运动
    /// @param pointData 
    /// @param tool 
    /// @param wobj 
    /// @param joints 
    /// @return 
    virtual RetStatus moveLinear(const RobotPointData& pointData, Pose tool, Pose wobj, std::vector<std::vector<DeviceJoint>>& joints) const ;



};