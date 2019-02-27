#include <iostream>
#include <fstream>
#include <algorithm>  //swap

#include "validation.hpp"
#include "appendTXT.hpp"
#include "searchFunctions.hpp"
#include "validation.hpp"

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

void readFileIntoVector(vector<int> &vector, string filename)
{
    std::ifstream inputFile;
    int number;
    string temp;

    inputFile.open(filename);
    if (!inputFile)  //Displays an error if the file isn't openable.
    {
        std::cout << "Could not access file, check filename and try again" << std::endl;
    }
    else
    {
        while(inputFile.good()) //read through to the end of the file
        {
            getline(inputFile, temp, '\n');  //reads number in as a string
            number = stoi(temp);  //converts string to int
            vector.push_back(number);
        }
    }
    inputFile.close();
}

void simpleSearch(vector<int> &control, vector<int> &early, vector<int> &middle, vector<int> &end)
{
    int searchValue;
    bool found = false;

    cout << "Simple Search: Enter an integer value to search for: ";
    searchValue = validateInt();
    cout << endl;

    for (int i=0; i < control.size(); i++){  //search control
        if(control[i] == searchValue){
            found = true;
        }
    }
    if(found == true){
        cout << "control.txt: target value found" << endl;
        found = false;
    }
    else{
        cout << "control.txt: target value not found" << endl;
    }

    for (int i=0; i < early.size(); i++){  //search early
        if(early[i] == searchValue){
            found = true;
        }
    }
    if(found == true){
        cout << "early.txt: target value found" << endl;
        found = false;
    }
    else{
        cout << "early.txt: target value not found" << endl;
    }

    for (int i=0; i < middle.size(); i++){  //search middle
        if(middle[i] == searchValue){
            found = true;
        }
    }
    if(found == true){
        cout << "middle.txt: target value found" << endl;
        found = false;
    }
    else{
        cout << "middle.txt: target value not found" << endl;
    }

    for (int i=0; i < end.size(); i++){  //search end
        if(end[i] == searchValue){
            found = true;
        }
    }
    if(found == true){
        cout << "end.txt: target value found" << endl;
        found = false;
    }
    else{
        cout << "end.txt: target value not found" << endl;
    }   
}

void sortAndOutput(vector<int> &control, vector<int> &early, vector<int> &middle, vector<int> &end)
{
    bubbleSort(control);
    writeVectorIntoFile(control, "control");
    printVectorContents(control, "control");

    bubbleSort(early);
    writeVectorIntoFile(early, "early");
    printVectorContents(early, "early");

    bubbleSort(middle);
    writeVectorIntoFile(middle, "middle");
    printVectorContents(middle, "middle");

    bubbleSort(end);
    writeVectorIntoFile(end, "end");
    printVectorContents(end, "end");
}

void bubbleSort(vector<int> &vector)  //citation: textbook pg. 614
{
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < vector.size() - 1; i++)
        {
            if (vector[i] > vector[i+1])
            {
                std::swap(vector[i], vector[i+1]);
                swapped = true;
            }
        }
    } while (swapped);
}

void printVectorContents(vector<int> const &vector, string vectorName)
{
    cout << "Contents of " << vectorName << ":" << endl;
    for (int i = 0; i < vector.size(); i++)
    {
        cout << ' ' << vector[i];
    }
    cout << endl << endl;
}

void writeVectorIntoFile(vector<int> &vector, string vectorName)
{
    std::ofstream outputFile;
    string outputFileName;

    std::cout << "Please enter name of file to output sorted " << vectorName << ": ";
    cin >> outputFileName;
    appendTXT(outputFileName);

    outputFile.open(outputFileName);
    for(int i = 0; i < vector.size(); i++)
    {
        outputFile  << vector[i];
        if(i < vector.size() - 1)  //this adds a newline after every person except for the last one, which prevents creating empty lines
        {
            outputFile << '\n';
        }
    }
}

void binarySearchSetup()
{
    vector<int> searchVector;
    string filename;
    int searchValue;
    bool found = false;
    int count = 1;

    cout << "Binary Search: Enter an integer value to search for: ";
    searchValue = validateInt();
    cout << endl;

    for(int i = 0; i < 4; i++)
    {
        cout << "Binary Search (" << count << "/4): Enter a file to search: ";
        cin >> filename;
        appendTXT(filename);

        readFileIntoVector(searchVector, filename);

        if(binarySearch(searchVector, 0, searchVector.size(), searchValue) == -1)
        {
            cout << filename << ": target value not found" << endl << endl;
        }
        else
        {
            cout << filename << ": target value found" << endl << endl;
        }
        count++;
        searchVector.clear();
    }
}

int binarySearch(vector<int> searchVector, int left, int right, int searchValue) //https://www.geeksforgeeks.org/binary-search/
{ 
    if (right >= left) { 
        int mid = left + (right - left) / 2; 
  
        // If the element is present at the middle 
        // itself 
        if (searchVector[mid] == searchValue) 
            return mid; 
  
        // If element is smaller than mid, then 
        // it can only be present in left subarray 
        if (searchVector[mid] > searchValue) 
            return binarySearch(searchVector, left, mid - 1, searchValue); 
  
        // Else the element can only be present 
        // in right subarray 
        return binarySearch(searchVector, mid + 1, right, searchValue); 
    } 
  
    // We reach here when element is not 
    // present in array 
    return -1; 
} 