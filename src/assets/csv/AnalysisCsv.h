#pragma once

#include "assets/AssetsAnalysis.h"


class AnalysisCsv : public AssetsAnalysis
{
public:
    AnalysisCsv();


    virtual AssetsCell* loadFromFile(const String& file, const String& type);

    virtual void unloadAssetes(AssetsCell* cell);


private:
    // 加载原始文本形式csv
    AssetsCell* loadSrcCsv(const String& filePath);
};

