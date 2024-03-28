#include "../../includes/MyRT.hpp"

Matrix::Matrix(int size): size(size)
{
	matrix = new float*[size];
	for (int i = 0; i < size; i++)
	{
		matrix[i] = new float[size];
		bzero(matrix[i], size * sizeof(float));
	}
}

Matrix::Matrix(int size, float **elements): size(size)
{
	matrix = new float*[size];
	for (int r = 0; r < size; r++)
	{
		matrix[r] = new float[size];
		bzero(matrix[r], size * sizeof(float));
		for (int c = 0; c < size; c++)
		{
			matrix[r][c] = elements[r][c];
		}
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < size; i++)
    {
        delete [] matrix[i];
    }
    delete [] matrix;
}

float	&Matrix::getElement(int r, int c) const
{
	return (matrix[r][c]);
}

int	Matrix::getSize() const
{
	return (size);
}

int		Matrix::setElement(int r, int c, float element)
{
	if (r >= size || c >= size)
		return (0);

	matrix[r][c] = element;
	return (1);
}

int	Matrix::fillMatrix(float **elements)
{
	int rlen = 0;
	int	clen = 0;
	for (int r = 0; elements[r] != NULL; r++)
	{
		for (int c = 0; elements[c] != NULL; c++)
			clen++;
		rlen++;
	}
	if (rlen != size || clen != size)
		return (0);
	
	for (int r = 0; elements[r] != NULL; r++)
	{
		for (int c = 0; elements[c] != NULL; c++)
			matrix[r][c] = elements[r][c];
	}
	return (1);
}

int		Matrix::deleteElement(int r, int c)
{
	if (r >= size || c >= size)
		return (0);

	matrix[r][c] = 0;
	return (1);
}

Matrix	&Matrix::operator=(Matrix const &mat)
{
	if (this != &mat)
	{
		this->fillMatrix(mat.matrix);
	}
	return (*this);
}

bool	Matrix::operator==(Matrix const &mat)
{
	if (size != mat.getSize())
		return (false);

	for (int r = 0; r < size; r++)
	{
		for (int c = 0; c < size; c++)
		{
			if (matrix[r][c] != mat.matrix[r][c])
				return (false);
		}
	}
	return (true);	
}

std::ostream	&operator<<(std::ostream &out, const Matrix &mat)
{
	for (int r = 0; r < mat.getSize(); r++)
	{
		for (int c = 0; c < mat.getSize(); c++)
		{
			out << " " << mat.getElement(r, c) << " |";
		}
		out << std::endl;
	}
	return (out);	
}