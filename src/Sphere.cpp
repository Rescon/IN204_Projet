//
//  Sphere.cpp
//  IN204_Projet
//
//  Created by wangyu980312 on 20/12/2020.
//

#include "Sphere.hpp"

Vector Sphere::getCenter() const
{
    return center;
}

double Sphere::getRadius() const
{
    return radius;
}

Color Sphere::getColor() const
{
    return color;
}

double Sphere::getReflect() const
{
    return reflect;
}

void Sphere::setCenter(const Vector center)
{
    this->center = center;
}

void Sphere::setRadius(const double radius)
{
    this->radius = radius;
}

void Sphere::setColor(const Color color)
{
    this->color = color;
}

void Sphere::setReflect(const double reflect)
{
    this->reflect = reflect;
}

Vector Sphere::getNormalAt(Vector point){
    return center.negative().add(point).normalize();
}


double Sphere::findIntersection(Ray ray) {
    // We use the mathematical formula for finding the roots to find the location of the intersection
    double b =
        2*(ray.getOrigin().getX() - center.getX())*ray.getDirection().getX() +
        2*(ray.getOrigin().getY() - center.getY())*ray.getDirection().getY() +
        2*(ray.getOrigin().getZ() - center.getZ())*ray.getDirection().getZ();
    
    double c =
        pow(ray.getOrigin().getX() - center.getX(), 2) +
        pow(ray.getOrigin().getY() - center.getY(), 2) +
        pow(ray.getOrigin().getZ() - center.getZ(), 2) -
        pow(radius, 2);

    double discriminant = b*b - 4*c;

    if (discriminant > 0) {
        // The ray intersects the sphere, but there will be two intersections
        // We need to choose the smaller value
        double rootOne = (-1*b - sqrt(discriminant))/2;
        if (rootOne > 0){
            return rootOne;
        } else {
            return (-1*b + sqrt(discriminant))/2;
        }
    } else {
        // The ray does not intersect the plane
        return -1;
    }
}
