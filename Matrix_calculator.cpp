
#include <iostream>
#include <iomanip>
using namespace std;
const unsigned MAX_SIZE = 100;

void free(int** matrix, size_t rows)
{
	for (size_t i = 0; i < rows; i++)
		delete[] matrix[i];

	delete[] matrix;
}

int** createMatrix(size_t rows, size_t columns)
{
	int** matrix = new int* [rows];

	for (size_t i = 0; i < rows; i++)
		matrix[i] = new int[columns];
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < columns; j++)
			matrix[i][j] = 0;

	return matrix;
}


void multiplicationOfMatrixWithScalar(int** matrix1, int matrix1Rows, int matrix1Columns, int scalar)
{
	//create matrix
	int** finalMatrix = createMatrix(matrix1Rows, matrix1Columns);

	//multiplying
	for (size_t i = 0; i < matrix1Rows; i++)
		for (size_t y = 0; y < matrix1Columns; y++)
			finalMatrix[i][y] = (matrix1[i][y]) * scalar;


	//printing

	for (int i = 0; i < matrix1Rows / 2; i++)
	{
		cout << "|";
		for (int j = 0; j < matrix1Columns; j++)
			cout << matrix1[i][j] << setw(3);
		cout << "|";
		cout << setw(11);
		cout << "|";
		for (int j = 0; j < matrix1Columns; j++)
			cout << finalMatrix[i][j] << setw(3);
		cout << "|";
		cout << endl;
	}
	cout << '|';
	for (int j = 0; j < matrix1Columns; j++)
	{

		cout << matrix1[matrix1Rows / 2][j] << setw(3);
	}
	cout << "|";
	cout << "  * " << scalar;
	cout << "  =  ";
	cout << "|";
	for (int j = 0; j < matrix1Columns; j++)
	{
		cout << finalMatrix[matrix1Rows / 2][j] << setw(3);
	}
	cout << "|";
	cout << endl;
	for (int i = matrix1Rows / 2 + 1; i < matrix1Rows; i++)
	{
		cout << "|";
		for (int j = 0; j < matrix1Columns; j++)
			cout << matrix1[i][j] << setw(3);
		cout << "|";
		cout << setw(11);
		cout << "|";
		for (int j = 0; j < matrix1Columns; j++)
			cout << finalMatrix[i][j] << setw(3);
		cout << "|";
		cout << endl;
	}

	//free
	free(finalMatrix, matrix1Rows);
}

void multiplicationOfMatrixWithMatrix(int** matrix1, size_t matrix1Rows, size_t matrix1Columns, int** matrix2, size_t matrix2Rows, size_t matrix2Columns)
{
	//is valid?

	if (matrix1Columns != matrix2Rows)
	{
		cout << "Invalid input!";
		return;
	}

	//create matrix
	int** finalMatrix = createMatrix(matrix1Rows, matrix2Columns);

	//multiplication
	for (size_t i = 0; i < matrix1Rows; i++)
		for (size_t y = 0; y < matrix2Columns; y++)
			for (size_t k = 0; k < matrix1Rows; k++)
				finalMatrix[i][y] += matrix1[i][k] * matrix2[k][y];

	//printing
	if (matrix1Rows < matrix2Rows)
	{
		for (int i = 0; i < matrix1Rows / 2; i++)
		{
			cout << "|";
			for (int j = 0; j < matrix1Columns;j++)
			{
				cout << matrix1[i][j] << setw(3);
			}
			cout << "|" << setw(4) << "|";
			for (int j = 0; j < matrix2Columns;j++)
			{
				cout << matrix2[i][j] << setw(3);
			}
			cout << "|" << setw(4) << "|";
			for (int j = 0; j < matrix2Columns;j++)
			{
				cout << finalMatrix[i][j] << setw(8);
			}
			cout << "|" << endl;
		}

		cout << "|";
		for (int j = 0; j < matrix1Columns;j++)
		{
			cout << matrix1[matrix1Rows / 2][j] << setw(3);
		}
		cout << "|" << " * " << "|";
		for (int j = 0; j < matrix1Columns;j++)
		{
			cout << matrix2[matrix1Rows / 2][j] << setw(3);
		}
		cout << "|" << " = " << "|";
		for (int j = 0; j < matrix1Columns;j++)
		{
			cout << finalMatrix[matrix1Rows / 2][j] << setw(8);
		}
		cout << "|" << endl;


		for (int i = matrix1Rows / 2 + 1; i < matrix1Rows; i++)
		{
			cout << "|";
			for (int j = 0; j < matrix1Columns;j++)
			{
				cout << matrix1[i][j] << setw(3);
			}
			cout << "|" << setw(4) << "|";
			for (int j = 0; j < matrix2Columns;j++)
			{
				cout << matrix2[i][j] << setw(3);
			}
			cout << "|" << setw(4) << "|";
			for (int j = 0; j < matrix2Columns;j++)
			{
				cout << finalMatrix[i][j] << setw(8);
			}
			cout << "|" << endl;
		}
		for (int i = matrix1Rows; i < matrix2Rows; i++)
		{
			cout << setw(20) << "|";
			for (int j = 0; j < matrix2Columns; j++)
			{
				cout << matrix2[i][j] << setw(3);
			}
			cout << "|" << endl;
		}
	}
	else
	{
		for (int i = 0; i < matrix2Rows / 2; i++)
		{
			cout << "|";
			for (int j = 0; j < matrix1Columns;j++)
			{
				cout << matrix1[i][j] << setw(3);
			}
			cout << "|" << setw(4) << "|";
			for (int j = 0; j < matrix2Columns;j++)
			{
				cout << matrix2[i][j] << setw(3);
			}
			cout << "|" << setw(4) << "|";
			for (int j = 0; j < matrix2Columns;j++)
			{
				cout << finalMatrix[i][j] << setw(8);
			}
			cout << "|" << endl;
		}

		cout << "|";
		for (int j = 0; j < matrix1Columns;j++)
		{
			cout << matrix1[matrix2Rows / 2][j] << setw(3);
		}
		cout << "|" << " * " << "|";
		for (int j = 0; j < matrix2Columns;j++)
		{
			cout << matrix2[matrix2Rows / 2][j] << setw(3);
		}
		cout << "|" << " = " << "|";
		for (int j = 0; j < matrix2Columns;j++)
		{
			cout << finalMatrix[matrix2Rows / 2][j] << setw(8);
		}
		cout << "|" << endl;


		for (int i = matrix2Rows / 2 + 1; i < matrix2Rows; i++)
		{
			cout << "|";
			for (int j = 0; j < matrix1Columns;j++)
			{
				cout << matrix1[i][j] << setw(3);
			}
			cout << "|" << setw(4) << "|";
			for (int j = 0; j < matrix2Columns;j++)
			{
				cout << matrix2[i][j] << setw(3);
			}
			cout << "|" << setw(4) << "|";
			for (int j = 0; j < matrix2Columns;j++)
			{
				cout << finalMatrix[i][j] << setw(8);
			}
			cout << "|" << endl;
		}
		for (int i = matrix2Rows; i < matrix1Rows; i++)
		{
			cout << "|";
			for (int j = 0; j < matrix1Columns; j++)
			{
				cout << matrix1[i][j] << setw(3);
			}
			cout << "|" << setw(20) << "|";
			for (int j = 0; j < matrix2Columns; j++)
			{
				cout << finalMatrix[i][j] << setw(8);
			}
			cout << "|" << endl;
		}
	}

	//free
	free(finalMatrix, matrix1Rows);
}


int main()
{
	
	int numberOfOperation;

	cout << "Select operation:" << endl;
	cout << "-----------------" << endl;
	cout << "1. Multiplication of matrix with scalar. " << endl;
	cout << "2. Multiplication of matrix with matrix. " << endl;
	cout << "3. Finding the determinant of a matrix up to 4x4. " << endl;
	cout << "4. Division of matrix by scalar. " << endl;
	cout << "5. Find reverse matrix. " << endl;
	cout << "6. Transposing a matrix" << endl;

	
}
