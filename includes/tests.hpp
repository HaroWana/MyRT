#ifndef TESTS_HPP
# define TESTS_HPP

#include "MyRT.hpp"

enum WPosition{ LEFT, CENTRE, RIGHT };  
enum WFGColor{ FBLACK = 30, FRED = 31, FGREEN = 32, FYELLOW = 33, FBLUE = 34, FMAGENTA = 35, FCYAN = 36, FWHITE = 37 };
enum WBGColor{ NOC = 0, BBLACK = 40, BRED = 41, BGREEN = 42, BYELLOW = 43, BBLUE = 44, BMAGENTA = 45, BCYAN = 46, BWHITE = 47 };
enum WFormat{ RESET = 0, BOLD = 1, ULINE = 4, BLINK = 5, BOLDOFF = 21, ULINEOFF = 24};
const int   LINELENGTH = 60;

void    colorize(std::string &s, WFGColor FGcolor, WBGColor BGcolor, WFormat format);
void    print( WPosition pos, std::string s, int linelength, WFGColor FGcolor, WBGColor BGcolor, WFormat format );

// Tuple Operations //
void    w_value();
void    tuple_add();
void    tuple_sub();
void    tuple_neg();
void    tuple_scalar();
void    tuple_mag();
void    tuple_norm();
void    tuple_dot();
void    tuple_cross();

// Projectiles //
struct  Projectile
{
    Point   pos;
    Vector  vel;
    Projectile(): pos(Point(0, 1, 0)), vel(Vector(1, 1, 0)) {}
};

struct  Environment
{
    Vector  grav;
    Vector  wind;
    Environment(): grav(Vector(0, -0.1, 0)), wind(Vector(-0.01, 0, 0)) {}
};

Projectile  tick(Environment env, Projectile proj);
void        shoot_up();

// Colors //
void    color_add();
void    color_sub();
void    color_mult();

// Image //
void    ppm_content();

// Matrices //
void	matrix_fill();

#endif