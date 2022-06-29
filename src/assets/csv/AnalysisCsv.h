#pragma once

#include "assets/AssetsAnalysis.h"


class AnalysisCsv : public AssetsAnalysis
{
public:
    AnalysisCsv();


    virtual AssetsCell* loadFromFile(const String& file);

    virtual void unloadAssetes(AssetsCell* cell);
};

