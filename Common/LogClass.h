#pragma once

#include <string>

enum LogType
{
    LOG_INFO,
    LOG_DEBUG,
    LOG_WARNING,
    LOG_ERROR,
    LOG_FATAL
};

class RetStatus
{
public:
    LogType type = LOG_INFO;
    long code = 0;
    std::string message = "";

    RetStatus() = default;
    RetStatus(LogType t, long c, const std::string& msg)
        : type(t), code(c), message(msg)
    {
    }   
};

class LogClass
{
public:
    LogClass() = default;
    ~LogClass() = default;

    LogClass(RetStatus status);
};