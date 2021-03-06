//
//  Vector.hpp
//  IN204_Projet
//
//  Created by wangyu980312 on 20/12/2020.
//

#ifndef Vector_hpp
#define Vector_hpp

#include <stdio.h>
#include <iostream>
#include <cmath>

class Vector{
public:
    // Constructor
    Vector() : x(0.0), y(0.0), z(0.0) {}
    Vector(double x, double y, double z) : x(x), y(y), z(z) {}
    explicit Vector(double d) : x(d), y(d), z(d) {}
    Vector(const Vector& v) : x(v.x), y(v.y), z(v.z) {}

    // Accessor
    double getX() const;
    double getY() const;
    double getZ() const;
    
    // Mutator
    void setX(const double x);
    void setY(const double y);
    void setZ(const double z);
    
    // Method
    // For some basic operations of the vector class, including reloading of “=”, getting the length, normalize, negative, dot, cross, addition, multiplication (with a number).
    Vector& operator =(const Vector& v);
    double length() const;
    Vector normalize() const;
    Vector negative() const;
    double dot(Vector v) const;
    Vector cross(Vector v) const;
    Vector add (Vector v) const;
    Vector mul (double d) const;
    
    ~Vector() {}
    
private:
    double x;
    double y;
    double z;

};

#endif /* Vector_hpp */
