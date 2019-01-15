/*********************************************************************
** Program name: LetterCounter
** Author: Andrew Wilson
** Date: Jan 15, 2019
** Description: Your program should first ask for the file the user would like to read, 
**              counts the frequency of letters in each paragraph and outputs the results
**              into user specified named files.
*********************************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include "countLetters.hpp"
#include "outputLetters.hpp"
#include "appendTxt.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    std::ifstream inputFile;    //file stream object for reading file
    std::ofstream outputFile;   //file stream object for writing file
    string fileName;            //Holds the user entered filename
    int letterCount[26] = {0};  //array to hold letter counts, initialized to 0

    cout << "Please enter name of text file to import: ";
    cin >> fileName;
    appendTxt(fileName);  //searches a string for ".txt", and appends it if missing. See appendTxt.cpp
    
    inputFile.open(fileName);
    if (!inputFile)  //Displays an error and exits program if the file isn't openable.
    {
        cout << "Could not access file, check filename and run program again" << endl;
        return 1;
    }

    while(inputFile.good()) //read through to the end of the file
    {
        countLetters(inputFile, letterCount);
        outputLetters(outputFile, letterCount);
    }
    
    inputFile.close();
    return 0;
}


/*
TODO:
✓   First ask for the file the user would like to read
✓       If the program fails to open input file, terminate.
✓    Read the file chosen by the user
✓    continue counting letters until the EOF (end of file) character

✓    For each paragraph in the input file, the program should count the frequency of each letters
✓    ask user what filename to output to
✓    then proceed to output the frequencies to the file
*/