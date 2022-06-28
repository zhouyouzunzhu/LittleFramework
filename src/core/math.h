#pragma once

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