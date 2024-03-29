#ifndef MATRIX_HPP
# define MATRIX_HPP

struct Matrix
{
	int		size;
	float	**matrix;
};


class MatrixXf
{
	Matrix	primary;
	float	**transfo;

public:
	MatrixXf(int size);
	MatrixXf(int size, float **elements);
	~MatrixXf();

	float	**getMatrix() const;
	float	**getTransformation() const;
	float	&getElement(int r, int c) const;
	int		getSize() const;
	void	setElement(int r, int c, float element);
	void	setMatrix(float **elements);
	void	deleteElement(int r, int c);

	MatrixXf	&operator=(MatrixXf const &mat);
	bool	operator==(MatrixXf const &mat);
	MatrixXf	operator*(MatrixXf const &mat);
	MatrixXf	operator*(Tuple const &tup);

	class M_WrongSizeException: public std::exception {
		public:
		virtual const char	*what() const throw()
		{
			return ("Matrix is the wrong size (operation is impossible)");
		}
	};

	class M_OutOfBoundsException: public std::exception {
		public:
		virtual const char	*what() const throw()
		{
			return ("You are trying to operate outside the bounds of this matrix");
		}
	};
};

std::ostream    &operator<<(std::ostream &out, const MatrixXf &mat);

#endif