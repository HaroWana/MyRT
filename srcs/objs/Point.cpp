#include "../../includes/MyRT.hpp"

Point::Point()
{
	Tuple(0, 0, 0, 1);
}

Point::Point(float x, float y, float z)
{
	Tuple(x, y, z, 1);
}

Point	Point::operator=(Tuple const &tup)
{
	if (this != &tup)
	{
		Tuple::operator=(tup);
	}
	return (*this);
}