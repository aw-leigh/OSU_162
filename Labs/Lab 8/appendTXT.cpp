/*********************************************************************
** Author: Andrew Wilson
** Date: Jan 15, 2019
** Description: This function takes a string by reference.
                It searches the string for ".", and
                if it is not found, it appends ".csv" to the end of the string.
*********************************************************************/
#include "appendTXT.hpp"

void appendTXT(std::string &inputString)
{
    //adapted from https://stackoverflow.com/questions/2340281/check-if-a-string-contains-a-string-in-c
    
    if (inputString.find(".") == std::string::npos)  //if "." is not found in a string
    {
        inputString = inputString + ".txt";
    }
}