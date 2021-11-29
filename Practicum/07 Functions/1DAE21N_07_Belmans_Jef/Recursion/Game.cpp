#include "pch.h"
#include "Game.h"

#pragma region gameFunctions											
void Start()
{
	
}

void Draw()
{
	ClearBackground(0.0f, 0.2f, 0.4f);
	DrawSierpinskiTriangle(Point2f(0.0f, 0.0f), Point2f(g_WindowWidth / 2.0f, g_WindowHeight), Point2f(g_WindowWidth, 0.0f), 5);
	
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
void DrawSierpinskiTriangle(const Point2f& left, const Point2f& top, const Point2f& right, const int n)
{
	DrawTriangle(left, top, right, 0.0f);

	if(n > 0)
	{
		SetColor(1.0f, 0.0f, 0.0f);
		DrawSierpinskiTriangle(left, GetMidPoint(left, top), GetMidPoint(left, right), n - 1);
		DrawSierpinskiTriangle(top, GetMidPoint(left, top), GetMidPoint(right, top), n - 1);
		DrawSierpinskiTriangle(right, GetMidPoint(right, top), GetMidPoint(left, right), n - 1);
	}
	SetColor(1.0f, 1.0f, 0.0f);
	
}

Point2f GetMidPoint(const Point2f& p1, const Point2f& p2)
{
	return Point2f((p1.x + p2.x) / 2.0f, (p1.y + p2.y) / 2.0f);
}
#pragma endregion ownDefinitions