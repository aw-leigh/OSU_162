/*********************************************************************
** Program name: LetterCounter
** Author: Andrew Wilson
** Date: Jan 15, 2019
** Description: This is the header file for the countLetters function.
                It takes an input file stream variable, and a pointer to an array of integers.
                
                The function first reads the paragraph string from the input file stream, then 
                counts the letter frequencies of that paragraph, and store the frequencies in the array. 
*********************************************************************/

#ifndef LETTERCOUNTER_HPP
#define LETTERCOUNTER_HPP

void countLetters(std::ifstream inputFile, int* intArray[]);

#endif