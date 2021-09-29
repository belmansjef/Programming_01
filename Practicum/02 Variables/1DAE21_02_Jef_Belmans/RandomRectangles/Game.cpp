#include "pch.h"
#include "Game.h"

#pragma region gameFunctions											
void Start()
{

}

void Draw()
{
	ClearBackground();

	DrawRandomRectangle(g_Padding);
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
void DrawRandomRectangle(int padding)
{
	float rectWidth{ float(rand() % (int(g_WindowWidth) - padding + 1)) };
	float rectHeight{ float(rand() % (int(g_WindowHeight) - padding + 1))};

	float minHorizontal{ float(padding) };
	float maxHorizontal{ g_WindowWidth - (padding + rectWidth)  };
	float minVertical{ float(padding) };
	float maxVertical{ g_WindowHeight - (padding + rectHeight) };

	Point2f pos
	{
		(rand() % (int((maxHorizontal - minHorizontal) * 100) + 1) + int(minHorizontal * 100)) / 100.0f,
		(rand() % (int((maxVertical - minVertical) * 100) + 1) + int(minVertical * 100)) / 100.0f
	};

	SetColor(RandomColor());
	FillRect(pos, rectWidth, rectHeight);
}

Color4f RandomColor()
{
	return Color4f((rand() % 101) / 100.0f, (rand() % 101) / 100.0f, (rand() % 101) / 100.0f, 1.0f);
}
#pragma endregion ownDefinitions