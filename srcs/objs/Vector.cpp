#include "../../includes/MyRT.hpp"

Vector::Vector()
{
	this->setCoor(0, 1, 0);
	this->setW(0);
}

Vector::Vector(float x, float y, float z)
{
	this->setCoor(x, y, z);
	this->setW(0);
}