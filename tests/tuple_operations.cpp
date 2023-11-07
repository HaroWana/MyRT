#include "tests.hpp"

void    w_value()
{
    print(LEFT, "W value for Vectors: ", LINELENGTH, FWHITE, NOC, RESET);
    Vector  v1;
    if (v1.getW() == 0)
        print(LEFT, "PASS", LINELENGTH, FGREEN, NOC, BOLD);
    else 
        print(LEFT, "FAIL", LINELENGTH, FRED, NOC, BOLD);
    std::cout << std::endl;
    print(LEFT, "W value for Points: ", LINELENGTH, FWHITE, NOC, RESET);
    Point   p1;
    if (p1.getW() == 1)
        print(LEFT, "PASS", LINELENGTH, FGREEN, NOC, BOLD);
    else 
        print(LEFT, "FAIL", LINELENGTH, FRED, NOC, BOLD);
    std::cout << std::endl;
}

void    tuple_add()
{
    print(LEFT, "Addition: ", LINELENGTH, FWHITE, NOC, RESET);
    Tuple   t1(3, -2, 5, 1);
    Tuple   t2(-2, 3, 1, 0);
    Tuple   t3;
    t3 = t1 + t2;
    if (t3.getCoor('x') == 1
        && t3.getCoor('y') == 1
        && t3.getCoor('z') == 6
        && t3.getW() == 1)
        print(LEFT, "PASS", LINELENGTH, FGREEN, NOC, BOLD);
    else
        print(LEFT, "FAIL", LINELENGTH, FRED, NOC, BOLD);
    std::cout << std::endl;
}

void    tuple_sub()
{
    {
    print(LEFT, "Substraction: ", LINELENGTH, FWHITE, NOC, RESET);
    Point p1(3, 2, 1);
    Point p2(5, 6, 7);
    Vector expected(-2, -4, -6);
    Tuple result;
    result = p1 - p2;
    if (expected == result)
        print(LEFT, "PASS", LINELENGTH, FGREEN, NOC, BOLD);
    else 
        print(LEFT, "FAIL", LINELENGTH, FRED, NOC, BOLD);
    std::cout << ", ";
    }
    {
    Point p1(3, 2, 1);
    Vector p2(5, 6, 7);
    Point expected(-2, -4, -6);
    Tuple result;
    result = p1 - p2;
    if (expected == result)
        print(LEFT, "PASS", LINELENGTH, FGREEN, NOC, BOLD);
    else 
        print(LEFT, "FAIL", LINELENGTH, FRED, NOC, BOLD);
    std::cout << ", ";
    }
    {
    Vector p1(3, 2, 1);
    Vector p2(5, 6, 7);
    Vector expected(-2, -4, -6);
    Tuple result;
    result = p1 - p2;
    if (expected == result)
        print(LEFT, "PASS", LINELENGTH, FGREEN, NOC, BOLD);
    else 
        print(LEFT, "FAIL", LINELENGTH, FRED, NOC, BOLD);
    std::cout << std::endl;
    }
}

void    tuple_neg()
{
    print(LEFT, "Negating (-tuple): ", LINELENGTH, FWHITE, NOC, RESET);
    Tuple   t1(1, -2, 3, -4);
    Tuple   expected(-1, 2, -3, 4);
    if (-t1 == expected)
        print(LEFT, "PASS", LINELENGTH, FGREEN, NOC, BOLD);
    else 
        print(LEFT, "FAIL", LINELENGTH, FRED, NOC, BOLD);
    std::cout << std::endl;
}

void    tuple_scalar()
{
    {
    print(LEFT, "Scalar multiplication: ", LINELENGTH, FWHITE, NOC, RESET);
    Tuple   t1(1, -2, 3, -4);
    Tuple   expected(3.5, -7, 10.5, -14);
    float   scalar = 3.5;
    t1 = t1 * scalar;
    if (t1 != expected)
        print(LEFT, "FAIL", LINELENGTH, FRED, NOC, BOLD);
    else 
        print(LEFT, "PASS", LINELENGTH, FGREEN, NOC, BOLD);
    std::cout << ", ";
    }{
    Tuple   t1(1, -2, 3, -4);
    Tuple   expected(0.5, -1, 1.5, -2);
    float scalar = 0.5;
    t1 = t1 * scalar;
    if (t1 != expected)
        print(LEFT, "FAIL", LINELENGTH, FRED, NOC, BOLD);
    else 
        print(LEFT, "PASS", LINELENGTH, FGREEN, NOC, BOLD);
    std::cout << std::endl;
    }{
    print(LEFT, "Scalar division: ", LINELENGTH, FWHITE, NOC, RESET);
    Tuple   t1(1, -2, 3, -4);
    Tuple   expected(0.5, -1, 1.5, -2);
    float   scalar = 2;
    t1 = t1 / scalar;
    if (t1 != expected)
        print(LEFT, "FAIL", LINELENGTH, FRED, NOC, BOLD);
    else 
        print(LEFT, "PASS", LINELENGTH, FGREEN, NOC, BOLD);
    std::cout << ", ";
    }
    {
    Tuple   t1(1, -2, 3, -4);
    Tuple   expected(2, -4, 6, -8);
    float   scalar = 0.5;
    t1 = t1 / scalar;
    if (t1 != expected)
        print(LEFT, "FAIL", LINELENGTH, FRED, NOC, BOLD);
    else 
        print(LEFT, "PASS", LINELENGTH, FGREEN, NOC, BOLD);
    std::cout << std::endl;
    }
}

void    tuple_mag()
{
    {
    print(LEFT, "Magnitude: ", LINELENGTH, FWHITE, NOC, RESET);
    Vector v1(1, 0, 0);
    if (v1.magnitude() == 1)
        print(LEFT, "PASS", LINELENGTH, FGREEN, NOC, BOLD);
    else 
        print(LEFT, "FAIL", LINELENGTH, FRED, NOC, BOLD);
    std::cout << ", ";
    }{
    Vector v1(0, 1, 0);
    if (v1.magnitude() == 1)
        print(LEFT, "PASS", LINELENGTH, FGREEN, NOC, BOLD);
    else 
        print(LEFT, "FAIL", LINELENGTH, FRED, NOC, BOLD);
    std::cout << ", ";
    }{
    Vector v1(0, 0, 1);
    if (v1.magnitude() == 1)
        print(LEFT, "PASS", LINELENGTH, FGREEN, NOC, BOLD);
    else 
        print(LEFT, "FAIL", LINELENGTH, FRED, NOC, BOLD);
    std::cout << ", ";
    }{
    Vector v1(1, 2, 3);
    if (v1.magnitude() == sqrtf(14.0))
        print(LEFT, "PASS", LINELENGTH, FGREEN, NOC, BOLD);
    else 
        print(LEFT, "FAIL", LINELENGTH, FRED, NOC, BOLD);
    std::cout << ", ";
    }{
    Vector v1(-1, -2, -3);
    if (v1.magnitude() == sqrtf(14.0))
        print(LEFT, "PASS", LINELENGTH, FGREEN, NOC, BOLD);
    else 
        print(LEFT, "FAIL", LINELENGTH, FRED, NOC, BOLD);
    std::cout << std::endl;
    }
}

void    tuple_norm()
{
    {
    print(LEFT, "Normalize: ", LINELENGTH, FWHITE, NOC, RESET);
    Vector  v1(4, 0, 0);
    v1.normalize();
    Vector  expected(1, 0, 0);
    if (v1 == expected)
        print(LEFT, "PASS", LINELENGTH, FGREEN, NOC, BOLD);
    else 
        print(LEFT, "FAIL", LINELENGTH, FRED, NOC, BOLD);
    std::cout << ", ";
    }{
    Vector  v1(1, 2, 3);
    Vector  v2;
    v2 = v1.normalized();
    Vector  expected(0.26726, 0.53452, 0.80178);
    if (v2 == expected)
        print(LEFT, "PASS", LINELENGTH, FGREEN, NOC, BOLD);
    else 
        print(LEFT, "FAIL", LINELENGTH, FRED, NOC, BOLD);
    std::cout << ", ";
    if (std::abs(v2.magnitude() - 1) < EPSILON)
        print(LEFT, "PASS", LINELENGTH, FGREEN, NOC, BOLD);
    else 
        print(LEFT, "FAIL", LINELENGTH, FRED, NOC, BOLD);
    std::cout << std::endl;
    }
}