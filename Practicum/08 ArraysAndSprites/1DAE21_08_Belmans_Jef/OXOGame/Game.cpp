#include "pch.h"
#include "Game.h"
#include <iostream>

#pragma region gameFunctions
void Start()
{
	LoadTextures(g_Textures);
	CreateCells(g_BoardCells, g_NrCells);
}

void Draw()
{
	ClearBackground();
	DrawCells(g_BoardCells, g_NrCells);
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
	SwitchPlayerSprite(key);
}

void OnKeyUpEvent(SDL_Keycode key)
{
	
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	CheckUIClicked(Point2f(float(e.x), float(g_WindowHeight - e.y)), g_BoardCells, g_NrCells);
}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{

}
#pragma endregion inputHandling

#pragma region ownDefinitions
void LoadTextures(Texture* pTextures)
{
	TextureFromFile("resources/bg.jpg", pTextures[int(TextureType::background)]);
	TextureFromFile("resources/White_O.png", pTextures[int(TextureType::whiteO)]);
	TextureFromFile("resources/White_X.png", pTextures[int(TextureType::whiteX)]);
	TextureFromFile("resources/Green_O.png", pTextures[int(TextureType::greenO)]);
	TextureFromFile("resources/Green_X.png", pTextures[int(TextureType::greenX)]);
	TextureFromFile("resources/Empty_Cell.png", pTextures[int(TextureType::emtypCell)]);
	TextureFromFile("resources/Win.png", pTextures[int(TextureType::winCell)]);
}

void FreeResources(Texture* pTextures, const int size)
{
	for (int i = 0; i < size; i++)
	{
		DeleteTexture(pTextures[i]);
	}
}

void CheckUIClicked(const Point2f& clickedPos, Cell* pBoardCells, const int size)
{
	if (IsGameWon()) return;

	const float cellSize{ pBoardCells[0].dstRect.width };
	for (int i = 0; i < size; i++)
	{
		if (clickedPos.x >= pBoardCells[i].dstRect.left
			&& clickedPos.x <= pBoardCells[i].dstRect.left + cellSize
			&& clickedPos.y >= pBoardCells[i].dstRect.bottom
			&& clickedPos.y <= pBoardCells[i].dstRect.bottom + cellSize)
		{
			if (IsEmpty(pBoardCells[i].type))
			{
				pBoardCells[i].type = g_PlayerCells[g_ActivePlayer].type;
				pBoardCells[i].texture = g_PlayerCells[g_ActivePlayer].texture;

				if (IsGameWon())
				{
					g_PlayerCells[g_ActivePlayer].type = TextureType::winCell;
					g_PlayerCells[g_ActivePlayer].texture = g_Textures[int(TextureType::winCell)];
				}
				g_ActivePlayer = ++g_ActivePlayer % 2;
			}
		}
	}
}

void SwitchPlayerSprite(const SDL_Keycode& pressedKey)
{
	if (pressedKey == SDLK_a)
	{
		if (g_PlayerCells[0].type == TextureType::whiteO)
		{
			g_PlayerCells[0].type = TextureType::whiteX;
		}
		else if (g_PlayerCells[0].type == TextureType::whiteX)
		{
			g_PlayerCells[0].type = TextureType::whiteO;
		}

		g_PlayerCells[0].texture = g_Textures[int(g_PlayerCells[0].type)];
	}
	else if (pressedKey == SDLK_i)
	{
		if (g_PlayerCells[1].type == TextureType::whiteO)
		{
			g_PlayerCells[1].type = TextureType::whiteX;
		}
		else if (g_PlayerCells[1].type == TextureType::whiteX)
		{
			g_PlayerCells[1].type = TextureType::whiteO;
		}

		g_PlayerCells[1].texture = g_Textures[int(g_PlayerCells[1].type)];
	}
}

void CreateCells(Cell* pCells, const int size)
{
	const float cellSize{ g_Textures[int(TextureType::emtypCell)].width };
	const float spacing{ 5.0f };
	const Point2f startPos{ (g_WindowWidth / 2.0f) - (cellSize * 1.5f) - spacing, (g_WindowHeight / 2.0f) + (cellSize * 0.5f) + spacing };

	for (int i = 0; i < size; i++)
	{
		Rectf dstRect
		{
			startPos.x + ((i % 3) * (cellSize + spacing)),
			startPos.y - ((i / 3) * (cellSize + spacing)),
			cellSize,
			cellSize
		};

		pCells[i].dstRect = dstRect;
		pCells[i].texture = g_Textures[int(TextureType::emtypCell)];
		pCells[i].type = TextureType::emtypCell;
	}

	Rectf leftPlayerRect
	{
		20.0f,
		20.0f,
		cellSize,
		cellSize
	};

	Rectf rightPlayerRect
	{
		g_WindowWidth - (cellSize + 20.0f),
		20.0f,
		cellSize,
		cellSize
	};

	g_PlayerCells[0].dstRect = leftPlayerRect;
	g_PlayerCells[0].texture = g_Textures[int(TextureType::whiteX)];
	g_PlayerCells[0].type = TextureType::whiteX;

	g_PlayerCells[1].dstRect = rightPlayerRect;
	g_PlayerCells[1].texture = g_Textures[int(TextureType::whiteX)];
	g_PlayerCells[1].type = TextureType::whiteX;
}

void DrawCells(Cell* pCells, const int size)
{
	DrawTexture(g_Textures[int(TextureType::background)], Point2f(0.0f, 0.0f));
	DrawTexture(g_PlayerCells[0].texture, g_PlayerCells[0].dstRect);
	DrawTexture(g_PlayerCells[1].texture, g_PlayerCells[1].dstRect);

	for (int i = 0; i < size; i++)
	{
		DrawTexture(pCells[i].texture, pCells[i].dstRect);
	}
}

bool IsEmpty(const TextureType& type)
{
	return type == TextureType::emtypCell;
}

bool IsGameWon()
{
	return
		(g_BoardCells[0].type == TextureType::whiteO && g_BoardCells[1].type == TextureType::whiteX && g_BoardCells[2].type == TextureType::whiteO) ||
		(g_BoardCells[3].type == TextureType::whiteO && g_BoardCells[4].type == TextureType::whiteX && g_BoardCells[5].type == TextureType::whiteO) ||
		(g_BoardCells[6].type == TextureType::whiteO && g_BoardCells[7].type == TextureType::whiteX && g_BoardCells[8].type == TextureType::whiteO) ||
		(g_BoardCells[0].type == TextureType::whiteO && g_BoardCells[3].type == TextureType::whiteX && g_BoardCells[6].type == TextureType::whiteO) ||
		(g_BoardCells[1].type == TextureType::whiteO && g_BoardCells[4].type == TextureType::whiteX && g_BoardCells[7].type == TextureType::whiteO) ||
		(g_BoardCells[2].type == TextureType::whiteO && g_BoardCells[5].type == TextureType::whiteX && g_BoardCells[8].type == TextureType::whiteO) ||
		(g_BoardCells[0].type == TextureType::whiteO && g_BoardCells[4].type == TextureType::whiteX && g_BoardCells[8].type == TextureType::whiteO) ||
		(g_BoardCells[6].type == TextureType::whiteO && g_BoardCells[4].type == TextureType::whiteX && g_BoardCells[2].type == TextureType::whiteO);
}
#pragma endregion ownDefinitions

#pragma region Structs
Cell::Cell()
	:Cell{ Texture(), TextureType::background, Rectf() }
{
}

Cell::Cell(Texture texture, TextureType type, Rectf dstRect)
	: texture{ texture }
	, type{ type }
	, dstRect{ dstRect }
{
}
#pragma endregion