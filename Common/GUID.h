#pragma once

class GUID
{
    public:

    /// @brief 比较两个GUID是否相等
    bool operator==(const GUID& other) const
    {

        return true ;
    }

    /// @brief 比较两个GUID是否不相等
    bool operator!=(const GUID& other) const
    {
        return !(*this == other);
    }
};