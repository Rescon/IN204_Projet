//
//  Ray.cpp
//  IN204_Projet
//
//  Created by wangyu980312 on 20/12/2020.
//

#include "Ray.hpp"

Vector Ray::getOrigin() const {
    return origin;
}

Vector Ray::getDirection() const {
    return direction;
}

void Ray::setOrigin(const Vector origin)
{
    this->origin = origin;
}

void Ray::setDirection(const Vector direction)
{
    this->direction = direction;
}
