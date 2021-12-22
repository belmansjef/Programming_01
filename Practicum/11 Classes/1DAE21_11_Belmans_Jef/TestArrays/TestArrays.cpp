#include "pch.h"
#include "Time.h"
#include <iostream>

void TestArrays();

int main()
{
    TestArrays();
}


void TestArrays()
{
    const int arrSize{ 4 };
    Time* pArrTime[arrSize]{};

    for (int i = 0; i < arrSize; i++)
    {
        pArrTime[i] = new Time(rand() % 1000);
        pArrTime[i]->AddSeconds(rand() % 10000);
    }

    delete[] pArrTime;
}