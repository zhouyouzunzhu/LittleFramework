#include "assetsAnalysis.h"


AssetsCell* AssetsAnalysis::loadFromFile(const String& file)
{
    return nullptr;
}

bool AssetsAnalysis::unloadAssetes(AssetsCell* cell)
{
    return true;
}

const std::vector<String>& AssetsAnalysis::getSupportAnalysisType()
{
    static std::vector<String> defaultTypes;
    return defaultTypes;
}
