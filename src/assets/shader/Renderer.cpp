#include "Renderer.h"
#include "assets/image/Texture.h"

Renderer::Renderer()
{
    glGenVertexArrays(1, &this->_vao);
    glGenBuffers(1, &this->_vbo);
    glGenBuffers(1, &this->_ebo);
}

Renderer::~Renderer()
{
    glDeleteVertexArrays(1, &this->_vao);
    glDeleteBuffers(1, &this->_vbo);
    glDeleteBuffers(1, &this->_ebo);
}

void Renderer::addAttribute(const char* name, unsigned int size, unsigned int type, unsigned int offset)
{
    unsigned int location = glGetAttribLocation(this->_data->id, name);
    if(location != -1)
    {
        glEnableVertexAttribArray(location);
        glVertexAttribPointer(location, size, type, GL_FALSE, this->_structSize, (void*)(offset));
    }
}

void Renderer::bindAttribute(const char* name, Vec2* offset)
{
    this->addAttribute(name, 2, GL_FLOAT, (unsigned int)(size_t)offset);
}

void Renderer::bindAttribute(const char* name, Mat3* offset)
{
    this->addAttribute(name, 9, GL_FLOAT, (unsigned int)(size_t)offset);
}

void Renderer::bindAttribute(const char* name, Color* offset)
{
    this->addAttribute(name, 4, GL_FLOAT, (unsigned int)(size_t)offset);
}

void Renderer::bindAttribute(const char* name, int* offset)
{
    this->addAttribute(name, 1, GL_INT, (unsigned int)(size_t)offset);
}

void Renderer::bindAttribute(const char* name, float* offset)
{
    this->addAttribute(name, 1, GL_FLOAT, (unsigned int)(size_t)offset);
}

void Renderer::active()
{
    Shader::active();
    glBindVertexArray(this->_vao);
    glBindBuffer(GL_ARRAY_BUFFER, this->_vbo);
}

void Renderer::draw()
{
    glDrawElements(GL_TRIANGLES, this->_indexCount, GL_UNSIGNED_INT, 0);
}

void Renderer::updateData(unsigned int count, const void* ptr, unsigned int type)
{
    glBindBuffer(GL_ARRAY_BUFFER, this->_vbo);
    glBufferData(GL_ARRAY_BUFFER, count * this->_structSize, ptr, type);
}

void Renderer::updateIndex(unsigned int count, const void* ptr, unsigned int type)
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->_ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * this->_structSize, ptr, type);
    this->_indexCount = count;
}

void Renderer::useTexture(const char* name, const Texture* v)
{
    int location = glGetUniformLocation(this->_data->id, name);
    if(location != -1)
    {
        glUniform1i(location, this->_currentTexIndex);
        v->active(this->_currentTexIndex);
        ++this->_currentTexIndex;
    }
}
