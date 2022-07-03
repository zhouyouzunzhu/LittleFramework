
#pragma once

#include "Def.h"

class Transform
{
private:
    Vec2 _position;
	Vec2 _anchor;
	Vec2 _size;
	Vec2 _scale;
	float _angle;

	bool _flipSignX;
	bool _flipSignY;

	Transform* _fathor;
    std::vector<Transform*> _chidren;

    void updata();
    
public:
    Mat3 localMat;
	Mat3 worldMat;

public:
    Transform();
    Transform(const Transform& obj) = default;
    Transform& operator=(const Transform& obj) = default;
    virtual ~Transform();

    // 坐标转换
    Vec2 toWorld(const Vec2& v);
    Vec2 toLocal(const Vec2& v);

    // 父子管理
    void addChild(Transform* obj);
    void removeChild(Transform* obj);

public:

    // 快捷变换
    void move(const Vec2& pos);
    void move(float x, float y);
    void rotate(float angle);

    // 变换设置
    void setPosition(const Vec2& pos);
    void setPosition(float x, float y);
    const Vec2& getPosition() const;

    void setAnchor(const Vec2& anchor);
    void setAnchor(float x, float y);
    const Vec2& getAnchor() const;

    void setAngle(float angle);
    float getAngle() const;

    void setSize(const Vec2& size);
    void setSize(float w, float h);
    const Vec2& getSize() const;
    
    void setScale(const Vec2& s);
    void setScale(float w, float h);
    const Vec2& getScale() const;

    void setFlip(bool flip, bool isX);
    bool isFlip(bool isX) const;

};