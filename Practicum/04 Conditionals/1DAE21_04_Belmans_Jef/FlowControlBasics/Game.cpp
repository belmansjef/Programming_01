#include "pch.h"
#include "Game.h"

#pragma region gameFunctions											
void Start()
{
	/*PrintTruthTable();
	CompareTwoNumbers();
	CalculatePrice();
	ConvertDayNumber();
	CheckLeapYear();
	ConvertSeconds();
	UseActorState();*/
	UsePoint2f();
}

void Draw()
{
	ClearBackground();
}

void Update(float elapsedSec)
{
	
}

void End()
{

}
#pragma endregion gameFunctions

#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{

}

void OnKeyUpEvent(SDL_Keycode key)
{
	
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{

}
#pragma endregion inputHandling

#pragma region ownDefinitions
void PrintTruthTable()
{
	bool isTrue { true }, isFalse { false };

	// Enable boolalpha flag
	cout << boolalpha;

	cout << "-- Print truth table --" << endl;
	cout << "Logical binary AND-operator (&&)" << endl;
	cout << isTrue << " && " << isTrue << " is " << (isTrue && isTrue) << endl;
	cout << isTrue << " && " << isFalse << " is " << (isTrue && isFalse) << endl;
	cout << isFalse << " && " << isTrue << " is " << (isFalse && isTrue) << endl;
	cout << isFalse << " && " << isFalse << " is " << (isFalse && isFalse) << endl;

	cout << "Logical binary OR-operator (||)" << endl;
	cout << isTrue << " || " << isTrue << " is " << (isTrue || isTrue) << endl;
	cout << isTrue << " || " << isFalse << " is " << (isTrue || isFalse) << endl;
	cout << isFalse << " || " << isTrue << " is " << (isTrue || isFalse) << endl;
	cout << isFalse << " || " << isFalse << " is " << (isFalse || isFalse) << endl;

	cout << "Logical unary NOT-operator (!)" << endl;
	cout << "!" << isTrue << " is " << !isTrue << endl;
	cout << "!" << isFalse << " is " << !isFalse << endl;
}

void CompareTwoNumbers()
{
	int firstNumber{ int(GenerateRandomNumber(0, 10)) };
	int secondNumber{ int(GenerateRandomNumber(0, 10)) };

	cout << endl << "-- Compare two numbers --" << endl;
	cout << "First number is " << firstNumber << endl;
	cout << "Second number is " << secondNumber << endl;

	if (firstNumber < secondNumber)
	{
		cout << "Second number is larger than the first number" << endl;
	}
	else if (firstNumber > secondNumber)
	{
		cout << "First number is larger than the first number" << endl;
	}
	else if (firstNumber == secondNumber)
	{
		cout << "First and second number are equal" << endl;
	}
}

void CalculatePrice()
{
	int nrBallpoints{ 0 };
	float totalPrice{ 0.0f };

	cout << endl << "-- Calculate price --" << endl;
	cout << "Number of ballpoints? ";
	cin >> nrBallpoints;
	
	if (nrBallpoints < 20)
	{
		totalPrice = nrBallpoints * 4.0f;
	}
	else if (nrBallpoints >= 20 && nrBallpoints < 50)
	{
		totalPrice = nrBallpoints * 3.5f;
	}
	else if (nrBallpoints >= 50 && nrBallpoints <= 100)
	{
		totalPrice = nrBallpoints * 3.25f;
	}
	else if (nrBallpoints > 100)
	{
		totalPrice = nrBallpoints * 3.1f;
	}

	cout << "Total price is " << totalPrice << endl;
}

void ConvertDayNumber()
{
	int dayNumber{ 0 };

	cout << endl << "-- Convert day number --" << endl;
	cout << "Day number [1, 7] ? ";
	cin >> dayNumber;

	switch (dayNumber)
	{
	case 1:
		cout << "Monday" << endl;
		break;
	case 2:
		cout << "Tuesday" << endl;
		break;
	case 3:
		cout << "Wednesday" << endl;
		break;
	case 4:
		cout << "Thursday" << endl;
		break;
	case 5:
		cout << "Friday" << endl;
		break;
	case 6:
		cout << "Saturday" << endl;
		break;
	case 7:
		cout << "Sunday" << endl;
		break;
	default:
		break;
	}
}

void CheckLeapYear()
{
	int year{ 0 };
	int daysInFebruary{ 0 };
	
	cout << endl << "-- Check leap year --" << endl;
	cout << "Year? ";
	cin >> year;
	
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
			{
				daysInFebruary = 29;
			}
			else
			{
				daysInFebruary = 28;
			}
		}
		else
		{
			daysInFebruary = 29;
		}
	}
	else
	{
		daysInFebruary = 28;
	}

	cout << year << ": " << daysInFebruary;
}

void ConvertSeconds()
{
	int seconds{ 0 }, minutes{ 0 }, hours{ 0 }, days{ 0 };

	cout << endl << "-- Convert seconds --" << endl;
	cout << "Number of seconds? ";
	cin >> seconds;

	days = seconds / (24 * 3600);
	seconds = seconds % (24 * 3600);

	hours = seconds / 3600;
	seconds %= 3600;

	minutes = seconds / 60;
	seconds %= 60;

	cout << days << " day(s)" << endl;
	cout << hours << " hour(s)" << endl;
	cout << minutes << " minute(s)" << endl;
	cout << seconds << " second(s)" << endl;
}

void UseActorState()
{
	enum class ActorState
	{
		running,
		flying,
		falling,

		first = running,
		last = falling
	};

	ActorState actorState{ ActorState(GenerateRandomNumber(int(ActorState::first), int(ActorState::last))) };

	cout << endl << "-- Define and use ActorState --" << endl;
	
	switch (actorState)
	{
	case ActorState::running:
		cout << "Running" << endl;
		break;
	case ActorState::flying:
		cout << "Flying" << endl;
		break;
	case ActorState::falling:
		cout << "Falling" << endl;
		break;
	default:
		cout << "Error getting actor state" << endl;
		break;
	}

}

void UsePoint2f()
{
	Point2f p1, p2{}, p3{ 26.0f, 25.0f };

	cout << endl << "-- Define and use Point2f --" << endl;

	cout << "Values after definition" << endl;
	// cout << "p1: [" << p1.x << ", " << p1.y << "]" << endl;
	cout << "p2: [" << p2.x << ", " << p2.y << "]" << endl;
	cout << "p3: [" << p3.x << ", " << p3.y << "]" << endl;

	p1.x = 20.0f;
	p1.y = 3.0f;

	p2 = Point2f(30.0f, 40.0f);

	++p3.x;
	--p3.y;

	cout << "Values after changing the members" << endl;
	cout << "p1: [" << p1.x << ", " << p1.y << "]" << endl;
	cout << "p2: [" << p2.x << ", " << p2.y << "]" << endl;
	cout << "p3: [" << p3.x << ", " << p3.y << "]" << endl;

}
#pragma endregion ownDefinitions