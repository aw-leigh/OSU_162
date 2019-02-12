/*********************************************************************
** Author: Andrew Wilson
** Date: Jan 15, 2019
** Description: Implementation file for recursive functions:
                reverseString takes a standard string and prints the reversed string to the console.
                sumArray takes a pointer to an integer array and an int array length, and returns the sum of the array elements
                triangleNum takes an int and returns the triangular number as an int.
*********************************************************************/
#include <iostream>
#include "recursiveFunctions.hpp"

/*
// Takes a string argument.
// Recursively prints a string in reverse, followed by a newline character.
// Example: Input of “Hello, world” should output “dlrow ,olleH(newline)”.
*/
void reverseString(std::string stringIn)
{
    int counter = stringIn.size();

    if(counter == 0)
    {
        std::cout << "\n";
    }
    else
    {
        std::cout << stringIn[counter - 1];
        reverseString(stringIn.substr(0, counter - 1));
    }
}

/*
// Takes a pointer to an integer array and an int array length, and returns the sum of the array elements
*/
int sumArray(int * intArray, int arrayLength)
{
    if(arrayLength == 0)
    {
        return 0;
    }
    else
    {
        return intArray[arrayLength - 1] + sumArray(intArray, arrayLength - 1);
    }
}

/*
// Takes an int and returns the triangular number as an int.
*/
int triangleNum(int intIn)
{
    if(intIn == 0)
    {
        return 0;
    }
    else
    {
        return intIn + triangleNum(intIn - 1);
    }
}