#include <vector>
#include <string>

void readFileIntoVector(std::vector<int> &vector, std::string filename);
void simpleSearch(std::vector<int> &control, std::vector<int> &early, std::vector<int> &middle, std::vector<int> &end);
void sortAndOutput(std::vector<int> &control, std::vector<int> &early, std::vector<int> &middle, std::vector<int> &end);
void writeVectorIntoFile(std::vector<int> &vector, std::string vectorName);
void bubbleSort(std::vector<int> &vector);
void printVectorContents(std::vector<int> const &vector, std::string vectorName);
void binarySearchSetup();
int binarySearch(std::vector<int> searchVector, int l, int r, int x);