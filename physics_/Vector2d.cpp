#include "Vector2d.h"

Vector2d::Vector2d()
{
    x = 0;
    y = 0;
}

Vector2d::Vector2d(float x, float y)
{
    this->x = x;
    this->y = y;
}

Vector2d  Vector2d::operator+(Vector2d other)
{
    return Vector2d(x + other.x, y + other.y);
}

Vector2d  Vector2d::operator-(Vector2d other)
{
    return Vector2d(this->x - other.x, this->y - other.y);
}

Vector2d Vector2d::operator+=(Vector2d other)
{
    x += other.x;
    y += other.y;
    return *this; // Return the current object to allow for chaining
}

Vector2d Vector2d::operator-=(Vector2d other)
{
    x -= other.x;
    y -= other.y;
    return *this; // Return the current object to allow for chaining
}

Vector2d Vector2d::operator=(Vector2d other)
{
    if (this != &other) { // Protect against self-assignment
        x = other.x;
        y = other.y;
    }
    return *this; // Return the current object to allow for chaining
}

bool Vector2d::operator==(Vector2d other)
{
    return (x == other.x) && (y == other.y); // Compare x and y components
}


Vector2d Vector2d::operator*(float a)
{
    return Vector2d(x * a, y * a);
}



Vector2d Vector2d::operator*=(float a)
{
    x *= a;
    y *= a;
    return *this; // Return the current object to allow for chaining
}

Vector2d Vector2d::operator/(float a)
{
    return Vector2d(x / a, y / a);
}

float Vector2d::Dot(Vector2d other)
{
    return (x * other.x + y * other.y); // Dot product
}

float Vector2d::getMagnitude()
{
    return sqrt(x * x + y * y); // Magnitude of the vector
}

Vector2d Vector2d::getNormalized()
{
    float mag = getMagnitude();
    if (mag == 0) {
        return Vector2d(0, 0); // Avoid division by zero
    }
    return (*this) / mag; // Normalize the vector
}

Vector2d Vector2d::getNormal()
{
    return Vector2d(y, -x); // A simple normal (perpendicular) vector
}
