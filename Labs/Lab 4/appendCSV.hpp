/*********************************************************************
** Author: Andrew Wilson
** Date: Jan 15, 2019
** Description: This is a helper function that searches a string for ".".
                If it is not found, it appends ".csv" to the end of the string.
*********************************************************************/

#ifndef APPENDCSV_HPP
#define APPENDCSV_HPP

#include <iostream>
#include <string>
#include <fstream>

void appendCSV(std::string &inputString);

#endif