#pragma once

#include <string>
#include "../Common/GUID.h"
#include "../Common/LogClass.h"
class DummyInfo
{
protected:

    /// @brief 对象名称
    std::string name;

    /// @brief 对象GUID号
    const GUID id = GUID();

    // @brief 对象类型
    const std::string classType = "SO0000";

public:
    DummyInfo() = default;
    ~DummyInfo() = default;

    DummyInfo(const std::string& name_)
        : name(name_)
    {
    }

    /// @brief 设置名称
    /// @param name_ 
    RetStatus setName(const std::string& name_) 
    { 
        name = name_; 
        return RetStatus( 0, "");
    }

    /// @brief 获取名称
    /// @return 名称
    std::string getName() const { return name; }

    /// @brief 获取GUID
    /// @return GUID
    GUID getID() const { return id; }

    /// @brief 获取类型
    /// @return 类型
    std::string getType() const { return classType; }
};