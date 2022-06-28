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

    void putLog(const String& info);

    template<typename AppType>
    AppType* getApp(){
        if(this->_instanceApp != nullptr)
            return dynamic_cast<AppType*>(this->_instanceApp);
        return nullptr;
    }
};
#define Director Inst(_Director)


#define pLog(info, ...)                                                                    \
	do                                                                                     \
	{                                                                                      \
		Director->putLog(String("%s:%d: {0}", __FILE__, __LINE__).arg(String((info), ##__VA_ARGS__)));      \
	} while (0)

