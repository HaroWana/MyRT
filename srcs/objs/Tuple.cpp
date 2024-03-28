#include "../../includes/MyRT.hpp"

Tuple::Tuple()
{

}

Tuple::Tuple(float x, float y, float z, int w): _x(x), _y(y), _z(z), _w(w)
{

}

Tuple::Tuple(const Tuple &cpy): _x(cpy.getCoor('x')), _y(cpy.getCoor('y')), _z(cpy.getCoor('z')), _w(cpy.getW())
{

}

Tuple	Tuple::operator=(Tuple const &tup)
{
	if (this != &tup)
	{
		this->setCoor(tup.getCoor('x'), tup.getCoor('y'), tup.getCoor('z'));
		_w = tup.getW();
	}
	return (*this);
}

Tuple	Tuple::operator+(Tuple const &tup)
{
	return (Tuple(_x + tup.getCoor('x'), 
					_y + tup.getCoor('y'),
					_z + tup.getCoor('z'),
					_w + tup.getW()));
}

Tuple	Tuple::operator-(Tuple const &tup)
{
	return (Tuple(_x - tup.getCoor('x'), 
					_y - tup.getCoor('y'),
					_z - tup.getCoor('z'),
					_w - tup.getW()));
}

Tuple	Tuple::operator-()
{
	return (Tuple(-_x, -_y, -_z, -_w));
}

Tuple	Tuple::operator*(float scalar)
{
	return (Tuple(_x * scalar,
					_y * scalar,
					_z * scalar,
					_w * scalar));
}

Tuple	Tuple::operator/(float &scalar)
{
	return (Tuple(_x / scalar,
					_y / scalar,
					_z / scalar,
					_w / scalar));
}

bool	Tuple::operator==(Tuple &tup)
{
	if (std::abs(_x - tup.getCoor('x')) < EPSILON && 
		std::abs(_y - tup.getCoor('y')) < EPSILON &&
		std::abs(_z - tup.getCoor('z')) < EPSILON)
		return (true);
	else
		return (false);
}

bool	Tuple::operator!=(Tuple &tup)
{
	if (std::abs(_x - tup.getCoor('x')) > EPSILON && 
		std::abs(_y - tup.getCoor('y')) > EPSILON &&
		std::abs(_z - tup.getCoor('z')) > EPSILON)
		return (true);
	else
		return (false);
}

float	Tuple::operator*(Tuple &tup)
{
	return ((_x * tup.getCoor('x')) + 
			(_y * tup.getCoor('y')) +
			(_z * tup.getCoor('z')) +
			(_w * tup.getW()));
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
	return (sqrtf((_x * _x) + (_y * _y) + (_z * _z)));
}

void	Tuple::normalize()
{
	_x /= this->magnitude();
	_y /= this->magnitude();
	_z /= this->magnitude();
	_w /= this->magnitude(); // Why? I don't know, but I'll find out.
}

Tuple	Tuple::normalized()
{
	return (Tuple(_x / this->magnitude(),
				_y / this->magnitude(),
				_z / this->magnitude(),
				_w / this->magnitude()));
}

std::ostream	&operator<<(std::ostream &out, const Tuple &tup)
{
	out << "(" << tup.getCoor('x') << ", " << tup.getCoor('y') << ", " << tup.getCoor('z') << tup.getW() << ")";
	return (out);
}