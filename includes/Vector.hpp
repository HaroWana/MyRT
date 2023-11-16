#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "Tuple.hpp"

class	Vector: public Tuple
{
public:
	Vector();
	Vector(float x, float y, float z);
	Vector	operator=(Tuple const &tup);
	Vector	operator^(Vector const &vec);
};

#endif