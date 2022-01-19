#include"Matrix calculator.h"
#include <iostream>
using namespace std;
#include<iomanip>


void freeMatrixesOfFractions(double** matrix, int rows)
{
	for (int i = 0; i < rows; i++)
		delete[] matrix[i];

	delete[] matrix;
}


double** createMatrixOfFractions(int rows, int columns)
{
	double** matrix = new double* [rows];

	for (int i = 0; i < rows; i++)
		matrix[i] = new double[columns];
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			matrix[i][j] = 0;

	return matrix;
}

void multiplicationOfMatrixWithScalar()
{
	int rows;
	int columns;
	double scalar;

	//create matrix
	cout << "Count of rows = ";
	cin >> rows;
	cout << "Count of columns = ";
	cin >> columns;

	//validation
	if (rows < 1 || columns < 1)
	{
		cout << "Invalid imput";
		return;
	}

	double** matrix = createMatrixOfFractions(rows, columns);
	cout << "Input a matrix:" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cin >> matrix[i][j];
		}
	}
	cout << "Scalar = ";
	cin >> scalar;

	double** finalMatrix = createMatrixOfFractions(rows, columns);

	//multiplying
	for (int i = 0; i < rows; i++)
		for (int y = 0; y < columns; y++)
			finalMatrix[i][y] = (matrix[i][y]) * scalar;


	//printing

	cout << endl;

	int half = rows / 2;
	if (rows % 2 == 0)
		half -= 1;

	for (int i = 0; i < half; i++)
	{
		cout << "|";
		for (int j = 0; j < columns; j++)
			cout << setw(3) << matrix[i][j];
		cout << "|";
		cout << setw(11);
		cout << "|";
		for (int j = 0; j < columns; j++)
			cout << setw(3) << finalMatrix[i][j];
		cout << "|";
		cout << endl;
	}
	cout << '|';
	for (int j = 0; j < columns; j++)
	{

		cout << setw(3) << matrix[rows / 2][j];
	}
	cout << "|";
	cout << "  * " << scalar;
	cout << "  =  ";
	cout << "|";
	for (int j = 0; j < columns; j++)
	{
		cout << setw(3) << finalMatrix[rows / 2][j];
	}
	cout << "|";
	cout << endl;
	for (int i = half + 1; i < rows; i++)
	{
		cout << "|";
		for (int j = 0; j < columns; j++)
			cout << setw(3) << matrix[i][j];
		cout << "|";
		cout << setw(11);
		cout << "|";
		for (int j = 0; j < columns; j++)
			cout << setw(3) << finalMatrix[i][j];
		cout << "|";
		cout << endl;
	}

	//free
	freeMatrixesOfFractions(finalMatrix, rows);
	freeMatrixesOfFractions(matrix, rows);
}

void multiplicationOfMatrixWithMatrix()
{
	int matrix1Rows;
	int matrix1Columns;

	cout << "Rows of the first matrix : ";
	cin >> matrix1Rows;
	cout << "Columns of the first matrix : ";
	cin >> matrix1Columns;

	double** matrix1 = createMatrixOfFractions(matrix1Rows, matrix1Columns);

	cout << "Input the first matrix" << endl;

	for (int i = 0; i < matrix1Rows; i++)
	{
		for (int j = 0; j < matrix1Columns; j++)
		{
			cin >> matrix1[i][j];
		}
	}

	int matrix2Rows;
	int matrix2Columns;

	cout << "Rows of the second matrix : ";
	cin >> matrix2Rows;
	cout << "Columns of the second matrix : ";
	cin >> matrix2Columns;

	//is valid?
	if (matrix1Columns != matrix2Rows || matrix1Columns < 1 || matrix1Rows < 1 || matrix2Rows < 1)
	{
		cout << "Invalid input!";
		return;
	}

	double** matrix2 = createMatrixOfFractions(matrix2Rows, matrix2Columns);

	cout << "Input the second matrix" << endl;

	for (int i = 0; i < matrix2Rows; i++)
	{
		for (int j = 0; j < matrix2Columns; j++)
		{
			cin >> matrix2[i][j];
		}
	}

	//create matrix
	double** finalMatrix = createMatrixOfFractions(matrix1Rows, matrix2Columns);

	//multiplication
	for (int i = 0; i < matrix1Rows; i++)
		for (int y = 0; y < matrix2Columns; y++)
			for (int k = 0; k < matrix1Columns; k++)
				finalMatrix[i][y] += matrix1[i][k] * matrix2[k][y];

	//printing

	if (matrix1Rows < matrix2Rows)
	{
		int half = matrix1Rows / 2;
		if (matrix1Rows % 2 == 0)
			half--;

		for (int i = 0; i < half; i++)
		{
			cout << "|";
			for (int j = 0; j < matrix1Columns;j++)
			{
				cout << setw(3) << matrix1[i][j];
			}
			cout << "|" << setw(4) << "|";
			for (int j = 0; j < matrix2Columns;j++)
			{
				cout << setw(3) << matrix2[i][j];
			}
			cout << "|" << setw(4) << "|";
			for (int j = 0; j < matrix2Columns;j++)
			{
				cout << setw(8) << finalMatrix[i][j];
			}
			cout << "|" << endl;
		}

		cout << "|";
		for (int j = 0; j < matrix1Columns;j++)
		{
			cout << setw(3) << matrix1[half][j];
		}
		cout << "|" << " * " << "|";
		for (int j = 0; j < matrix2Columns;j++)
		{
			cout << setw(3) << matrix2[half][j];
		}
		cout << "|" << " = " << "|";
		for (int j = 0; j < matrix2Columns;j++)
		{
			cout << setw(8) << finalMatrix[half][j];
		}
		cout << "|" << endl;


		for (int i = half + 1; i < matrix1Rows; i++)
		{
			cout << "|";
			for (int j = 0; j < matrix1Columns;j++)
			{
				cout << setw(3) << matrix1[i][j];
			}
			cout << "|" << setw(4) << "|";
			for (int j = 0; j < matrix2Columns;j++)
			{
				cout << setw(3) << matrix2[i][j];
			}
			cout << "|" << setw(4) << "|";
			for (int j = 0; j < matrix2Columns;j++)
			{
				cout << setw(8) << finalMatrix[i][j];
			}
			cout << "|" << endl;
		}

		for (int i = matrix1Rows; i < matrix2Rows; i++)
		{
			cout << setw(3 * matrix1Columns + 6) << "|";
			for (int j = 0; j < matrix2Columns; j++)
			{
				cout << setw(3) << matrix2[i][j];
			}
			cout << "|" << endl;
		}
	}
	else
	{
		int half = matrix2Rows / 2;
		if (matrix1Rows % 2 == 0)
			half--;
		for (int i = 0; i < half; i++)
		{
			cout << "|";
			for (int j = 0; j < matrix1Columns;j++)
			{
				cout << setw(3) << matrix1[i][j];
			}
			cout << "|" << setw(4) << "|";
			for (int j = 0; j < matrix2Columns;j++)
			{
				cout << setw(3) << matrix2[i][j];
			}
			cout << "|" << setw(4) << "|";
			for (int j = 0; j < matrix2Columns;j++)
			{
				cout << setw(8) << finalMatrix[i][j];
			}
			cout << "|" << endl;
		}

		cout << "|";
		for (int j = 0; j < matrix1Columns;j++)
		{
			cout << setw(3) << matrix1[half][j];
		}
		cout << "|" << " * " << "|";
		for (int j = 0; j < matrix2Columns;j++)
		{
			cout << setw(3) << matrix2[half][j];
		}
		cout << "|" << " = " << "|";
		for (int j = 0; j < matrix2Columns;j++)
		{
			cout << setw(8) << finalMatrix[half][j];
		}
		cout << "|" << endl;


		for (int i = half + 1; i < matrix2Rows; i++)
		{
			cout << "|";
			for (int j = 0; j < matrix1Columns;j++)
			{
				cout << setw(3) << matrix1[i][j];
			}
			cout << "|" << setw(4) << "|";
			for (int j = 0; j < matrix2Columns;j++)
			{
				cout << setw(3) << matrix2[i][j];
			}
			cout << "|" << setw(4) << "|";
			for (int j = 0; j < matrix2Columns;j++)
			{
				cout << setw(8) << finalMatrix[i][j];
			}
			cout << "|" << endl;
		}
		for (int i = matrix2Rows; i < matrix1Rows; i++)
		{
			cout << "|";
			for (int j = 0; j < matrix1Columns; j++)
			{
				cout << setw(3) << matrix1[i][j];
			}
			cout << "|" << setw(3 * matrix2Columns + 9) << "|";
			for (int j = 0; j < matrix2Columns; j++)
			{
				cout << setw(8) << finalMatrix[i][j];
			}
			cout << "|" << endl;
		}
	}


	//free
	freeMatrixesOfFractions(finalMatrix, matrix1Rows);
	freeMatrixesOfFractions(matrix1, matrix1Rows);
	freeMatrixesOfFractions(matrix2, matrix2Rows);
}

void subMatrix(double** matrix, double** temp, int p, int q, int size)
{
	int i = 0, j = 0;
	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++)
		{
			if (row != p && col != q)
			{
				temp[i][j++] = matrix[row][col];
				if (j == size - 1)
				{
					j = 0;
					i++;
				}
			}
		}
	}
}

double determinantOfMatrix(double** matrix, int size)
{
	double determinant = 0;
	if (size == 1)
	{
		return matrix[0][0];
	}
	if (size == 2)
	{
		return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	}
	double** temp = createMatrixOfFractions(size - 1, size - 1);
	int sign = 1;
	for (int i = 0; i < size; i++)
	{
		subMatrix(matrix, temp, 0, i, size);
		determinant += sign * matrix[0][i] * determinantOfMatrix(temp, size - 1);
		sign = -sign;
	}

	freeMatrixesOfFractions(temp, size - 1);

	return determinant;
}

void findTheDeterminantOfMatrix()
{
	int rows;
	int columns;

	cout << "Count of rows = ";
	cin >> rows;
	cout << "Count of columns = ";
	cin >> columns;

	// validation
	if (rows != columns || rows > 4 || rows < 1)
	{
		cout << "Invalid imput!";
		return;
	}

	double** matrix = createMatrixOfFractions(rows, columns);
	cout << "Input a matrix:" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cin >> matrix[i][j];
		}
	}

	//calculation
	double result = determinantOfMatrix(matrix, rows);

	//print
	int half = rows / 2;
	if (rows % 2 == 0)
		half--;

	for (int i = 0; i < half; i++)
	{
		cout << setw(5) << '|';
		for (int j = 0; j < columns; j++)
		{
			cout << setw(3) << matrix[i][j];
		}
		cout << '|' << endl;
	}
	cout << "det " << '|';
	for (int j = 0; j < columns; j++)
	{
		cout << setw(3) << matrix[half][j];
	}
	cout << '|' << '=' << result << endl;
	for (int i = half + 1; i < rows; i++)
	{
		cout << setw(5) << '|';
		for (int j = 0; j < columns; j++)
		{
			cout << setw(3) << matrix[i][j];
		}
		cout << '|' << endl;
	}

	//free
	freeMatrixesOfFractions(matrix, rows);
}

void divisionOfMatrixByScalar()
{
	int rows;
	int columns;
	double scalar;

	//create matrix
	cout << "Count of rows = ";
	cin >> rows;

	cout << "Count of columns = ";
	cin >> columns;

	//validation
	if (rows < 1 || columns < 1)
	{
		cout << "Invalid input";
		return;
	}

	double** matrix = createMatrixOfFractions(rows, columns);
	cout << "Input a matrix:" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cin >> matrix[i][j];
		}
	}
	cout << "Scalar = ";
	cin >> scalar;
	if (scalar == 0)
	{
		cout << "Can't divide by zero";
		return;
	}

	double** finalMatrix = createMatrixOfFractions(rows, columns);

	//dividing
	for (int i = 0; i < rows; i++)
		for (int y = 0; y < columns; y++)
			finalMatrix[i][y] = round((matrix[i][y] / scalar) * 100) / 100.0;


	//printing
	int half = rows / 2;
	if (rows % 2 == 0)
		half--;

	for (int i = 0; i < half; i++)
	{
		cout << "|";
		for (int j = 0; j < columns; j++)
			cout << setw(3) << matrix[i][j];
		cout << "|";
		cout << setw(11);
		cout << "|";
		for (int j = 0; j < columns; j++)
			cout << setw(5) << finalMatrix[i][j];
		cout << "|";
		cout << endl;
	}
	cout << '|';
	for (int j = 0; j < columns; j++)
	{
		cout << setw(3) << matrix[half][j];
	}
	cout << "|";
	cout << "   /" << scalar;
	cout << "  =  ";
	cout << "|";
	for (int j = 0; j < columns; j++)
	{
		cout << setw(5) << finalMatrix[half][j];
	}
	cout << "|";
	cout << endl;
	for (int i = half + 1; i < rows; i++)
	{
		cout << "|";
		for (int j = 0; j < columns; j++)
			cout << setw(3) << matrix[i][j];
		cout << "|";
		cout << setw(11);
		cout << "|";
		for (int j = 0; j < columns; j++)
			cout << setw(5) << finalMatrix[i][j];
		cout << "|";
		cout << endl;
	}

	//free
	freeMatrixesOfFractions(finalMatrix, rows);
	freeMatrixesOfFractions(matrix, rows);
}

double** transposeMatrix(double** matrix, int rows, int columns)
{
	double** newMatrix = createMatrixOfFractions(columns, rows);
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			newMatrix[i][j] = matrix[j][i];
		}
	}
	return newMatrix;
}

void findingReverseMatrix()
{

	int rows;
	int columns;

	//create matrix
	cout << "Count of rows = ";
	cin >> rows;
	cout << "Count of columns = ";
	cin >> columns;

	//validation
	if (rows != columns || rows < 1)
	{
		cout << "Invalid input!";
		return;
	}

	double** matrix = createMatrixOfFractions(rows, columns);
	cout << "Input a matrix:" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cin >> matrix[i][j];
		}
	}


	double determinant = determinantOfMatrix(matrix, rows);
	if (determinant == 0)
	{
		cout << "Irreversible matrix!";
		return;
	}
	//reversing
	double** newMatrix = createMatrixOfFractions(rows, columns);
	if (rows == 1)
		newMatrix[0][0] = round(100 / matrix[0][0]) / 100;
	else
	{
		double** temp = createMatrixOfFractions(rows - 1, columns - 1);
		int sign;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				subMatrix(matrix, temp, j, i, rows);

				double determinantOfTemp = determinantOfMatrix(temp, rows - 1);
				if ((i + j) % 2 == 0)
					sign = 1;
				else
					sign = -1;
				newMatrix[i][j] = sign * round(determinantOfTemp / determinant * 100) / 100;

			}
		}
		freeMatrixesOfFractions(temp, rows - 1);

	}

	//print
	if (rows == 1)
	{
		cout << '|' << setw(3) << matrix[0][0] << '|' << "-1 = |" << setw(3) << newMatrix[0][0] << '|';
		return;
	}

	cout << '|';
	for (int j = 0; j < columns; j++)
	{
		cout << setw(3) << matrix[0][j];
	}
	cout << '|' << "-1" << setw(5) << '|';
	for (int j = 0; j < columns; j++)
	{
		cout << setw(6) << newMatrix[0][j];
	}
	cout << '|' << endl;
	int half = rows / 2;
	if (rows % 2 == 0 && rows != 2)
		half--;
	for (int i = 1; i < half; i++)
	{
		cout << '|';
		for (int j = 0; j < columns; j++)
		{
			cout << setw(3) << matrix[i][j];
		}
		cout << '|' << setw(7) << '|';
		for (int j = 0; j < columns; j++)
		{
			cout << setw(6) << newMatrix[i][j];
		}
		cout << '|' << endl;
	}
	cout << '|';
	for (int j = 0; j < columns; j++)
	{
		cout << setw(3) << matrix[half][j];
	}
	cout << '|' << "   =  " << '|';
	for (int j = 0; j < columns; j++)
	{
		cout << setw(6) << newMatrix[half][j];
	}
	cout << '|' << endl;
	for (int i = half + 1; i < rows; i++)
	{
		cout << '|';
		for (int j = 0; j < columns; j++)
		{
			cout << setw(3) << matrix[i][j];
		}
		cout << '|' << setw(7) << '|';
		for (int j = 0; j < columns; j++)
		{
			cout << setw(6) << newMatrix[i][j];
		}
		cout << '|' << endl;
	}
	freeMatrixesOfFractions(matrix, rows);

	freeMatrixesOfFractions(newMatrix, rows);
}

void transposingMatrix()
{
	int rows;
	int columns;

	//create matrix
	cout << "Count of rows = ";
	cin >> rows;
	cout << "Count of columns = ";
	cin >> columns;

	//validation
	if (rows < 1 || columns < 1)
	{
		cout << "Invalid imput";
		return;
	}

	double** matrix = createMatrixOfFractions(rows, columns);
	cout << "Input a matrix:" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cin >> matrix[i][j];
		}
	}

	//transposing
	double** newMatrix = transposeMatrix(matrix, rows, columns);

	//print

	if (rows == 1)
	{
		cout << '|';
		for (int i = 0; i < columns; i++)
		{
			cout << setw(3) << matrix[0][i];
		}
		cout << '|' << 't' << " = " << '|' << setw(3) << newMatrix[0][0] << '|' << endl;
		for (int i = 1; i < columns; i++)
			cout << setw(7 + 3 * columns) << '|' << setw(3) << newMatrix[i][0] << '|' << endl;
		return;
	}

	if (rows > columns)
	{
		cout << '|';
		for (int j = 0; j < columns; j++)
		{
			cout << setw(3) << matrix[0][j];
		}
		cout << '|' << 't' << setw(6) << '|';
		for (int j = 0; j < rows; j++)
		{
			cout << setw(3) << newMatrix[0][j];
		}
		cout << '|' << endl;
		int half = columns / 2;
		if (columns % 2 == 0 && columns != 2)
		{
			half--;
		}
		for (int i = 1; i < half; i++)
		{
			cout << '|';
			for (int j = 0; j < columns; j++)
			{
				cout << setw(3) << matrix[i][j];
			}
			cout << '|' << setw(6) << '|';
			for (int j = 0; j < rows; j++)
			{
				cout << setw(3) << newMatrix[i][j];
			}
			cout << '|' << endl;
		}
		cout << '|';
		for (int j = 0; j < columns; j++)
		{
			cout << setw(3) << matrix[half][j];
		}
		cout << '|' << "   =  " << '|';
		for (int j = 0; j < rows; j++)
		{
			cout << setw(3) << newMatrix[half][j];
		}
		cout << '|' << endl;

		for (int i = half + 1; i < columns; i++)
		{
			cout << '|';
			for (int j = 0; j < columns; j++)
			{
				cout << setw(3) << matrix[i][j];
			}
			cout << '|' << setw(6) << '|';
			for (int j = 0; j < rows; j++)
			{
				cout << setw(3) << newMatrix[i][j];
			}
			cout << '|' << endl;
		}

		for (int i = columns; i < rows; i++)
		{
			cout << '|';
			for (int j = 0; j < columns; j++)
			{
				cout << setw(3) << matrix[i][j];
			}
			cout << '|' << endl;
		}

	}
	else
	{
		cout << '|';
		for (int j = 0; j < columns; j++)
		{
			cout << setw(3) << matrix[0][j];
		}
		cout << '|' << 't' << setw(6) << '|';
		for (int j = 0; j < rows; j++)
		{
			cout << setw(3) << newMatrix[0][j];
		}
		cout << '|' << endl;
		int half = rows / 2;
		if (rows % 2 == 0 && rows != 2)
		{
			half--;
		}
		for (int i = 1; i < half; i++)
		{
			cout << '|';
			for (int j = 0; j < columns; j++)
			{
				cout << setw(3) << matrix[i][j];
			}
			cout << '|' << setw(6) << '|';
			for (int j = 0; j < rows; j++)
			{
				cout << setw(3) << newMatrix[i][j];
			}
			cout << '|' << endl;
		}
		cout << '|';
		for (int j = 0; j < columns; j++)
		{
			cout << setw(3) << matrix[half][j];
		}
		cout << '|' << "   =  " << '|';
		for (int j = 0; j < rows; j++)
		{
			cout << setw(3) << newMatrix[half][j];
		}
		cout << '|' << endl;
		for (int i = half + 1; i < columns; i++)
		{
			cout << setw(3 * columns + 9) << '|';
			for (int j = 0; j < rows; j++)
			{
				cout << setw(3) << newMatrix[i][j];
			}
			cout << '|' << endl;
		}
	}

	freeMatrixesOfFractions(matrix, rows);
	freeMatrixesOfFractions(newMatrix, columns);
}