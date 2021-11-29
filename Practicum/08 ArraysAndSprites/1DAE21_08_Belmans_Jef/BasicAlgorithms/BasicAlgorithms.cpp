#include "pch.h"
#include <iostream>

int main()
{
    srand(unsigned int(time(nullptr)));
    
    // Declare vars
    const int size{ 10 };
    int arrayInt01[size]{};
    int arrayInt02[size]{};

    // Initialize arrays with data
    InitializeArray(arrayInt01, size);
    InitializeArray(arrayInt02, size);

    #pragma region Count
    cout << "-- Test of count function --" << endl;

    int nrCount{ Count(arrayInt01, size, 2) };
    PrintArray(arrayInt01, size);
    cout << "2 occurs " << nrCount << " time(s) in this array" << endl << endl;

    nrCount = Count(arrayInt02, size, -5);
    PrintArray(arrayInt02, size);
    cout << "-5 occurs " << nrCount << " time(s) in this array" << endl << endl;
    #pragma endregion

    #pragma region Min/Max
    cout << "-- Test the MinElement and MaxElement functions --" << endl;

    int min{ MinElement(arrayInt01, size) };
    int max{ MaxElement(arrayInt01, size) };
    PrintArray(arrayInt01, size);
    cout << min << " is the smallest value in this array" << endl;
    cout << max << " is the largest value in this array" << endl << endl;

    min = MinElement(arrayInt02, size);
    max = MaxElement(arrayInt02, size);
    PrintArray(arrayInt02, size);
    cout << min << " is the smallest value in this array" << endl;
    cout << max << " is the largest value in this array" << endl << endl;
    #pragma endregion

    #pragma region Swap
    cout << "-- Test of Swap function --" << endl;
    
    cout << "Before swapping" << endl;
    PrintArray(arrayInt01, size);

    cout << "After swapping the first and last element" << endl;
    Swap(arrayInt01, size, 0, size - 1);
    PrintArray(arrayInt01, size);

    cout << endl << "Before swapping" << endl;
    PrintArray(arrayInt02, size);

    cout << "After swapping the second and second from last element" << endl;
    Swap(arrayInt02, size, 1, size - 2);
    PrintArray(arrayInt02, size);
    #pragma endregion

    #pragma region Shuffle
    cout << endl << "-- Test of Shuffle function --" << endl;

    cout << "Before shuffling" << endl;
    PrintArray(arrayInt01, size);

    Shuffle(arrayInt01, size, 10);
    cout << "After shuffling 10 times" << endl;
    PrintArray(arrayInt01, size);

    cout << endl << "Before shuffling" << endl;
    PrintArray(arrayInt01, size);

    Shuffle(arrayInt01, size, 20);
    cout << "After shuffling 20 times" << endl;
    PrintArray(arrayInt01, size);

    cout << endl << "Before shuffling" << endl;
    PrintArray(arrayInt01, size);

    Shuffle(arrayInt01, size, 50);
    cout << "After shuffling 50 times" << endl;
    PrintArray(arrayInt01, size);
    #pragma endregion


    #pragma region BubbleSort
    cout << endl << "-- Test of BubbleSort function --" << endl;
    
    cout << "Before sort" << endl;
    PrintArray(arrayInt01, size);

    BubbleSort(arrayInt01, size, true);
    cout << "After sort" << endl;
    PrintArray(arrayInt01, size);

    cout << endl << "Before sort" << endl;
    PrintArray(arrayInt02, size);

    BubbleSort(arrayInt02, size, false);
    cout << "After sort" << endl;
    PrintArray(arrayInt02, size);
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

void BubbleSort(int* pArray, int size, bool sortAscending)
{
    for (int i = 0; i < size - 1; i++)
    {
        const int valueIdx1{ pArray[i] };
        const int valueIdx2{ pArray[i + 1] };

        if (valueIdx1 > valueIdx2 && sortAscending)
        {
            pArray[i] = valueIdx2;
            pArray[i + 1] = valueIdx1;
        }
        else if(valueIdx1 < valueIdx2 && !sortAscending)
        {
            pArray[i] = valueIdx2;
            pArray[i + 1] = valueIdx1;
        }
    }

    if (size > 1)
    {
        BubbleSort(pArray, size - 1, sortAscending);
    }
}

int GetRand(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

void InitializeArray(int* pArrayToInit,const int size)
{
    for (int i = 0; i < size; i++)
    {
        pArrayToInit[i] = GetRand(-10, 10);
    }
}

void PrintArray(const int* pArray, const int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << pArray[i] << " ";
    }
    cout << endl;
}