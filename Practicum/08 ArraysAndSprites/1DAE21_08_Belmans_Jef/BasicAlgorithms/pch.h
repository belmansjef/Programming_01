#ifndef PCH_H
#define PCH_H
using namespace std;

int Count(const int* pArray, const int size, const int valueToCompare);
int MinElement(const int* pArray, const int size);
int MaxElement(const int* pArray, const int size);
void Swap(int* pArray, const int size, const int idx1, const int idx2);
void Shuffle(int* pArray, const int size, const int nrShuffles);
void BubbleSort(int* pArray, int size, bool sortAscending = true);

int GetRand(int min, int max);
void InitializeArray(int* pArrayToInit, const int size );
void PrintArray(const int* pArrayToPrint, const int size);
#endif
