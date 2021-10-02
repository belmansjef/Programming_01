#include "pch.h"
#include "Game.h"

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground(0.1f, 0.1f, 0.1f);
	DrawBeam();
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
void DrawBeam()
{	
	const float squareSize{ 200.0f };
	const float border{ 10.0f };

	// Borders
	SetColor(1.0f, 1.0f, 1.0f);
	DrawRect(Point2f(border, border), squareSize, squareSize, 2.0f);
	DrawRect(Point2f(g_WindowWidth - (border + squareSize), g_WindowHeight - (border + squareSize)), squareSize, squareSize, 2.0f);

	// Squares
	SetColor(0.0f, 0.6f, 0.0f);
	FillRect(Point2f(border, border), squareSize, squareSize);
	FillRect(Point2f(g_WindowWidth - (border + squareSize), g_WindowHeight - (border + squareSize)), squareSize, squareSize);

	// Lines
	SetColor(1.0f, 1.0f, 1.0f);
	DrawLine(Point2f(border, border), Point2f(g_WindowWidth - (border + squareSize), g_WindowHeight - (border + squareSize)));
	DrawLine(Point2f(border + squareSize, border), Point2f(g_WindowWidth - border, g_WindowHeight - (border + squareSize)));
	DrawLine(Point2f(border, border + squareSize), Point2f(g_WindowWidth - (border + squareSize), g_WindowHeight - border));
	DrawLine(Point2f(border + squareSize, border + squareSize), Point2f(g_WindowWidth - border, g_WindowHeight - border));
}
#pragma endregion ownDefinitions