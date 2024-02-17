#ifndef CVECTOR2D_H
#define CVECTOR2D_H

#include <cmath>
#include <bits/move.h>

template<typename T>
class CVector2D
{
public:
    T x,y;

    CVector2D(): x{}, y{} {}
    CVector2D(T&& px, T&& py): x(px), y(py){}
    CVector2D(const CVector2D<T>& other): x(other.x), y(other.y){}
    CVector2D(CVector2D<T>&& other) noexcept: x(std::move(other.x)), y(std::move(other.y)){}

    CVector2D<T>& operator=(const CVector2D<T>& other)
    {
        if(this != &other)
        {
            x = other.x;
            y = other.y;
        };
        return *this;
    }

    CVector2D<T>& zero()
    {
        this->x = static_cast<T>(0);
        this->y = static_cast<T>(0);
        return *this;
    }

    CVector2D<T>& one()
    {
        this->x = static_cast<T>(1);
        this->y = static_cast<T>(1);
        return *this;
    }

    // Start Vector addition
    CVector2D<T> operator+(const CVector2D<T>& other) const {
        return CVector2D<T>(x + other.x, y + other.y);
    }

    CVector2D<T>& operator+=(const CVector2D<T>& other) const {
        x += other.x;
        y += other.y;
        return *this;
    }
    // End Vector addition

    // Start Vector subtraction
    CVector2D<T> operator-(const CVector2D<T>& other) const {
        return CVector2D<T>(x - other.x, y - other.y);
    }

    CVector2D<T>& operator-=(const CVector2D<T>& other) const {
        x -= other.x;
        y -= other.y;
        return *this;
    }
    // End Vector subtraction

    // Start Scalar multiplication
    CVector2D<T> operator*(float scalar) const {
        return CVector2D<T>(x * scalar, y * scalar);
    }

    CVector2D<T>& operator*=(const CVector2D<T>& other) const {
        x *= other.x;
        y *= other.y;
        return *this;
    }
    // End Scalar multiplication

    // Start Scalar division
    CVector2D<T> operator/(float scalar) const {
        return Vector2D(x / scalar, y / scalar);
    }

    CVector2D<T>& operator/=(const CVector2D<T>& other) const {
        x /= other.x;
        y /= other.y;
        return *this;
    }
    // End Scalar division


    // Dot product
    T dot(const CVector2D<T>& other) const
    {
        return (x * other.x + y * other.y);
    }

    // Magnitude (length) of the vector
    T magnitude() const
    {
        return std::sqrt(x * x + y * y);
    }

    // Normalization (produces a unit vector)
    CVector2D<T> normalize() const
    {
        T mag = this->magnitude();
        if(mag != 0)
        {
            return *this / mag;
        }
        else
        {
            return *this;
        }
    }

    // Perpendicular vector
    CVector2D perp() const {
        // Rotate vector by 90 degrees counterclockwise
        return CVector2D(-y, x);
    }

    // Static method to calculate distance between two vectors
    static float distance(const CVector2D<T>& v1, const CVector2D<T>& v2) {
        return (v2 - v1).magnitude();
    }

};

using vec2i = CVector2D<int>;
using vec2f = CVector2D<float>;
using vec2d = CVector2D<double>;

#endif // CVECTOR2D_H
