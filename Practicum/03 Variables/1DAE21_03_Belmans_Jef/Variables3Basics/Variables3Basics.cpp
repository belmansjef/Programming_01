#include "pch.h"
#include <iostream>
#include <limits>

int main()
{
	DisplaySizeOf();
	DisplayBinaryAndHexadecimal();
	DisplayRangeOfInteger();
	DisplayBitwiseOperators();
}

void DisplaySizeOf()
{
	bool isVar{};
	int intVar{};
	float floatVar{};
	double doubleVar{};

	cout << "Size of bool: " << sizeof(isVar) << " byte(s)" << endl;
	cout << "Size of int: " << sizeof(intVar) << " byte(s)" << endl;
	cout << "Size of float: " << sizeof(floatVar) << " byte(s)" << endl;
	cout << "Size of double: " << sizeof(doubleVar) << " byte(s)" << endl;
}

void DisplayBinaryAndHexadecimal()
{
	int d[3];
	int b[3];
	int x[3];

	d[0] = 0;
	b[0] = 0b0;
	x[0] = 0x0;

	d[1] = 1;
	b[1] = 0b1;
	x[1] = 0x1;

	d[2] = 2;
	b[2] = 0b10;
	x[2] = 0x2;

	cout << endl;

	for (int i = 0; i < 3; i++)
	{
		cout << "Decimal: " << d[i] << " || Binary: " << b[i] << " || Hexadecimal: " << x[i] << endl;
	}
}

void DisplayRangeOfInteger()
{
	unsigned int unsignedMax{ numeric_limits<unsigned int>::max() };
	unsigned int unsignedMin{ numeric_limits<unsigned int>::min() };
	int signedMax{ numeric_limits<int>::max() };
	int signedMin{ numeric_limits<int>::min() };

	cout << endl << "Unsigned max: " << unsignedMax << " || Unsigned min: " << unsignedMin
		<< " || Signed max: " << signedMax << " || Signed min: " << signedMin << endl;
	cout << "Unsigned max + 1: " << unsignedMax + 1 << " || Unsigned min - 1: " << unsignedMin - 1
		<< " || Signed max + 1: " << signedMax + 1 << " || Signed min - 1: " << signedMin - 1 << endl;
}

void DisplayBitwiseOperators()
{
	unsigned int x{ 3 };
	unsigned int y{ 5 };
	int userInput{ 0 };
	unsigned int bitShift{ 2048 };
	unsigned int bitDefined{ 0 };

	cout << endl << "Bitwise & (and) operator: " << (x & y) << endl;
	cout << "Bitwise | (or) operator: " << (x | y) << endl;

	cout << "Number to check which bits are set? ";
	cin >> userInput;

	cout << "1st bit " << (userInput & (1 << 0)) << endl;
	cout << "2nd bit " << (userInput & (1 << 1)) << endl;
	cout << "3rd bit " << (userInput & (1 << 2)) << endl;
	cout << "4th bit " << (userInput & (1 << 3)) << endl;

	cout << endl << "Number to set 3rd bit in? ";
	cin >> userInput;

	cout << endl << "This number with 3rd  bit set: " << (userInput | (1 << 2));

	cout << endl << bitShift << " shifted one bit to the right gives: " << (bitShift >> 1) << endl;

	cout << endl << "Is bit representing 256 set in the value 4448? " << ((4448 >> 7) & 1) << endl;

	cout << endl << bitShift << " shifted one bit to the left gives: " << (bitShift << 1) << endl;

	bitDefined =
		(1 << 0) | (1 << 1) | (1 << 2) | (1 << 3) |
		(1 << 4) | (1 << 5) | (0 << 6) | (1 << 7) |
		(1 << 8) | (1 << 9) | (0 << 10)| (1 << 11)|
		(0 << 12)| (1 << 13)| (1 << 14)| (0 << 15)|
		(1 << 16)| (1 << 17)| (0 << 18)| (1 << 19)|
		(0 << 20)| (1 << 21)| (0 << 22)| (0 << 23);

	cout << endl << "Bit defined value: " << bitDefined << endl;
}