#pragma once

#include "assets/AssetsCell.h"
#include <unordered_map>
#include <vector>

class CellCsv : public AssetsCell
{
    friend class AnalysisCsv;
    friend class WrappersCsv;

public:
    // 一行数据
    typedef std::unordered_map<String, String> LineItem;
    
private:
    // 数据头
    std::vector<String> _header;

    // 所有数据
    std::vector<LineItem> _datas;
};

