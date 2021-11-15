#include "pch.h"
#include "Game.h"
#include <iostream>

#pragma region gameFunctions											
void Start()
{
	PrintLetters();
}

void Draw()
{
	ClearBackground();
	DrawCircle();
}

void Update(float elapsedSec)
{
	UpdateCircle();
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
	switch (key)
	{
	case SDLK_UP:
		g_Speed += 0.4f;
		if (g_Speed > 5.0f)
		{
			g_Speed = 5.0f;
		}
		break;
	case SDLK_DOWN:
		g_Speed -= 0.4f;
		if (g_Speed < 0.2f)
		{
			g_Speed = 0.2f;
		}
		break;
	default:
		return;
		break;
	}
	
	std::cout << "g_Speed = " << g_Speed << std::endl;
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	if (g_CurrentCircleState != CircleState::waiting) return;

	GenerateNewCircle( Point2f(
		float(e.x),
		float(g_WindowHeight - e.y))
	);
}
#pragma endregion inputHandling

#pragma region ownDefinitions
void PrintLetters()
{
	int nrCharsPerLine{};
	int index{};

	std::cout << "How many of characters per line? ";
	std::cin >> nrCharsPerLine;

	while (index < 26)
	{
		std::cout << std::endl;
		for (int i = 0; i < nrCharsPerLine; i++)
		{
			if (index >= 26) return;

			std::cout << char(97 + index);
			++index;
		}
	}
}

void GenerateNewCircle(const Point2f center)
{
	g_MaxRadius = int(GenerateRandomNumber(50.0f, 150.0f));
	g_CurrentColor = GenerateRandomColor4f();
	g_CurrentCircle = Ellipsef
	(
		center,
		0.0f,
		0.0f
	);
	g_CurrentCircleState = CircleState::growing;

	std::cout << std::endl << "Growing state." << std::endl;
	std::cout << "The maximum radius is " << g_MaxRadius << std::endl;
}

void UpdateCircle()
{
	if (g_CurrentCircleState == CircleState::waiting) return;

	switch (g_CurrentCircleState)
	{
	case CircleState::growing:
		g_CurrentCircle.radiusX += g_Speed;
		g_CurrentCircle.radiusY += g_Speed;
		if (g_CurrentCircle.radiusX >= g_MaxRadius)
		{
			g_CurrentCircleState = CircleState::shrinking;
			std::cout << "Shrinking state." << std::endl;
		}
		break;
	case CircleState::shrinking:
		g_CurrentCircle.radiusX -= g_Speed;
		g_CurrentCircle.radiusY -= g_Speed;

		if (g_CurrentCircle.radiusX <= 0.0f || g_CurrentCircle.radiusY <= 0.0f)
		{
			g_CurrentCircle.radiusX = g_CurrentCircle.radiusY = 0.0f;

			g_CurrentCircleState = CircleState::waiting;
			std::cout << "Waiting state." << std::endl;
		}
		break;
	default:
		std::cout << "Error getting circle state!" << std::endl;
		break;
	}

	// Check if circle collides with window border
	if 
		(
			g_CurrentCircle.center.x + g_CurrentCircle.radiusX >= g_WindowWidth ||
			g_CurrentCircle.center.x - g_CurrentCircle.radiusX <= 0.0f ||
			g_CurrentCircle.center.y + g_CurrentCircle.radiusY >= g_WindowHeight ||
			g_CurrentCircle.center.y - g_CurrentCircle.radiusY <= 0.0f
		)
	{
		g_CurrentColor = Color4f(0.8f, 0.1f, 0.1f, 1.0f);
		std::cout << "Ouch!" << std::endl;

		g_CurrentCircleState = CircleState::shrinking;
		std::cout << "Shrinking state." << std::endl;
	}
}

void DrawCircle()
{
	if (g_CurrentCircleState == CircleState::waiting) return;

	SetColor(g_CurrentColor);
	FillEllipse(g_CurrentCircle);
}
#pragma endregion ownDefinitions