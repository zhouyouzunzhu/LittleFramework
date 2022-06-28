
#pragma once

#include "AssetsCell.h"
#include <vector>

// 资产解析器基类
class AssetsAnalysis
{
private:
    std::vector<String> _supportAnalysisTypes;

protected:
    AssetsAnalysis(const String& supporTypes);

public:

    // 从文件加载
    virtual AssetsCell* loadFromFile(const String& file) = 0;

    // 卸载资源
    virtual void unloadAssetes(AssetsCell* cell) = 0;

    // 获取支持解析的文件后缀
    const std::vector<String>& getSupportAnalysisType();
};
