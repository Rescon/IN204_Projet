//
//  Color.hpp
//  IN204_Projet
//
//  Created by wangyu980312 on 20/12/2020.
//

#ifndef Color_hpp
#define Color_hpp

#include <stdio.h>
#include <iostream>

class Color{
public:
    // Constructor
    Color() : r(0.0), g(0.0), b(0.0) {}
    Color(double r, double g, double b) : r(r), g(g), b(b) {}
    explicit Color(double d) : r(d), g(d), b(d) {}
    Color(const Color& c) : r(c.r), g(c.g), b(c.b) {}

    // Accessor
    double getR() const;
    double getG() const;
    double getB() const;

    // Mutator
    void setR(const double r);
    void setG(const double g);
    void setB(const double b);

    // Method
    // For some basic operations of the color class, including reloading of “=”, addition, multiplication (with a number), modulation, clamp.
    Color& operator =(const Color& c);
    Color add(Color c) const;
    Color mul (double d) const;
    Color modulate (Color c) const;
    void clamp(double min = 0.0, double max = 1.0);
    
    ~Color() {}
    
private:
    double r;
    double g;
    double b;
};

#endif /* Color_hpp */
