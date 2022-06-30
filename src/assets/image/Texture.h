#pragma once

#include "assets/AssetsWrappers.h"
#include "CellImage.h"

class Texture : public AssetsWrappers
{
protected:
    virtual void onWrappers(AssetsCell* cell);

private:
    CellImage* _data = nullptr;
    unsigned int _id = 0;       // 纹理id
    Vec2 _size;

    void updateAllCellData();   // 更新cell数据
public:
    Texture();
    virtual ~Texture();

    // 获取纹理颜色格式
    int getTexFormat()const;

    // 获取id
    int getTexId()const;

    // 激活纹理
    void active(int index = 0)const;

    // 获取尺寸
    const Vec2& getSize()const;
};
