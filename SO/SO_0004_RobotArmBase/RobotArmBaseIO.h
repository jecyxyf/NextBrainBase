#pragma once
#include <LogClass.h>
#include <map>

/// @brief 机械臂输入输出接口类,用于存储和管理机械臂的输入输出信息,包括数字输入输出和组输入输出
class RobotArmBaseIO
{
private:
    std::map<std::string, bool> digitalInputs;
    std::map<std::string, bool> digitalOutputs;
    std::map<std::string,unsigned int> groupInputs;
    std::map<std::string,unsigned int> groupOutputs;

public:

    RetStatus addDigitalInput(const std::string& name, bool value);
    RetStatus clearDigitalInput();
    RetStatus removeDigitalInput(const std::string& name);
    RetStatus getDigitalInput(const std::string& name, bool& value) const;
    RetStatus waitDigitalInput(const std::string& name, bool value, unsigned int timeout);

    RetStatus addDigitalOutput(const std::string& name, bool value);
    RetStatus clearDigitalOutput();
    RetStatus removeDigitalOutput(const std::string& name);
    RetStatus setDigitalOutput(const std::string& name, bool value);
    RetStatus getDigitalOutput(const std::string& name, bool& value) const;

    RetStatus addGroupInput(const std::string& name, unsigned int value);
    RetStatus clearGroupInput();
    RetStatus removeGroupInput(const std::string& name);
    RetStatus getGroupInput(const std::string& name, unsigned int& value) const;
    RetStatus waitGroupInput(const std::string& name, unsigned int value, unsigned int timeout);

    RetStatus addGroupOutput(const std::string& name, unsigned int value);
    RetStatus clearGroupOutput();
    RetStatus removeGroupOutput(const std::string& name);
    RetStatus setGroupOutput(const std::string& name, unsigned int value);
    RetStatus getGroupOutput(const std::string& name, unsigned int& value) const;
};