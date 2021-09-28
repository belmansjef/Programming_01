// Belmans, Jef - 1DAE21

#include "pch.h"
#include <iostream>
#include <string>

// Function declaration
void OddOrEven();
void ConvertASCII();
void RandomASCII();
void RoundFloat(float numToRound);
void ExploreStrings();

int RandomNumber(int lowerBound, int upperBound);
float RandomNumberf(float lowerBound, float upperBound);

int main()
{
	srand(int(time(nullptr)));

	OddOrEven();
	
	std::cout << "Random number from 0 to 50: " << RandomNumber(0, 51) << std::endl;
	std::cout << "Random number from 10 to 80: " << RandomNumber(10, 81) << std::endl;
	std::cout << "Random number from -20 to +20: " << RandomNumber(-20, 21) << std::endl;
	std::cout << "Random number from -2 to +2: " << RandomNumber(-2, 3) << std::endl;

	std::cout << "Random number from 5.00 to 10.00: " << RandomNumberf(5.0f, 10.0f) << std::endl;
	std::cout << "Random number from -5.00 to 5.00: " << RandomNumberf(-5.0f, 5.0f) << std::endl;

	ConvertASCII();
	RandomASCII();

	RoundFloat(5.44f);
	RoundFloat(5.45f);
	RoundFloat(5.51f);

	std::cout << "The aspect ratio of full HD (1920 x 1080) is: " << 1920.0f / 1080.0f << std::endl;

	ExploreStrings();
}

void OddOrEven()
{
	int userInput{ 0 };
	std::cout << "Enter a number: ";
	std::cin >> userInput;
	std::cout << "If 0 then entered number is even, if 1 then entered number is odd: " << userInput % 2 << std::endl;
}

void ConvertASCII()
{
	char userInput{};

	std::cout << "Letter? ";
	std::cin >> userInput;
	
	std::cout << "Letter " << userInput << ". ASCII value " << static_cast<int>(userInput) << std::endl;
}

void RandomASCII()
{
	char c;
	int r;

	r = rand() % 26;
	c = 'a' + r;
	
	std::cout << "Random letter " << c << ", ASCII value " << static_cast<int>(c) << std::endl;
}

void ExploreStrings()
{
	std::string someString{ "I am a string literal" };
	std::string firstWord;
	std::string secondWord;
	std::string concatenatedString{};
	std::string numbersLog{};
	int enteredNr;

	std::cout << "Enter some text, no whitespace allowed: ";
	std::cin >> someString;

	std::cout << "First word? ";
	std::cin >> firstWord;
	std::cout << "Second word? ";
	std::cin >> secondWord;

	concatenatedString = firstWord + secondWord;
	std::cout << concatenatedString << std::endl;

	char x{ 'x' };
	std::cout << "String literal + String var: " << "literal" + firstWord << std::endl;
	std::cout << "Char var + String var: " << x + firstWord << std::endl;
	std::cout << "Char literal + string var: " << 'y' + firstWord << std::endl;

	std::cout << "Enter an integer value: ";
	std::cin >> enteredNr;
	numbersLog += std::to_string(enteredNr) + " ";
	std::cout << "Enter an integer value: ";
	std::cin >> enteredNr;
	numbersLog += std::to_string(enteredNr) + " ";
	std::cout << "Enter an integer value: ";
	std::cin >> enteredNr;
	numbersLog += std::to_string(enteredNr) + " ";

	std::cout << "Log of entered numbers: " << numbersLog;
}

void RoundFloat(float numToRound)
{
	std::cout << numToRound << ", rounded: " << round(numToRound) << ", int cast: " << static_cast<int>(numToRound) << std::endl;
}

int RandomNumber(int lowerBound, int upperBound)
{
	return (rand() % upperBound - lowerBound) + lowerBound;
}

float RandomNumberf(float lowerBound, float upperBound)
{
	return lowerBound + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (upperBound - lowerBound)));

}