//
//  Sphere.hpp
//  IN204_Projet
//
//  Created by wangyu980312 on 20/12/2020.
//

#ifndef Sphere_hpp
#define Sphere_hpp

#include <stdio.h>
#include <iostream>
#include "Object.hpp"

class Sphere: public Object{
public:
    // Constructor
    Sphere():center(0.0), radius(1.0), color(0.5), reflect(0.0) {}
    Sphere(Vector center, double radius, Color color, double reflect) : center(center), radius(radius), color(color), reflect(reflect) {}

    // Accessor
    Vector getCenter() const;
    double getRadius() const;
    Color getColor() const;
    double getReflect() const;

    // Mutator
    void setCenter(const Vector center);
    void setRadius(const double radius);
    void setColor(const Color color);
    void setReflect(const double reflect);

    // Method
    Vector getNormalAt (Vector point);
    double findIntersection(Ray ray);
    
    ~Sphere(){}
    
private:
    Vector center;
    double radius;
    Color color;
    double reflect; // It represents reflectiveness of the sphere
};

#endif /* Sphere_hpp */
