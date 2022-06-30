#pragma once

#include "assets/AssetsWrappers.h"
#include "CellCsv.h"
#include <unordered_map>

class Csv : public AssetsWrappers
{
protected:
    virtual void onWrappers(AssetsCell* cell);

public:
    typedef std::vector<const CellCsv::LineItem*> LineItems;    // 多行数据

private:
    CellCsv* _data;                                             // 数据模型
    String _mainKey;                                            // 主键
    std::unordered_map<String, LineItems> _mainKeyDatas;        // 以主键构建的索引表

    void rebuildMainKey();        // 重建以主键索引的表

public:

    // 获取数据行数
    size_t getCount()const;
    
    // 通过行数获取数据
    const CellCsv::LineItem* getData(int index);

    // 通过主键获取数据组的第一个数据
    const CellCsv::LineItem* getData(const String& key);

    // 通过主键获取数据组
    const Csv::LineItems* getDatas(const String& key);

    // 获取表头
    const std::vector<String>& getHeader()const;

    // 设置主键
    void setMainKey(const String& key);

};

