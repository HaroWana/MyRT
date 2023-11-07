#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "Tuple.hpp"

typedef class Vector: private Tuple
{
public:
	Vector();
	Vector(float x, float y, float z);
}	t_vec;

#endif