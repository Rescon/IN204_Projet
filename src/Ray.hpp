//
//  Ray.hpp
//  IN204_Projet
//
//  Created by wangyu980312 on 20/12/2020.
//

#ifndef Ray_hpp
#define Ray_hpp

#include <stdio.h>
#include <iostream>
#include "Vector.hpp"
class Ray{
public:
    // Constructor
    Ray() : origin(0.0), direction(1.0, 0.0, 0.0) {}
    Ray(Vector origin, Vector direction): origin(origin), direction(direction.normalize()){}
    
    // Accessor
    Vector getOrigin() const;
    Vector getDirection() const;
    
    // Mutator
    void setOrigin(const Vector origin);
    void setDirection(const Vector direction);

    ~Ray(){}
    
private:
    Vector origin;
    Vector direction;
};

#endif /* Ray_hpp */
