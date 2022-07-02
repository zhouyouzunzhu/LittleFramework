#include "App.h"
#include "WindowFramework.h"
#include "assets/AssetsManager.h"

void App::exit(ExitCode code)
{
    this->_exitCode = code;
    this->_isRunning = false;
    this->realExit();
}

void App::realInit()
{
    this->onInit();
    
    if(this->_appConfig == nullptr)
        this->_appConfig = new AppConfig;

    this->initFramework();
    this->_isRunning = this->_isFrameworkInited;

    // 创建默认管理器
    if(this->assets == nullptr)
        this->assets = AssetsManager::CreateDefaultManager();

    if(this->_isFrameworkInited)
        this->onStart();
}

void App::realLoop()
{
    if(!this->_isFrameworkInited)
        return;
    
    while(!Framework->isShouldClose())
    {
        Framework->newFrame();
        this->realNewFrame();
    }
}

void App::realNewFrame()
{
    this->onFrame();
}

void App::realExit()
{
    this->onExit();

    if(this->_appConfig != nullptr)
        delete this->_appConfig;

    // app的资产管理需要在框架结束前调用清理
    if(this->assets != nullptr)
    {
        this->assets->clearAssets();
        this->assets->clearAnlysis();
        this->assets = nullptr;
    }

    this->quitFramework();
}

ExitCode App::getExitCode()
{
    return this->_exitCode;
}

void App::initFramework()
{
    if(this->_isFrameworkInited)
        return;
    
    Framework->changeConfig(&this->_appConfig->window);
    this->_isFrameworkInited = Framework->isInited();
}

void App::quitFramework()
{
    if(!this->_isFrameworkInited)
        return;
    if(Framework->isInited())
        Framework->quit();
    this->_isFrameworkInited = false;
}

void App::setAppConfig(AppConfig* config)
{
    if(config != nullptr)
        this->_appConfig = config;
}

void App::onInit()
{

}

void App::onStart()
{

}

void App::onFrame()
{

}

void App::onExit()
{

}


