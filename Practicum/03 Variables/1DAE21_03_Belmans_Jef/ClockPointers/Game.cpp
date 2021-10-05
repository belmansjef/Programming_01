#include "pch.h"
#include "Game.h"

#pragma region gameFunctions											
void Start()
{

}

void Draw()
{
	ClearBackground();
	DrawPointers();
}

void Update(float elapsedSec)
{
	g_NrFrames = ++g_NrFrames % int(g_FramesPerRotation * 12);
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
void DrawPointers()
{
	float currentAngleRad{ g_AnglePerFrameRad * (g_NrFrames % 240) };

	Point2f center
	(
		g_WindowWidth / 2.0f,
		g_WindowHeight / 2.0f
	);

	Point2f p1
	(
		cosf(currentAngleRad) * g_PointerLength + center.x,
		sinf(currentAngleRad) * g_PointerLength + center.y
	);

	SetColor(1.0f, 1.0f, 1.0f);
	DrawLine(center, p1, 2.0f);
}
#pragma endregion ownDefinitions