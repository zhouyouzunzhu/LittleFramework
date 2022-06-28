#pragma once

#include "def.h"
#include "math.h"

class WindowConfig
{
public:
    Vec2 size;                          // 窗口尺寸
    String title;                       // 标题
    bool enableSwapInterval;            // 开启垂直同步
    Color backgroundColor;              // 背景清除色

public:
    WindowConfig();
};

