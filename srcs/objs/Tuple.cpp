#include "../../includes/MyRT.hpp"

Tuple::Tuple()
{

}

Tuple::Tuple(float x, float y, float z, int w)
{
	this->setCoor(x, y, z);
	this->setW(w);
}

Tuple::Tuple(const Tuple &cpy)
{
	this->setCoor(cpy.getCoor('x'), cpy.getCoor('y'), cpy.getCoor('z'));
	this->setW(cpy.getW());
}

Tuple	Tuple::operator=(Tuple const &tup)
{
	if (this != &tup)
	{
		this->setCoor(tup.getCoor('x'), tup.getCoor('y'), tup.getCoor('z'));
		this->setW(tup.getW());
	}
	return (*this);
}

Tuple	Tuple::operator+(Tuple &tup)
{
	return (Tuple(this->getCoor('x') + tup.getCoor('x'), 
					this->getCoor('y') + tup.getCoor('y'),
					this->getCoor('z') + tup.getCoor('z'),
					this->getW() + tup.getW()));
}

Tuple	Tuple::operator-(Tuple &tup)
{
	return (Tuple(this->getCoor('x') - tup.getCoor('x'), 
					this->getCoor('y') - tup.getCoor('y'),
					this->getCoor('z') - tup.getCoor('z'),
					this->getW() - tup.getW()));
}

Tuple	Tuple::operator-()
{
	return (Tuple(-(this->getCoor('x')), -(this->getCoor('y')), -(this->getCoor('z')), -(this->getW())));
}

Tuple	Tuple::operator*(float &scalar)
{
	return (Tuple(this->getCoor('x') * scalar,
					this->getCoor('y') * scalar,
					this->getCoor('z') * scalar,
					this->getW() * scalar));
}

Tuple	Tuple::operator/(float &scalar)
{
	return (Tuple(this->getCoor('x') / scalar,
					this->getCoor('y') / scalar,
					this->getCoor('z') / scalar,
					this->getW() / scalar));
}

bool	Tuple::operator==(Tuple &tup)
{
	if (std::abs(this->getCoor('x') - tup.getCoor('x')) < EPSILON && 
		std::abs(this->getCoor('y') - tup.getCoor('y')) < EPSILON &&
		std::abs(this->getCoor('z') - tup.getCoor('z')) < EPSILON &&
		this->getW() == tup.getW())
		return (true);
	else
		return (false);
}

bool	Tuple::operator!=(Tuple &tup)
{
	if (this->getCoor('x') != tup.getCoor('x') && 
		this->getCoor('y') != tup.getCoor('y') &&
		this->getCoor('z') != tup.getCoor('z') &&
		this->getW() != tup.getW())
		return (true);
	else
		return (false);
}

float	Tuple::getCoor(char type) const
{
	switch (type)
	{
		case 'x':
			return (this->_x);
		case 'y':
			return (this->_y);
		case 'z':
			return (this->_z);
		default:
			return (std::numeric_limits<float>::quiet_NaN());
	}
}

// float	*Tuple::getCoor() const
// {
// 	float ret[3] = {this->_x, this->_y, this->_z};
// 	return (ret);
// }

int		Tuple::getW() const
{
	return (this->_w);
}

void	Tuple::setCoor(char type, float nValue)
{
	switch (type)
	{
		case 'x':
			this->_x = nValue;
			break ;
		case 'y':
			this->_y = nValue;
			break ;
		case 'z':
			this->_z = nValue;
			break ;
	}
}

void	Tuple::setCoor(float x, float y, float z)
{
	this->_x = x;
	this->_y = y;
	this->_z = z;
}

void	Tuple::setW(int nValue)
{
	this->_w = nValue;
}

float	Tuple::magnitude()
{
	return (sqrtf((this->getCoor('x') * this->getCoor('x'))
				+ (this->getCoor('y') * this->getCoor('y'))
				+ (this->getCoor('z') * this->getCoor('z'))));
}

void	Tuple::normalize()
{
	this->setCoor(this->getCoor('x') / this->magnitude(),
				this->getCoor('y') / this->magnitude(),
				this->getCoor('z') / this->magnitude());
	this->setW(this->getW() / this->magnitude()); // Why? I don't know, but I'll find out.
}

Tuple	Tuple::normalized()
{
	return (Tuple(this->getCoor('x') / this->magnitude(),
				this->getCoor('y') / this->magnitude(),
				this->getCoor('z') / this->magnitude(),
				this->getW() / this->magnitude()));
}