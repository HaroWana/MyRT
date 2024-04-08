#ifndef TUPLE_HPP
#define TUPLE_HPP

class Tuple
{
	float	_x;
	float	_y;
	float	_z;
	int		_w;

public:
	Tuple();
	Tuple(float x, float y, float z, int w);
	Tuple(const Tuple &cpy);

	Tuple	operator=(Tuple const &tup);
	Tuple	operator+(Tuple const &tup);
	Tuple	operator-(Tuple const &tup);
	Tuple	operator-();
	Tuple	operator*(float scalar);
	Tuple	operator/(float &scalar);
	bool	operator==(Tuple &tup);
	bool	operator!=(Tuple &tup);
	float	operator*(Tuple &tup); // !! Dot product !!

	float	magnitude();
	void	normalize();
	Tuple	normalized();

	//-----Accessors-----//
	float	getCoor(char type) const;
	float	*getCoor() const;
	int		getW() const;
	void	setCoor(char type, float nValue);
	void	setCoor(float x, float y, float z);
	void	setW(int nValue);
};

std::ostream	&operator<<(std::ostream &out, const Tuple &tup);

#endif