#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>  //swap
#include "validation.hpp"
#include "appendTXT.hpp"
#include "searchFunctions.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;


int main()
{
    int * control;
    int * early;
    int * middle;
    int * end;

    int controlSize, earlySize, middleSize, endSize;

    clearScreen();

    controlSize = readFileIntoArray(control, "control.txt");
    earlySize = readFileIntoArray(early, "early.txt");
    middleSize = readFileIntoArray(middle, "middle.txt");
    endSize = readFileIntoArray(end, "end.txt");

    cout << "Simple Search: Enter an integer value to search for: ";
    int searchValue = validateInt();
    cout << endl;

    simpleSearch(control, "control", controlSize, searchValue);
    simpleSearch(early, "early", earlySize, searchValue);
    simpleSearch(middle, "middle", middleSize, searchValue);
    simpleSearch(end, "end", endSize, searchValue);

    cout << endl;
    systemPause();
    clearScreen();

    sortAndOutput(control, "control", controlSize);
    sortAndOutput(early, "early", earlySize);
    sortAndOutput(middle, "middle", middleSize);
    sortAndOutput(end, "end", endSize);

    systemPause();
    clearScreen();

    binarySearchSetup();

    delete [] control;
    delete [] early;
    delete [] middle;
    delete [] end;

    return 0;
}