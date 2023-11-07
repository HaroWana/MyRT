#ifndef POINT_HPP
# define POINT_HPP

#include "Tuple.hpp"

class	Point: public Tuple
{
public:
	Point();
	Point(float x, float y, float z);
	Point	operator=(Tuple const &tup);
};

#endif