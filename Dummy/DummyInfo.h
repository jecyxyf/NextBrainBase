#pragma once

#include <string>
#include "../Common/GUID.h"

class DummyInfo
{
public:

    /// @brief 对象名称
    std::string name;

    /// @brief 对象GUID号
    const GUID id = GUID();

    // @brief 对象类型
    const std::string type = "SO0000";
};