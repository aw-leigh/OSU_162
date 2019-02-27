/*********************************************************************
** Author: Andrew Wilson
** Date: Jan 15, 2019
** Description: This is a helper function that searches a string for ".".
                If it is not found, it appends ".txt" to the end of the string.
*********************************************************************/

#ifndef APPENDTXT_HPP
#define APPENDTXT_HPP

#include <iostream>
#include <string>
#include <fstream>

void appendTXT(std::string &inputString);

#endif