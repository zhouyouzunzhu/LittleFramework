#pragma once

#include "core/Director.h"

#include "assets/AssetsManager.h"
#include "assets/csv/AnalysisCsv.h"
#include "assets/csv/WrappersCsv.h"

class TestApp : public App
{
protected:
    virtual void onInit(){
        AssetsManager manager;
        manager.regAnlysis(new AnalysisCsv);

        auto csv = manager.getObj<WrappersCsv>(u8"res/temp.csv");
        if(csv)
        {
            auto it = csv->getData(u8"2");
            String name = it->at(u8"name");
            pLog(name);
        }
    }

    virtual void onFrame(){
    }

    virtual void onExit(){
    }
};
