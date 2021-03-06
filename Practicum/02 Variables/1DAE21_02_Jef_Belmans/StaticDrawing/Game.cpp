#include "pch.h"
#include "Game.h"
#include <iostream>

#pragma region gameFunctions
void Start()
{
	CalculateColorBandRatios((g_WindowWidth / 2.0f) - (2.0f * g_CellPadding), (g_WindowHeight / 3.0f) - (2.0f * g_CellPadding));
	GenerateColorBandColors();
	CalculatePentagramVerts();
	GetColumnChartInput();
}

void Draw()
{
	ClearBackground(0.3f, 0.0f, 0.3f);

	DrawHouse(Point2f(0.0f * (g_WindowWidth / 2.0f) + g_CellPadding, ((g_WindowHeight / 3.0f) * 2.0f) + g_CellPadding), (g_WindowWidth / 2.0f) - (2.0f * g_CellPadding), (g_WindowHeight / 3.0f) - (2.0f * g_CellPadding));
	DrawFlag(Point2f(0.0f * (g_WindowWidth / 2.0f) + g_CellPadding, ((g_WindowHeight / 3.0f) * 1.0f) + g_CellPadding), (g_WindowWidth / 2.0f) - (2.0f * g_CellPadding), (g_WindowHeight / 3.0f) - (2.0f * g_CellPadding));
	DrawCheckerPattern(Point2f(0.0f * (g_WindowWidth / 2.0f) + g_CellPadding, ((g_WindowHeight / 3.0f) * 0.0f) + g_CellPadding), (g_WindowWidth / 2.0f) - (2.0f * g_CellPadding), (g_WindowHeight / 3.0f) - (2.0f * g_CellPadding));
	DrawColorBand(Point2f( 1.0f * (g_WindowWidth / 2.0f) + g_CellPadding, ((g_WindowHeight / 3.0f) * 2.0f) + g_CellPadding), g_ColorbandWidth);
	DrawPentagram(Point2f( 1.0f * (g_WindowWidth / 2.0f) + g_CellPadding + (g_WindowWidth / 2.0f) / 2.0f, ((g_WindowHeight / 3.0f) * 1.0f) + g_CellPadding + (g_WindowHeight / 3.0f) / 2.0f));
	DrawColumnChart(Point2f( 1.0f * (g_WindowWidth / 2.0f) + g_CellPadding, ((g_WindowHeight / 3.0f) * 0.0f) + g_CellPadding), (g_WindowWidth / 2.0f) - (2.0f * g_CellPadding), (g_WindowHeight / 3.0f) - (2.0f * g_CellPadding), g_ColumnChartPercentages);
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

void DrawPentagram(Point2f center)
{
	SetColor(g_ColorBlack);
	for (int i = 0; i < 5; i++)
	{
		Point2f p1{ g_PentagramVerts[(i * 2) % 5].x + center.x, g_PentagramVerts[(i * 2) % 5].y + center.y };
		Point2f p2{ g_PentagramVerts[((i + 1) * 2) % 5].x + center.x, g_PentagramVerts[((i + 1) * 2) % 5].y + center.y };
		DrawLine(p1, p2, 2.0f);
	}
}

void DrawColumnChart(Point2f pos, float width, float height, float percentages[])
{
	float colWidth{ width / 4.0f };
	Color4f lightGreen{155.0f / 255.0f, 245.0f / 255.0f, 37.0f / 255.0f, 1.0f};
	Color4f darkGreen{101.0f / 255.0f, 168.0f / 255.0f, 13.0f / 255.0f, 1.0f};
	
	for (int i = 0; i < sizeof(percentages); i++)
	{
		SetColor(i % 2 == 0 ? darkGreen : lightGreen);
		FillRect(pos.x + i * colWidth, pos.y, colWidth, height * (percentages[i] / 100.0f));
	}
}

void GetColumnChartInput()
{
	std::cout << "% people playing games\n";

	std::cout << "In the range [0, 20]? ";
	std::cin >> g_ColumnChartPercentages[0];

	std::cout << "In the range [21, 40]? ";
	std::cin >> g_ColumnChartPercentages[1];

	std::cout << "In the range [41, 60]? ";
	std::cin >> g_ColumnChartPercentages[2];

	std::cout << "Older than 60? ";
	std::cin >> g_ColumnChartPercentages[3];
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

void CalculatePentagramVerts()
{
	for (int i = 0; i < 5; i++)
	{
		g_PentagramVerts[i] = Point2f(cosf(((2.0f * static_cast<float>(M_PI)) / 5.0f) * i), sinf(((2.0f * static_cast<float>(M_PI)) / 5.0f) * i)) * g_PentagramRadius;
		std::cout << "Pentagram vert " << i << " (x,y): (" << g_PentagramVerts[i].x << "," << g_PentagramVerts[i].y << ")\n";
	}
}
#pragma endregion ownDefinitions