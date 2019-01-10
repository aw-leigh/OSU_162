/*********************************************************************
** Author: Andrew Wilson
** Date: Jan 10, 2019
** Description: Prompts user to input integers to fill the matrix in MatrixCalculator
*********************************************************************/
#ifndef READMATRIX_HPP
#define READMATRIX_HPP

void readMatrix(int** matrix, int size); // returns number of items in cart
void validateInput(int &input);  //takes an int by constant reference. Ensures input is an int, reprompting if necessary

#endif