#include "Csv.h"
#include <algorithm>

void Csv::onWrappers(AssetsCell* cell)
{
    this->_data = dynamic_cast<CellCsv*>(cell);
    this->_mainKey = u8"ID";
    this->rebuildMainKey();
}

void Csv::rebuildMainKey()
{
    this->_mainKeyDatas.clear();

    // 检查表头是否有主键
    auto it = std::find(this->_data->header.begin(), this->_data->header.end(), this->_mainKey);
    if(it == this->_data->header.end())
        return;
    
    // 构建
    for(const auto& lineData : this->_data->datas)
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
size_t Csv::getCount()const
{
    return this->_data->datas.size();
}

// 通过行数获取数据
const CellCsv::LineItem* Csv::getData(int index)
{
    if(index >= this->_data->datas.size())
        return nullptr;
    return &(this->_data->datas.at(index));
}

// 通过主键获取数据组的第一个数据
const CellCsv::LineItem* Csv::getData(const String& key)
{
    auto it = this->_mainKeyDatas.find(key);
    if(it == this->_mainKeyDatas.end())
        return nullptr;
    
    if(it->second.empty())
        return nullptr;
    
    return it->second.front();
}

const Csv::LineItems* Csv::getDatas(const String& key)
{
    auto it = this->_mainKeyDatas.find(key);
    if(it == this->_mainKeyDatas.end())
        return nullptr;
    
    return &it->second;
}

const std::vector<String>& Csv::getHeader()const
{
    return this->_data->header;
}

// 设置主键
void Csv::setMainKey(const String& key)
{
    this->_mainKey = key;
    this->rebuildMainKey();
}
