#ifndef TESTS_HPP
# define TESTS_HPP

#include "../includes/MyRT.hpp"

enum WPosition{ LEFT, CENTRE, RIGHT };  
enum WFGColor{ FBLACK = 30, FRED = 31, FGREEN = 32, FYELLOW = 33, FBLUE = 34, FMAGENTA = 35, FCYAN = 36, FWHITE = 37 };
enum WBGColor{ NOC = 0, BBLACK = 40, BRED = 41, BGREEN = 42, BYELLOW = 43, BBLUE = 44, BMAGENTA = 45, BCYAN = 46, BWHITE = 47 };
enum WFormat{ RESET = 0, BOLD = 1, ULINE = 4, BLINK = 5, BOLDOFF = 21, ULINEOFF = 24};
const int   LINELENGTH = 80;

void    colorize(std::string &s, WFGColor FGcolor, WBGColor BGcolor, WFormat format);
void    print( WPosition pos, std::string s, int linelength, WFGColor FGcolor, WBGColor BGcolor, WFormat format );

void    w_value();
void    tuple_add();
void    tuple_sub();
void    tuple_neg();
void    tuple_scalar();
void    tuple_mag();

#endif