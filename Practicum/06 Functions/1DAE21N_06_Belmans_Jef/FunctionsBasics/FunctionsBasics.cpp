#include "pch.h"
#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

#pragma region Debugging
int Sum(int a, int b);
#pragma endregion

#pragma region FunctionOverloading
void Print(int value, char delimiter);
void Print(char value, char delimiter);
void Print(float value, char delimiter);
void TestPrint();
#pragma endregion

#pragma region SimpleFuctions
int Multiply(int a, int b);
void TestMultiply();

int Modulo(int dividend, int divisor);

void PrintNumbers(int lower, int upper);
void TestPrintNumbers();

void CalcElapsedTime(int lower, int upper);
void TestCalcElapsedTime();

void PrintMessage(string message, int numSpaces);
void TestPrintMessage();

bool IsEven(int value);
void TestIsEven();

bool IsLeapYear(int year);
void TestIsLeapYear();

int GetRand(int lower, int upper);
void TestGetIntRand();

float GetRand(float lower, float upper);
void TestGetFloatRand();

float GetDistance(float x1, float y1, float x2, float y2);
float GetDistance(Point2f p1, Point2f p2);
void TestGetDistance();
#pragma endregion

int main()
{
    srand(unsigned int(time(nullptr)));

    // int result{ Sum(5, 2) };

    // TestPrint();

    // TestMultiply();
    // cout << Modulo(250, 24) << endl;
    // TestPrintNumbers();
    // TestCalcElapsedTime();
    // TestPrintMessage();
    // TestIsEven();
    // TestIsLeapYear();
    // TestGetIntRand();
    // TestGetFloatRand();
    // TestGetDistance();

    cout << endl;
    system("pause");
}

#pragma region Debugging
int Sum(int a, int b)
{
    return a + b;
}
#pragma endregion

#pragma region FunctionOverloading
void Print(int value, char delimiter)
{
    cout << value << delimiter;
}

void Print(char value, char delimiter)
{
    cout << value << delimiter;
}

void Print(float value, char delimiter)
{
    cout << value << delimiter;
}

void TestPrint()
{
    Print('a', ',');
    Print(20, ',');
    Print(20.0f, ',');
}
#pragma endregion

#pragma region SimpleFunctions
int Multiply(int a, int b)
{
    return a * b;
}
void TestMultiply()
{
    int a{}, b{}, c{}, d{};
    cout << "-- Function that calcuates the product of 2 integers --" << endl;
    cout << "2 numbers to multiply? ";
    cin >> a >> b;
    cout << a << " * " << b << " = " << Multiply(a, b) << endl;
    
    cout << "4 numbers to multiply? ";
    cin >> a >> b >> c >> d;
    cout << a << " * " << b << " * " << c << " * " << d << " = " << Multiply(Multiply(a, b), Multiply(c, d)) << endl;
}

int Modulo(int dividend, int divisor)
{
    return dividend - ((dividend / divisor) * divisor);
}
void PrintNumbers(int lower, int upper)
{
    cout << "Interval [" << lower << ", " << upper << "]" << endl;
    for (int i = lower; i < upper + 1; i++)
    {
        cout << i << " ";
    }
    cout << endl;
}
void TestPrintNumbers()
{
    cout << "-- Function that prints the integers in a given interval --" << endl;
    PrintNumbers(10, 20);
    PrintNumbers(90, 115);
}

void CalcElapsedTime(int lower, int upper)
{
    steady_clock::time_point startTime{ steady_clock::now() };
    PrintNumbers(lower, upper);
    steady_clock::time_point endTime{ steady_clock::now() };

    duration<float, std::milli> elapsedTime{ endTime - startTime };
    cout << "This print task took " << elapsedTime.count() << " milliseconds" << endl << endl;
}
void TestCalcElapsedTime()
{
    cout << "-- Function that counts the time of a printing task --" << endl;
    CalcElapsedTime(10, 20);
    CalcElapsedTime(0, 400);
}

void PrintMessage(string message, int numSpaces = 0)
{
    for (int i = 0; i < numSpaces; i++)
    {
        cout << char(0x20);
    }

    cout << message << endl;
}
void TestPrintMessage()
{
    cout << "-- Function that prints an indented message --" << endl;
    PrintMessage("No intedation specified");
    PrintMessage("2 spaces intendation specified", 2);
    PrintMessage("4 spaces intendation specified", 4);
}

bool IsEven(int value)
{
    return Modulo(value, 2) == 0;
}
void TestIsEven()
{
    int num{};
    cout << "-- Function that checks whether a number is even --" << endl;

    string result = IsEven(num = 41) ? "even" : "odd";
    cout << num << " is " << result << endl;

    result = IsEven(num = 18467) ? "even" : "odd";
    cout << num <<" is " << result << endl;

    result = IsEven(num = 6334) ? "even" : "odd";
    cout << num << " is " << result << endl;

    result = IsEven(num = 26500) ? "even" : "odd";
    cout << num << " is " << result << endl;

    result = IsEven(num = 19169) ? "even" : "odd";
    cout << num << " is " << result << endl;
}

bool IsLeapYear(int year)
{
    if (Modulo(year, 4) == 0)
    {
        if (Modulo(year, 100) == 0)
        {
            return (Modulo(year, 400) == 0);
        }
        else
        {
            return true;
        }
    }
    return false;
}
void TestIsLeapYear()
{
    int userInput{};
    cout << "-- Function that checks wether year is leap --" << endl;

    while (userInput != -1)
    {
        cout << "Year ? ";
        cin >> userInput;

        if (userInput == -1) return;

        const int days{ IsLeapYear(userInput) ? 29 : 28 };
        cout << userInput << " has " << days << " days in february" << endl;
    }
}

int GetRand(int lower, int upper)
{
    return Modulo(rand(), (upper - lower) + 1) + lower;
}
void TestGetIntRand()
{
    cout << "-- Function that generates a random number in a given integer interval --" << endl;
    cout << "In [1, 6] " << GetRand(1, 6) << endl;
    cout << "In [10, 20] " << GetRand(10, 20) << endl;
    cout << "In [-5, 0] " << GetRand(-5, 0) << endl;
}

float GetRand(float lower, float upper)
{
    return float((Modulo(rand(), (int((upper - lower) * 100) + 1)) + int(lower * 100.0f)) / 100.0f);
}
void TestGetFloatRand()
{
    cout << "-- Function that generates a random number in a given float interval --" << endl;
    cout << "In [0, 3.14159] " << GetRand(0.0f, 3.14159f) << endl;
    cout << "In [-2, 3] " << GetRand(-2.0f, 3.0f) << endl;
}

float GetDistance(float x1, float y1, float x2, float y2)
{
    return GetDistance(Point2f(x1, y1), Point2f(x2, y2));
}
float GetDistance(Point2f p1, Point2f p2)
{
    Point2f freeVector{ Point2f(p2.x - p1.x, p2.y - p1.y) };
    
    return sqrtf(pow(freeVector.x, 2) + pow(freeVector.y, 2));
}
void TestGetDistance()
{
    const Point2f p1{ GetRand(-100.0f, 100.0f), GetRand(-100.0f, 100.0f) };
    const Point2f p2{ GetRand(-100.0f, 100.0f), GetRand(-100.0f, 100.0f) };
    const Point2f p3{ GetRand(-100.0f, 100.0f), GetRand(-100.0f, 100.0f) };
    const Point2f p4{ GetRand(-100.0f, 100.0f), GetRand(-100.0f, 100.0f) };

    cout << "-- Function that calculates distance between 2 points --" << endl;

    cout << "Distance between [" << p1.x << ", " << p1.y << "] and [" << p2.x << ", " << p2.y << "]" << endl;
    cout << "Calling one version: " << GetDistance(p1, p2) << endl;
    cout << "Calling the other version: " << GetDistance(p1.x, p1.y, p2.x, p2.y) << endl << endl;

    cout << "Distance between [" << p3.x << ", " << p3.y << "] and [" << p4.x << ", " << p4.y << "]" << endl;
    cout << "Calling one version: " << GetDistance(p3, p4) << endl;
    cout << "Calling the other version: " << GetDistance(p3.x, p3.y, p4.x, p4.y) << endl << endl;
}
#pragma endregion
