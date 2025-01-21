#pragma once
#include "cmath"
#include "string"

struct Vector2
{
    float x = 0; ///< The x-coordinate of the vector.
    float y = 0; ///< The y-coordinate of the vector.

    static const Vector2 Zero; ///< A vector with both coordinates set to zero.
    static const Vector2 One;  ///< A vector with both coordinates set to one.

    Vector2() : x(0), y(0) {}

    Vector2(float pX, float pY) : x(pX), y(pY) {}

    inline void operator+=(Vector2& right)
    {
        x += right.x;
        y += right.y;
    }

    inline void operator+=(float length)
    {
        x += length;
        y += length;
    }

    inline void operator-=(Vector2& right)
    {
        x -= right.x;
        y -= right.y;
    }

    inline void operator-=(float length)
    {
        x -= length;
        y -= length;
    }

    inline void operator*=(Vector2& multiplyer)
    {
        x *= multiplyer.x;
        y *= multiplyer.y;
    }

    inline void operator*=(float length)
    {
        x *= length;
        y *= length;
    }

    inline void operator/=(Vector2& divider)
    {
        x /= divider.x;
        y /= divider.y;
    }

    inline void operator/=(float length)
    {
        x /= length;
        y /= length;
    }

    friend Vector2 operator-(Vector2& left, Vector2 right)
    {
        return { left.x - right.x, left.y - right.y };
    }

    friend Vector2 operator-(Vector2 left, Vector2& right)
    {
        return { left.x - right.x, left.y - right.y };
    }

    friend Vector2 operator-(Vector2& left, Vector2& right)
    {
        return { left.x - right.x, left.y - right.y };
    }

    friend Vector2 operator-(Vector2& left, float right)
    {
        return { left.x - right, left.y - right };
    }

    friend Vector2 operator+(Vector2& left, Vector2 right)
    {
        return { left.x + right.x, left.y + right.y };
    }

    friend Vector2 operator+(Vector2 left, Vector2& right)
    {
        return { left.x + right.x, left.y + right.y };
    }

    friend Vector2 operator+(Vector2& left, Vector2& right)
    {
        return { left.x + right.x, left.y + right.y };
    }

    friend Vector2 operator+(Vector2& left, float right)
    {
        return { left.x + right, left.y + right };
    }

    friend Vector2 operator*(float scalar, Vector2& right)
    {
        return { scalar * right.x, scalar * right.y };
    }

    friend Vector2 operator*(Vector2& left, float scalar)
    {
        return { left.x * scalar, left.y * scalar };
    }

    friend Vector2 operator/(float scalar, Vector2& right)
    {
        return { scalar / right.x, scalar / right.y };
    }

    friend Vector2 operator/(Vector2& left, float scalar)
    {
        return { left.x / scalar, left.y / scalar };
    }

    inline float Length() const
    {
        return sqrt(x * x + y * y);
    }

    inline bool Equal(Vector2 right, double acceptance) const
    {
        if (x < right.x - acceptance || x > right.x + acceptance || y < right.y - acceptance || y > right.y + acceptance) return false;
        else return true;
    }

    inline void Normalize()
    {
        (*this) /= Length();
    }

    friend Vector2 Normalize(Vector2 temp)
    {
        return temp / temp.Length();
    }

    friend float Dot(Vector2& left, Vector2& right)
    {
        return left.x * right.x + left.y * right.y;
    }

    inline void Clamp(float minValue, float maxValue)
    {
        if ((*this).x < minValue)  (*this).x = minValue;
        if ((*this).x > maxValue) (*this).x = maxValue;

        if ((*this).y < minValue)  (*this).y = minValue;
        if ((*this).y > maxValue)  (*this).y = maxValue;
    }

    friend Vector2 Clamp(Vector2 temp, float minValue, float maxValue)
    {
        if (temp.x < minValue)  temp.x = minValue;
        if (temp.x > maxValue)  temp.x = maxValue;

        if (temp.y < minValue)  temp.y = minValue;
        if (temp.y > maxValue)  temp.y = maxValue;

        return temp;
    }

    inline std::string ToString()
    {
        return " (" + std::to_string(x) + " , " + std::to_string(y) + ") ";
    }
};