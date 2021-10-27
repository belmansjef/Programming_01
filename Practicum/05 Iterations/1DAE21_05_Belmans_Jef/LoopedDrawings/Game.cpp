#include "pch.h"
#include "Game.h"

#pragma region gameFunctions											
void Start()
{

}

void Draw()
{
	ClearBackground(0.0f, 0.0f, 0.0f);
	DrawStairs();
	DrawSpinningLines();
	DrawSquares();
	DrawSpiral();
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
void DrawStairs()
{
	const int nrStairs{ 5 };
	const float columnWidth{ (g_WindowWidth - 30.0f) / 2.0f };
	const float rowHeight{ (g_WindowHeight - 30.0f) / 2.0f };

	const Point2f stairStep
	{
		columnWidth / nrStairs,
		rowHeight / nrStairs
	};

	const Point2f startPos
	{
		10.0f,
		10.0f + rowHeight
	};

	for (int i = 0; i < nrStairs; i++)
	{
		if ((i + 1) % 2 == 0)
		{
			SetColor(0.2f, 0.2f, 0.8f);
		}
		else
		{
			SetColor(0.8f, 0.2f, 0.2f);	
		}

		Point2f p1
		{
			startPos.x + (stairStep.x * i),
			startPos.y + (stairStep.y * i)
		};
		
		Point2f p2
		{
			p1.x + stairStep.x,
			p1.y
		};

		Point2f p3
		{
			p1.x + stairStep.x,
			p2.y + stairStep.y
		};

		DrawLine(p1, p2);
		DrawLine(p2, p3);
	}
}

void DrawSpinningLines()
{
	const int nrLinesPerSet{ 5 };
	
	const float columnWidth{ (g_WindowWidth - 30.0f) / 2.0f };
	const float rowHeight{ (g_WindowHeight - 30.0f) / 2.0f };

	const Point2f startPos
	{
		20.0f + columnWidth,
		20.0f + rowHeight
	};

	Point2f p1{};
	Point2f p2{};

	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < nrLinesPerSet; y++)
		{
			switch (x)
			{
			case 0:
				SetColor(0.8f, 0.2f, 0.2f);
				p1.x = startPos.x + ((columnWidth / nrLinesPerSet) * y);
				p1.y = startPos.y;

				p2.x = startPos.x + columnWidth;
				p2.y = startPos.y + ((rowHeight / nrLinesPerSet) * y);

				DrawLine(p1, p2);
				break;
			case 1:
				SetColor(0.2f, 0.8f, 0.2f);
				p1.x = startPos.x + columnWidth;
				p1.y = startPos.y + ((rowHeight / nrLinesPerSet) * y);

				p2.x = startPos.x + columnWidth - ((columnWidth / nrLinesPerSet) * y);
				p2.y = startPos.y + rowHeight;

				DrawLine(p1, p2);
				break;
			case 2:
				SetColor(0.2f, 0.2f, 0.8f);
				p1.x = startPos.x + columnWidth - ((columnWidth / nrLinesPerSet) * y);
				p1.y = startPos.y + rowHeight;

				p2.x = startPos.x;
				p2.y = startPos.y + rowHeight - ((rowHeight / nrLinesPerSet) * y);

				DrawLine(p1, p2);
				break;
			case 3:
				SetColor(0.8f, 0.8f, 0.2f);
				p1.x = startPos.x;
				p1.y = startPos.y + rowHeight - ((rowHeight / nrLinesPerSet) * y);

				p2.x = startPos.x + ((columnWidth / nrLinesPerSet) * y);
				p2.y = startPos.y;

				DrawLine(p1, p2);
				break;
			default:
				break;
			}
		}
	}
}

void DrawSquares()
{
	const int nrSquares{ 5 };
	
	const float columnWidth{ (g_WindowWidth - 30.0f) / 2.0f };
	const float rowHeight{ (g_WindowHeight - 30.0f) / 2.0f };

	const Point2f startPos
	{
		10.0f,
		10.0f
	};

	SetColor(0.2f, 0.8f, 0.2f);
	for (int i = 0; i < nrSquares; i++)
	{
		const float offsetX{ (columnWidth / (2.0f * nrSquares)) * i };
		const float offsetY{ (rowHeight / (2.0f * nrSquares)) * i };

		const Rectf rect
		{
			startPos.x + offsetX,
			startPos.y + offsetY,
			columnWidth - (2.0f * offsetX) - 10.0f,
			rowHeight - (2.0f * offsetY) - 10.0f
		};

		DrawRect(rect);
	}
}

void DrawSpiral()
{
	const int nrIterations{ 5 };
	
	const float columnWidth{ (g_WindowWidth - 30.0f) / 2.0f };
	const float rowHeight{ (g_WindowHeight - 30.0f) / 2.0f };

	const Point2f startPos
	{
		20.0f + columnWidth,
		10.0f
	};

	for (int i = 0; i < nrIterations; i++)
	{
		
	}
}
#pragma endregion ownDefinitions