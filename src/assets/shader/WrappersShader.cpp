﻿#include "WrappersShader.h"

void WrappersShader::onWrappers(AssetsCell* cell)
{
    this->_data = dynamic_cast<CellShader*>(cell);
}

WrappersShader* WrappersShader::use()
{
    if(this->_data->_id > 0)
        glUseProgram(this->_data->_id);
    return this;
}

WrappersShader* WrappersShader::set(const String& name, int v1)
{
    int location = glGetUniformLocation(this->_data->_id, name.data());
    if(location == -1)
        pWarning(u8"%s uniform %s 未找到!", this->_data->getResPath().data(), name.data());
    else
        glUniform1i(location, v1);
    return this;
}

WrappersShader* WrappersShader::set(const String& name, float v1)
{
    int location = glGetUniformLocation(this->_data->_id, name.data());
    if(location == -1)
        pWarning(u8"%s uniform %s 未找到!", this->_data->getResPath().data(), name.data());
    else
        glUniform1f(location, v1);
    return this;
}

WrappersShader* WrappersShader::set(const String& name, double v1)
{
    int location = glGetUniformLocation(this->_data->_id, name.data());
    if(location == -1)
        pWarning(u8"%s uniform %s 未找到!", this->_data->getResPath().data(), name.data());
    else
        glUniform1f(location, v1);
    return this;
}

WrappersShader* WrappersShader::set(const String& name, int v1, int v2)
{
    int location = glGetUniformLocation(this->_data->_id, name.data());
    if(location == -1)
        pWarning(u8"%s uniform %s 未找到!", this->_data->getResPath().data(), name.data());
    else
        glUniform2i(location, v1, v2);
    return this;
}

WrappersShader* WrappersShader::set(const String& name, float v1, float v2)
{
    int location = glGetUniformLocation(this->_data->_id, name.data());
    if(location == -1)
        pWarning(u8"%s uniform %s 未找到!", this->_data->getResPath().data(), name.data());
    else
        glUniform2f(location, v1, v2);
    return this;
}

WrappersShader* WrappersShader::set(const String& name, double v1, double v2)
{
    int location = glGetUniformLocation(this->_data->_id, name.data());
    if(location == -1)
        pWarning(u8"%s uniform %s 未找到!", this->_data->getResPath().data(), name.data());
    else
        glUniform2f(location, v1, v2);
    return this;
}

WrappersShader* WrappersShader::set(const String& name, int v1, int v2, int v3)
{
    int location = glGetUniformLocation(this->_data->_id, name.data());
    if(location == -1)
        pWarning(u8"%s uniform %s 未找到!", this->_data->getResPath().data(), name.data());
    else
        glUniform3i(location, v1, v2, v3);
    return this;
}

WrappersShader* WrappersShader::set(const String& name, float v1, float v2, float v3)
{
    int location = glGetUniformLocation(this->_data->_id, name.data());
    if(location == -1)
        pWarning(u8"%s uniform %s 未找到!", this->_data->getResPath().data(), name.data());
    else
        glUniform3f(location, v1, v2, v3);
    return this;
}

WrappersShader* WrappersShader::set(const String& name, double v1, double v2, double v3)
{
    int location = glGetUniformLocation(this->_data->_id, name.data());
    if(location == -1)
        pWarning(u8"%s uniform %s 未找到!", this->_data->getResPath().data(), name.data());
    else
        glUniform3f(location, v1, v2, v3);
    return this;
}

WrappersShader* WrappersShader::set(const String& name, int v1, int v2, int v3, int v4)
{
    int location = glGetUniformLocation(this->_data->_id, name.data());
    if(location == -1)
        pWarning(u8"%s uniform %s 未找到!", this->_data->getResPath().data(), name.data());
    else
        glUniform4i(location, v1, v2, v3, v4);
    return this;
}

WrappersShader* WrappersShader::set(const String& name, float v1, float v2, float v3, float v4)
{
    int location = glGetUniformLocation(this->_data->_id, name.data());
    if(location == -1)
        pWarning(u8"%s uniform %s 未找到!", this->_data->getResPath().data(), name.data());
    else
        glUniform4f(location, v1, v2, v3, v4);
    return this;
}

WrappersShader* WrappersShader::set(const String& name, double v1, double v2, double v3, double v4)
{
    int location = glGetUniformLocation(this->_data->_id, name.data());
    if(location == -1)
        pWarning(u8"%s uniform %s 未找到!", this->_data->getResPath().data(), name.data());
    else
        glUniform4f(location, v1, v2, v3, v4);
    return this;
}

WrappersShader* WrappersShader::set(const String& name, const Vec2& v)
{
    return this->set(name, v.x, v.y);
}

WrappersShader* WrappersShader::set(const String& name, const Color& v)
{
    return this->set(name, v.r, v.g, v.b, v.a);
}