#ifndef POINT_HPP
# define POINT_HPP

class	Point: public Tuple
{
public:
	Point();
	Point(float x, float y, float z);
	Point	operator=(Tuple const &tup);
	Point	operator+(Tuple const &tup);
};

#endif