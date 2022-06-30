#pragma once

#include "assets/AssetsAnalysis.h"


class AnalysisImage : public AssetsAnalysis
{
public:
    AnalysisImage();


    virtual AssetsCell* loadFromFile(const String& file, const String& type);

    virtual void unloadAssetes(AssetsCell* cell);


private:
    // 从文件加载原始图片
    AssetsCell* loadSrcImageByFile(const String& filePath);
};

