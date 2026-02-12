#pragma once

#include "../Common/GUID.h"
#include "../Common/LogClass.h"

#include <string>
#include <functional>

/// @brief 对象信息类.用于存储和管理对象的基本信息.
class ObjectInfo
{
private:
    
    /// @brief 对象名称
    std::string name;

    /// @brief 对象GUID号
    const GUID id = GUID();

    // @brief 对象类型
    const std::string type = "SO0001";



public:
    ObjectInfo() = default;
    ~ObjectInfo() = default;

    ObjectInfo(const std::string& name,
               const GUID& id,
               const std::string& type,
               bool isVirtualDevice)
        : name(name), id(id), type(type)
    {
    }

    /// @brief 设置名称
    /// @param name_ 
    RetStatus setName(const std::string& name_) { name = name_; }

    /// @brief 获取名称
    /// @return 名称
    std::string getName() const { return name; }

    /// @brief 获取GUID
    /// @return GUID
    GUID getID() const { return id; }

    /// @brief 获取类型
    /// @return 类型
    std::string getType() const { return type; }
    
};