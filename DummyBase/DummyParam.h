#pragma once

#include "../Common/LogClass.h"

/// @brief 对象参数类.用于存储和管理对象的参数信息.
class DummyParam
{
public:
    /// @brief 此处为参数的根指针
    /// @note 根据自己需要,定义不同的参数结构体,并将根指针指向它.
    /// @note 后续VMDeviceManager会进行参数的序列化和反序列化
    void* param_root = nullptr;

    /// @brief 将数据转成XML格式
    /// @return 
    virtual std::string save();

    /// @brief 将XML格式转成数据,并进行初始化
    /// @return 
    virtual RetStatus load(std::string xml);    
};