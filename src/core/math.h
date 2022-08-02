#pragma once

#include "Inst.h"
#include <cmath>

// pi
#define Math_PI 3.1415926f
#define Math_2PI 6.2831852f
#define Math_PI2 1.5707963f

// 位移操作
#define AddBitN(a, b) a |= (1 << (b - 1))
#define DelBitN(a, b) a = ~((~a) | (1 << (b - 1)))
#define HasBitN(a, b) (a & (1 << (b - 1)) ? true : false)
#define AddBit(a, b) a |= b
#define DelBit(a, b) a = ~((~a) | b)
#define HasBit(a, b) ((a & b) ? true : false)
#define MoveBit(source, n) (n > 0 ? (source >> (sizeof(source) * 8 - n)) | (source << n) : (source << (sizeof(source) * 8 - (-n))) | (source >> (-n)))

//获取结构体成员偏移地址
#define StructElement(s, e) &(((s *)0)->e)

class Vec2;
class Mat3;
class Rect;
class Color;

namespace Easing
{
    enum Type
    {
        linear,
        outQuad,
        outCubic,
        outQuart,
        outQuint,
        inOutQuad,
        inOutCubic,
        inOutQuart,
        inOutQuint,
        inQuad,
        inCubic,
        inQuart,
        inQuint,
        inSine,
        outSine,
        inOutSine,
        inExpo,
        outExpo,
        inOutExpo,
        inCirc,
        outCirc,
        inOutCirc,
        inElastic,
        outElastic,
        Count
    };
}

class Vec2
{
public:
    Vec2();
    Vec2(float num);
    Vec2(float x, float y);
    Vec2(const Vec2& v);

    Vec2 operator-() const;
    Vec2& operator=(const Vec2& v);
    bool operator==(const Vec2& v) const;
    bool operator!=(const Vec2& v) const;
    Vec2 operator+(float v) const;
    Vec2 operator+(const Vec2& v) const;
    Vec2 operator-(float v) const;
    Vec2 operator-(const Vec2& v) const;
    Vec2 operator*(float v) const;
    Vec2 operator*(const Vec2& v) const;
    Vec2 operator/(float v) const;
    Vec2 operator/(const Vec2& v) const;

    void operator+=(const Vec2& v);
    void operator+=(float v);
    void operator-=(const Vec2& v);
    void operator-=(float v);
    void operator*=(const Vec2& v);
    void operator*=(float v);

    Vec2 operator*(const Mat3& mat) const;

    void zero();
    bool isZero() const;
    void set(float x, float y);
    float length() const;
    float llength() const;
    float dot(const Vec2& v) const;
    float dot(float x, float y) const;

    Vec2 skew() const;
    float angle() const;
    Vec2 normal() const;
    Vec2 abs() const;

public:
    float x, y;
};

class Vec3
{
public:
    Vec3();
    Vec3(float num);
    Vec3(float x, float y, float z);
    Vec3(const Vec3& v);

    Vec3 operator-() const;
    Vec3& operator=(const Vec3& v);
    bool operator==(const Vec3& v) const;
    bool operator!=(const Vec3& v) const;
    Vec3 operator+(float v) const;
    Vec3 operator+(const Vec3& v) const;
    Vec3 operator-(float v) const;
    Vec3 operator-(const Vec3& v) const;
    Vec3 operator*(float v) const;
    Vec3 operator*(const Vec3& v) const;
    Vec3 operator/(float v) const;
    Vec3 operator/(const Vec3& v) const;

    void operator+=(const Vec3& v);
    void operator+=(float v);
    void operator-=(const Vec3& v);
    void operator-=(float v);
    void operator*=(const Vec3& v);
    void operator*=(float v);

    Vec3 operator*(const Mat3& mat) const;

    void zero();
    bool isZero() const;
    void set(float x, float y, float z);
    float length() const;
    float llength() const;
    float dot(const Vec3& v) const;
    float dot(float x, float y, float z) const;

    Vec3 normal() const;
    Vec3 abs() const;

public:
    float x, y, z;
};

class Mat3
{
public:
    Mat3();
    void operator=(const Mat3& v);
    bool operator==(const Mat3& v);
    bool operator!=(const Mat3& v);
    float* operator[](int idx);

    Mat3 operator+(const Mat3& v) const;
    Mat3 operator-(const Mat3& v) const;
    Mat3 operator*(const Mat3& v) const;
    Mat3 operator*(float v) const;
    Mat3 operator/(float v) const;

    void zero();
    void identity();

    void transpose();
    Mat3 reversal() const;
    Mat3 abs() const;

public:
    float v[3][3];
};

class Rect
{
public:
    Rect();
    Rect(const Vec2& s);
    Rect(const Rect& v);
    Rect(const Vec2& min, const Vec2& max);

    Rect& operator=(const Rect& v);
    bool operator==(const Rect& v);
    bool operator!=(const Rect& v);

    Vec2 size() const;
    Vec2 core() const;

    Rect& move(const Vec2& pos);
    Rect& scale(const Vec2& size);

public:
    Vec2 minPos;
    Vec2 maxPos;
};

class Color
{
public:
    Color();
    Color(float ar, float ag, float ab, float aa = 1.0f);
    Color(unsigned int num);
    Color(int num);

    void set(float r, float g, float b, float a = 1.0f);
    void set(unsigned int num);
    void set(unsigned int num, unsigned int a);
    void set(unsigned int r, unsigned int g, unsigned int b, unsigned int a);

    Color& operator=(unsigned int v);
    Color& operator=(const Color& v);
    bool operator!=(const Color& val);
    bool operator==(const Color& val);

    Color operator+(const Color& v) const;
    Color operator-(const Color& v) const;
    Color operator*(const Color& v) const;
    Color operator/(const Color& v) const;
    Color operator+(float v) const;
    Color operator-(float v) const;
    Color operator*(float v) const;
    Color operator/(float v) const;

    int hex() const;

public:
    float r, g, b, a;
};


class _Math
{
private:
    InstClass(_Math) { init(); }
    void init();

public:
    // 矩阵计算
    Mat3 ortho(const Vec2& size);
    Mat3 ortho(const Rect& area);
    Mat3 translate(const Vec2& offset);
    Mat3 translate(const Mat3& mat, const Vec2& offset);
    Mat3 rotate(float angle);
    Mat3 rotate(const Mat3& mat, float angle);
    Mat3 rotateX(float angle);
    Mat3 rotateX(const Mat3& mat, float angle);
    Mat3 rotateY(float angle);
    Mat3 rotateY(const Mat3& mat, float angle);
    Mat3 scale(const Vec2& v);
    Mat3 scale(const Mat3& mat, const Vec2& offset);
    Mat3 transform(const Vec2& pos, const Vec2& scale, float angle);
    Mat3 complexTrans(const Mat3& mat, const Vec2& size, const Vec2& anchor);

    // 缓动函数
    float easing(float value, const Easing::Type& type);
    float linear(float begin, float end, float v);
    Vec2 linear(const Vec2& begin, const Vec2& end, float v);

    // 贝塞尔
    Vec2 bezier(float t, const Vec2& p1, const Vec2& p2, const Vec2& p3);
    Vec2 bezier(float t, const Vec2& p1, const Vec2& p2, const Vec2& p3, const Vec2& p4);

    // 弧形
    Vec2 circle(float t, const Vec2& c, float r, float fr, float rd);

    // 随机数
    float random();
    float random(float min, float max);
    Vec2 randomVec2(const Vec2& min = Vec2(0.0f), const Vec2& max = Vec2(1.0f));
    Color randomColor(const Color& min = Color(0x000000FF), const Color& max = Color(0xFFFFFFFF));

    // 区间映射
    float map(float target, float begin, float end, float tbegin, float tend);
    Vec2 map(const Vec2& target, const Vec2& begin, const Vec2& end, const Vec2& tbegin, const Vec2& tend);

    // 获取角度的方向向量
    Vec2 dirVec(float angle);

    // 角度转弧度  弧度转角度
    float angleToRadian(float num);
    float radianToAngle(float num);

    // 角度限制 范围限制
    float range(float angle);
    float range(float min, float max, float v);

private:
    typedef float (*InchingFunc)(float);
    InchingFunc easings[Easing::Type::Count];
};
#define Math Inst(_Math)
