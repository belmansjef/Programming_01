#include "pch.h"
#include "Game.h"

#pragma region gameFunctions											
void Start()
{

}

void Draw()
{
	ClearBackground(0.1f, 0.1f, 0.3f);
	DrawOctagon();
	DrawCrosier();
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
void DrawOctagon()
{
	const float xRadius{ (g_WindowWidth - 60.0f) / 4.0f };
	const float yRadius{ (g_WindowHeight - 40.0f) / 2.0f };
	const Point2f center{ g_WindowWidth / 4.0f, g_WindowHeight / 2.0f };

	SetColor(1.0f, 0.1f, 0.1f);
	for (int i = 0; i < 10; i++)
	{
		const Point2f p1{ center.x + xRadius * cosf(((2.0f * g_Pi) / 10) * i), center.y + yRadius * sinf(((2.0f * g_Pi) / 10) * i) };
		const Point2f p2{ center.x + xRadius * cosf(((2.0f * g_Pi) / 10) * (i + 1)), center.y + yRadius * sinf(((2.0f * g_Pi) / 10) * (i + 1)) };
		DrawLine(p1, p2);
	}
}

void DrawCrosier()
{
	const Point2f center{ (g_WindowWidth / 4.0f) * 3.0f, g_WindowHeight / 2.0f };
	const float opening{ g_WindowWidth / 4.0f };
	const float windings{ 8.0f };
	const float angleStep{ 0.01f };

	float angle{ g_Pi / 2.0f };
	float r{};

	SetColor(0.4f, 0.4f, 1.0f);
	while (angle < (windings * (g_Pi * 2.0f) + (g_Pi / 2.0f)))
	{
		const Point2f p1{ center.x + (opening / sqrtf(angle)) * cosf(angle), center.y + (opening / sqrtf(angle)) * sinf(angle) };
		angle += angleStep;
		const Point2f p2{ center.x + (opening / sqrtf(angle)) * cosf(angle), center.y + (opening / sqrtf(angle)) * sinf(angle) };
		DrawLine(p1, p2);
	}
}
#pragma endregion ownDefinitions