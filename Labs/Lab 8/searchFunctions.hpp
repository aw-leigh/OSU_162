#include <vector>
#include <string>

int readFileIntoArray(int * &array, std::string filename);
void simpleSearch(int * &array, std::string filename, int arrayLength, int searchValue);
void sortAndOutput(int * &array, std::string arrayName, int arrayLength);
void writeArrayToFile(int * const &array, std::string arrayName, int arrayLength);
void bubbleSort(int * &array, int arrayLength);
void printArrayContents(int * const &array, std::string arrayName, int arrayLength);
void binarySearchSetup();
int binarySearch(int * &array, int left, int right, int searchValue);