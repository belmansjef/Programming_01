// Belmans, Jef - 1DAE21

#include "pch.h"
#define _USE_MATH_DEFINES
#include<cmath>
#include <iostream>

void TestOneParFunctions();
void TestTwoParFunctions();

int main( )
{
	// 1. Show my data
	std::cout << "My name is Belmans, Jef" << std::endl;
	std::cout << "I am in group 1DAE21" << std::endl << std::endl;

	// 2. Show my student history
	std::cout << "Name of my high school: Howest" << std::endl;
	std::cout << "In the last year I had 0 hours math a week" << std::endl << std::endl;

	TestOneParFunctions();
	TestTwoParFunctions();

	// Wait
	std::cout << "Push ENTER to quit\n";
	std::cin.get( );

	return 0;
}

void TestOneParFunctions()
{
	float pi{ 3.1415926535f };
	float angle{ 0.0f };

	std::cout << "Use existing functions with 1 parameter\n";

	std::cout << "Angle: " << angle * (pi / 4.0f) << std::endl;
	std::cout << "cos: " << cosf(angle * (pi / 4.0f)) << std::endl;
	++angle;

	std::cout << "Angle: " << angle * (pi / 4.0f) << std::endl;
	std::cout << "cos: " << cosf(angle * (pi / 4.0f)) << std::endl;
	++angle;

	std::cout << "Angle: " << angle * (pi / 4.0f) << std::endl;
	std::cout << "cos: " << cosf(angle * (pi / 4.0f)) << std::endl;
	++angle;

	std::cout << "Angle: " << angle * (pi / 4.0f) << std::endl;
	std::cout << "cos: " << cosf(angle * (pi / 4.0f)) << std::endl;
	++angle;

	std::cout << "Angle: " << angle * (pi / 4.0f) << std::endl;
	std::cout << "cos: " << cosf(angle * (pi / 4.0f)) << std::endl;
}

void TestTwoParFunctions()
{
	float x{ 2.0f }, y{ 8.0f };
	float a{ 3.0f }, b{ 4.0f }, c{ 0.0f };

	float result = powf(x, y);
	std::cout << "\nThe result of pow (" << x << ", " << y << "): " << result << std::endl;

	c = sqrtf(powf(a, 2.0f) + powf(b, 2.0f));
	std::cout << "The hypothenuse of the triangle: " << c << std::endl;
}
