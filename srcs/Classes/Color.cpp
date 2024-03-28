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

Color    Color::getRGB() const
{
    return (Color(this->getCoor('x'), this->getCoor('y'), this->getCoor('z')));
}

std::ostream    &operator<<(std::ostream &out, const Color &color)
{
    out << "(" << color.getCoor('x') << ", " << color.getCoor('y') << ", " << color.getCoor('z') << ")";
    return (out);
}