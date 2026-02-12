#pragma once

#include "../Common/GUID.h"
#include "../Common/LogClass.h"
#include "../DummyBase/DummyInfo.h"
#include <string>
#include <functional>

/// @brief 对象信息类.用于存储和管理对象的基本信息.
class ObjectInfo : public DummyInfo
{
private:
    const std::string classType = "SO0001";
public:

};