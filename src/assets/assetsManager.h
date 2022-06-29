#pragma once

#include "AssetsAnalysis.h"
#include "AssetsWrappers.h"
#include <unordered_map>
#include <vector>

// 资产管理器
class AssetsManager
{
private:
    std::vector<AssetsAnalysis*> _analysisList;                 // 解析器列表
    std::unordered_map<String, AssetsAnalysis*> _analysisDict;  // 解析器查询表
    std::unordered_map<String, AssetsCell*> _assetsCellDict;    // 资产表

private:
    AssetsCell* tryLoad(const String& resPath);
    void tryUnload(AssetsCell* cell);



private:
    friend class App;
    // 清理资产
    void clearAssets();

    // 清理解释器
    void clearAnlysis();


public:
    virtual ~AssetsManager();

    // 注册资产解析器
    void regAnlysis(AssetsAnalysis* analysis);

    // 加载资产(原始资产)
    template<typename AssetsType = AssetsCell>
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

    // 卸载资产(原始资产)
    template<typename AssetsType = AssetsCell>
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

    // 获取包装资产(可由外部自由delete)
    template<typename AssetsType = AssetsWrappers>
    AssetsType* getObj(const String& resPath){
        AssetsCell* cell = this->load(resPath);
        if(cell == nullptr)
            return nullptr;
        AssetsType* obj = new AssetsType();
        obj->initWrappers(this, cell);
        return obj;
    }


    // 创建默认管理器
    static AssetsManager* CreateDefaultManager();
};
