#ifndef COLOR_HPP
# define COLOR_HPP

#include "MyRT.hpp"

class   Color: public Tuple
{
public:
    Color();
    Color(float r, float g, float b);
    Color(Tuple const &tup);

    Color   operator*(Color const &color);
    Color   operator*(float scalar) { return(Tuple::operator*(scalar)); }

    int     getRGB() const;
};

std::ostream    &operator<<(std::ostream &out, const Color &color);

#endif