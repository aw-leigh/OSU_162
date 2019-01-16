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
#include "appendTxt.hpp"

void outputLetters(std::ofstream& outputFile, int* intArray)
{
    std::string outputFileName;
    
    std::cout << "Please enter name of text file to output: ";
    std::cin >> outputFileName;
    appendTxt(outputFileName);  //searches a string for ".", and if not found appends ".txt". See appendTxt.cpp

    outputFile.open(outputFileName);
    //need to test how to add txt as needed

    for(int i = 0; i < 26; i++)  //26 because we are couting just the 26 letters
    {
        outputFile << (char)(i+97) << ": " << intArray[i] << std::endl; //cast i+97 to lowercase letters
                                                                        //0+97 = 97 = a, 1+97 = 98 = b, etc.
    }
    
    outputFile.close();
}