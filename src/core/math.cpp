#include "Math.h"
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
Vec2 Vec2::abs() const
{
    return Vec2(std::fabs(x), std::fabs(y));
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

Vec3 Vec3::abs() const
{
    return Vec3(std::fabs(x), std::fabs(y), std::fabs(z));
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
    static Mat3 temp;
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

Mat3 Mat3::abs() const
{
    static Mat3 temp;
    temp.v[0][0] = std::fabs(v[0][0]);
    temp.v[0][1] = std::fabs(v[0][1]);
    temp.v[0][2] = std::fabs(v[0][2]);
    temp.v[1][0] = std::fabs(v[1][0]);
    temp.v[1][1] = std::fabs(v[1][1]);
    temp.v[1][2] = std::fabs(v[1][2]);
    temp.v[2][0] = std::fabs(v[2][0]);
    temp.v[2][1] = std::fabs(v[2][1]);
    temp.v[2][2] = std::fabs(v[2][2]);
    return temp;
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

float easing_linear(float v) { return v; }
float easing_outQuad(float v)
{
    v -= 1.0f;
    return -(v * v - 1.0f);
}
float easing_outCubic(float v)
{
    v -= 1.0f;
    return v * v * v + 1.0f;
}
float easing_outQuart(float v)
{
    v -= 1.0f;
    return -(v * v * v * v - 1.0f);
}
float easing_outQuint(float v)
{
    v -= 1.0f;
    return v * v * v * v * v + 1.0f;
}
float easing_inOutQuad(float v)
{
    v *= 2.0f;
    if (v < 1.0f)
        return 0.5f * v * v;
    v -= 2;
    return 0.5f * (v * v + 2.0f);
}
float easing_inOutCubic(float v)
{
    v *= 2.0f;
    if (v < 1.0f)
        return 0.5f * v * v * v;
    v -= 2;
    return 0.5f * (v * v * v + 2.0f);
}
float easing_inOutQuart(float v)
{
    v *= 2.0f;
    if (v < 1.0f)
        return 0.5f * v * v * v * v;
    v -= 2;
    return -0.5f * (v * v * v * v - 2.0f);
}
float easing_inOutQuint(float v)
{
    v *= 2.0f;
    if (v < 1.0f)
        return 0.5f * v * v * v * v * v;
    v -= 2;
    return 0.5f * (v * v * v * v * v + 2.0f);
}
float easing_inQuad(float v) { return v * v; }
float easing_inCubic(float v) { return v * v * v; }
float easing_inQuart(float v) { return v * v * v * v; }
float easing_inQuint(float v) { return v * v * v * v * v; }
float easing_inSine(float v) { return -1.0f * std::cos(v * Math_PI2) + 1.0f; }
float easing_outSine(float v) { return std::sin(v * Math_PI2); }
float easing_inOutSine(float v) { return -0.5f * (std::cos(v * Math_PI) - 1.0f); }
float easing_inExpo(float v) { return (v == 0.0f ? 0.0f : std::pow(2.0f, 10.0f * (v - 1.0f)) - 0.001f); }
float easing_outExpo(float v) { return (v == 1.0f ? 1.0f : -std::pow(2.0f, -10.0f * v) + 1.0f); }
float easing_inOutExpo(float v)
{
    v *= 2;
    return (v < 1.0f ? std::pow(2, 10 * (v - 1)) : (-std::pow(2, -10 * (v - 1)) + 2)) * 0.5f;
}
float easing_inCirc(float v) { return -1 * (std::sqrt(1 - v * v) - 1); }
float easing_outCirc(float v)
{
    v -= 1;
    return std::sqrt(1 - v * v);
}
float easing_inOutCirc(float v)
{
    v *= 2;
    if (v < 1)
        return -0.5f * (std::sqrt(1 - v * v) - 1);
    v -= 2;
    return 0.5f * (std::sqrt(1 - v * v) + 1);
}
float easing_inElastic(float v)
{
    if (v == 0 || v == 1)
        return v;
    v -= 1;
    return -std::pow(2, 10 * v) * std::sin((v - 0.075f) * Math_2PI / 0.3f);
}
float easing_outElastic(float v)
{
    if (v == 0 || v == 1)
        return v;
    return std::pow(2, -10 * v) * std::sin((v - 0.075f) * Math_2PI / 0.3f) + 1;
}

void _Math::init()
{
    easings[Easing::Type::linear] = easing_linear;
    easings[Easing::Type::outQuad] = easing_outQuad;
    easings[Easing::Type::outCubic] = easing_outCubic;
    easings[Easing::Type::outQuart] = easing_outQuart;
    easings[Easing::Type::outQuint] = easing_outQuint;
    easings[Easing::Type::inOutQuad] = easing_inOutQuad;
    easings[Easing::Type::inOutCubic] = easing_inOutCubic;
    easings[Easing::Type::inOutQuart] = easing_inOutQuart;
    easings[Easing::Type::inOutQuint] = easing_inOutQuint;
    easings[Easing::Type::inQuad] = easing_inQuad;
    easings[Easing::Type::inCubic] = easing_inCubic;
    easings[Easing::Type::inQuart] = easing_inQuart;
    easings[Easing::Type::inQuint] = easing_inQuint;
    easings[Easing::Type::inSine] = easing_inSine;
    easings[Easing::Type::outSine] = easing_outSine;
    easings[Easing::Type::inOutSine] = easing_inOutSine;
    easings[Easing::Type::inExpo] = easing_inExpo;
    easings[Easing::Type::outExpo] = easing_outExpo;
    easings[Easing::Type::inOutExpo] = easing_inOutExpo;
    easings[Easing::Type::inCirc] = easing_inCirc;
    easings[Easing::Type::outCirc] = easing_outCirc;
    easings[Easing::Type::inOutCirc] = easing_inOutCirc;
    easings[Easing::Type::inElastic] = easing_inElastic;
    easings[Easing::Type::outElastic] = easing_outElastic;
}
Mat3 _Math::ortho(const Vec2 &size)
{
    static Mat3 temp;
    temp[0][0] = 2.0f / size.x;
    temp[1][1] = 2.0f / size.y;
    temp[2][2] = 1.0f;

    temp[2][0] = -1.0f;
    temp[2][1] = -1.0f;
    return temp;
}
Mat3 _Math::ortho(const Rect &area)
{
    static Mat3 temp;
    temp[0][0] = 2.0f / (area.maxPos.x - area.minPos.x);
    temp[1][1] = 2.0f / (area.maxPos.y - area.minPos.y);
    temp[2][2] = 1.0f;

    temp[2][0] = -(area.maxPos.x + area.minPos.x) / (area.maxPos.x - area.minPos.x);
    temp[2][1] = -(area.maxPos.y + area.minPos.y) / (area.maxPos.y - area.minPos.y);
    return temp;
}
Mat3 _Math::translate(const Vec2 &offset)
{
    static Mat3 temp;
    temp[2][0] = offset.x;
    temp[2][1] = offset.y;
    return temp;
}
Mat3 _Math::translate(const Mat3 &mat, const Vec2 &offset)
{
    static Mat3 temp;
    temp[2][0] = offset.x;
    temp[2][1] = offset.y;
    return mat * temp;
}
Mat3 _Math::rotate(float angle)
{
    static Mat3 temp;
    temp[0][0] = std::cos(angleToRadian(angle));
    temp[0][1] = std::sin(angleToRadian(angle));
    temp[1][0] = -temp[0][1];
    temp[1][1] = temp[0][0];
    return temp;
}
Mat3 _Math::rotate(const Mat3 &mat, float angle)
{
    static Mat3 temp;
    temp[0][0] = std::cos(angleToRadian(angle));
    temp[0][1] = std::sin(angleToRadian(angle));
    temp[1][0] = -temp[0][1];
    temp[1][1] = temp[0][0];
    return mat * temp;
}
Mat3 _Math::rotateX(float angle)
{
    static Mat3 temp;
    temp[1][1] = std::cos(angleToRadian(angle));
    temp[1][2] = std::sin(angleToRadian(angle));
    temp[2][1] = -temp[1][2];
    temp[2][2] = temp[1][1];
    return temp;
}
Mat3 _Math::rotateX(const Mat3 &mat, float angle)
{
    static Mat3 temp;
    temp[1][1] = std::cos(angleToRadian(angle));
    temp[1][2] = std::sin(angleToRadian(angle));
    temp[2][1] = -temp[1][2];
    temp[2][2] = temp[1][1];
    return mat * temp;
}
Mat3 _Math::rotateY(float angle)
{
    static Mat3 temp;
    temp[0][0] = std::cos(angleToRadian(angle));
    temp[2][0] = std::sin(angleToRadian(angle));
    temp[0][2] = -temp[2][0];
    temp[2][2] = temp[0][0];
    return temp;
}
Mat3 _Math::rotateY(const Mat3 &mat, float angle)
{
    static Mat3 temp;
    temp[0][0] = std::cos(angleToRadian(angle));
    temp[2][0] = std::sin(angleToRadian(angle));
    temp[0][2] = -temp[2][0];
    temp[2][2] = temp[0][0];
    return mat * temp;
}
Mat3 _Math::scale(const Vec2 &v)
{
    static Mat3 temp;
    temp[0][0] = v.x;
    temp[1][1] = v.y;
    return temp;
}
Mat3 _Math::scale(const Mat3 &mat, const Vec2 &offset)
{
    static Mat3 temp;
    temp[0][0] = offset.x;
    temp[1][1] = offset.y;
    return mat * temp;
}
Mat3 _Math::transform(const Vec2 &pos, const Vec2 &scale, float angle)
{
    static Mat3 temp;
    float ca = std::cos(angleToRadian(angle));
    float sa = std::sin(angleToRadian(angle));

    temp.v[0][0] = ca * scale.x;
    temp.v[0][1] = sa * scale.x;
    temp.v[1][0] = -sa * scale.y;
    temp.v[1][1] = ca * scale.y;

    temp.v[2][0] = pos.x;
    temp.v[2][1] = pos.y;

    return temp;
}
Mat3 _Math::complexTrans(const Mat3 &mat, const Vec2 &size, const Vec2 &anchor)
{
    static Mat3 temp;
    temp.v[0][0] = size.x;
    temp.v[1][1] = size.y;
    temp.v[2][0] = size.x * (0.5f - anchor.x);
    temp.v[2][1] = size.y * (0.5f - anchor.y);
    return temp * mat;
}
float _Math::easing(float value, const Easing::Type &type) { return (type < Easing::Type::Count ? easings[type](value) : easings[Easing::Type::linear](value)); }
float _Math::linear(float begin, float end, float v) { return begin + (end - begin) * v; }
Vec2 _Math::linear(const Vec2 &begin, const Vec2 &end, float v) { return begin + (end - begin) * v; }

Vec2 bezier(float t, const Vec2 &p1, const Vec2 &p2, const Vec2 &p3)
{
    static Vec2 tp;
    tp.x = pow((1 - t), 2) * p1.x + 2 * t * (1 - t) * p2.x + pow(t, 2) * p3.x;
    tp.y = pow((1 - t), 2) * p1.y + 2 * t * (1 - t) * p2.y + pow(t, 2) * p3.y;
    return tp;
}

Vec2 bezier(float t, const Vec2 &p1, const Vec2 &p2, const Vec2 &p3, const Vec2 &p4)
{
    static Vec2 tp;
    tp.x = pow((1 - t), 3) * p1.x + pow((1 - t), 2) * 3 * t * p2.x + pow(t, 2) * (1 - t) * 3 * p3.x + pow(t, 3) * p4.x;
    tp.y = pow((1 - t), 3) * p1.y + pow((1 - t), 2) * 3 * t * p2.y + pow(t, 2) * (1 - t) * 3 * p3.y + pow(t, 3) * p4.y;
    return tp;
}

Vec2 circle(float t, const Vec2 &c, float r, float fr, float rd)
{
    static Vec2 p;
    p.x = c.x + r * cos(fr + rd * t);
    p.y = c.y + r * sin(fr + rd * t);
    return p;
}

float _Math::random() { return rand() / (float)RAND_MAX; }
float _Math::random(float min, float max) { return min + random() * (max - min); }
Vec2 _Math::randomVec2(const Vec2 &min, const Vec2 &max) { return Vec2(random(min.x, max.x), random(min.y, max.y)); }
Color _Math::randomColor(const Color &min, const Color &max)
{
    static Color col;
    col.r = random(min.r, max.r);
    col.g = random(min.g, max.g);
    col.b = random(min.b, max.b);
    col.a = random(min.a, max.a);
    return col;
}
float _Math::map(float target, float begin, float end, float tbegin, float tend) { return ((tend - tbegin) / (end - begin)) * (target - begin) + tbegin; }
Vec2 _Math::map(const Vec2 &target, const Vec2 &begin, const Vec2 &end, const Vec2 &tbegin, const Vec2 &tend) { return ((tend - tbegin) / (end - begin)) * (target - begin) + tbegin; }
Vec2 _Math::dirVec(float angle) { return Vec2(cos(angleToRadian(angle)), sin(angleToRadian(angle))); }
float _Math::angleToRadian(float num) { return num * 0.0174532925f; }
float _Math::radianToAngle(float num) { return num * 57.29577951f; }
float _Math::range(float angle)
{
    float decimal = (float)(angle - (int)angle);
    if (angle > 360.0f)
    {
        decimal += (float)((int)angle % 360);
        return decimal;
    }
    if (angle < 0.0f)
    {
        decimal += 360.0f - (float)((-(int)angle) % 360);
        return decimal;
    }
    return angle;
}
float _Math::range(float min, float max, float v) { return (v >= max ? max : (v <= min ? min : v)); }
