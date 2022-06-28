#include "Director.h"
#include <iostream>

int _Director::run(App* app)
{
    if(this->_instanceApp != nullptr || app == nullptr)
        return 0;
    
    this->_instanceApp = app;
    this->_instanceApp->realInit();
    this->_instanceApp->realLoop();
    this->_instanceApp->realExit();
    
    int exitCode = static_cast<int>(this->_instanceApp->getExitCode());
    delete this->_instanceApp;
    this->_instanceApp = nullptr;

    return exitCode;
}
