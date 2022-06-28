#pragma once

#include "core/def.h"

// 资产单元基类
class AssetsCell
{
    friend class AssetsManager;
private:
    int refCount = 0;      // 一个简单的引用计数
    String type;           // 资产类型
    String resPath;        // 资产路径
};
