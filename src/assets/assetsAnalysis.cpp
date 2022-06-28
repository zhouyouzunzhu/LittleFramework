#include "assetsAnalysis.h"


AssetsCell* AssetsAnalysis::loadFromFile(const String& file)
{
    return nullptr;
}

void AssetsAnalysis::unloadAssetes(AssetsCell* cell)
{
}

const std::vector<String>& AssetsAnalysis::getSupportAnalysisType()
{
    static std::vector<String> defaultTypes;
    return defaultTypes;
}
