#include "AssetsManager.h"


AssetsCell* AssetsManager::tryLoad(const String& resPath)
{
    int index = resPath.rfind(".");
    if(index <= 0)
    {
        pWarning(u8"不支持无后缀的资产! %s", resPath.data());
        return nullptr;
    }

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
        }else
            pWarning(u8"资产解析失败! %s", resPath.data());
    }else
        pWarning(u8"没有找到合适的资产解析器! %s", resPath.data());

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
