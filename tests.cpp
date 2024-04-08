#include "includes/tests.hpp"

void    colorize(std::string &s, WFGColor FGcolor, WBGColor BGcolor, WFormat format)
{
    std::string pre = "\033[" + std::to_string(static_cast<int>(format)) + ";" + std::to_string(static_cast<int>(FGcolor));
    std::string pre2;
    std::string post = "\033[0m";
    if (BGcolor != 0)
        pre2 = ";" + std::to_string(static_cast<int>(BGcolor));
    s = pre + pre2 + "m" + s + post;
}

void    print( WPosition pos, std::string s, int linelength, WFGColor FGcolor, WBGColor BGcolor, WFormat format )
{
   int spaces;
   switch( pos )
   {
      case CENTRE: spaces = ( linelength - s.size() ) / 2; break;
      case RIGHT : spaces =   linelength - s.size()      ; break;
      case LEFT  : spaces = 0                            ; break;
   }
   colorize(s, FGcolor, BGcolor, format);
   if ( spaces > 0 ) std::cout << std::string( spaces, ' ' );
   std::cout << s;
}

int main()
{
    std::cout << std::endl;
    print(CENTRE, "Test Results", LINELENGTH, FGREEN, BRED, BOLD);
    std::cout << std::endl << std::endl;

    print(LEFT, "TUPLE OPERATIONS:", LINELENGTH, FGREEN, NOC, ULINE);
    std::cout << std::endl;
    w_value();
    tuple_add();
    tuple_sub();
    tuple_neg();
    tuple_scalar();
    tuple_mag();
    tuple_norm();
    tuple_dot();
    tuple_cross();
    std::cout << std::endl;

    print(LEFT, "PROJECTILE:", LINELENGTH, FGREEN, NOC, ULINE);
    std::cout << std::endl;
    shoot_up();
    std::cout << std::endl;

    print(LEFT, "COLOR OPERATIONS:", LINELENGTH, FGREEN, NOC, ULINE);
    std::cout << std::endl;
    color_add();
    color_sub();
    color_mult();
    std::cout << std::endl;

    print(LEFT, "IMAGE:", LINELENGTH, FGREEN, NOC, ULINE);
    std::cout << std::endl;
    ppm_content();
    std::cout << std::endl;

	print(LEFT, "MATRIX:", LINELENGTH, FGREEN, NOC, ULINE);
    std::cout << std::endl;
	std::cout << std::endl;
	matrix_fill();
    std::cout << std::endl;
    matrix_transpose();
}