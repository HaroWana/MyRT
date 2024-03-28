#ifndef MATRIX_HPP
# define MATRIX_HPP

class Matrix
{
	float **matrix;
	int		size;

public:
	Matrix(int size);
	Matrix(int size, float **elements);
	~Matrix();

	float	&getElement(int r, int c) const;
	int		getSize() const;
	int		setElement(int r, int c, float element);
	int		fillMatrix(float **elements);
	int		deleteElement(int r, int c);

	Matrix	&operator=(Matrix const &mat);
	bool	operator==(Matrix const &mat);
	Matrix	operator*(Matrix const &mat);
};

std::ostream    &operator<<(std::ostream &out, const Matrix &mat);

#endif