#pragma once

#include "core/Def.h"

// 资产单元基类(通常不直接使用)
// 如：一张图片加载进来后，图片的数据是作为数据单元记录的，而可被渲染的纹理是被包装后的
class AssetsCell
{
    friend class AssetsManager;
private:
    int refCount = 0;      // 一个简单的引用计数
    String type;           // 资产类型
    String resPath;        // 资产路径
public:
    virtual ~AssetsCell();  // 保证有个多态表

    const String& getResPath()const;    // 获取资产路径
};
