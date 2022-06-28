#pragma once
#include "def.h"
#include "appConfig.h"

class App
{
    friend class _Director;

private:
    ExitCode _exitCode;
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

    virtual void onInit() = 0;
    virtual void onFrame() = 0;
    virtual void onExit() = 0;
};
