#pragma once

#include "assets/AssetsWrappers.h"
#include "CellShader.h"

class WrappersShader : public AssetsWrappers
{
protected:
    virtual void onWrappers(AssetsCell* cell);

private:
    CellShader* _data;

public:
    
    // 使用shader
    WrappersShader* use();


    // 设置uniform
    WrappersShader* set(const String& name, int v1);
    WrappersShader* set(const String& name, float v1);
    WrappersShader* set(const String& name, double v1);
    WrappersShader* set(const String& name, int v1, int v2);
    WrappersShader* set(const String& name, float v1, float v2);
    WrappersShader* set(const String& name, double v1, double v2);
    WrappersShader* set(const String& name, int v1, int v2, int v3);
    WrappersShader* set(const String& name, float v1, float v2, float v3);
    WrappersShader* set(const String& name, double v1, double v2, double v3);
    WrappersShader* set(const String& name, int v1, int v2, int v3, int v4);
    WrappersShader* set(const String& name, float v1, float v2, float v3, float v4);
    WrappersShader* set(const String& name, double v1, double v2, double v3, double v4);

    // 扩展
    WrappersShader* set(const String& name, const Vec2& v);
    WrappersShader* set(const String& name, const Color& v);
};
