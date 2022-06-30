#pragma once

#include "assets/AssetsWrappers.h"
#include "CellShader.h"

class Shader : public AssetsWrappers
{
protected:
    virtual void onWrappers(AssetsCell* cell);

private:
    CellShader* _data;

public:
    
    // 使用shader
    Shader* use();


    // 设置uniform
    Shader* set(const String& name, int v1);
    Shader* set(const String& name, float v1);
    Shader* set(const String& name, double v1);
    Shader* set(const String& name, int v1, int v2);
    Shader* set(const String& name, float v1, float v2);
    Shader* set(const String& name, double v1, double v2);
    Shader* set(const String& name, int v1, int v2, int v3);
    Shader* set(const String& name, float v1, float v2, float v3);
    Shader* set(const String& name, double v1, double v2, double v3);
    Shader* set(const String& name, int v1, int v2, int v3, int v4);
    Shader* set(const String& name, float v1, float v2, float v3, float v4);
    Shader* set(const String& name, double v1, double v2, double v3, double v4);

    // 扩展
    Shader* set(const String& name, const Vec2& v);
    Shader* set(const String& name, Mat3& v, bool trans = false);
    Shader* set(const String& name, const Color& v);
};
