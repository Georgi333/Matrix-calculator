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
* header file
*
*/

#pragma once
#include<iostream>

void freeMatrixesOfFractions(double** matrix, int rows);
double** createMatrixOfFractions(int rows, int columns);
void multiplicationOfMatrixWithScalar();
void multiplicationOfMatrixWithMatrix();
void subMatrix(int** matrix, int** temp, int p, int q, int size);
int determinantOfMatrix(int** matrix, int size);
void findTheDeterminantOfMatrix();
void divisionOfMatrixByScalar();
void findingReverseMatrix();
void transposingMatrix();
