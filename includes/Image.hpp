#ifndef IMAGE_HPP
# define IMAGE_HPP

#include "MyRT.hpp"

class   Image
{
public:
    int const     width;
    int const     height;
    Color         **pixels;

    Image();
    Image(int width, int height);
    ~Image();

    void    writePixel(int width, int height, Color &color);
    Color   &pixelAt(int width, int height);
};

std::ostream    &operator<<(std::ostream &out, const Image &img);

#endif