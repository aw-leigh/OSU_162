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

int readFileIntoArray(int * &array, string filename)
{
    std::ifstream inputFile;
    string tempString;
    string tempChar;
    int number;
    

    inputFile.open(filename);
    while(!inputFile.is_open())
    {
        std::cout << "Error. Please reenter filename: ";
        std::cin >> filename;
        appendTXT(filename);
        std::cin.ignore();
        inputFile.open(filename);
    }
    
    while(inputFile.good())
    {
        std::getline(inputFile, tempString);  //copy whole file into string
    }

    std::string::iterator end_pos = std::remove(tempString.begin(), tempString.end(), ' ');
    tempString.erase(end_pos, tempString.end());  //remove spaces from string. Reference: https://stackoverflow.com/a/83481
    array = new int[tempString.size()];  //creates new array the size of the string

    for (int i = 0; i < tempString.size(); i++)
    {
        tempChar = tempString[i];
        array[i] = stoi(tempChar);
    }
    inputFile.close();

    return tempString.size();
}

void simpleSearch(int * &array, string filename, int arrayLength, int searchValue)
{
    bool found = false;

    for (int i=0; i < arrayLength; i++){  //search
        if(array[i] == searchValue){
            found = true;
        }
    }
    if(found == true){
        cout << filename << ".txt: target value found" << endl;
    }
    else{
        cout << filename << ".txt: target value not found" << endl;
    }
}

void sortAndOutput(int * &array, string arrayName, int arrayLength)
{
    bubbleSort(array, arrayLength);
    writeArrayToFile(array, arrayName, arrayLength);
    printArrayContents(array, arrayName, arrayLength);
}

void bubbleSort(int * &array, int arrayLength)  //citation: textbook pg. 614
{
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < arrayLength - 1; i++)
        {
            if (array[i] > array[i+1])
            {
                std::swap(array[i], array[i+1]);
                swapped = true;
            }
        }
    } while (swapped);
}

void printArrayContents(int * const &array, string arrayName, int arrayLength)
{
    cout << "Contents of " << arrayName << ":" << endl;
    for (int i = 0; i < arrayLength; i++)
    {
        cout << ' ' << array[i];
    }
    cout << endl << endl;
}

void writeArrayToFile(int * const &array, std::string arrayName, int arrayLength)
{
    std::ofstream outputFile;
    string outputFileName;

    std::cout << "Please enter name of file to output sorted " << arrayName << ": ";
    cin >> outputFileName;
    appendTXT(outputFileName);

    outputFile.open(outputFileName);
    for(int i = 0; i < arrayLength; i++)
    {
        outputFile  << array[i];
        if(i < arrayLength - 1)  //this adds a newline after every person except for the last one, which prevents creating empty lines
        {
            outputFile << ' ';
        }
    }
}

void binarySearchSetup()
{
    std::ifstream inputFile;
    int * tempArray;
    int tempArrayLength = 0;
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

        inputFile.open(filename);
	
        //test if file can't open, get different file if so
        while(!inputFile.is_open())
        {
            std::cout << "Error. Please reenter filename: ";
            std::cin >> filename;
            appendTXT(filename);
            std::cin.ignore();
            inputFile.open(filename);
	    }

        tempArrayLength = readFileIntoArray(tempArray, filename);

        if(binarySearch(tempArray, 0, tempArrayLength, searchValue) == -1)
        {
            cout << filename << ": target value not found" << endl << endl;
        }
        else
        {
            cout << filename << ": target value found" << endl << endl;
        }
        count++;
        inputFile.close();
        delete [] tempArray;
    }
}

int binarySearch(int * &array, int left, int right, int searchValue) //https://www.geeksforgeeks.org/binary-search/
{ 
    if (right >= left) { 
        int mid = left + (right - left) / 2; 
  
        // If the element is present at the middle 
        // itself 
        if (array[mid] == searchValue) 
            return mid; 
  
        // If element is smaller than mid, then 
        // it can only be present in left subarray 
        if (array[mid] > searchValue) 
            return binarySearch(array, left, mid - 1, searchValue); 
  
        // Else the element can only be present 
        // in right subarray 
        return binarySearch(array, mid + 1, right, searchValue); 
    } 
  
    // We reach here when element is not 
    // present in array 
    return -1; 
} 