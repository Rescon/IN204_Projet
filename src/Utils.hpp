//
//  Utils.hpp
//  IN204_Projet
//
//  Created by wangyu980312 on 20/12/2020.
//

#ifndef Utils_hpp
#define Utils_hpp

#include <stdio.h>
#include <vector>
#include <float.h>

#include "Plane.hpp"
#include "Vector.hpp"
#include "Ray.hpp"
#include "Camera.hpp"
#include "Color.hpp"
#include "Light.hpp"
#include "Source.hpp"
#include "Object.hpp"
#include "Sphere.hpp"

// Several very useful functions are defined here to improve the readability of the code.

// Given a ray, find its intersection with all objects and return it in object order.
// It returns the distance between the origin of the ray to the point of intersection, -1 indicates that there is no intersection.
std::vector<double> findIntersections(Ray ray, std::vector<Object*> objects);

// Among all the intersection points, we choose the point closest to the camera and return its index, -1 indicates that there is no intersection with all objects.
int findIndexClosest(std::vector<double> intersections);

// After determining the intersection point, we get the color of this point.
Color getColor(int indexClosest, Ray ray, std::vector<double> intersections, std::vector<Object*> objects, std::vector<Source*> sources);

#endif /* Utils_hpp */
