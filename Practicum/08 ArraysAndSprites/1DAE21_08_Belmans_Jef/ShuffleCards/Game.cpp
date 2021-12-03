#include "pch.h"
#include "Game.h"
#include <iostream>
#include <iomanip>

#pragma region gameFunctions
void Start()
{
	InitCards(g_Cards, g_NrCards);
}

void Draw()
{
	ClearBackground();
	DrawCards(g_Cards, g_NrCards);
}

void Update(float elapsedSec)
{
	
}

void End()
{
	DeleteCards(g_Cards, g_NrCards);
}
#pragma endregion gameFunctions

#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{
	switch (key)
	{
	case SDLK_s:
		ShuffleCards(g_Cards, g_NrCards, 100);
		break;
	default:
		break;
	}
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
void InitCards(Texture* pCards, const int size)
{
	for (int x = 1; x < 5; x++)
	{
		for (int y = 1; y < 14; y++)
		{
			const int idx{ ((x - 1) * 13) + (y - 1) };
			std::cout << "Current index: " << idx << std::endl;

			std::string filepath{};
			if (y < 10)
			{
				filepath =  "resources/" + std::to_string(x) + "0" + std::to_string(y) + ".png";
			}
			else
			{
				filepath = "resources/" + std::to_string(x) + std::to_string(y) + ".png";
			}

			TextureFromFile(filepath, pCards[idx]);			
		}
	}
}
void DeleteCards(Texture* pCards, const int size)
{
	for (int i = 0; i < size; i++)
	{
		DeleteTexture(pCards[i]);
	}
}
void DrawCards(const Texture* pCards, const int size)
{
	for (int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 14; y++)
		{
			const int idx{ (x * 13) + y };
			const Rectf destRect
			{
				(pCards[0].width / 2.0f) * y,
				g_WindowHeight - ((pCards[0].height / 2.0f) * (x + 1)),
				pCards[0].width / 2.0f,
				pCards[0].height / 2.0f
			};

			DrawTexture(pCards[idx], destRect);
		}
	}
}
void ShuffleCards(Texture* pCards, const int size, const int nrShuffles)
{
	for (int i = 0; i < nrShuffles; i++)
	{
		const int idx1{ int(GenerateRandomNumber(0, size)) };
		int idx2{ int(GenerateRandomNumber(0, size)) };

		while (idx1 == idx2)
		{
			idx2 = int(GenerateRandomNumber(0, size));
		}

		const Texture tex1{ pCards[idx1] };
		const Texture tex2{ pCards[idx2] };

		pCards[idx1] = tex2;
		pCards[idx2] = tex1;
	}
}
#pragma endregion ownDefinitions