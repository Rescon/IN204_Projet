//
//  Object.hpp
//  IN204_Projet
//
//  Created by wangyu980312 on 20/12/2020.
//

#ifndef Object_hpp
#define Object_hpp

#include <stdio.h>
#include <iostream>
#include "Vector.hpp"
#include "Color.hpp"
#include "Ray.hpp"

class Object{
public:
    virtual Color getColor() const {
        return Color(0.0);
    }
    virtual double getReflect() const {
        return 0.0;
    }
    // Get the normal vector of a certain point, which is especially important for spheres
    virtual Vector getNormalAt(Vector point) {
        return Vector(0.0);
    }
    // Given a ray, find the point of intersection between the object and it, this is the core of ray tracing.
    // It returns the distance between the origin of the ray to the point of intersection, -1 indicates that there is no intersection.
    virtual double findIntersection(Ray ray) = 0;
};

#endif /* Object_hpp */
