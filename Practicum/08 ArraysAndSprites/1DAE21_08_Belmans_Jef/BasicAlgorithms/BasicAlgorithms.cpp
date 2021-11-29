#include "pch.h"
#include <iostream>

int main()
{
    srand(unsigned int(time(nullptr)));
    
    #pragma region Count
    
    cout << "-- Test of count function --" << endl;
    #pragma endregion

}

int Count(const int* pArray, const int size, const int valueToCompare)
{
    int count{};
    for (int i = 0; i < size; i++)
    {
        if (pArray[i] == valueToCompare) ++count;
    }
    return count;
}

int MinElement(const int* pArray, const int size)
{
    int min{ pArray[0] };
    for (int i = 0; i < size; i++)
    {
        if (pArray[i] < min) min = pArray[i];
    }
    return min;
}

int MaxElement(const int* pArray, const int size)
{
    int max{ pArray[0] };
    for (int i = 0; i < size; i++)
    {
        if (pArray[i] > max) max = pArray[i];
    }
    return max;
}

void Swap(int* pArray, const int size, const int idx1, const int idx2)
{
    const int valueIdx1{ pArray[idx1] };
    const int valueIdx2{ pArray[idx2] };
    
    pArray[idx1] = valueIdx2;
    pArray[idx2] = valueIdx1;
}

void Shuffle(int* pArray, const int size, const int nrShuffles)
{
    for (int i = 0; i < nrShuffles; i++)
    {
        const int idx1{ GetRand(0, size - 1) };
        int idx2{ GetRand(0, size - 1) };

        while (idx1 == idx2)
        {
            idx2 = GetRand(0, size - 1);
        }

        Swap(pArray, size, idx1, idx2);
    }
    
}

void BubbleSort(const int* pArray, int size, bool sortAscending)
{
}

int GetRand(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

int GenerateRandomArray(const int size)
{
    // int rndArray[size]{};
}

void PrintArray(const int* pArray, const int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << pArray[i] << " ";
    }
    cout << endl;
}