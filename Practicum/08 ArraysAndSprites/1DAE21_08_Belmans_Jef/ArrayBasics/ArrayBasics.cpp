#include "pch.h"
#include <iostream>

int main()
{
	const int arrayInt01[g_ArraySize]{};
	const int arrayInt02[]{15, 5, 4, 24, 12};
	int arrayInt03[g_ArraySize]{20, 19, 4};

	AccessingElements(arrayInt03);

	#pragma region ArraySize
	const int arraySize{ sizeof(arrayInt02) };
	const int elementSize{ sizeof(arrayInt02[0]) };
	const int nrOfElements{ arraySize / elementSize };

	cout << endl << "-- Size of arrays --" << endl;
	cout << "  nr of bytes: " << arraySize << endl;
	cout << "  size of one element: " << elementSize << endl;
	cout << "  nr of elements: " << nrOfElements << endl;

	for (int i = 0; i < nrOfElements; i++)
	{
		cout << arrayInt02[i] << " ";
	}
	cout << endl;
	#pragma endregion

	#pragma region ArrayMem
	const Point2f arrayPoint2f[g_ArraySize]{};

	cout << "-- The elements occupy consecutive memory locations --" << endl;
	cout << "Array of int types" << endl;

	for (int i = 0; i < g_ArraySize; i++)
	{
		cout << "Address of element with index " << i << " is " << &arrayInt01[i] << endl;
	}

	cout << endl << endl << "Array of Point2f types" << endl;
	for (int i = 0; i < g_ArraySize; i++)
	{
		cout << "Address of element with index " << i << " is " << &arrayPoint2f[i] << endl;
	}
	#pragma endregion

	#pragma region ArayFunctionParam
	cout << endl << "-- Passing an array to a function, PrintElements --" << endl;
	cout << "Print all elements" << endl;
	PrintElements(arrayInt01, g_ArraySize);
	PrintElements(arrayInt02, g_ArraySize);
	PrintElements(arrayInt03, g_ArraySize);

	cout << "Print a range of elements" << endl;
	PrintElements(arrayInt02, 2, 4);
	#pragma endregion

	#pragma region Array2D
	const int nrRows{ 4 };
	const int nrCols{ 5 };
	int array2d[20]{};

	for (int i = 0; i < nrRows; i++)
	{
		for (int y = 0; y < nrCols; y++)
		{
			const int idx{ GetIndex(i, y, nrCols) };
			string value{ to_string(i + 1) + to_string(y + 1) };

			array2d[idx] = stoi(value);
		}
	}

	cout << endl << "-- 2D Arrays --" << endl;
	Print2dArray(array2d, nrRows, nrCols);
	#pragma endregion
}

void AccessingElements(int* pArrayToPrint)
{
	cout << "-- Accessing elements --" << endl;
	cout << "First element: " << pArrayToPrint[0] << endl;
	cout << "Last element: " << pArrayToPrint[g_ArraySize - 1] << endl;

	cout << endl << "Itterating over the elements" << endl;
	for (int i = 0; i < g_ArraySize; i++)
	{
		++pArrayToPrint[i];
		cout << pArrayToPrint[i] << " ";
	}
	cout << endl;
}

void PrintElements(const int* pNumbers, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << pNumbers[i] << " ";
	}
	cout << endl;
}

void PrintElements(const int* pNumbers, int startIdx, int endIdx)
{
	for (int i = startIdx; i <= endIdx; i++)
	{
		cout << pNumbers[i] << " ";
	}
	cout << endl;
}

int GetIndex(const int rowIdx, const int colIdx, const int nrCols)
{
	return (rowIdx * nrCols) + colIdx;
}

void Print2dArray(const int* pArray2d, const int nrRows, const int nrCols)
{
	for (int i = 0; i < nrRows; i++)
	{
		for (int y = 0; y < nrCols; y++)
		{
			cout << pArray2d[GetIndex(i, y, nrCols)] << " ";
		}
		cout << endl;
	}
}
