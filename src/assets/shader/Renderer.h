#pragma once

#include "Shader.h"

class Texture;

//获取结构体成员偏移地址
#define StructElement(s, e) &(((s *)0)->e)

class Renderer : public Shader
{
private:
    unsigned int _vao = 0;
    unsigned int _vbo = 0;
    unsigned int _ebo = 0;
    unsigned int _indexCount = 0;
    unsigned int _currentTexIndex = 0;
    size_t _structSize = 0;


protected:
    void addAttribute(const char* name, unsigned int size, unsigned int type, unsigned int offset);

public:
    Renderer();
    virtual ~Renderer();

    // 激活
    virtual void active();

    // 渲染
    virtual void draw();

    // 绑定类型
    template<typename StructType>
    void bindType(){
        this->_structSize = sizeof(StructType);
    }

    // 绑定输入属性
    void bindAttribute(const char* name, Vec2* offset);
    void bindAttribute(const char* name, Mat3* offset);
    void bindAttribute(const char* name, Color* offset);
    void bindAttribute(const char* name, int* offset);
    void bindAttribute(const char* name, float* offset);


    // 更新顶点数据
    void updateData(unsigned int count, const void* ptr, unsigned int type = GL_STATIC_DRAW);

    // 更新索引数据
    void updateIndex(unsigned int count, const void* ptr, unsigned int type = GL_STATIC_DRAW);

    // 激活纹理set
    void useTexture(const char* name, const Texture* v);
};


