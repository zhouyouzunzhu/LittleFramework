﻿#include "WrappersCsv.h"
#include <algorithm>

void WrappersCsv::onWrappers(AssetsCell* cell)
{
    this->_data = dynamic_cast<CellCsv*>(cell);
    this->_mainKey = u8"ID";
    this->rebuildMainKey();
}

void WrappersCsv::rebuildMainKey()
{
    this->_mainKeyDatas.clear();

    // 检查表头是否有主键
    auto it = std::find(this->_data->_header.begin(), this->_data->_header.end(), this->_mainKey);
    if(it == this->_data->_header.end())
        return;
    
    // 构建
    for(const auto& lineData : this->_data->_datas)
    {
        // 获取主键值
        String mainKeyVal = lineData.at(this->_mainKey);

        // 获取记录
        LineItems* items = nullptr;
        auto lineIt = this->_mainKeyDatas.find(mainKeyVal);
        if(lineIt != this->_mainKeyDatas.end())
            items = &(lineIt->second);
        else
        {
            auto addInfo = this->_mainKeyDatas.emplace(mainKeyVal, LineItems());
            if(addInfo.second)
                items = &(addInfo.first->second);
        }
        
        // 添加记录
        if(items != nullptr)
            items->emplace_back(&lineData);
    }
}

// 获取数据行数
size_t WrappersCsv::getCount()const
{
    return this->_data->_datas.size();
}

// 通过行数获取数据
const CellCsv::LineItem* WrappersCsv::getData(int index)
{
    if(index >= this->_data->_datas.size())
        return nullptr;
    return &(this->_data->_datas.at(index));
}

// 通过主键获取数据组的第一个数据
const CellCsv::LineItem* WrappersCsv::getData(const String& key)
{
    auto it = this->_mainKeyDatas.find(key);
    if(it == this->_mainKeyDatas.end())
        return nullptr;
    
    if(it->second.empty())
        return nullptr;
    
    return it->second.front();
}

const WrappersCsv::LineItems* WrappersCsv::getDatas(const String& key)
{
    auto it = this->_mainKeyDatas.find(key);
    if(it == this->_mainKeyDatas.end())
        return nullptr;
    
    return &it->second;
}

const std::vector<String>& WrappersCsv::getHeader()const
{
    return this->_data->_header;
}

// 设置主键
void WrappersCsv::setMainKey(const String& key)
{
    this->_mainKey = key;
    this->rebuildMainKey();
}
