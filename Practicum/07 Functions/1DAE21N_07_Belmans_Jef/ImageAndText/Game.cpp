#include "pch.h"
#include "Game.h"
#include <iostream>

#pragma region gameFunctions											
void Start()
{
	bool isSuccess{ TextureFromFile("resources/dae.png", g_DaeTexture) };
	if (!isSuccess) cout << "Failed to load texture!" << endl;

	isSuccess = TextureFromString("Hello world!", "resources/DIN-Light.otf", 34, Color4f(1.0f, 0.2f, 0.0f), g_TextTexture);
	if (!isSuccess) cout << "Failed to create text!" << endl;
}

void Draw()
{
	ClearBackground(0.0f, 0.2f, 0.4f);

	const Point2f texPos{ 10.0f, g_WindowHeight - (g_DaeTexture.height + 10.0f) };
	const Point2f textPos{ 10.0f, g_WindowHeight - (g_DaeTexture.height + 50.0f) };

	DrawTexture(g_DaeTexture, texPos);
	DrawTexture(g_TextTexture, textPos);
}

void Update(float elapsedSec)
{
	
}

void End()
{
	DeleteTexture(g_DaeTexture);
	DeleteTexture(g_TextTexture);
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

#pragma endregion ownDefinitions