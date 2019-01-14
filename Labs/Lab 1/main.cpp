/*********************************************************************
** Program name: MatrixCalculator
** Author: Andrew Wilson
** Date: Jan 10, 2019
** Description: Asks user to select either a 2x2 or 3x3 matrix and the integer values within,
** then displays both the matrix and the determinant
*********************************************************************/
#include <iostream>
#include <iomanip> //setw
#include "readMatrix.hpp"
#include "determinant.hpp"

using std::cin;
using std::cout;
using std::endl;

void validateMainMenuChoice(int &choiceMain);
void printMatrix(int **array_in, int size);
void clearScreen();

int main()
{
    int main_menu_choice = 0;
    int matrix_size = 0;
    
    cout << "Please enter 1 or 2 to select a matrix size" << endl;
    cout << "1. 2x2 matrix" << endl;
    cout << "2. 3x3 matrix" << endl;
    cin >> main_menu_choice;
    validateMainMenuChoice(main_menu_choice);

    matrix_size = main_menu_choice+1; //main menu choice is 1 for 2x2, and 2 for 3x3
                                      //so adding 1 to it gives the side length of chosen matrix

    int**matrix = new int*[matrix_size];  //adpoted from https://www.learncpp.com/cpp-tutorial/6-14-pointers-to-pointers/
    for (int i = 0; i < matrix_size; i++) 
    {
        matrix[i] = new int[matrix_size];
    }

    readMatrix(matrix, matrix_size);

    cout << endl << "Your matrix is:" << endl;
    printMatrix(matrix, matrix_size);

    cout << endl << "The determinant of the matrix is: " << determinant(matrix, matrix_size) << endl;

    for (int i = 0; i < matrix_size; i++)
    {
        delete [] matrix[i];
    }
    delete [] matrix;

    return 0;
}


//Reprompts users for input if choice was not of the "int" datatype, or not 1 or 2
//takes a single int by reference
void validateMainMenuChoice(int &choiceMain)
{
	while (!cin || choiceMain > 2 || choiceMain < 1)
	{
		cin.clear();  //Clear bad input flag
		cin.ignore(1000, '\n');	 //Discard input
		cout << endl << "Please enter 1 or 2 to select a matrix size" << endl;
		cin >> choiceMain;
	}
}

//Prints the square matrix. Takes a 2d dynamically allocated array, and an integer side length.
void printMatrix(int **array_in, int size)
{
    for (int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout << std::setw(3) << array_in[i][j] << " ";
        }
        cout << endl;
    }
}

/*
TODO:

✓ Ask the users to choose the size of the matrix (2x2 or 3x3).
✓ Dynamically allocates the memory space for the matrix, using readMatrix() to prompt the user to enter 4 or 9 integers to fill the matrix
✓ Calculate the determinant using determinant().
✓ Display both the matrix and the determinant to the user.
✓ Free the dynamically allocated memory

*/