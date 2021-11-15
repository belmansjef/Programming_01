#include "pch.h"
#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

#pragma region Debugging
int Sum(int a, int b);
#pragma endregion Debugging

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
#pragma endregion SimpleFucntions

int main()
{
    // int result{ Sum(5, 2) };

    // TestPrint();

    // TestMultiply();
    // cout << Modulo(250, 24) << endl;
    // TestPrintNumbers();
    // TestCalcElapsedTime();
    // TestPrintMessage();
    TestIsEven();

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
#pragma endregion
