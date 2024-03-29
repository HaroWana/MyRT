#include "../../includes/MyRT.hpp"

MatrixXf::MatrixXf(int size)
{
	primary.size = size;
	primary.matrix = new float*[size];
	for (int i = 0; i < size; i++)
	{
		primary.matrix[i] = new float[size];
		bzero(primary.matrix[i], size * sizeof(float));
	}
	transfo = NULL;
}

MatrixXf::MatrixXf(int size, float **elements)
{
	primary.size = size;
	primary.matrix = new float*[size];
	for (int r = 0; r < size; r++)
	{
		primary.matrix[r] = new float[size];
		bzero(primary.matrix[r], size * sizeof(float));
		for (int c = 0; c < size; c++)
		{
			primary.matrix[r][c] = elements[r][c];
		}
	}
	transfo = NULL;
}

MatrixXf::~MatrixXf()
{
	for (int i = 0; i < primary.size; i++)
    {
        delete [] primary.matrix[i];
    }
    delete [] primary.matrix;

	if (transfo != NULL)
	{
		for (int i = 0; i < primary.size; i++)
		{
			delete [] transfo[i];
		}
		delete [] transfo;
	}
}

float	**MatrixXf::getMatrix() const
{
	return (primary.matrix);
}

float	**MatrixXf::getTransformation() const
{
	return (transfo);
}

float	&MatrixXf::getElement(int r, int c) const
{
	return (primary.matrix[r][c]);
}

int	MatrixXf::getSize() const
{
	return (primary.size);
}

void	MatrixXf::setElement(int r, int c, float element)
{
	if (r >= primary.size || c >= primary.size)
		throw M_WrongSizeException();

	primary.matrix[r][c] = element;
	// return (1);
}

void	MatrixXf::setMatrix(float **elements)
{
	// int rlen = 0;
	// int	clen = 0;
	// float **rtmp = elements;
	
	// while (rtmp++ != NULL)
	// {
	// 	// float *tmp = elements[r];
	// 	// while (tmp++)
	// 	// 	clen++; 
	// 	// rlen++;
	// }
	// if (rlen != size || clen != size)
	// 	throw M_WrongSizeException();
	// if (sizeof(elements) / sizeof(float*) != primary.size)
	// 	throw M_WrongSizeException();
	std::cout << "Elements: " << sizeof(*elements) / sizeof(elements[0]) << std::endl;
	
	for (int r = 0; r < primary.size; r++)
	{
		for (int c = 0; c < primary.size; c++)
			primary.matrix[r][c] = elements[r][c];
	}
	// return (1);
}

void		MatrixXf::deleteElement(int r, int c)
{
	if (r >= primary.size || c >= primary.size)
		throw M_OutOfBoundsException();

	primary.matrix[r][c] = 0;
	// return (1);
}

MatrixXf	&MatrixXf::operator=(MatrixXf const &mat)
{
	if (this != &mat)
	{
		this->setMatrix(mat.primary.matrix);
	}
	return (*this);
}

bool	MatrixXf::operator==(MatrixXf const &mat)
{
	if (primary.size != mat.getSize())
		return (false);

	for (int r = 0; r < primary.size; r++)
	{
		for (int c = 0; c < primary.size; c++)
		{
			if (std::abs(primary.matrix[r][c] - mat.primary.matrix[r][c]) > EPSILON)
				return (false);
		}
	}
	return (true);
}

MatrixXf	MatrixXf::operator*(MatrixXf const &mat)
{
	// int rlen = 0;
	// int	clen = 0;
	// for (int r = 0; mat.matrix[r] != NULL; r++)
	// {
	// 	for (int c = 0; mat.matrix[r][c] != NULL; c++)
	// 		clen++;
	// 	rlen++;
	// }
	// if (rlen != size || clen != size)
	// 	return (NULL);

	if (mat.primary.size != this->primary.size)
		throw M_WrongSizeException();

	MatrixXf	res(primary.size);
	for (int r = 0; r < primary.size; r++)
	{
		for (int c = 0; c < primary.size; c++)
		{
			for (int i = 0; i < primary.size; i++)
				res.primary.matrix[r][c] += this->primary.matrix[r][i] * mat.primary.matrix[i][c];
		}
	}
	return (res);
}

MatrixXf	MatrixXf::operator*(Tuple const &tup)
{
	if (this->primary.size != 3 && this->primary.size != 4) // Might need to be changed for check only of size 4
		throw M_WrongSizeException();

	MatrixXf res(primary.size);
	for (int r = 0; r < primary.size; r++)
	{
		for (int c = 0; c < primary.size; c++)
		{
			for (int i = 0; i < primary.size; i++)
				res.primary.matrix[r][c] += this->primary.matrix[r][i] * tup.getCoor()[i];
		}
	}
	return (res);
}

std::ostream	&operator<<(std::ostream &out, const MatrixXf &mat)
{
	for (int r = 0; r < mat.getSize(); r++)
	{
		for (int c = 0; c < mat.getSize(); c++)
		{
			out << " " << mat.getElement(r, c);
			if (c < mat.getSize() - 1)
				out << " |";
		}
		out << std::endl;
		if (r < mat.getSize() - 1)
		{
			for (int i = 0; i < mat.getSize() * 4 - 1; i++)
				out << "-";
		}
		out << std::endl;
	}
	return (out);	
}