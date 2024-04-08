#include "../../includes/MyRT.hpp"

Image::Image(): width(600), height(400)
{
    pixels = new Color*[width];
    for (int i = 0; i < width; i++)
    {
        pixels[i] = new Color[height];
        bzero((void*)pixels[i], height * sizeof(Color));
    }
}

Image::Image(int width, int height): width(width), height(height)
{
    pixels = new Color*[width];
    for (int w = 0; w < width; w++)
    {
        pixels[w] = new Color[height];
        bzero((void*)pixels[w], height * sizeof(Color));
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

void    Image::writePixel(int width, int height, Color const &color)
{
    pixels[width][height] = color;
}


Color   &Image::pixelAt(int width, int height)
{
    return (pixels[width][height]);
}

std::string     Image::canvas_to_ppm()
{
    int line_len = 0;
    std::string ppm = "P3\n" + std::to_string(this->width) + ' ' + std::to_string(this->height) + '\n';
    ppm += "255\n";
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            for (char   c = 'x'; c < 123; c++)
            {
                int color = static_cast<int>(pixels[w][h].getCoor(c) * 255 + 0.5 > 255 ? 255 : pixels[w][h].getCoor(c) * 255 + 0.5);
                if (color < 0)
                    color = 0;
                int digitsNum = numDigits(color);
                if (line_len + digitsNum + 1 >= 70)
                {
                    ppm += '\n';
                    line_len = 0;
                }
                else if (line_len != 0)
                {
                    ppm += ' ';
                    line_len++;
                }
                ppm += std::to_string(color);
                line_len += digitsNum;
            }
        }
        ppm += '\n';
        line_len = 0;
    }
    return (ppm);
}

std::ostream    &operator<<(std::ostream &out, const Image img)
{
    out << "Width: " << img.width << "  Height: " << img.height;
    return (out);
}