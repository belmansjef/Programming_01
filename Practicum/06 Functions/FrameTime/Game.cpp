#include "pch.h"
#include "Game.h"

#pragma region gameFunctions											
void Start()
{
	cout << fixed << setprecision(3);
}

void Draw()
{
	ClearBackground();
}

void Update(float elapsedSec)
{
	UpdateNrFrames();
	UpdateAccumulatedTime(elapsedSec);
	UpdateFramerate(elapsedSec);

	if (g_NrFrames % 100 == 0)
	{
		PrintFrameStats();
	}
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
void UpdateNrFrames()
{
	++g_NrFrames;
}
void UpdateAccumulatedTime(const float deltaTime)
{
	g_AccumulatedTime += deltaTime;
}
void UpdateFramerate(const float deltaTime)
{
	g_AvgFrameTime += deltaTime;
	if (g_NrFrames % 100 == 0)
	{
		g_AvgFrameRate = 1.0f / (g_AvgFrameTime / 100.0f);
		g_AvgFrameTime = 0.0f;
	}
	
}
void PrintFrameStats()
{
	cout << "Number of frames: " << g_NrFrames << "\t\tAccumulatedTime: " << g_AccumulatedTime << "\t\tFramerate: " << g_AvgFrameRate << endl;
}
#pragma endregion ownDefinitions