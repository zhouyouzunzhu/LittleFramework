#pragma once

#include "assets/AssetsWrappers.h"
#include "CellShader.h"

class Shader : public AssetsWrappers
{
protected:
    virtual void onWrappers(AssetsCell* cell);

protected:
    CellShader* _data;

public:
    
    // 使用shader
    virtual void active();


    // 设置uniform
    void set(const char* name, int v1);
    void set(const char* name, float v1);
    void set(const char* name, double v1);
    void set(const char* name, int v1, int v2);
    void set(const char* name, float v1, float v2);
    void set(const char* name, double v1, double v2);
    void set(const char* name, int v1, int v2, int v3);
    void set(const char* name, float v1, float v2, float v3);
    void set(const char* name, double v1, double v2, double v3);
    void set(const char* name, int v1, int v2, int v3, int v4);
    void set(const char* name, float v1, float v2, float v3, float v4);
    void set(const char* name, double v1, double v2, double v3, double v4);

    // 扩展
    void set(const char* name, const Vec2& v);
    void set(const char* name, Mat3& v, bool trans = false);
    void set(const char* name, const Color& v);
};
