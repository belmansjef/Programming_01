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
	g_NrFrames = ++g_NrFrames % int(g_FramesPerRotationMinutePointer * 12);
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
	const float minutePointerLength{ 200.0f };
	const float hourPointerLength{ minutePointerLength * (2.0f / 3.0f) };

	const float anglePerFrameRad{ (360.0f / g_FramesPerRotationMinutePointer) * (g_Pi / 180.0f) };
	const float offsetAngleRad{ g_Pi / 16.0f };

	const float currentAngleMinutePointerRad{ g_Pi / 2.0f - (anglePerFrameRad * (g_NrFrames % int(g_FramesPerRotationMinutePointer))) };
	const float currentAngleHourPointerRad{ g_Pi / 2.0f - ((anglePerFrameRad / 12) * g_NrFrames) };

	Point2f center
	(
		g_WindowWidth / 2.0f,
		g_WindowHeight / 2.0f
	);

	Point2f pMinutePointer1
	(
		cosf(currentAngleMinutePointerRad + offsetAngleRad) * (minutePointerLength / 3.0f) + center.x,
		sinf(currentAngleMinutePointerRad + offsetAngleRad) * (minutePointerLength / 3.0f) + center.y
	);

	Point2f pMinutePointer2
	(
		cosf(currentAngleMinutePointerRad - offsetAngleRad) * (minutePointerLength / 3.0f) + center.x,
		sinf(currentAngleMinutePointerRad - offsetAngleRad) * (minutePointerLength / 3.0f) + center.y
	);

	Point2f pMinutePointer3
	(
		cosf(currentAngleMinutePointerRad) * minutePointerLength + center.x,
		sinf(currentAngleMinutePointerRad) * minutePointerLength + center.y
	);

	Point2f pHourPointer1
	(
		cosf(currentAngleHourPointerRad + offsetAngleRad) * (hourPointerLength / 3.0f) + center.x,
		sinf(currentAngleHourPointerRad + offsetAngleRad) * (hourPointerLength / 3.0f) + center.y
	);

	Point2f pHourPointer2
	(
		cosf(currentAngleHourPointerRad - offsetAngleRad) * (hourPointerLength / 3.0f) + center.x,
		sinf(currentAngleHourPointerRad - offsetAngleRad) * (hourPointerLength / 3.0f) + center.y
	);

	Point2f pHourPointer3
	(
		cosf(currentAngleHourPointerRad) * hourPointerLength + center.x,
		sinf(currentAngleHourPointerRad) * hourPointerLength + center.y
	);

	SetColor(1.0f, 1.0f, 1.0f);

	// Minute pointer
	DrawLine(center, pMinutePointer1);
	DrawLine(center, pMinutePointer2);
	DrawLine(pMinutePointer1, pMinutePointer3);
	DrawLine(pMinutePointer2, pMinutePointer3);

	// Hour pointer
	DrawLine(center, pHourPointer1);
	DrawLine(center, pHourPointer2);
	DrawLine(pHourPointer1, pHourPointer3);
	DrawLine(pHourPointer2, pHourPointer3);
}
#pragma endregion ownDefinitions