#pragma once

#include "assets/AssetsCell.h"

class CellImage : public AssetsCell
{
public:
    int    width  = 0;              // 宽度
    int    height = 0;              // 高度
    int    component = 0;           // 通道数
    unsigned char* data = nullptr;  // 元数据
};

