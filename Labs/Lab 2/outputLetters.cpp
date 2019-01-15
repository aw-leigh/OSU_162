/*********************************************************************
** Program name: LetterCounter
** Author: Andrew Wilson
** Date: Jan 15, 2019
** Description: This is the implementation file for the outputLetters function.
                It takes an output file stream variable, 
                and a pointer to an array of integers that contains frequencies of letters.

                The function first asks user for the filename the user would like to output to, 
                then outputs the frequencies of letters to the output file in the format specified above. 
*********************************************************************/
#include <iostream>
#include <string>
#include <fstream>

#include "outputLetters.hpp"

void outputLetters(std::ofstream& outputFile, int* intArray)
{
    std::string outputFileName;
    
    std::cout << "Please enter your output filename: ";
    std::cin >> outputFileName;

    outputFile.open(outputFileName);
    //need to test how to add txt as needed

    for(int i = 0; i < 26; i++)  //26 because we are couting just the 26 letters
    {
        outputFile << (char)(i+97) << ": " << intArray[i] << std::endl;
    }
    
    outputFile.close();
}