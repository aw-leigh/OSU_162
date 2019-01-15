/*********************************************************************
** Program name: LetterCounter
** Author: Andrew Wilson
** Date: Jan 15, 2019
** Description: This is the implementation file for the countLetters function.
                It takes an input file stream variable, and a pointer to an array of integers.

                The function first reads the paragraph string from the input file stream, then 
                counts the letter frequencies of that paragraph, and store the frequencies in the array. 
*********************************************************************/
#include <iostream>
#include <string>
#include <fstream>

#include "countLetters.hpp"

void countLetters(std::ifstream& inputFile, int* intArray)
{
    std::string paragraph;
    char letter;

    std::getline(inputFile, paragraph,'\n');  //copy whole paragraph into string
    std::cout << paragraph << std::endl;

    for(int i = 0; i < paragraph.length(); i++)  //loops through each character in paragraph string
    {
        if((tolower(paragraph[i]) - 97) > -1)  //we subtract 97 to get the ASCII offset from 0
                                               // (a - 97) = 0, (k - 97) = 10, etc.
                                               //nonletter characters are negative, and are ignored
        {
            intArray[tolower(paragraph[i]) - 97]++;  //increments the array for each letter                              
        }
    }
}