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
    std::function<void(int,const String&)> callbackError;
    std::function<void()> callbackOnFrame;


private:
    bool initGL();
    void installCallback(bool isEnable);

public:
    void changeConfig(WindowConfig* config);

    void init();
    void newFrame();
    void quit();

    bool isInited();
    bool isShouldClose();

    double getTime()const;
};
#define Framework Inst(_WindowFramework)