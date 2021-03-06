//
//  Camera.hpp
//  IN204_Projet
//
//  Created by wangyu980312 on 20/12/2020.
//

#ifndef Camera_hpp
#define Camera_hpp

#include <stdio.h>
#include <iostream>
#include "Vector.hpp"
#include "Ray.hpp"

class Camera{
public:
    // Constructor
    Camera() : position(0.0), direction(0.0, 0.0, 1.0), right(0.0), down(0.0) {}
    Camera(Vector position, Vector direction, Vector right, Vector down) : position(position), direction(direction), right(right), down(down) {}

    // Accessor
    Vector getPosition() const;
    Vector getDirection() const;
    Vector getRight() const;
    Vector getDown() const;
    
    // Mutator
    void setPosition(const Vector position);
    void setDirection(const Vector direction);
    void setRight(const Vector right);
    void setDown(const Vector down);
    
    // Method
    // Given the camera position and observation point, generate the corresponding camera
    void generateCamera(Vector position, Vector destination);
    
    // Generate a corresponding ray according to the position of the pixel
    Ray generateRay(double xPosition, double yPosition);

    ~Camera(){}

private:
    Vector position;
    Vector direction;
    Vector right;
    Vector down;
};

#endif /* Camera_hpp */
