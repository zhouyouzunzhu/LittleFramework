#pragma once

#include "core/Director.h"

#include "assets/shader/WrappersShader.h"

class TestApp : public App
{
protected:
    virtual void onStart(){
        auto shader = assets->getObj<WrappersShader>(u8"res/shaders/test.shader");
        if(shader != nullptr)
            pLog("loaded!!");
    }

    virtual void onFrame(){
    }

    virtual void onExit(){
    }
};
