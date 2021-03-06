//
//  Light.cpp
//  IN204_Projet
//
//  Created by wangyu980312 on 20/12/2020.
//

#include "Light.hpp"

Vector Light::getPosition() const {
    return position;
}

Color Light::getColor() const {
    return color;
}

void Light::setPosition(const Vector position)
{
    this->position = position;
}
void Light::setColor(const Color color)
{
    this->color = color;
}
