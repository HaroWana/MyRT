#include "../../includes/tests.hpp"

void	matrix_fill()
{
	try
	{
		MatrixXf mat(4);
		float	**toto = new float*[4];
		for (int i = 0; i < 4; i++)
		{
			toto[i] = new float[4];
			for (int j = 0; j < 4; j++)
			{
				toto[i][j] = static_cast<float>(j);
			}
		}
		
		mat.setMatrix(toto);
		std::cout << mat << std::endl;
		for (int i = 0; i < 4; i++)
		{
			delete [] toto[i];
		}
		delete [] toto;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return ;
	}
}

void	matrix_assign()
{

}

void	matrix_equal()
{

}

void	matrix_mult()
{

}

void	matrix_transpose()
{
	try
	{
		MatrixXf mat(4);
		float	**toto = new float*[4];
		for (int i = 0; i < 4; i++)
		{
			toto[i] = new float[4];
			for (int j = 0; j < 4; j++)
			{
				toto[i][j] = static_cast<float>(j);
			}
		}
		
		mat.setMatrix(toto);
		std::cout << mat << std::endl;
		
		mat.transpose();
		std::cout << std::endl << mat << std::endl;
		for (int i = 0; i < 4; i++)
		{
			delete [] toto[i];
		}
		delete [] toto;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return ;
	}
}

