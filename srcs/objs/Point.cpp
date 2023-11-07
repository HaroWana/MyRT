#include "../../includes/MyRT.hpp"

Point::Point()
{
	this->setCoor(0, 1, 0);
	this->setW(1);
}

Point::Point(float x, float y, float z)
{
	this->setCoor(x, y, z);
	this->setW(1);
}

Point	Point::operator=(Tuple const &tup)
{
	if (this != &tup)
	{
		Tuple::operator=(tup);
	}
	return (*this);
}