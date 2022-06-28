#pragma once

#include "app.h"

class _Director
{
    InstClass(_Director){
        this->_instanceApp = nullptr;
    }

private:
    App* _instanceApp;

public:
    int run(App* app);

    template<typename AppType>
    AppType* getApp(){
        if(this->_instanceApp != nullptr)
            return dynamic_cast<AppType*>(this->_instanceApp);
        return nullptr;
    }
};
#define Director Inst(_Director)

