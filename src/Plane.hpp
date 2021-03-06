//
//  Plane.hpp
//  IN204_Projet
//
//  Created by wangyu980312 on 20/12/2020.
//

#ifndef Plane_hpp
#define Plane_hpp

#include <stdio.h>
#include "Object.hpp"

class Plane : public Object {
public:
    // Constructor
    Plane() : distance(1.0), normal(1.0, 0.0, 0.0), color(0.5), reflect(0.0) {}
    Plane(double distance, Vector normal, Color color, double reflect) : distance(distance), normal(normal), color(color), reflect(reflect) {}

    // Accessor
    double getDistance() const;
    Vector getNormal() const;
    Color getColor() const;
    double getReflect() const;
    
    // Mutator
    void setDistance(const double distance);
    void setNormal(const Vector normal);
    void setColor(const Color color);
    void setReflect(const double reflect);
    
    // Method
    Vector getNormalAt (Vector point);
    double findIntersection(Ray ray);
    
    ~Plane(){}
    
private:
    double distance;
    Vector normal;
    Color color;
    double reflect; // It represents reflectiveness of the plane
};

#endif /* Plane_hpp */
