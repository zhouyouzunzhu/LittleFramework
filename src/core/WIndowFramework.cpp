#include "WindowFramework.h"


void CallbackError(int errorCode, const char* errorStr)
{
    if(Framework->callbackError)
        Framework->callbackError(errorCode, errorStr);
}


void CallbackMouseButton(GLFWwindow* window, int button, int action, int mods)
{
}

void CallbackScroll(GLFWwindow* window, double xoffset, double yoffset)
{
}

void CallbackKey(GLFWwindow* window, int key, int scancode, int action, int mods)
{
}

void CallbackChar(GLFWwindow* window, unsigned int c)
{
}

bool _WindowFramework::initGL()
{
    // Setup window
    glfwSetErrorCallback(CallbackError);
    if (!glfwInit())
        return false;

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
        return false;
    glfwMakeContextCurrent(window);

    // 垂直同步
    glfwSwapInterval(this->_config->enableSwapInterval ? 1 : 0);

    // glad
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        glfwDestroyWindow(window);
        return false;
    }

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
    }else
    {
        glfwSetMouseButtonCallback(this->_window, nullptr);
        glfwSetScrollCallback(this->_window, nullptr);
        glfwSetKeyCallback(this->_window, nullptr);
        glfwSetCharCallback(this->_window, nullptr);
    }
}

void _WindowFramework::changeConfig(WindowConfig* config)
{
    if(config == nullptr || config == this->_config)
        return;
    
    this->quit();
    this->_config = config;
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
    glfwSwapBuffers(this->_window);
    glfwPollEvents();

    int displayW, displayH;
    glfwGetFramebufferSize(this->_window, &displayW, &displayH);
    glViewport(0, 0, displayW, displayH);

    const Color& col = this->_config->backgroundColor;
    glClearColor(col.r, col.g, col.b, col.a);
    glClear(GL_COLOR_BUFFER_BIT);

    if(this->callbackOnFrame)
        this->callbackOnFrame();
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
