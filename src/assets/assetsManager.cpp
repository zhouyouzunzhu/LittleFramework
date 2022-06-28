#include "assetsManager.h"


AssetsCell* AssetsManager::tryLoad(const String& resPath)
{
    int index = resPath.rfind(".");
    if(index <= 0)
        return nullptr;

    String suffix = resPath.substr(index + 1);
    auto it = this->_analysisDict.find(suffix);
    if(it != this->_analysisDict.end())
    {
        AssetsAnalysis* analysis = it->second;
        AssetsCell* cell = analysis->loadFromFile(resPath);
        if(cell != nullptr)
        {
            cell->resPath = resPath;
            cell->type = suffix;
            return cell;
        }
    }

    return nullptr;
}

void AssetsManager::tryUnload(AssetsCell* cell)
{
    if(cell == nullptr)
        return;
    auto it = this->_analysisDict.find(cell->type);
    if(it != this->_analysisDict.end())
    {
        it->second->unloadAssetes(cell);
    }
}

void AssetsManager::regAnlysis(AssetsAnalysis* analysis)
{
    if(analysis == nullptr)
        return;
    
    auto list = analysis->getSupportAnalysisType();
    for(auto& it : list)
    {
        if(!it.isEmpty())
        {
            if(this->_analysisDict.find(it) == this->_analysisDict.end())
                this->_analysisDict[it] = analysis;
            else
                pWarning(u8"重复的资源解析器 %s", it.data());
        }
    }
}
