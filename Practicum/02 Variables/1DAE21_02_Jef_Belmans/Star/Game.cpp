#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
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
void DrawStar()
{

}

void CalculateVerts()
{
	float angle_30{ 30 * (g_Pi / 180.0f) };
	float angle_45{ 45 * (g_Pi / 180.0f) };
	float angle_60{ 60 * (g_Pi / 180.0f) };
	float angle_90{ 90 * (g_Pi / 180.0f) };

	Point2f verts[16];
	
	for (int i = 0; i < sizeof(verts); i++)
	{
		switch (i + 1 % 4)
		{
			case 1:
				Point2f p{};
				break;
			case 2:
				break;
			case 3:
				break;
			case 0:
				break;
			default:
				std::cout << "Error calculating verts";
				break;
		}
	}
}
#pragma endregion ownDefinitions