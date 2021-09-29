#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions
void Start()
{
	// initialize game resources here
	CalculateColorBandRatios((g_WindowWidth / 2.0f) - (2.0f * g_CellPadding), (g_WindowHeight / 3.0f) - (2.0f * g_CellPadding));
	GenerateColorBandColors();
}

void Draw()
{
	ClearBackground(0.3f, 0.0f, 0.3f);

	DrawHouse(Point2f(static_cast<float>(g_CellPadding), ((g_WindowHeight / 3.0f) * 2.0f) + g_CellPadding), (g_WindowWidth / 2.0f) - (2.0f * g_CellPadding), (g_WindowHeight / 3.0f) - (2.0f * g_CellPadding));
	DrawFlag(Point2f(static_cast<float>(g_CellPadding), ((g_WindowHeight / 3.0f) * 1.0f) + g_CellPadding), (g_WindowWidth / 2.0f) - (2.0f * g_CellPadding), (g_WindowHeight / 3.0f) - (2.0f * g_CellPadding));
	DrawCheckerPattern(Point2f(static_cast<float>(g_CellPadding), ((g_WindowHeight / 3.0f) * 0.0f) + g_CellPadding), (g_WindowWidth / 2.0f) - (2.0f * g_CellPadding), (g_WindowHeight / 3.0f) - (2.0f * g_CellPadding));
	DrawColorBand(Point2f((g_WindowWidth / 2.0f) + g_CellPadding, ((g_WindowHeight / 3.0f) * 2.0f) + g_CellPadding), g_ColorbandWidth);
}

void Update(float elapsedSec)
{
	// process input, do physics 

	// e.g. Check keyboard state
	//const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	//if ( pStates[SDL_SCANCODE_RIGHT] )
	//{
	//	std::cout << "Right arrow key is down\n";
	//}
	//if ( pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
	//{
	//	std::cout << "Left and up arrow keys are down\n";
	//}
}

void End()
{
	// free game resources here
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{

}

void OnKeyUpEvent(SDL_Keycode key)
{
	//switch (key)
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	////std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//switch (e.button)
	//{
	//case SDL_BUTTON_LEFT:
	//{
	//	//std::cout << "Left mouse button released\n";
	//	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
	//	break;
	//}
	//case SDL_BUTTON_RIGHT:
	//	//std::cout << "Right mouse button released\n";
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	//std::cout << "Middle mouse button released\n";
	//	break;
	//}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
void DrawHouse(Point2f pos, float width, float height)
{
	utils::SetColor(g_ColorRed);
	utils::FillRect(pos, width, height / 2.0f);
	utils::FillTriangle(Point2f(pos.x, pos.y + height / 2.0f), Point2f(pos.x + width / 2.0f, pos.y + height), Point2f(pos.x + width, pos.y + height / 2.0f));
	utils::SetColor(g_ColorWhite);
	utils::DrawRect(pos, width, height / 2.0f, 2.0f);
	utils::DrawTriangle(Point2f(pos.x, pos.y + height / 2.0f), Point2f(pos.x + width / 2.0f, pos.y + height), Point2f(pos.x + width, pos.y + height / 2.0f), 2.0f);
}

void DrawFlag(Point2f pos, float width, float height)
{
	utils::SetColor(g_ColorBlack);
	utils::FillRect(pos, width / 3.0f, height);
	utils::SetColor(g_ColorYellow);
	utils::FillRect(Point2f(pos.x + 1.0f * (width / 3.0f), pos.y), width / 3.0f, height);
	utils::SetColor(g_ColorRed);
	utils::FillRect(Point2f(pos.x + 2.0f * (width / 3.0f), pos.y), width / 3.0f, height);
	utils::SetColor(g_ColorWhite);
	utils::DrawRect(pos, width, height, 2.0f);
}

void DrawCheckerPattern(Point2f pos, float width, float height)
{
	// Draw white background square
	utils::SetColor(g_ColorWhite);
	utils::FillRect(Point2f(pos.x - 2.0f, pos.y - 2.0f), width + 4.0f, height + 4.0f);

	// Draw black squares
	utils::SetColor(g_ColorBlack);
	for (int x = 0; x < g_CheckerRows; x++)
	{
		for (int y = 0; y < g_CheckerCollumns; y++)
		{
			// On even rows we want to draw black in even collumns
			if (x % 2 == 0)
			{
				if (y % 2 == 0)
				{
					utils::FillRect(Point2f(pos.x + y * (width / g_CheckerCollumns), pos.y + x * (height / g_CheckerRows)), width / g_CheckerCollumns, height / g_CheckerRows);
				}
			}
			// On odd rows we want to draw black in odd collumns
			else if (x % 2 == 1)
			{
				if (y % 2 == 1)
				{
					utils::FillRect(Point2f(pos.x + y * (width / g_CheckerCollumns), pos.y + x * (height / g_CheckerRows)), width / g_CheckerCollumns, height / g_CheckerRows);
				}
			}
		}
	}
}

void DrawColorBand(Point2f pos, float width)
{
	float rectWidth{ width / g_NumColorBands };

	// Yellow border
	utils::SetColor(g_ColorYellow);
	utils::DrawRect(pos, width, rectWidth * 4.0f, 4.0f);

	// Individual color bands
	for (int i = 0; i < g_NumColorBands; i++)
	{
		SetColor(g_ColorBandColors[i]);
		FillRect(Point2f(pos.x + (i * rectWidth), pos.y), rectWidth, rectWidth * 4.0f);
	}
	
	SetColor(g_ColorBlackTransparent);
	FillRect(pos, width, rectWidth * 2.0f);
}

void DrawPentagram(Point2f center, float radius)
{
}

void DrawColumnChart(Point2f pos, float colWidth, float percentages[])
{
}

void CalculateColorBandRatios(float maxWidth, float maxHeight)
{
	float currentWidth{ maxWidth };
	
	// While the calculated height exceeds the max allowed height
	while ((currentWidth / g_NumColorBands) * 4.0f > maxHeight)
	{
		--currentWidth;
	}


	g_ColorbandWidth = currentWidth;
	std::cout << "Max width: " << maxWidth << " Current width: " << currentWidth << std::endl;
}

void GenerateColorBandColors()
{
	for (int i = 0; i < g_NumColorBands; i++)
	{
		g_ColorBandColors[i] = Color4f( (rand() % 101) / 100.0f, (rand() % 101) / 100.0f, (rand() % 101) / 100.0f, 1.0f );
	}
}
#pragma endregion ownDefinitions