#include "pch.h"
#include "Game.h"
#include "Vehicle.h"
#include <iostream>

#pragma region gameFunctions											
void Start()
{
	InitializeResources();
	PrintInstructions();
}	

void Draw()
{
	ClearBackground();
	DrawFrame();
}

void Update(float elapsedSec)
{
	for (int i = 0; i < g_NumVehicles; i++)
	{
		g_pVehicles[i]->Update(elapsedSec, g_WindowWidth);
		if (g_pVehicles[i]->IsIntersecting(g_PlayerChicken.position))
		{
			StopChicken();
			g_CurrentState = GameState::lose;
			g_pVehicles[i]->SetActive(false);
		}
	}

	if (g_PlayerChicken.isMovingDown)
	{
		g_PlayerChicken.position.y -= g_PlayerChicken.speed * elapsedSec;
	}

	if (g_PlayerChicken.isMovingLeft)
	{
		g_PlayerChicken.position.x -= g_PlayerChicken.speed * elapsedSec;
	}

	if (g_PlayerChicken.isMovingRight)
	{
		g_PlayerChicken.position.x += g_PlayerChicken.speed * elapsedSec;
	}

	// Chicken reached pavement
	if ((g_PlayerChicken.position.y + g_PlayerChicken.height / 2.0f) <= 43.0f)
	{
		g_CurrentState = GameState::win;
		StopChicken();
	}
}
void End()
{
	FreeResources();
}
#pragma endregion gameFunctions

#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{
	switch (key)
	{
	case SDLK_DOWN:
		if (g_CurrentState != GameState::play) return;
		g_PlayerChicken.isMovingDown = true;
		break;
	case SDLK_LEFT:
		if (g_CurrentState != GameState::play) return;
		g_PlayerChicken.isMovingLeft = true;
		break;
	case SDLK_RIGHT:
		if (g_CurrentState != GameState::play) return;
		g_PlayerChicken.isMovingRight = true;
		break;
	case SDLK_r:
		ResetChicken();
		ResetVehicles();
		break;
	case SDLK_p:
		PauseGame();
		break;
	default:
		break;
	}
}

void OnKeyUpEvent(SDL_Keycode key)
{
	switch (key)
	{
	case SDLK_DOWN:
		g_PlayerChicken.isMovingDown = false;
		break;
	case SDLK_LEFT:
		g_PlayerChicken.isMovingLeft = false;
		break;
	case SDLK_RIGHT:
		g_PlayerChicken.isMovingRight = false;
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
void InitializeResources()
{
	// Background
	TextureFromFile("Resources/street.PNG", g_StreetTexture);

	// Text
	TextureFromString("The chicken survived!", "Resources/consola.ttf", 40, Color4f(1.0f, 1.0f, 1.0f), g_WinText);
	TextureFromString("The chicken died!", "Resources/consola.ttf", 40, Color4f(1.0f, 1.0f, 1.0f), g_LoseText);
	TextureFromString("Pause", "Resources/consola.ttf", 40, Color4f(1.0f, 1.0f, 1.0f), g_PauseText);

	// Vehicles
	bool isIndexGenerated[5]{};
	for (int i = 0; i < g_NumVehicles; i++)
	{
		int rnd{ int(GenerateRandomNumber(0, 4)) };
		while (isIndexGenerated[rnd]) {
			rnd = int(GenerateRandomNumber(0, 4));
		}
		isIndexGenerated[rnd] = true;
		g_pVehicles[i] = new Vehicle{ rnd + 1 };
		g_pVehicles[i]->SetYPos(43.0f + (45.0f * i));
	}

	// Chicken
	TextureFromFile("Resources/Chicken.bmp", g_PlayerChicken.image);	

	g_PlayerChicken.width = g_PlayerChicken.image.width / 3.0f;
	g_PlayerChicken.height = g_PlayerChicken.image.height;

	g_PlayerChicken.position.x = g_WindowWidth / 2.0f;
	g_PlayerChicken.position.y = g_WindowHeight - 20.0f;
	g_PlayerChicken.speed = 100.0f;

	g_CurrentState = GameState::play;
}

void FreeResources()
{
	DeleteTexture(g_StreetTexture);
	delete[] *g_pVehicles;
}

void StopChicken()
{
	g_PlayerChicken.isMovingDown = false;
	g_PlayerChicken.isMovingLeft = false;
	g_PlayerChicken.isMovingRight = false;
}

void ResetChicken()
{
	g_PlayerChicken.position.x = g_WindowWidth / 2.0f;
	g_PlayerChicken.position.y = g_WindowHeight - 20.0f;

	g_CurrentState = GameState::play;
}

void ResetVehicles()
{
	for (int i = 0; i < g_NumVehicles; i++)
	{
		g_pVehicles[i]->Reset();
	}
}

void PauseGame()
{
	switch (g_CurrentState)
	{
	case GameState::play:
		g_CurrentState = GameState::pause;
		StopChicken();
		for (int i = 0; i < g_NumVehicles; i++)
		{
			g_pVehicles[i]->SetActive(false);
		}
		break;
	case GameState::pause:
		g_CurrentState = GameState::play;
		for (int i = 0; i < g_NumVehicles; i++)
		{
			g_pVehicles[i]->SetActive(true);
		}
		break;
	default:
		break;
	}
}

void PrintInstructions()
{
	std::cout << "Press r to reset\r\nPress p to pause/unpause\r\nUse the arrow keys to move the chicken\r\n";
}

void DrawFrame()
{
	// Background
	DrawTexture(g_StreetTexture, Point2f(0.0f, 0.0f));

	// Chicken
	const Rectf dstRect
	{
		g_PlayerChicken.position.x - (g_PlayerChicken.width / 2.0f),
		g_PlayerChicken.position.y - (g_PlayerChicken.height / 2.0f),
		40.0f,
		40.0f,
	};
	 
	float left{};

	if (g_PlayerChicken.isMovingDown)
	{
		left = 0.0f;
	}

	if (g_PlayerChicken.isMovingLeft)
	{
		left = g_PlayerChicken.width;
	}

	if (g_PlayerChicken.isMovingRight)
	{
		left = g_PlayerChicken.width * 2.0f;
	}

	const Rectf srcRect
	{
		left,
		g_PlayerChicken.height,
		g_PlayerChicken.width - 1.0f,
		g_PlayerChicken.height,
	};

	DrawTexture(g_PlayerChicken.image, dstRect, srcRect);

	// Vehicles
	for (int i = 0; i < g_NumVehicles; i++)
	{
		g_pVehicles[i]->Draw();
	}

	// Text
	Point2f textPos{};
	Rectf bgRect{};
	switch (g_CurrentState)
	{
	case GameState::pause:
		textPos = Point2f(g_WindowWidth / 2.0f - (g_PauseText.width / 2.0f), g_WindowHeight / 2.0f - (g_PauseText.height / 2.0f));
		bgRect = Rectf
		(
			textPos.x,
			textPos.y,
			g_PauseText.width,
			g_PauseText.height
		);

		SetColor(0.0f, 0.0f, 0.0f, 0.4f);
		FillRect(bgRect);

		DrawTexture(g_PauseText, textPos);
		break;
	case GameState::win:
		textPos = Point2f(g_WindowWidth / 2.0f - (g_WinText.width / 2.0f), g_WindowHeight / 2.0f - (g_WinText.height / 2.0f));
		bgRect = Rectf
		(
			textPos.x,
			textPos.y,
			g_WinText.width,
			g_WinText.height
		);

		SetColor(0.0f, 0.0f, 0.0f, 0.4f);
		FillRect(bgRect);

		DrawTexture(g_WinText, textPos);
		break;
	case GameState::lose:
		textPos = Point2f(g_WindowWidth / 2.0f - (g_LoseText.width / 2.0f), g_WindowHeight / 2.0f - (g_LoseText.height / 2.0f));
		bgRect = Rectf
		(
			textPos.x,
			textPos.y,
			g_LoseText.width,
			g_LoseText.height
		);

		SetColor(0.0f, 0.0f, 0.0f, 0.4f);
		FillRect(bgRect);

		DrawTexture(g_LoseText, textPos);
		break;
	default:
		break;
	}
}
#pragma endregion ownDefinitions