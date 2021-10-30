#include "pch.h"
#include "Game.h"

#pragma region gameFunctions											
void Start()
{

}

void Draw()
{
	ClearBackground(0.0f, 0.0f, 0.0f);
	DrawMatches();
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
	case SDLK_1:
		TakeMatches(1);
		break;
	case SDLK_2:
		TakeMatches(2);
		break;
	case SDLK_3:
		TakeMatches(3);
		break;
	case SDLK_r:
		ResetGame();
		break;
	default:
		cout << "Wrong input!" << endl;
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
void DrawMatch(Point2f origin)
{
	SetColor(0.9f, 0.3f, 0.3f);
	FillRect(origin, 3.5f, 50.0f);

	SetColor(0.9f, 0.9f, 0.3f);
	FillRect(origin.x, origin.y + 45.0f, 3.5f, 10.0f);
}

void DrawMatches()
{
	for (int i = 0; i < g_NrMatchesGame; i++)
	{
		DrawMatch(Point2f(20.0f + (i * 10.0f), g_WindowHeight - 80.0f));
	}

	for (int i = 0; i < g_NrMatchesPlayer; i++)
	{
		DrawMatch(Point2f(20.0f + (i * 10.0f), 20.0f));
	}

	for (int i = 0; i < g_NrMatchesCPU; i++)
	{
		DrawMatch(Point2f(20.0f + (g_WindowWidth / 2.0f) + (i * 10.0f), 20.0f));
	}
}

void TakeMatches(int nrMatches)
{
	if (nrMatches > g_NrMatchesGame)
	{
		cout << "There are not enough matches left!" << endl;
		return;
	}

	g_MovesPlayer += to_string(nrMatches) + " ";
	g_NrMatchesPlayer += nrMatches;
	g_NrMatchesGame -= nrMatches;

	if (g_NrMatchesGame <= 0)
	{
		cout << "CPU Moves: " << g_MovesCPU << endl;
		cout << "Your Moves: " << g_MovesPlayer << endl;
		cout << "CPU Wins!" << endl << "Press 'R' to reset...";
		return;
	}

	int nrMatchesCPU{ 0 };
	do
	{
		nrMatchesCPU = int(GenerateRandomNumber(1, 3));
	} while (nrMatchesCPU > g_NrMatchesGame);

	g_MovesCPU += to_string(nrMatchesCPU) + " ";
	g_NrMatchesCPU += nrMatchesCPU;
	g_NrMatchesGame -= nrMatchesCPU;

	if (g_NrMatchesGame <= 0)
	{
		cout << "CPU Moves: " << g_MovesCPU << endl;
		cout << "Your Moves: " << g_MovesPlayer << endl;
		cout << "You Win!" << endl << "Press 'R' to reset..." << endl;
		return;
	}
}

void ResetGame()
{
	g_NrMatchesGame = 21;
	g_NrMatchesPlayer = g_NrMatchesCPU = 0;

	cout << endl << "Game reset!" << endl << endl;
}
#pragma endregion ownDefinitions