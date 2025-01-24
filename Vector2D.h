#pragma once
#include "cmath"
#include "string"

struct Vector2D
{
    float x = 0; ///< The x-coordinate of the vector.
    float y = 0; ///< The y-coordinate of the vector.

    static const Vector2D Zero; ///< A vector with both coordinates set to zero.
    static const Vector2D One;  ///< A vector with both coordinates set to one.

    Vector2D() : x(0), y(0) {}

    Vector2D(float pX, float pY) : x(pX), y(pY) {}

    inline bool operator!=(Vector2D right) const
    {
        return (x != right.x && y != right.y);
    }

    inline bool operator==(Vector2D right) const
    {
        return (x == right.x && y == right.y);
    }

    inline void operator+=(Vector2D& right)
    {
        x += right.x;
        y += right.y;
    }

    inline void operator+=(float length)
    {
        x += length;
        y += length;
    }

    inline void operator-=(Vector2D& right)
    {
        x -= right.x;
        y -= right.y;
    }

    inline void operator-=(float length)
    {
        x -= length;
        y -= length;
    }

    inline void operator*=(Vector2D& multiplyer)
    {
        x *= multiplyer.x;
        y *= multiplyer.y;
    }

    inline void operator*=(float length)
    {
        x *= length;
        y *= length;
    }

    inline void operator/=(Vector2D& divider)
    {
        x /= divider.x;
        y /= divider.y;
    }

    inline void operator/=(float length)
    {
        x /= length;
        y /= length;
    }

    friend Vector2D operator-(Vector2D& left, Vector2D right)
    {
        return { left.x - right.x, left.y - right.y };
    }

    friend Vector2D operator-(Vector2D left, Vector2D& right)
    {
        return { left.x - right.x, left.y - right.y };
    }

    friend Vector2D operator-(Vector2D& left, Vector2D& right)
    {
        return { left.x - right.x, left.y - right.y };
    }

    friend Vector2D operator-(Vector2D& left, float right)
    {
        return { left.x - right, left.y - right };
    }

    friend Vector2D operator+(Vector2D& left, Vector2D right)
    {
        return { left.x + right.x, left.y + right.y };
    }

    friend Vector2D operator+(Vector2D left, Vector2D& right)
    {
        return { left.x + right.x, left.y + right.y };
    }

    friend Vector2D operator+(Vector2D& left, Vector2D& right)
    {
        return { left.x + right.x, left.y + right.y };
    }

    friend Vector2D operator+(Vector2D& left, float right)
    {
        return { left.x + right, left.y + right };
    }

    friend Vector2D operator*(float scalar, Vector2D& right)
    {
        return { scalar * right.x, scalar * right.y };
    }

    friend Vector2D operator*(Vector2D& left, float scalar)
    {
        return { left.x * scalar, left.y * scalar };
    }

    friend Vector2D operator/(int scalar, Vector2D& right)
    {
        return { scalar / right.x, scalar / right.y };
    }

    friend Vector2D operator/(Vector2D& left, float scalar)
    {
        return { left.x / scalar, left.y / scalar };
    }

    inline float Length() const
    {
        return sqrt(x * x + y * y);
    }

    inline bool Equal(Vector2D& right, double acceptance) const
    {
        if (x < right.x - acceptance || x > right.x + acceptance || y < right.y - acceptance || y > right.y + acceptance) return false;
        else return true;
    }

    inline void Normalize()
    {
        (*this) /= Length();
    }

    friend Vector2D Normalize(Vector2D temp)
    {
        return temp / temp.Length();
    }

    friend float Dot(Vector2D& left, Vector2D& right)
    {
        return left.x * right.x + left.y * right.y;
    }

    inline void Clamp(int minValue, int maxValue)
    {
        if ((*this).x < minValue)  (*this).x = minValue;
        if ((*this).x > maxValue) (*this).x = maxValue;

        if ((*this).y < minValue)  (*this).y = minValue;
        if ((*this).y > maxValue)  (*this).y = maxValue;
    }

    inline float Distance(Vector2D& right) 
    {
        return sqrt(((*this).x - right.x) * ((*this).x - right.x) + ((*this).y - right.y) * ((*this).y - right.y));
    }

    friend Vector2D Clamp(Vector2D temp, float minValue, float maxValue)
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