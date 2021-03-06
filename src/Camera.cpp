//
//  Camera.cpp
//  IN204_Projet
//
//  Created by wangyu980312 on 20/12/2020.
//

#include "Camera.hpp"

Vector Camera::getPosition() const
{
    return position;
}

Vector Camera::getDirection() const
{
    return direction;
}

Vector Camera::getRight() const
{
    return right;
}

Vector Camera::getDown() const
{
    return down;
}

void Camera::setPosition(const Vector position)
{
    this->position = position;
}

void Camera::setDirection(const Vector direction)
{
    this->direction = direction;
}

void Camera::setRight(const Vector right)
{
    this->right = right;
}

void Camera::setDown(const Vector down)
{
    this->down = down;
}

void Camera::generateCamera(Vector position, Vector destination)
{
    setPosition(position);
    setDirection(destination.add(position.negative()).normalize());
    setRight(Vector(0.0, 1.0, 0.0).cross(direction).normalize());
    setDown(right.cross(direction));
}

Ray Camera::generateRay(double xPosition, double yPosition)
{
    return  Ray(position, direction.add(right.mul(yPosition).add(down.mul(xPosition))).normalize());
}
