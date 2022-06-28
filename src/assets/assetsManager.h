#pragma once

#include "assetsAnalysis.h"
#include <unordered_map>


// 资产管理器
class AssetsManager
{
private:
    std::unordered_map<String, AssetsAnalysis*> _analysisDict;  // 解析器表
    std::unordered_map<String, AssetsCell*> _assetsCellDict;    // 资产表

private:
    AssetsCell* tryLoad(const String& resPath);
    void tryUnload(AssetsCell* cell);

public:
    // 注册资产解析器
    void regAnlysis(AssetsAnalysis* analysis);

    // 加载资产
    template<typename AssetsType>
    AssetsType* load(const String& resPath){
        AssetsCell* cell = nullptr;
        auto it = this->_assetsCellDict.find(resPath);
        if(it != this->_assetsCellDict.end())
            cell = dynamic_cast<AssetsType*>(it->second);
        else
        {
            cell = this->tryLoad(resPath);
            this->_assetsCellDict[resPath] = cell;
        }
        if(cell != nullptr)
            ++cell->refCount;
        
        return dynamic_cast<AssetsType*>(cell);
    }

    // 卸载资产
    template<typename AssetsType>
    void unload(AssetsType* obj){
        if(obj == nullptr)
            return;
        
        const String& resPath = obj->resPath;
        auto it = this->_assetsCellDict.find(resPath);
        if(it != this->_assetsCellDict.end())
        {
            --(it->second->refCount);
            if(it->second->refCount == 0)
            {
                this->tryUnload(it->second);
                this->_assetsCellDict.erase(it);
            }
        }
    }
};
