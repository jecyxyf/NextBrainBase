#pragma once

#include "../Common/LogClass.h"

/// @brief 对象参数类.用于存储和管理对象的参数信息.
class ObjectParam
{
public:
    /// @brief 将数据转成XML格式
    /// @return 
    std::string save();

    /// @brief 将XML格式转成数据,并进行初始化
    /// @return 
    RetStatus load(std::string xml);    
};