#include "pch.h"
#include "Game.h"

using namespace std;

#pragma region gameFunctions											
void Start()
{

}

void Draw()
{
	ClearBackground(0.0f, 0.0f, 0.0f);
	DrawLines();
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
	switch (key)
	{
	case SDLK_RIGHT:
		SwitchColor();
		break;
	default:
		break;
	}
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
void DrawLines()
{
	switch (g_Color)
	{
	case Color::red:
		SetColor(0.8f, 0.2f, 0.2f);
		break;
	case Color::green:
		SetColor(0.2f, 0.8f, 0.2f);
		break;
	case Color::blue:
		SetColor(0.2f, 0.2f, 0.8f);
		break;
	}

	for (int i = 0; i < g_WindowWidth / 9.0f; i++)
	{
		Point2f pBottom
		{
			9.0f * i,
			0.0f
		};

		Point2f pTop
		{
			9.0f * i,
			g_WindowHeight
		};

		DrawLine(pBottom, g_MousePos);
		DrawLine(pTop, g_MousePos);
	}

	for (int i = 0; i < g_WindowHeight / 9.0f; i++)
	{
		Point2f pLeft
		{
			0.0f,
			9.0f * i
		};

		Point2f pRight
		{
			g_WindowWidth,
			9.0f * i
		};

		DrawLine(pLeft, g_MousePos);
		DrawLine(pRight, g_MousePos);
	}
}

void SwitchColor()
{
	g_Color = Color((int(g_Color) + 1) % 3);
}
#pragma endregion ownDefinitions