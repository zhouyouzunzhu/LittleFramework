#include "WindowFramework.h"

// 按键状态
static char InputKeys[KeysCount] = { 0 };
static bool IsNeedUpdateKeys = false;

// 按下或释放的特殊状态
static const char SpecialStatus = InputStatus::Press | InputStatus::Release;


static void CallbackError(int errorCode, const char* errorStr)
{
    pErr(errorStr);
    if(Framework->callbackError)
        Framework->callbackError(errorCode, errorStr);
}


static void CallbackMouseButton(GLFWwindow* window, int button, int action, int mods)
{
    if (button >= 0 && button <= KeysCount)
    {
        if (action == GLFW_PRESS)
        {
            AddBit(InputKeys[button], InputStatus::Press);
            AddBit(InputKeys[button], InputStatus::Keep);
            DelBit(InputKeys[button], InputStatus::Release);
            IsNeedUpdateKeys = true;
        }
        else if (action == GLFW_RELEASE)
        {
            DelBit(InputKeys[button], InputStatus::Press);
            DelBit(InputKeys[button], InputStatus::Keep);
            AddBit(InputKeys[button], InputStatus::Release);
            IsNeedUpdateKeys = true;
        }
    }
}

static void CallbackScroll(GLFWwindow* window, double xoffset, double yoffset)
{
    static float* roll = &(Framework->roll);
    *roll = (float)yoffset;
}

static void CallbackKey(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key >= 0 && key <= KeysCount)
    {
        if (action == GLFW_PRESS)
        {
            AddBit(InputKeys[key], InputStatus::Press);
            AddBit(InputKeys[key], InputStatus::Keep);
            DelBit(InputKeys[key], InputStatus::Release);
            IsNeedUpdateKeys = true;
        }
        else if (action == GLFW_RELEASE)
        {
            DelBit(InputKeys[key], InputStatus::Press);
            DelBit(InputKeys[key], InputStatus::Keep);
            AddBit(InputKeys[key], InputStatus::Release);
            IsNeedUpdateKeys = true;
        }
    }
}

static void CallbackChar(GLFWwindow* window, unsigned int c)
{
}

void CallbackCursorPos(GLFWwindow* window, double xoffset, double yoffset)
{
    static Vec2* currenPos = &(Framework->cursorPos);
    static Vec2* lastPos = &(Framework->lastCursorPos);
    static Vec2* deltaPos = &(Framework->deltaCursorPos);
    static _WindowFramework* framework = Framework;

    lastPos->x = currenPos->x;
    lastPos->y = currenPos->y;

    currenPos->x = (float)xoffset;
    currenPos->y = framework->config->size.y - (float)yoffset;

    deltaPos->x = currenPos->x - lastPos->x;
    deltaPos->y = currenPos->y - lastPos->y;
}

void CallbackWindowSize(GLFWwindow* window, int w, int h)
{
    glViewport(0, 0, w, h);
}


void UpdateKeysStatus()
{
    static Vec2* deltaCursorPos = &(Framework->deltaCursorPos);
    static float* roll = &(Framework->roll);

    *roll = 0.0f;
    deltaCursorPos->x = 0.0f;
    deltaCursorPos->y = 0.0f;


    if(IsNeedUpdateKeys)
    {
        IsNeedUpdateKeys = false;

        static int i = 0;
        for (i = 0; i < KeysCount; ++i)
        {
            if (HasBit(InputKeys[i], InputStatus::Keep))
                DelBit(InputKeys[i], SpecialStatus);
            else
                InputKeys[i] = InputStatus::NoAction;
        }
    }
}


bool _WindowFramework::initGL()
{
    // Setup window
    glfwSetErrorCallback(CallbackError);
    if (!glfwInit())
    {
        pErr(u8"glfw初始化失败");
        return false;
    }

#if defined(__APPLE__)
    // GL 3.2 + GLSL 150
    const char* glsl_version = "#version 150";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
#else
    // GL 3.0 + GLSL 130
    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
#endif

    int width = (int)(this->_config->size.x);
    int hight = (int)(this->_config->size.y);
    GLFWwindow* window = glfwCreateWindow(width, hight, this->_config->title.data(), NULL, NULL);
    if (window == NULL)
    {
        pErr(u8"glfw初始化失败");
        return false;
    }
    glfwMakeContextCurrent(window);

    // 垂直同步
    glfwSwapInterval(this->_config->enableSwapInterval ? 1 : 0);

    // glad
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        pErr(u8"glad加载失败");
        glfwDestroyWindow(window);
        return false;
    }

    // 混合测试
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // 清空色
    const Color& col = this->_config->backgroundColor;
    glClearColor(col.r, col.g, col.b, col.a);

    this->_window = window;
    return true;
}

void _WindowFramework::installCallback(bool isEnable)
{
    if(this->_window == nullptr)
        return;
        
    if(isEnable)
    {
        glfwSetMouseButtonCallback(this->_window, CallbackMouseButton);
        glfwSetScrollCallback(this->_window, CallbackScroll);
        glfwSetKeyCallback(this->_window, CallbackKey);
        glfwSetCharCallback(this->_window, CallbackChar);
        glfwSetFramebufferSizeCallback(this->_window, CallbackWindowSize);
        glfwSetCursorPosCallback(this->_window, CallbackCursorPos);
    }else
    {
        glfwSetMouseButtonCallback(this->_window, nullptr);
        glfwSetScrollCallback(this->_window, nullptr);
        glfwSetKeyCallback(this->_window, nullptr);
        glfwSetCharCallback(this->_window, nullptr);
        glfwSetFramebufferSizeCallback(this->_window, nullptr);
    }
}

void _WindowFramework::changeConfig(WindowConfig* config)
{
    if(config == nullptr || config == this->_config)
        return;
    
    this->quit();
    this->_config = config;
    this->config = this->_config;
    this->init();
}

void _WindowFramework::init()
{
    if(this->_isInited)
        return;

    if(this->initGL())
    {
        this->installCallback(true);
        glfwShowWindow(this->_window);
        this->_isInited = true;
    }
}

void _WindowFramework::newFrame()
{
    // dt
    static double lastTime = 0;
    this->totalTime = glfwGetTime();
    dt = this->totalTime - lastTime;
    lastTime = this->totalTime;

    // input
    UpdateKeysStatus();

    // gl
    glfwSwapBuffers(this->_window);
    glfwPollEvents();
    glClear(GL_COLOR_BUFFER_BIT);
}

void _WindowFramework::quit()
{
    if(!this->_isInited)
        return;
    
    this->installCallback(false);
    glfwDestroyWindow(this->_window);
    glfwTerminate();

    this->_window = nullptr;
    this->_isInited = false;
}

bool _WindowFramework::isInited()
{
    return this->_isInited;
}

bool _WindowFramework::isShouldClose()
{
    return glfwWindowShouldClose(this->_window);
}

bool _WindowFramework::isKeyPress(Keys key)
{
    return HasBit(InputKeys[key], InputStatus::Press);
}

bool _WindowFramework::isKeyRelease(Keys key)
{
    return HasBit(InputKeys[key], InputStatus::Release);
}

bool _WindowFramework::isKeyKeep(Keys key)
{
    return HasBit(InputKeys[key], InputStatus::Keep);
}

bool _WindowFramework::KeyStatus(Keys key, InputStatus status)
{
    return HasBit(InputKeys[key], status);
}

