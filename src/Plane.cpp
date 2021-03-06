//
//  Plane.cpp
//  IN204_Projet
//
//  Created by wangyu980312 on 20/12/2020.
//

#include "Plane.hpp"

double Plane::getDistance() const
{
    return distance;
}

Vector Plane::getNormal() const
{
    return normal;
}

Color Plane::getColor() const
{
    return color;
}

double Plane::getReflect() const
{
    return reflect;
}

void Plane::setDistance(const double distance)
{
    this->distance = distance;
}

void Plane::setNormal(const Vector normal)
{
    this->normal = normal;
}

void Plane::setColor(const Color color)
{
    this->color = color;
}

void Plane::setReflect(const double reflect)
{
    this->reflect = reflect;
}

Vector Plane::getNormalAt (Vector point){
    return normal;
}

double Plane::findIntersection(Ray ray) {
    double nDotD = normal.dot(ray.getDirection());
    if (nDotD >= 0) {
        // The ray does not intersect the plane
        return -1;
    }
    else{
        return -1*normal.dot(ray.getOrigin().add(normal.mul(distance).negative()))/nDotD;
    }
}
