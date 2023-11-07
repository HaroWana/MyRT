#include "Tuple.hpp"

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

Tuple	&Tuple::operator=(Tuple &tup)
{
	this->setCoor(tup.getCoor('x'), tup.getCoor('y'), tup.getCoor('z'));
	this->setW(0);
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
	if (this->getCoor('x') == tup.getCoor('x') && 
		this->getCoor('y') == tup.getCoor('y') &&
		this->getCoor('z') == tup.getCoor('z') &&
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
	}
}

float	*Tuple::getCoor() const
{
	float ret[3] = {this->_x, this->_y, this->_z};
	return (ret);
}

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