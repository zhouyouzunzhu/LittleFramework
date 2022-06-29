#pragma once

#include "AssetsCell.h"

class AssetsManager;

// 资产包装器(通常使用包装后的资产)
class AssetsWrappers
{
    friend class AssetsManager;
private:
    AssetsCell* _cell = nullptr;
    AssetsManager* _from = nullptr;

private:
    AssetsWrappers(AssetsManager* from, AssetsCell* cell);

public:
    virtual ~AssetsWrappers();

protected:
    virtual void onWrappers(AssetsCell* cell) = 0;  // 资产包装
};
