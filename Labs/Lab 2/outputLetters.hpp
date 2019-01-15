/*********************************************************************
** Program name: LetterCounter
** Author: Andrew Wilson
** Date: Jan 15, 2019
** Description: This is the header file for the outputLetters function.
                It takes an output file stream variable, 
                and a pointer to an array of integers that contains frequencies of letters.

                The function first asks user for the filename the user would like to output to, 
                then outputs the frequencies of letters to the output file in the format specified above. 
*********************************************************************/

#ifndef OUTPUTLETTERS_HPP
#define OUTPUTLETTERS_HPP

void outputLetters(std::ofstream outputFile, int* intArray[]);

#endif