#include "../../includes/Image.hpp"
#include "../../includes/Color.hpp"

Image::Image(): width(600), height(400)
{
    pixels = new Color*;
    for (int i = 0; i < width; i++)
    {
        pixels[i] = new Color[height];
        bzero(pixels[i], height);
    }
}

Image::Image(int width, int height): width(width), height(height)
{
    pixels = new Color*;
    for (int i = 0; i < width; i++)
    {
        pixels[i] = new Color[height];
        bzero(pixels[i], height);
    }
}

Image::~Image()
{
    for (int i = 0; i < width; i++)
    {
        delete [] pixels[i];
    }
    delete [] pixels;
}

void    Image::writePixel(int width, int height, Color &color)
{
    pixels[width][height] = color;
}


Color   &Image::pixelAt(int width, int height)
{
    return (pixels[width][height]);
}

std::ostream    &operator<<(std::ostream &out, const Image img)
{
    out << "Width: " << img.width << "  Height: " << img.height;
    return (out);
}