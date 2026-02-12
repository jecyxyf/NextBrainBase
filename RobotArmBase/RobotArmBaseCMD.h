#pragma once
#include "../Common/LogClass.h"

class RobotArmBaseCMD
{
public:

    // 执行指令
    virtual RetStatus execute() = 0;
};

/// @brief 调用Program指令
class cmdCall : public RobotArmBaseCMD
{
public:
    RetStatus execute() override;
};

/// @brief 线性运动指令
class cmdMoveL : public RobotArmBaseCMD
{
public:
    RetStatus execute() override;
};

/// @brief 关节运动指令
class cmdMoveJ : public RobotArmBaseCMD
{
public:
    RetStatus execute() override;
};

/// @brief 等待输入指令
class cmdWaitDI : public RobotArmBaseCMD
{
public:
    RetStatus execute() override;
};

/// @brief 设置数字输出指令
class cmdSetDO : public RobotArmBaseCMD
{
public:
    RetStatus execute() override;
};

