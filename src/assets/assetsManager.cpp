#include "AssetsManager.h"

AssetsManager::~AssetsManager()
{
    this->clearAnlysis();
    this->clearAssets();
}

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
        AssetsCell* cell = analysis->loadFromFile(resPath, suffix);
        if(cell != nullptr)
        {
            cell->resPath = resPath;
            cell->type = suffix;
            return cell;
        }else
            pWarning(u8"资产解析失败! %s", resPath.data());
    }else
        pWarning(u8"没有找到合适的资产解析器! %s %s", suffix.data(), resPath.data());

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
    this->_analysisList.push_back(analysis);
}

void AssetsManager::clearAssets()
{
    // 释放所有资源
    for(auto& it : this->_assetsCellDict)
        this->tryUnload(it.second);
    this->_assetsCellDict.clear();
}

void AssetsManager::clearAnlysis()
{
    // 移除所有解析器
    for(auto& it : this->_analysisList)
        delete it;
    this->_analysisList.clear();
    this->_analysisDict.clear();
}