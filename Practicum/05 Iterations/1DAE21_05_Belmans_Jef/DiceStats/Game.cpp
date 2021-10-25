#include "pch.h"
#include "Game.h"

using namespace std;

#pragma region gameFunctions											
void Start()
{

}

void Draw()
{
	ClearBackground(0.1f, 0.05f, 0.3f);
	ThrowDice();
	DrawDiceStats();
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
void ThrowDice()
{
	const int oneDiceThrow{ int(GenerateRandomNumber(0.0f, 5.0f)) };
	const int twoDiceThrow{ int(GenerateRandomNumber(0.0f, 10.0f)) };

	++g_SingleDiceThrows[oneDiceThrow];
	++g_DoubleDiceThrows[twoDiceThrow];
}

void DrawDiceStats()
{
	const float barHeight{ (g_WindowHeight - 30.0f) / 17.0f };
	
	// Draw one dice stats
	SetColor(0.8f, 0.2f, 0.4f);
	for (int i = 0; i < 6; i++)
	{
		FillRect(10.0f, 10.0f + (barHeight * i), float(g_SingleDiceThrows[i]), barHeight - 5.0f);
	}

	// Draw two dice stats
	SetColor(0.4f, 0.2f, 0.8f);
	for (int i = 0; i < 11; i++)
	{
		FillRect(10.0f, 20.0f + (barHeight * 6.0f) + (barHeight * i), float(g_DoubleDiceThrows[i]), barHeight - 5.0f);
	}
}
#pragma endregion ownDefinitions