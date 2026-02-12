#pragma once
#include <TopoDS_Shape.h>
#include <array>
#include <Pose.h>
#include <functional>

/// @brief 对象数模逻辑类.用于存储和管理对象的几何形状和位姿信息.
class ObjectShape
{

private:

    /// @brief 对象的几何形状
    TopoDS_Shape shape ;

    /// @brief 对象形状文件路径
    std::string shapePath = "";

    /// @brief 保存形状的类型,如"STL","STEP","IGES"等
    std::string shapeType = ""; 

    /// @brief 是否可交互
    bool isInteractive = false;

    /// @brief 对象是否可见
    bool isVisible = true;

    /// @brief 本地坐标系是否可见
    bool isLocalAxisVisible = false;

    /// @brief 是否被选中
    bool isSelected = true;

    /// @brief 是否触发碰撞检测
    bool isCollisionEnabled = false;

    /// @brief 父类坐标系下数模位置
    Pose parentPose;

    /// @brief 世界坐标系下数模位置
    Pose worldPose;

    /// @brief 碰撞回调函数
    /// @param bool 是否发生碰撞
    /// @param GUID 对象的GUID号
    /// @param std::string 对象的名称
    std::function<void(bool, GUID,std::string)> onCollisionCallBack;

public:
    ObjectShape() = default;
    ~ObjectShape() = default;

    /// @brief 设置形状
    /// @param shape_
    RetStatus setShape(const TopoDS_Shape& shape_, std::string path="") 
    { 
        shape = shape_;
        if(path != "")
        {
            shapePath = path;
        }
    }

    /// @brief 获取形状
    /// @return 形状
    TopoDS_Shape getShape() const { return shape; }

    /// @brief 设置形状路径
    /// @param pathh
    RetStatus setShapePath(const std::string& path) { shapePath = path; }

    /// @brief 获取形状路径
    /// @return 形状路径
    std::string getShapePath() const { return shapePath; }

    /// @brief 设置是否可交互
    /// @param interactive
    RetStatus setIsInteractive(bool interactive) { isInteractive = interactive; }

    /// @brief 获取是否可交互
    bool getIsInteractive() const { return isInteractive; }

    /// @brief 设置是否可见
    /// @param visible
    RetStatus setIsVisible(bool visible) { isVisible = visible; }

    /// @brief 获取是否可见
    bool getIsVisible() const { return isVisible; }

    /// @brief 设置本地坐标系是否可见
    /// @param visible
    RetStatus setIsLocalAxisVisible(bool visible) { isLocalAxisVisible = visible; }

    /// @brief 获取本地坐标系是否可见
    bool getIsLocalAxisVisible() const { return isLocalAxisVisible; }

    /// @brief 设置是否被选中
    /// @param selected
    RetStatus setIsSelected(bool selected) { isSelected = selected; }

    /// @brief 获取是否被选中
    bool getIsSelected() const { return isSelected; }

    /// @brief 设置是否启用碰撞检测
    /// @param collisionEnabled
    RetStatus setIsCollisionEnabled(bool collisionEnabled) ;

    /// @brief 获取是否启用碰撞检测
    bool getIsCollisionEnabled() const;

    RetStatus setOnCollisionCallBack(std::function<void(bool, std::string)> callback);

    /// @brief 设置父类坐标系下数模位置
    /// @param pose
    RetStatus setParentPose(const Pose& pose);

    /// @brief 获取父类坐标系下数模位置
    /// @return 位置
    Pose getParentPose() const;

    /// @brief 设置世界坐标系下数模位置
    /// @param pose
    RetStatus setPose(const Pose& pose) ;

    /// @brief 获取世界坐标系下数模位置
    /// @return 位置
    Pose getPose() const;

    /***************************** 补充一下方法 ********************************** */

    /// @brief 设置本地原点坐标系
    RetStatus setLocalOriginAxis(const Pose& pose);

    /// @brief 设置在父类坐标系下数模位置
    /// @return 
    RetStatus setPoseFromParentPose(const Pose& pose);

    /// @brief 设置在世界坐标系下数模位置
    /// @return 
    RetStatus setPoseFromWorldPose(const Pose& pose);

    /// @brief 设置在本地坐标系下数模位置
    /// @return
    RetStatus setPoseFromLocalPose(const Pose& pose);

    /// @brief 围绕某个空间位姿旋转一个角度
    /// @param pose 空间位姿,可以是世界坐标系,父类坐标系或本地坐标系下的位姿
    /// @param axis 轴 第一位为X轴,第二位为Y轴,第三位为Z轴,正向为正方向
    /// @param angle 旋转角度
    /// @return 
    RetStatus rotateAroundAxis(Pose pose, std::array<int,3> axis, double angle);

    /// @brief 围绕某个空间位姿平移一个距离
    /// @param pose 空间位姿,可以是世界坐标系,父类坐标系或本地坐标系下的位姿
    /// @param axis 轴 第一位为X轴,第二位为Y轴,第三位为Z轴,正向为正方向
    /// @param distance 移动距离
    /// @return 
    RetStatus translateAlongAxis(Pose pose, std::array<int,3> axis, double distance);
};