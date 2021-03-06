//
//  Source.hpp
//  IN204_Projet
//
//  Created by wangyu980312 on 20/12/2020.
//

#ifndef Source_hpp
#define Source_hpp

#include <stdio.h>
#include "Vector.hpp"
#include "Color.hpp"

class Source{
public:
    // Get the position of the light source.
    virtual Vector getPosition() const {
        return Vector(0.0);
    }
    // Get the color of the light source.
    virtual Color getColor() const {
        return Color(1.0);
    }
};

#endif /* Source_hpp */
