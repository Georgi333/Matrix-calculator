/**
*
* Solution to course project # 11
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Georgi Georgiev
* @idnumber 6MI0600059
* @compiler VC
*
* main file
*
*/


#include <iostream>
using namespace std;
#include "Matrix calculator.h"

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
	cout << endl << "Choose an operation : ";

	cin >> numberOfOperation;



	switch (numberOfOperation)
	{
	case 1: multiplicationOfMatrixWithScalar(); break;
	case 2: multiplicationOfMatrixWithMatrix(); break;
	case 3: findTheDeterminantOfMatrix(); break;
	case 4: divisionOfMatrixByScalar(); break;
	case 5: findingReverseMatrix(); break;
	case 6: transposingMatrix(); break;
	default: cout << "Invalid input"; break;
	}
}
