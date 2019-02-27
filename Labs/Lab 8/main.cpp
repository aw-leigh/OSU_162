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
    vector<int> control;
    vector<int> early;
    vector<int> middle;
    vector<int> end;

    clearScreen();

    readFileIntoVector(control, "control.txt");
    readFileIntoVector(early, "early.txt");
    readFileIntoVector(middle, "middle.txt");
    readFileIntoVector(end, "end.txt");

    simpleSearch(control, early, middle, end);

    cout << endl;
    systemPause();
    clearScreen();

    sortAndOutput(control, early, middle, end);

    systemPause();
    clearScreen();

    binarySearchSetup();

    return 0;
}