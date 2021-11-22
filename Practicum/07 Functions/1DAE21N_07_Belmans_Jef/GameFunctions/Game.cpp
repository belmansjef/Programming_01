#include "pch.h"
#include "Game.h"

#pragma region gameFunctions											
void Start()
{
	GenerateRandomCirclef(g_Circle, g_WindowWidth, g_WindowHeight, 65.0f, 20.0f, 60.0f);
	GenerateRandomRectf(g_Rect, g_WindowWidth, g_WindowHeight, 65.0f, 20.0f, 30.0f, 30.0f);
}

void Draw()
{
	ClearBackground(0.0f, 0.0f, 0.0f);
	TestIsPointInCircle();
	TestPointInRect();
	TestIsOverlapping();
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
	g_MousePos.x = float(e.x);
	g_MousePos.y = float(g_WindowHeight - e.y);
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{

}
#pragma endregion inputHandling

#pragma region ownDefinitions
void TestIsPointInCircle()
{
	SetColor(1.0f, 1.0f, 1.0f);
	FillEllipse(g_Circle);

	if (IsPointInCircle(g_Circle, g_MousePos))
	{
		SetColor(1.0f, 0.0f, 0.0f);
		DrawEllipse(g_Circle, 4.0f);
	}
}

void TestPointInRect()
{
	SetColor(1.0f, 1.0f, 1.0f);
	FillRect(g_Rect);

	if (IsPointInRect(g_Rect, g_MousePos))
	{
		SetColor(1.0f, 0.0f, 0.0f);
		DrawRect(g_Rect, 4.0f);
	}
}

void UpdateMouseRectf(Rectf& rect)
{
	rect.left = g_MousePos.x;
	rect.bottom = g_MousePos.y;
}

void UpdateMouseCirclef(Circlef& circle)
{
	circle.center.x = g_MousePos.x + 40.0f; // Yikes, magic number, but I'm lazy
	circle.center.y = g_MousePos.y;
}

void TestIsOverlapping()
{
	Rectf rect{ 0.0f, 0.0f, 20.0f, 10.0f };
	Circlef circle{ 0.0f, 0.0f, 20.0f };

	UpdateMouseRectf(rect);
	UpdateMouseCirclef(circle);

	SetColor(0.0f, 1.0f, 0.0f, 0.5f);
	FillRect(rect);
	FillEllipse(circle);

	SetColor(1.0f, 0.0f, 0.0f, 0.5f);
	if (IsOverlapping(rect, g_Rect))
	{
		FillRect(rect);
	}

	if (IsOverlapping(circle, g_Circle))
	{
		FillEllipse(circle);
	}
}
#pragma endregion ownDefinitions