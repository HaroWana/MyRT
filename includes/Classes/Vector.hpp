#ifndef VECTOR_HPP
# define VECTOR_HPP

class	Vector: public Tuple
{
public:
	Vector();
	Vector(float x, float y, float z);
	Vector	operator=(Tuple const &tup);
	Vector	operator^(Vector const &vec); //Cross product
	Vector	operator+(Tuple const &tup);
};

#endif