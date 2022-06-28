#include "math.h"
#include <cmath>
#include <cfloat>
#include <cstdlib>
#include <string.h>

Vec2::Vec2() : x(0.0f), y(0.0f) {}
Vec2::Vec2(float num) : x(num), y(num) {}
Vec2::Vec2(float x, float y) : x(x), y(y) {}
Vec2::Vec2(const Vec2 &v) : x(v.x), y(v.y) {}
Vec2 Vec2::operator-() const
{
    Vec2 v(-x, -y);
    return v;
}

Vec2 &Vec2::operator=(const Vec2 &v)
{
    x = v.x;
    y = v.y;
    return *this;
}

bool Vec2::operator==(const Vec2 &v) const { return ((this->x == v.x) && (this->y == v.y)); }
bool Vec2::operator!=(const Vec2 &v) const { return ((this->x != v.x) || (this->y != v.y)); }
Vec2 Vec2::operator+(float v) const { return Vec2(x + v, y + v); }
Vec2 Vec2::operator+(const Vec2 &v) const { return Vec2(x + v.x, y + v.y); }
Vec2 Vec2::operator-(float v) const { return Vec2(x - v, y - v); }
Vec2 Vec2::operator-(const Vec2 &v) const { return Vec2(x - v.x, y - v.y); }
Vec2 Vec2::operator*(float v) const { return Vec2(x * v, y * v); }
Vec2 Vec2::operator*(const Vec2 &v) const { return Vec2(x * v.x, y * v.y); }
Vec2 Vec2::operator/(float v) const { return Vec2(x / v, y / v); }
Vec2 Vec2::operator/(const Vec2 &v) const { return Vec2(x / v.x, y / v.y); }
void Vec2::operator+=(const Vec2 &v)
{
    x += v.x;
    y += v.y;
}
void Vec2::operator+=(float v)
{
    x += v;
    y += v;
}
void Vec2::operator-=(const Vec2 &v)
{
    x -= v.x;
    y -= v.y;
}
void Vec2::operator-=(float v)
{
    x -= v;
    y -= v;
}
void Vec2::operator*=(const Vec2 &v)
{
    x *= v.x;
    y *= v.y;
}
void Vec2::operator*=(float v)
{
    x *= v;
    y *= v;
}
Vec2 Vec2::operator*(const Mat3 &mat) const
{
    Vec2 temp;
    temp.x = this->x * mat.v[0][0] + this->y * mat.v[1][0] + mat.v[2][0];
    temp.y = this->x * mat.v[0][1] + this->y * mat.v[1][1] + mat.v[2][1];
    return temp;
}
void Vec2::zero()
{
    this->x = 0.0f;
    this->y = 0.0f;
}
bool Vec2::isZero() const { return this->x == 0.0f && this->y == 0.0f; }
void Vec2::set(float x, float y)
{
    this->x = x;
    this->y = y;
}
float Vec2::length() const { return std::sqrt(x * x + y * y); }
float Vec2::llength() const { return x * x + y * y; }
float Vec2::dot(const Vec2 &v) const { return x * v.x + y * v.y; }
float Vec2::dot(float x, float y) const { return x * x + y * y; }
Vec2 Vec2::skew() const { return Vec2(-y, x); }
float Vec2::angle() const
{
    if (x < 0.0f && y > 0.0f)
        return 180.0f + (float)(180.0f * std::atan(y / x) / Math_PI);
    if (x < 0.0f && y < 0.0f)
        return (float)(180.0f * std::atan(y / x) / Math_PI) - 180.0f;
    return (float)(180.0f * std::atan(y / x) / Math_PI);
}
Vec2 Vec2::normal() const
{
    Vec2 t(x, y);
    float sign = t.length();
    if (sign < FLT_EPSILON)
        return Vec2();
    sign = 1.0f / sign;
    t.set(x * sign, y * sign);
    return t;
}

Vec3::Vec3() : x(0.0f), y(0.0f), z(0.0f) {}
Vec3::Vec3(float num) : x(num), y(num), z(num) {}
Vec3::Vec3(float x, float y, float z) : x(x), y(y), z(z) {}
Vec3::Vec3(const Vec3 &v) : x(v.x), y(v.y), z(v.z) {}
Vec3 Vec3::operator-() const
{
    Vec3 v(-x, -y, -z);
    return v;
}
Vec3 &Vec3::operator=(const Vec3 &v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    return *this;
}
bool Vec3::operator==(const Vec3 &v) const { return ((this->x == v.x) && (this->y == v.y) && (this->z == v.z)); }
bool Vec3::operator!=(const Vec3 &v) const { return ((this->x != v.x) || (this->y != v.y) || (this->z != v.z)); }
Vec3 Vec3::operator+(float v) const { return Vec3(x + v, y + v, z + v); }
Vec3 Vec3::operator+(const Vec3 &v) const { return Vec3(x + v.x, y + v.y, z + v.z); }
Vec3 Vec3::operator-(float v) const { return Vec3(x - v, y - v, z - v); }
Vec3 Vec3::operator-(const Vec3 &v) const { return Vec3(x - v.x, y - v.y, z - v.z); }
Vec3 Vec3::operator*(float v) const { return Vec3(x * v, y * v, z * v); }
Vec3 Vec3::operator*(const Vec3 &v) const { return Vec3(x * v.x, y * v.y, z * v.z); }
Vec3 Vec3::operator/(float v) const { return Vec3(x / v, y / v, z / v); }
Vec3 Vec3::operator/(const Vec3 &v) const { return Vec3(x / v.x, y / v.y, z / v.z); }
void Vec3::operator+=(const Vec3 &v)
{
    x += v.x;
    y += v.y;
    z += v.z;
}
void Vec3::operator+=(float v)
{
    x += v;
    y += v;
    z += v;
}
void Vec3::operator-=(const Vec3 &v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
}
void Vec3::operator-=(float v)
{
    x -= v;
    y -= v;
    z -= v;
}
void Vec3::operator*=(const Vec3 &v)
{
    x *= v.x;
    y *= v.y;
    z *= v.z;
}
void Vec3::operator*=(float v)
{
    x *= v;
    y *= v;
    z *= v;
}
Vec3 Vec3::operator*(const Mat3 &mat) const
{
    Vec3 temp;
    temp.x = this->x * mat.v[0][0] + this->y * mat.v[1][0] + this->z * mat.v[2][0];
    temp.y = this->x * mat.v[0][1] + this->y * mat.v[1][1] + this->z * mat.v[2][1];
    temp.z = this->x * mat.v[0][2] + this->y * mat.v[1][2] + this->z * mat.v[2][2];
    return temp;
}
void Vec3::zero()
{
    this->x = 0.0f;
    this->y = 0.0f;
    this->z = 0.0f;
}
bool Vec3::isZero() const { return this->x == 0.0f && this->y == 0.0f && this->z == 0.0f; }
void Vec3::set(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}
float Vec3::length() const { return std::sqrt(x * x + y * y + z * z); }
float Vec3::llength() const { return x * x + y * y + z * z; }
float Vec3::dot(const Vec3 &v) const { return x * v.x + y * v.y + z * v.z; }
float Vec3::dot(float x, float y, float z) const { return x * x + y * y + z * z; }

Vec3 Vec3::normal() const
{
    Vec3 t(x, y, z);
    float sign = t.length();
    if (sign < FLT_EPSILON)
        return Vec3();
    sign = 1.0f / sign;
    t.set(x * sign, y * sign, z * sign);
    return t;
}

Mat3::Mat3()
{
    v[0][0] = 1.0f;
    v[0][1] = 0.0f;
    v[0][2] = 0.0f;
    v[1][0] = 0.0f;
    v[1][1] = 1.0f;
    v[1][2] = 0.0f;
    v[2][0] = 0.0f;
    v[2][1] = 0.0f;
    v[2][2] = 1.0f;
}
void Mat3::operator=(const Mat3 &v)
{
    this->v[0][0] = v.v[0][0];
    this->v[0][1] = v.v[0][1];
    this->v[0][2] = v.v[0][2];
    this->v[1][0] = v.v[1][0];
    this->v[1][1] = v.v[1][1];
    this->v[1][2] = v.v[1][2];
    this->v[2][0] = v.v[2][0];
    this->v[2][1] = v.v[2][1];
    this->v[2][2] = v.v[2][2];
}
bool Mat3::operator==(const Mat3 &v) { return ::memcmp(&this->v[0], &v.v[0], sizeof(float) * 9) == 0; }
bool Mat3::operator!=(const Mat3 &v) { return ::memcmp(&this->v[0], &v.v[0], sizeof(float) * 9) != 0; }
float *Mat3::operator[](int idx) { return v[idx]; }

Mat3 Mat3::operator+(const Mat3 &v) const
{
    Mat3 t;
    t[0][0] = this->v[0][0] + v.v[0][0];
    t[0][1] = this->v[0][1] + v.v[0][1];
    t[0][2] = this->v[0][2] + v.v[0][2];

    t[1][0] = this->v[1][0] + v.v[1][0];
    t[1][1] = this->v[1][1] + v.v[1][1];
    t[1][2] = this->v[1][2] + v.v[1][2];

    t[2][0] = this->v[2][0] + v.v[2][0];
    t[2][1] = this->v[2][1] + v.v[2][1];
    t[2][2] = this->v[2][2] + v.v[2][2];

    return t;
}
Mat3 Mat3::operator-(const Mat3 &v) const
{
    Mat3 t;
    t[0][0] = this->v[0][0] - v.v[0][0];
    t[0][1] = this->v[0][1] - v.v[0][1];
    t[0][2] = this->v[0][2] - v.v[0][2];

    t[1][0] = this->v[1][0] - v.v[1][0];
    t[1][1] = this->v[1][1] - v.v[1][1];
    t[1][2] = this->v[1][2] - v.v[1][2];

    t[2][0] = this->v[2][0] - v.v[2][0];
    t[2][1] = this->v[2][1] - v.v[2][1];
    t[2][2] = this->v[2][2] - v.v[2][2];

    return t;
}
Mat3 Mat3::operator*(const Mat3 &v) const
{
    Mat3 t;
    t[0][0] = this->v[0][0] * v.v[0][0] + this->v[0][1] * v.v[1][0] + this->v[0][2] * v.v[2][0];
    t[0][1] = this->v[0][0] * v.v[0][1] + this->v[0][1] * v.v[1][1] + this->v[0][2] * v.v[2][1];
    t[0][2] = this->v[0][0] * v.v[0][2] + this->v[0][1] * v.v[1][2] + this->v[0][2] * v.v[2][2];

    t[1][0] = this->v[1][0] * v.v[0][0] + this->v[1][1] * v.v[1][0] + this->v[1][2] * v.v[2][0];
    t[1][1] = this->v[1][0] * v.v[0][1] + this->v[1][1] * v.v[1][1] + this->v[1][2] * v.v[2][1];
    t[1][2] = this->v[1][0] * v.v[0][2] + this->v[1][1] * v.v[1][2] + this->v[1][2] * v.v[2][2];

    t[2][0] = this->v[2][0] * v.v[0][0] + this->v[2][1] * v.v[1][0] + this->v[2][2] * v.v[2][0];
    t[2][1] = this->v[2][0] * v.v[0][1] + this->v[2][1] * v.v[1][1] + this->v[2][2] * v.v[2][1];
    t[2][2] = this->v[2][0] * v.v[0][2] + this->v[2][1] * v.v[1][2] + this->v[2][2] * v.v[2][2];

    return t;
}
Mat3 Mat3::operator*(float v) const
{
    Mat3 t;
    t[0][0] = this->v[0][0] * v;
    t[0][1] = this->v[0][1] * v;
    t[0][2] = this->v[0][2] * v;

    t[1][0] = this->v[1][0] * v;
    t[1][1] = this->v[1][1] * v;
    t[1][2] = this->v[1][2] * v;

    t[2][0] = this->v[2][0] * v;
    t[2][1] = this->v[2][1] * v;
    t[2][2] = this->v[2][2] * v;

    return t;
}
Mat3 Mat3::operator/(float v) const
{
    Mat3 t;
    t[0][0] = this->v[0][0] / v;
    t[0][1] = this->v[0][1] / v;
    t[0][2] = this->v[0][2] / v;

    t[1][0] = this->v[1][0] / v;
    t[1][1] = this->v[1][1] / v;
    t[1][2] = this->v[1][2] / v;

    t[2][0] = this->v[2][0] / v;
    t[2][1] = this->v[2][1] / v;
    t[2][2] = this->v[2][2] / v;

    return t;
}

void Mat3::zero()
{
    v[0][0] = 0.0f;
    v[0][1] = 0.0f;
    v[0][2] = 0.0f;
    v[1][0] = 0.0f;
    v[1][1] = 0.0f;
    v[1][2] = 0.0f;
    v[2][0] = 0.0f;
    v[2][1] = 0.0f;
    v[2][2] = 0.0f;
}
void Mat3::identity()
{
    v[0][0] = 1.0f;
    v[0][1] = 0.0f;
    v[0][2] = 0.0f;
    v[1][0] = 0.0f;
    v[1][1] = 1.0f;
    v[1][2] = 0.0f;
    v[2][0] = 0.0f;
    v[2][1] = 0.0f;
    v[2][2] = 1.0f;
}

void Mat3::transpose()
{
    float temp = 0.0f;

    temp = v[1][0];
    v[1][0] = v[0][1];
    v[0][1] = temp;
    temp = v[2][0];
    v[2][0] = v[0][2];
    v[0][2] = temp;
    temp = v[2][1];
    v[2][1] = v[1][2];
    v[1][2] = temp;
}
Mat3 Mat3::reversal() const
{
    Mat3 temp;
    temp.v[0][0] = v[1][1] * v[2][2] - v[1][2] * v[2][1];
    temp.v[0][1] = v[0][2] * v[2][1] - v[0][1] * v[2][2];
    temp.v[0][2] = v[0][1] * v[1][2] - v[0][2] * v[1][1];

    temp.v[1][0] = v[1][2] * v[2][0] - v[1][0] * v[2][2];
    temp.v[1][1] = v[0][0] * v[2][2] - v[0][2] * v[2][0];
    temp.v[1][2] = v[1][0] * v[0][2] - v[0][0] * v[1][2];

    temp.v[2][0] = v[1][0] * v[2][1] - v[1][1] * v[2][0];
    temp.v[2][1] = v[0][1] * v[2][0] - v[0][0] * v[2][1];
    temp.v[2][2] = v[0][0] * v[1][1] - v[1][0] * v[0][1];
    float deter = v[0][0] * (v[1][1] * v[2][2] - v[1][2] * v[2][1]) -
                  v[1][0] * (v[0][1] * v[2][2] - v[0][2] * v[2][1]) +
                  v[2][0] * (v[0][1] * v[1][2] - v[0][2] * v[1][1]);
    return temp / deter;
}

Rect::Rect() : minPos(0.0f), maxPos(1.0f) {}
Rect::Rect(const Vec2 &s) : minPos(0.0f), maxPos(s) {}
Rect::Rect(const Rect &v) : minPos(v.minPos), maxPos(v.maxPos) {}
Rect::Rect(const Vec2 &min, const Vec2 &max) : minPos(min), maxPos(max) {}
Rect &Rect::operator=(const Rect &v)
{
    minPos = v.minPos;
    maxPos = v.maxPos;
    return *this;
}
bool Rect::operator==(const Rect &v) { return (minPos == v.minPos) && (maxPos == v.maxPos); }
bool Rect::operator!=(const Rect &v) { return (minPos != v.minPos) || (maxPos != v.maxPos); }
Vec2 Rect::size() const { return maxPos - minPos; }
Vec2 Rect::core() const { return (maxPos - minPos) * 0.5f; }
Rect &Rect::move(const Vec2 &pos)
{
    minPos += pos;
    maxPos += pos;
    return *this;
}
Rect &Rect::scale(const Vec2 &size)
{
    minPos -= size;
    maxPos += size;
    return *this;
}

Color::Color() : r(0.0f), g(0.0f), b(0.0f), a(0.0f) {}
Color::Color(float ar, float ag, float ab, float aa) : r(ar), g(ag), b(ab), a(aa) {}
Color::Color(unsigned int num) { set(num); }
Color::Color(int num) { set(num); }
void Color::set(float r, float g, float b, float a)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}
void Color::set(unsigned int r, unsigned int g, unsigned int b, unsigned int a)
{
    this->r = r / 255.0f;
    this->g = g / 255.0f;
    this->b = b / 255.0f;
    this->a = a / 255.0f;
}
void Color::set(unsigned int num) { set((num & 0xff000000) >> 24, (num & 0xff0000) >> 16, (num & 0xff00) >> 8, num & 0xff); }
void Color::set(unsigned int num, unsigned int a) { set((num & 0xff0000) >> 16, (num & 0xff00) >> 8, (num & 0xff), a & 0xff); }
Color &Color::operator=(unsigned int v)
{
    set((v & 0xff000000) >> 24, (v & 0xff0000) >> 16, (v & 0xff00) >> 8, v & 0xff);
    return *this;
}
Color &Color::operator=(const Color &v)
{
    r = v.r;
    g = v.g;
    b = v.b;
    a = v.a;
    return *this;
}
bool Color::operator!=(const Color &val) { return ((r != val.r) || (g != val.g) || (b != val.b) || (a != val.a)); }
bool Color::operator==(const Color &val) { return ((r == val.r) && (g == val.g) && (b == val.b) && (a == val.a)); }
Color Color::operator+(const Color &v) const { return Color(v.r + r, v.g + g, v.b + b, v.a + a); }
Color Color::operator-(const Color &v) const { return Color(v.r - r, v.g - g, v.b - b, v.a - a); }
Color Color::operator*(const Color &v) const { return Color(v.r * r, v.g * g, v.b * b, v.a * a); }
Color Color::operator/(const Color &v) const { return Color(v.r / r, v.g / g, v.b / b, v.a / a); }
Color Color::operator+(float v) const { return Color(r + v, g + v, b + v, a); }
Color Color::operator-(float v) const { return Color(r - v, g - v, b - v, a); }
Color Color::operator*(float v) const { return Color(r * v, g * v, b * v, a); }
Color Color::operator/(float v) const { return Color(r / v, g / v, b / v, a); }
int Color::hex() const
{
    int val = 0;
    val = (val | (unsigned int)(r * 255)) << 8;
    val = (val | (unsigned int)(g * 255)) << 8;
    val = (val | (unsigned int)(b * 255)) << 8;
    val = (val | (unsigned int)(a * 255));
    return val;
}
