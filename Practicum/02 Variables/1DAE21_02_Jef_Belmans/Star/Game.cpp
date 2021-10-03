#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	CalculateVerts();
}

void Draw()
{
	ClearBackground();
	
	DrawStar();
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
	SetColor(1.0f, 0.0f, 0.0f);

	DrawLine(g_Verts[0], g_Verts[8]);
	DrawLine(g_Verts[8], g_Verts[4]);
	DrawLine(g_Verts[4], g_Verts[12]);
	DrawLine(g_Verts[12], g_Verts[1]);

	DrawLine(g_Verts[1], g_Verts[9]);
	DrawLine(g_Verts[9], g_Verts[5]);
	DrawLine(g_Verts[5], g_Verts[13]);
	DrawLine(g_Verts[13], g_Verts[2]);

	DrawLine(g_Verts[2], g_Verts[10]);
	DrawLine(g_Verts[10], g_Verts[6]);
	DrawLine(g_Verts[6], g_Verts[14]);
	DrawLine(g_Verts[14], g_Verts[3]);

	DrawLine(g_Verts[3], g_Verts[11]);
	DrawLine(g_Verts[11], g_Verts[7]);
	DrawLine(g_Verts[7], g_Verts[15]);
	DrawLine(g_Verts[15], g_Verts[0]);
}

void CalculateVerts()
{
	float angle_30{ 30.0f * (g_Pi / 180.0f) };
	float angle_45{ 45.0f * (g_Pi / 180.0f) };
	float angle_60{ 60.0f * (g_Pi / 180.0f) };
	float angle_90{ 90.0f * (g_Pi / 180.0f) };
	
	for (int i = 0; i < 4; i++)
	{
		Point2f p
		(
			cosf(i * angle_90) * g_Radius,
			sinf(i * angle_90) * g_Radius
		);

		g_Verts[i] = p;
	}

	for (int i = 4; i < 8; i++)
	{
		Point2f p
		(
			cosf((i * angle_90) + angle_45) * (g_Radius * (2.0f / 3.0f)),
			sinf((i * angle_90) + angle_45) * (g_Radius * (2 / 3))
		);

		g_Verts[i] = p;
	}

	for (int i = 8; i < 12; i++)
	{
		Point2f p
		(
			cosf((i * angle_90) + angle_30) * (g_Radius / 3),
			sinf((i * angle_90) + angle_30) * (g_Radius / 3)
		);

		g_Verts[i] = p;
	}

	for (int i = 12; i < 16; i++)
	{
		Point2f p
		(
			cosf((i * angle_90) + angle_60) * (g_Radius / 3),
			sinf((i * angle_90) + angle_60) * (g_Radius / 3)
		);

		g_Verts[i] = p;
	}

	// Move star towards center of the screen
	int i{ 0 };
	for (Point2f vert : g_Verts)
	{
		vert.x += g_WindowWidth / 2.0f;
		vert.y += g_WindowHeight / 2.0f;
		g_Verts[i] = vert;
		i++;
	}
}
#pragma endregion ownDefinitions