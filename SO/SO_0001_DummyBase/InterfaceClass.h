#pragma once

#include "../../Common/LogClass.h"

/// @brief 对象交互器类.用于处理对象与外部环境的交互逻辑.
class InterfaceClass
{
public:
    /// @brief 应用加载时调用,例如加载配置文件
    virtual RetStatus app_load() ;

    /// @brief 应用程序卸载时调用
    virtual RetStatus app_unload();

    /// @brief 仿真开始时调用,比如初始化通讯和同步设备参数
    virtual RetStatus sim_start() ;

    /// @brief 仿真停止时调用,比如清理通讯和资源
    virtual RetStatus sim_stop();

    /// @brief 仿真更新时调用,比如同步设备状态和处理交互逻辑
    virtual RetStatus sim_update() ;

};