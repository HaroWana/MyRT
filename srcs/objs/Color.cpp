#include "../../includes/MyRT.hpp"

Color::Color()
{
    this->setCoor(0, 0, 0);
}

Color::Color(float r, float g, float b)
{
    this->setCoor(r, g, b);
}

Color::Color(Tuple const &tup)
{
    this->setCoor(tup.getCoor('x'), tup.getCoor('y'), tup.getCoor('z'));
}

Color   Color::operator*(Color const &color)
{
    return (Color(getCoor('x') * color.getCoor('x'),
                getCoor('y') * color.getCoor('y'),
                getCoor('z') * color.getCoor('z')));
}

// float   *Color::getRGB() const
// {
//     float   ret[3] = {this->_r, this->_g, this->_b};
//     return (ret);
// }

std::ostream    &operator<<(std::ostream &out, const Color &color)
{
    out << "(" << color.getCoor('x') << ", " << color.getCoor('y') << ", " << color.getCoor('z') << ")";
}