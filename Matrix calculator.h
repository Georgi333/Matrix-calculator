#pragma once
#include<iostream>

void free(int** matrix, int rows);
void freeMatrixesOfFractions(double** matrix, int rows);
int** createMatrixOfIntegers(int rows, int columns);
double** createMatrixOfFractions(int rows, int columns);
void multiplicationOfMatrixWithScalar();
void multiplicationOfMatrixWithMatrix();
void subMatrix(int** matrix, int** temp, int p, int q, int size);
int determinantOfMatrix(int** matrix, int size);
void findTheDeterminantOfMatrix();
void divisionOfMatrixByScalar();
void findingReverseMatrix();
void transposingMatrix();
