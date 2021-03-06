//
//  Light.hpp
//  IN204_Projet
//
//  Created by wangyu980312 on 20/12/2020.
//

#ifndef Light_hpp
#define Light_hpp

#include <stdio.h>
#include <iostream>
#include "Source.hpp"

class Light : public Source{
public:
    // Constructor
    Light() : position(0.0), color(1.0) {}
    Light(Vector position) : position(position), color(1.0) {}
    Light(Vector position, Color color): position(position), color(color){}
    Light(const Light& l) : position(l.position), color(l.color) {}

    // Accessor
    Vector getPosition() const;
    Color getColor() const;
    
    // Mutator
    void setPosition(const Vector position);
    void setColor(const Color color);

    ~Light() {}

private:
    Vector position;
    Color color;
};

#endif /* Light_hpp */
