#ifndef IMAGE_HPP
# define IMAGE_HPP

class   Image
{
public:
    int const     width;
    int const     height;
    Color         **pixels;

    Image();
    Image(int width, int height);
    ~Image();

    void    writePixel(int width, int height, Color const &color);
    Color   &pixelAt(int width, int height);
    std::string canvas_to_ppm();
};

std::ostream    &operator<<(std::ostream &out, const Image &img);

#endif