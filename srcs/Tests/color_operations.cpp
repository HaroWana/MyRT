#include "../../includes/tests.hpp"

void    color_add()
{
    std::string title = "Color addition: ";
    print(LEFT, title, LINELENGTH, FWHITE, NOC, RESET);
    Color   c1(0.9, 0.6, 0.75);
    Color   c2(0.7, 0.1, 0.25);
    Color   expected(1.6, 0.7, 1.0);
    if ((c1 + c2) == expected)
        print(RIGHT, "PASS", LINELENGTH - title.length(), FGREEN, NOC, BOLD);
    else 
        print(RIGHT, "FAIL", LINELENGTH - title.length(), FRED, NOC, BOLD);
    std::cout << std::endl;
}

void    color_sub()
{
    std::string title = "Color substraction: ";
    print(LEFT, title, LINELENGTH, FWHITE, NOC, RESET);
    Color   c1(0.9, 0.6, 0.75);
    Color   c2(0.7, 0.1, 0.25);
    Color   expected(0.2, 0.5, 0.5);
    if ((c1 - c2) == expected)
        print(RIGHT, "PASS", LINELENGTH - title.length(), FGREEN, NOC, BOLD);
    else 
        print(RIGHT, "FAIL", LINELENGTH - title.length(), FRED, NOC, BOLD);
    std::cout << std::endl;
}

void    color_mult()
{
    std::string title = "Color multiplication (by scalar): ";
    print(LEFT, title, LINELENGTH, FWHITE, NOC, RESET);
    {
    Color   c1(0.2, 0.3, 0.4);
    float   scalar = 2;
    Color   expected(0.4, 0.6, 0.8);
    if ((c1 * scalar) == expected)
        print(RIGHT, "PASS", LINELENGTH - title.length(), FGREEN, NOC, BOLD);
    else 
        print(RIGHT, "FAIL", LINELENGTH - title.length(), FRED, NOC, BOLD);
    std::cout << std::endl;
    }{
    title = "Color multiplication (by color): ";
    print(LEFT, title, LINELENGTH, FWHITE, NOC, RESET);
    Color   c1(1, 0.2, 0.4);
    Color   c2(0.9, 1, 0.1);
    Color   expected(0.9, 0.2, 0.04);
    if ((c1 * c2) == expected)
        print(RIGHT, "PASS", LINELENGTH - title.length(), FGREEN, NOC, BOLD);
    else 
        print(RIGHT, "FAIL", LINELENGTH, FRED, NOC, BOLD);
    std::cout << std::endl;
    }
}