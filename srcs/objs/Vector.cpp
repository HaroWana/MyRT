#include "../../includes/MyRT.hpp"

Vector::Vector()
{
	Tuple(0, 1, 0, 0);
}

Vector::Vector(float x, float y, float z)
{
	Tuple(x, y, z, 0);
}

Vector	Vector::operator=(Tuple const &tup)
{
	if (this != &tup)
	{
		Tuple::operator=(tup);
	}
	return (*this);
}

Vector	Vector::operator^(Vector const &vec)
{
	return (Vector(this->getCoor('y') * vec.getCoor('z') - this->getCoor('z') * vec.getCoor('y'),
					this->getCoor('z') * vec.getCoor('x') - this->getCoor('x') * vec.getCoor('z'),
					this->getCoor('x') * vec.getCoor('y') - this->getCoor('y') * vec.getCoor('x')));
}
