#ifndef PCH_H
#define PCH_H

#include "structs.h";
using namespace std;

// Global vars
unsigned const int g_ArraySize{ 5 };

// Functions
void AccessingElements(int* pArrayToPrint);
void PrintElements(const int* pNumbers, int size);
void PrintElements(const int* pNumbers, int startIdx, int endIdx);
int GetIndex(const int rowIdx, const int colIdx, const int nrCols);
void Print2dArray(const int* pArray2d, const int nrRows, const int nrCols);

#endif
