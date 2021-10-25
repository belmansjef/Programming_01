#include "pch.h"
#include <iostream>
#include <iomanip>
#include <vector>

int main()
{
	// EvenNumbers();
	// ExamScores();
	// RandomGuess();
	// Trigonometry();
	ASCIITable();
}

void EvenNumbers()
{
	int x{ 0 };

	cout << "-- Even numbers -- " << endl;

	for (int i = 2; i <= 24; i += 2)
	{
		cout << i << " ";
	}

	cout << endl;

	while (x < 24)
	{
		++x;
		if (x % 2 == 0)
		{
			cout << x << " ";
		}
	}

	x = 0;
	cout << endl;

	do
	{
		++x;
		if (x % 2 == 0)
		{
			cout << x << " ";
		}
	} while (x < 24);

}

void ExamScores()
{
	int userInput{};

	int totalAPlus{ 0 },
		totalA{ 0 },
		totalB{ 0 },
		totalC{ 0 },
		totalD{ 0 },
		totalE{ 0 },
		totalFX{ 0 },
		totalF{ 0 };

	vector<int> scores{};
	int totalScore{};

	cout << "-- Exam scores --" << endl;

	while (userInput != -1)
	{
		cout << "Score [0,20] ? ";
		
		cin >> userInput;
		cin.clear();
		cin.ignore(1);

		if (userInput < -1 || userInput > 20)
		{
			cout << "Wrong score!" << endl;
		}
		else if(userInput != -1)
		{
			totalScore += userInput;
			scores.push_back(int(userInput));

			if (userInput < 8)
			{
				++totalF;
			}
			else if (userInput < 10)
			{
				++totalFX;
			}
			else if (userInput < 11)
			{
				++totalE;
			}
			else if (userInput < 13)
			{
				++totalD;
			}
			else if (userInput < 15)
			{
				++totalC;
			}
			else if (userInput < 16)
			{
				++totalB;
			}
			else if (userInput < 18)
			{
				++totalA;
			}
			else
			{
				++totalAPlus;
			}
		}
	}

	cout << "A+: " << totalAPlus << endl;
	cout << "A: " << totalA << endl;
	cout << "B: " << totalB << endl;
	cout << "C: " << totalC << endl;
	cout << "D: " << totalD << endl;
	cout << "E: " << totalE << endl;
	cout << "FX: " << totalFX << endl;
	cout << "F: " << totalF << endl;

	cout << "Total scores: " << totalScore << endl;

	cout << "Entered scores: ";
	for (int score : scores)
	{
		cout << score << " ";
	}

	cout << endl;
}

void RandomGuess()
{
	int userInput{ 0 };
	int generatedNumber{ 0 };
	int numGuesses{ 0 };
	
	cout << "-- Guess number --" << endl;
	cout << "Number to guess ? ";
	cin >> userInput;
	cin.clear();
	cin.ignore(1);

	while (userInput < 0 || userInput > RAND_MAX)
	{
		cout << "This is a wrong number, number to guess ? ";
		cin >> userInput;
		cin.clear();
		cin.ignore(1);
	}

	while (generatedNumber != userInput)
	{
		generatedNumber = rand();
		++numGuesses;
	}

	cout << "Number found after " << numGuesses << " guesses" << endl;
}

void Trigonometry()
{
	cout << "-- Trigonometry --" << endl;
	
	cout << setw(10);
	cout << "Degrees";
	cout << setw(10);
	cout << "Radians";
	cout << setw(10);
	cout << "Cos";
	cout << setw(10);
	cout << "Sin";
	cout << endl;
	
	cout.precision(2);
	cout << fixed;
	for (int i = 0; i <= 180; i += 10)
	{
		float rad{ float((M_PI / 180.0f) * i) };

		cout << setw(10);
		cout << i;
		cout << setw(10);
		cout << rad;
		cout << setw(10);
		cout << cosf(rad);
		cout << setw(10);
		cout << sinf(rad);
		cout << endl;
	}
}

void ASCIITable()
{
	cout << "-- ASCII table --" << endl;
	for (int i = 'a'; i <= 'm'; i++)
	{
		
		cout
			<< setw(2)
			<< char(i) 
			<< setw(8)
			<< i
			<< setw(4)
			<< char(i + 13)
			<< setw(8)
			<< i + 13
			<< endl;
	}
}
