/*********************************************************************
** Program name: LetterCounter
** Author: Andrew Wilson
** Date: Jan 15, 2019
** Description: This is a helper function that searches a string for ".txt".
                If it is not found, it appends it to the end of the string.
*********************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include "appendTxt.hpp"

void appendTxt(std::string &inputString)
{
    //adapted from https://stackoverflow.com/questions/2340281/check-if-a-string-contains-a-string-in-c
    
    if (inputString.find(".txt") == std::string::npos)  //if ".txt" is not found in a string
    {
        inputString = inputString + ".txt";
    }
}