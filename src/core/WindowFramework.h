#pragma once

#include "WindowConfig.h"
#include <GLFW/glfw3.h>
#include <functional>

class _WindowFramework
{
    InstClass(_WindowFramework){
    }
private:
    WindowConfig* _config = nullptr;
    GLFWwindow* _window = nullptr;
    bool _isInited = false;

public:
    const WindowConfig* config = nullptr;                   // 对外配置
    std::function<void(int,const String&)> callbackError;


private:
    bool initGL();
    void installCallback(bool isEnable);

public:
    // 切换配置
    void changeConfig(WindowConfig* config);

    void init();
    void newFrame();
    void quit();

    bool isInited();
    bool isShouldClose();

    // 获取按键状态
    bool isKeyPress(Keys key);
    bool isKeyRelease(Keys key);
    bool isKeyKeep(Keys key);
    bool KeyStatus(Keys key, InputStatus status);

public:
    // 运行时间
    double totalTime = 0.0;

    // 帧时间差
    double dt = 0.0;

    // 光标坐标
    Vec2 cursorPos;

    // 上一次光标坐标
    Vec2 lastCursorPos;

    // 光标位置差
    Vec2 deltaCursorPos;

    // 鼠标滚轮
    float roll;

};
#define Framework Inst(_WindowFramework)