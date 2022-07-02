#include "Shader.h"

void Shader::onWrappers(AssetsCell* cell)
{
    this->_data = dynamic_cast<CellShader*>(cell);
}

void Shader::active()
{
    if(this->_data->id > 0)
        glUseProgram(this->_data->id);
}

void Shader::set(const char* name, int v1)
{
    int location = glGetUniformLocation(this->_data->id, name);
    if(location != -1)
        glUniform1i(location, v1);
}

void Shader::set(const char* name, float v1)
{
    int location = glGetUniformLocation(this->_data->id, name);
    if(location != -1)
        glUniform1f(location, v1);
}

void Shader::set(const char* name, double v1)
{
    int location = glGetUniformLocation(this->_data->id, name);
    if(location != -1)
        glUniform1f(location, v1);
}

void Shader::set(const char* name, int v1, int v2)
{
    int location = glGetUniformLocation(this->_data->id, name);
    if(location != -1)
        glUniform2i(location, v1, v2);
}

void Shader::set(const char* name, float v1, float v2)
{
    int location = glGetUniformLocation(this->_data->id, name);
    if(location != -1)
        glUniform2f(location, v1, v2);
}

void Shader::set(const char* name, double v1, double v2)
{
    int location = glGetUniformLocation(this->_data->id, name);
    if(location != -1)
        glUniform2f(location, v1, v2);
}

void Shader::set(const char* name, int v1, int v2, int v3)
{
    int location = glGetUniformLocation(this->_data->id, name);
    if(location != -1)
        glUniform3i(location, v1, v2, v3);
}

void Shader::set(const char* name, float v1, float v2, float v3)
{
    int location = glGetUniformLocation(this->_data->id, name);
    if(location != -1)
        glUniform3f(location, v1, v2, v3);
}

void Shader::set(const char* name, double v1, double v2, double v3)
{
    int location = glGetUniformLocation(this->_data->id, name);
    if(location != -1)
        glUniform3f(location, v1, v2, v3);
}

void Shader::set(const char* name, int v1, int v2, int v3, int v4)
{
    int location = glGetUniformLocation(this->_data->id, name);
    if(location != -1)
        glUniform4i(location, v1, v2, v3, v4);
}

void Shader::set(const char* name, float v1, float v2, float v3, float v4)
{
    int location = glGetUniformLocation(this->_data->id, name);
    if(location != -1)
        glUniform4f(location, v1, v2, v3, v4);
}

void Shader::set(const char* name, double v1, double v2, double v3, double v4)
{
    int location = glGetUniformLocation(this->_data->id, name);
    if(location != -1)
        glUniform4f(location, v1, v2, v3, v4);
}

void Shader::set(const char* name, Mat3& v, bool trans)
{
    int location = glGetUniformLocation(this->_data->id, name);
    if(location != -1)
        glUniformMatrix3fv(location, 1, (trans ? GL_TRUE : GL_FALSE), &(v[0][0]));
}

void Shader::set(const char* name, const Vec2& v)
{
    this->set(name, v.x, v.y);
}

void Shader::set(const char* name, const Color& v)
{
    this->set(name, v.r, v.g, v.b, v.a);
}
