#ifndef POINT_HPP
# define POINT_HPP

#include "Tuple.hpp"

typedef class	Point: public Tuple
{
public:
	Point();
	Point(float x, float y, float z);
}	t_point;

#endif