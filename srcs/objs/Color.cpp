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

int  Color::getRGB() const
{
    // int   ret = 0;
    // ret = (static_cast<int>(this->getCoor('x') * 255) << 16 && 0xFF) | (static_cast<int>(this->getCoor('y') * 255) << 8 && 0xFF) | (static_cast<int>(this->getCoor('z') * 255) && 0xFF);
    return (static_cast<int>(this->getCoor('x') * 255) << 16 & 0xFF) | (static_cast<int>(this->getCoor('y') * 255) << 8 & 0xFF) | (static_cast<int>(this->getCoor('z') * 255) & 0xFF);
}

std::ostream    &operator<<(std::ostream &out, const Color &color)
{
    out << "(" << color.getCoor('x') << ", " << color.getCoor('y') << ", " << color.getCoor('z') << ")";
    return (out);
}