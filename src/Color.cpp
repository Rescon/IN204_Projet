//
//  Color.cpp
//  IN204_Projet
//
//  Created by wangyu980312 on 20/12/2020.
//

#include "Color.hpp"

double Color::getR() const
{
    return r;
}

double Color::getG() const
{
    return g;
}

double Color::getB() const
{
    return b;
}

void Color::setR(const double r)
{
    this->r = r;
}

void Color::setG(const double g)
{
    this->g = g;
}

void Color::setB(const double b)
{
    this->b = b;
}

Color& Color::operator =(const Color& c)
{
    r = c.r;
    g = c.g;
    b = c.b;
    return *this;
}

Color Color::add(Color c) const
{
    return Color(r+c.getR(), g+c.getG(), b+c.getB());
}

Color Color::mul (double d) const
{
    return Color(d*r, d*g, d*b);
}

Color Color::modulate (Color c) const{
    return Color(r*c.getR(), g*c.getG(), b*c.getB());
}

void Color::clamp(double min, double max)
{
    r = std::max(min, std::min(max, r));
    g = std::max(min, std::min(max, g));
    b = std::max(min, std::min(max, b));
}
