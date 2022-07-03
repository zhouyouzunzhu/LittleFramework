#include "Transform.h"


void Transform::updata()
{
    // 更新自己的矩阵
    static Vec2 tScale;
    tScale.x = this->_scale.x * (this->_flipSignX ? -1.0f : 1.0f);
    tScale.y = this->_scale.y * (this->_flipSignY ? -1.0f : 1.0f);
    this->localMat = Math->transform(this->_position, tScale, this->_angle);

    if (this->_fathor)
        this->localMat = this->localMat * this->_fathor->localMat;
    
    // 更新世界矩阵
    this->worldMat = Math->complexTrans(this->localMat, this->_size, this->_anchor);

    // 更新子节点
    for(auto& it : this->_chidren)
        it->updata();
}

Transform::Transform():
    _position(),
    _anchor(0.5f),
    _size(100.0f),
    _scale(1.0f),
    _angle(0.0f),
    _flipSignX(false),
    _flipSignY(false),
    _fathor(nullptr),
    localMat(),
    worldMat()
{
}

Transform::~Transform()
{
    for(auto& it : this->_chidren)
    {
        it->_fathor = nullptr;
        it->updata();
    }
    this->_chidren.clear();
}

Vec2 Transform::toWorld(const Vec2& v)
{
    return v * this->localMat;
}

Vec2 Transform::toLocal(const Vec2& v)
{
    return v * this->localMat.reversal();
}

void Transform::addChild(Transform* obj)
{
    if(obj == nullptr || obj->_fathor)
        return;
    
    this->_chidren.push_back(obj);
    obj->_fathor = this;
    obj->updata();
}

void Transform::removeChild(Transform* obj)
{
    if(obj == nullptr)
        return;
    
    auto it = std::find(this->_chidren.begin(), this->_chidren.end(), obj);
    if(it != this->_chidren.end())
        this->_chidren.erase(it);
    
    obj->_fathor = nullptr;
    obj->updata();
}


void Transform::move(const Vec2& pos)
{
    if (pos.x == 0.0f && pos.y == 0.0f)
        return;
    this->_position.x += pos.x;
    this->_position.y += pos.y;
    this->updata();
}

void Transform::move(float x, float y)
{
    if (x == 0.0f && y == 0.0f)
        return;
    this->_position.x += x;
    this->_position.y += y;
    this->updata();
}

void Transform::rotate(float angle)
{
    if (angle == 0.0f)
        return;
    this->_angle += angle;
    this->updata();
}

void Transform::setPosition(const Vec2& pos)
{
    if (pos == this->_position)
        return;
    this->_position.x = pos.x;
    this->_position.y = pos.y;
    this->updata();
}

void Transform::setPosition(float x, float y)
{
    if (this->_position.x == x && this->_position.y == y)
        return;
    this->_position.x = x;
    this->_position.y = y;
    this->updata();
}

const Vec2& Transform::getPosition() const
{
    return this->_position;
}

void Transform::setAnchor(const Vec2& anchor)
{
    if (anchor == this->_anchor)
        return;
    this->_anchor.x = anchor.x;
    this->_anchor.y = anchor.y;
    this->updata();
}

void Transform::setAnchor(float x, float y)
{
    if (this->_anchor.x == x && this->_anchor.y == y)
        return;
    this->_anchor.x = x;
    this->_anchor.y = y;
    this->updata();
}

const Vec2& Transform::getAnchor() const
{
    return this->_anchor;
}

void Transform::setAngle(float angle)
{
    if (this->_angle == angle)
        this->_angle = angle;
    this->updata();
}

float Transform::getAngle() const
{
    return this->_angle;
}

void Transform::setSize(const Vec2& size)
{
    if (size == this->_size)
        return;
    this->_size.x = size.x;
    this->_size.y = size.y;
    this->updata();
}

void Transform::setSize(float w, float h)
{
    if (this->_size.x == w && this->_size.y == h)
        return;
    this->_size.x = w;
    this->_size.y = h;
    this->updata();
}

const Vec2& Transform::getSize() const
{
    return this->_size;
}

void Transform::setScale(const Vec2& s)
{
    if (s == this->_scale)
        return;
    this->_scale.x = s.x;
    this->_scale.y = s.y;
    this->updata();
}

void Transform::setScale(float w, float h)
{
    if (this->_scale.x == w && this->_scale.y == h)
        return;
    this->_scale.x = w;
    this->_scale.y = h;
    this->updata();
}

const Vec2& Transform::getScale() const
{
    return this->_scale;
}

void Transform::setFlip(bool flip, bool isX)
{
    if (isX)
        this->_flipSignX = flip;
    else
        this->_flipSignY = flip;
    this->updata();
}

bool Transform::isFlip(bool isX) const
{
    return (isX ? this->_flipSignX : this->_flipSignY);
}


