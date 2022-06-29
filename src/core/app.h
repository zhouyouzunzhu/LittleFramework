#pragma once
#include "AppConfig.h"
#include "assets/AssetsManager.h"

class App
{
    friend class _Director;

private:
    ExitCode _exitCode = ExitCode::Normal;
    AppConfig* _appConfig = nullptr;
    bool _isFrameworkInited = false;
    bool _isRunning = false;

public:
    void exit(ExitCode code = ExitCode::Normal);

private:
    void realInit();
    void realLoop();
    void realNewFrame();
    void realExit();

    ExitCode getExitCode();

    void initFramework();
    void quitFramework();

protected:
    void setAppConfig(AppConfig* config);

    template<typename ConfigType = AppConfig>
    ConfigType* getAppConfig(){
        if(this->_appConfig == nullptr)
            return nullptr;
        return dynamic_cast<ConfigType*>(this->_appConfig);
    }

    virtual void onInit();              // 初始化，用于读取各项配置，此时框架还未初始化
    virtual void onStart() = 0;         // 可以开始部署游戏逻辑，框架已完成初始化
    virtual void onFrame();             // 开始后每帧执行
    virtual void onExit();              // 结束退出，清理资源

protected:
    AssetsManager* assets = nullptr;    // 内置一个全局资产管理器
};
