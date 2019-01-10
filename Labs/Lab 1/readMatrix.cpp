/*********************************************************************
** Author: Andrew Wilson
** Date: Jan 10, 2019
** Description: Prompts user to input integers to fill the matrix in MatrixCalculator
*********************************************************************/
#include <iostream>
#include "readMatrix.hpp"

void readMatrix(int** matrix, int size)
{
    int input = 0;

    std::cout << "Please enter " << size*size << " integers, pressing Enter after each." << std::endl;
    
    for (int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            std::cin >> input;
            validateInput(input);
            matrix[i][j] = input;
        }
    }
}


void validateInput(int &input)
{
	while (!std::cin)
	{
		std::cin.clear();  //Clear bad input flag
		std::cin.ignore(1000, '\n');  //Discard input
		std::cout << std::endl << "Input must be an integer" << std::endl;
		std::cin >> input;
	}
}