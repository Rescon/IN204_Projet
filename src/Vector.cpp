//
//  Vector.cpp
//  IN204_Projet
//
//  Created by wangyu980312 on 20/12/2020.
//

#include "Vector.hpp"

double Vector::getX() const
{
    return x;
}

double Vector::getY() const
{
    return y;
}

double Vector::getZ() const
{
    return z;
}

void Vector::setX(const double x)
{
    this->x = x;
}

void Vector::setY(const double y)
{
    this->y = y;
}

void Vector::setZ(const double z)
{
    this->z = z;
}

Vector& Vector::operator =(const Vector& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    return *this;
}

double Vector::length() const
{
    return sqrt(x*x + y*y + z*z);
}

Vector Vector::normalize() const
{
    double len = length();
    return Vector(x/len, y/len, z/len);
}

Vector Vector::negative () const
{
    return Vector(-1*x, -1*y, -1*z);
}

double Vector::dot(Vector v) const
{
    return x*v.getX() + y*v.getY() + z*v.getZ();
}

Vector Vector::cross(Vector v) const
{
    return Vector(y * v.getZ() - z * v.getY(),
                  z * v.getX() - x * v.getZ(),
                  x * v.getY() - y * v.getX());
}

Vector Vector::add (Vector v) const
{
    return Vector(x + v.getX(), y + v.getY(), z + v.getZ() );
}

Vector Vector::mul (double d) const
{
    return Vector(d*x, d*y, d*z);
}
