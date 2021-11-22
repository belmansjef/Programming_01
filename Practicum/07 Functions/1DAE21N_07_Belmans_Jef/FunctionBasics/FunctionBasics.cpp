#include "pch.h"
#include <iostream>
#include <iomanip>

int main()
{
    srand(unsigned int(time(nullptr)));

    Print(54);
    TestCalcCosSin();

    system("pause");
}

void Print(const int value, const char delimiter)
{
    cout << value << delimiter << endl;
}

void CalcCosSin(const float& angle, float& cos, float& sin)
{
    cos = cosf(angle);
    sin = sinf(angle);
}

void TestCalcCosSin()
{
    float angle{};
    float cos{};
    float sin{};

    cout << fixed << setprecision(2) << endl;
    cout << "-- Function that calculates cosine and sine --" << endl;

    cout << "   Radians\t\t Cos\t\t Sin" << endl;
    for (int i = 0; i < 10; i++)
    {
        angle = GetRand(0.0f, 2.0f * M_PI);
        CalcCosSin(angle, cos, sin);
        cout << "     " << angle << "\t\t" << cos << "\t\t" << sin << endl;
    }
}

float GetRand(const float lower, const float upper)
{
    return float((rand() % (int((upper - lower) * 100) + 1)) + int(lower * 100.0f)) / 100.0f;
}