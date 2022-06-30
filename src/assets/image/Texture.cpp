#include "Texture.h"

void Texture::onWrappers(AssetsCell* cell)
{
    this->_data = dynamic_cast<CellImage*>(cell);
    this->_size = Vec2(this->_data->width, this->_data->height);
    this->updateAllCellData();
}

int Texture::getTexFormat()const
{
    int out = GL_RGBA;
    if(this->_data != nullptr)
    {
        switch (this->_data->component)
        {
        case 1: out = GL_RED; break;
        case 3: out = GL_RGB; break;
        case 4: out = GL_RGBA; break;
        }
    }

    return out;
}

int Texture::getTexId()const
{
    return this->_id;
}

void Texture::updateAllCellData()
{
    GLint lastTexture = 0;
    glGetIntegerv(GL_TEXTURE_BINDING_2D, &lastTexture);
    glBindTexture(GL_TEXTURE_2D, this->_id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int format = this->getTexFormat();
    glTexImage2D(GL_TEXTURE_2D, 0, format, this->_data->width, this->_data->height, 0, format, GL_UNSIGNED_BYTE, this->_data->data);
    // glGenerateMipmap(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, lastTexture);
}

void Texture::active(int index)const
{
    glActiveTexture(GL_TEXTURE0 + index);
    glBindTexture(GL_TEXTURE_2D, this->_id);
}

const Vec2& Texture::getSize()const
{
    return this->_size;
}

Texture::Texture()
{
    glGenTextures(1, &this->_id);
}

Texture::~Texture()
{
    if(this->_id > 0)
        glDeleteTextures(1, &this->_id);
}
