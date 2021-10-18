#include "pch.h"
#include "Game.h"

#pragma region gameFunctions											
void Start()
{

}

void Draw()
{
	ClearBackground();
	DrawMouseSquare();
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
	cout << endl << "SDL_KEYDOWN" << endl;
}

void OnKeyUpEvent(SDL_Keycode key)
{
	cout << endl << "SDL_KEYUP" << endl;
	if (key == SDLK_LEFT)
	{
		cout << "    Left arrow is released" << endl;
	}
	else if (key == SDLK_RIGHT)
	{
		cout << "    Right arrow is released" << endl;
	}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	g_MousePos.x = float(e.x);
	g_MousePos.y = float(g_WindowHeight - e.y);
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	cout << endl << "SDL_MOUSEBUTTONDOWN" << endl;
	cout << "    [" << e.x << ", " << (g_WindowHeight - e.y) << "]" << endl;

	if (e.button == SDL_BUTTON_LEFT)
	{
		cout << "    Left mouse button went down" << endl;
	}
	else if (e.button == SDL_BUTTON_MIDDLE)
	{
		cout << "    Middle mouse button went down" << endl;
	}
	else if (e.button == SDL_BUTTON_RIGHT)
	{
		cout << "    Right mouse button went down" << endl;
	}
}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	cout << endl << "SDL_MOUSEBUTTONUP" << endl;
}
#pragma endregion inputHandling

#pragma region ownDefinitions
void DrawMouseSquare()
{
	float size{ 10.0f };

	Rectf square{ g_MousePos.x - (size / 2.0f), g_MousePos.y - (size / 2.0f), size, size};

	SetColor(1.0f, 0.1f, 0.1f);
	FillRect(square);
}
#pragma endregion ownDefinitions