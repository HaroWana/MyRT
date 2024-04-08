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

Vector	Vector::operator+(Tuple const &tup)
{
	Vector ret(this->getCoor('x') + tup.getCoor('x'),
			this->getCoor('y') + tup.getCoor('y'),
			this->getCoor('z') + tup.getCoor('z'));
	return (ret);
}
