
#pragma once

#include "assetsCell.h"
#include <vector>

// 资产解析器基类
class AssetsAnalysis
{
public:
    
    // 从文件加载
    virtual AssetsCell* loadFromFile(const String& file);

    // 卸载资源
    virtual bool unloadAssetes(AssetsCell* cell);

    // 获取支持解析的文件后缀
    virtual const std::vector<String>& getSupportAnalysisType() = 0;
};
