#include "assetsManager.h"


AssetsCell* AssetsManager::tryLoad(const String& resPath)
{
    String suffix = resPath.substr(resPath.rfind("."));

    return nullptr;
}

void AssetsManager::tryUnload(AssetsCell* cell)
{
    
}

void AssetsManager::regAnlysis(AssetsAnalysis* analysis)
{
    if(analysis == nullptr)
        return;
    
    auto list = analysis->getSupportAnalysisType();
    for(auto& it : list)
    {
        if(!it.isEmpty())
            this->_analysisDict[it] = analysis;
    }
}
