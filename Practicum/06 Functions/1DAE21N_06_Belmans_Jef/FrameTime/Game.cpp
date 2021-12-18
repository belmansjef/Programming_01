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
	SetColor(0.8f, 0.4f, 0.0f);
	DrawBall();
	SetColor(1.0f, 1.0f, 0.0f);
	DrawFreeFall();
}

void Update(float elapsedSec)
{
	UpdateBall(elapsedSec);

	UpdateFreeFall(elapsedSec);

	UpdateNrFrames();
	UpdateAccumulatedTime(elapsedSec);
	UpdateFramerate(elapsedSec);

	if (g_NrFrames % 100 == 0)
	{
		// PrintFrameStats();
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
	switch (key)
	{
	case SDLK_s:
		isGravityEnabled = !isGravityEnabled;
		break;
	default:
		break;
	}
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

void UpdateBall(const float deltaTime)
{
	g_BallPos.x += g_BallVelocity.x * deltaTime;
	g_BallPos.y += g_BallVelocity.y * deltaTime;

	if (g_BallPos.x + g_BallRadius > g_WindowWidth || g_BallPos.x - g_BallRadius < 0.0f)
	{
		g_BallVelocity.x = -g_BallVelocity.x;
	}

	if (g_BallPos.y + g_BallRadius > g_WindowHeight || g_BallPos.y - g_BallRadius < 0.0f)
	{
		g_BallVelocity.y = -g_BallVelocity.y;
	}
}

void DrawBall()
{
	FillEllipse(g_BallPos, g_BallRadius, g_BallRadius);
}

void UpdateFreeFall(const float deltaTime)
{
	if (!isGravityEnabled) return;

	g_FreeFallPos.y = g_WindowHeight - (g_FreeFallSize + 5.0f) + (g_Gravity.y * powf(g_FreeFallTime, 2.0f)) / 2.0f;

	g_FreeFallTime += deltaTime;
	cout << g_FreeFallTime << endl;

	if (g_FreeFallPos.y - g_FreeFallSize < 0.0f)
	{
		g_FreeFallPos.y = g_WindowHeight - (g_FreeFallSize + 5.0f);
		g_FreeFallTime = 0.0f;
		isGravityEnabled = false;
	}
}

void DrawFreeFall()
{
	FillRect(g_FreeFallPos, g_FreeFallSize, g_FreeFallSize);
}
#pragma endregion ownDefinitions