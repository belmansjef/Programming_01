#include "pch.h"
#include "Game.h"

#pragma region gameFunctions											
void Start()
{
}

void Draw()
{
	ClearBackground();
	DrawSlidingRectangles();
}

void Update(float elapsedSec)
{
	g_RectangleProgress = float(int(++g_RectangleProgress) % int(g_WindowWidth));
	// cout << "Rectangle progress: " << g_RectangleProgress << endl;
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
void DrawSlidingRectangles()
{
	float rectWidth{ 100.0f };
	float rectHeight{ 100.0f };

	Rectf redRect
	{
		(0.0f + g_RectangleProgress),
		(0.0f + g_RectangleProgress),
		rectWidth, rectHeight
	};

	Rectf greenRect
	{ 
		(0.0f + g_RectangleProgress),
		(g_WindowHeight - g_RectangleProgress), 
		rectWidth, -rectHeight 
	};

	Rectf blueRect
	{
		(g_WindowWidth - g_RectangleProgress),
		(g_WindowHeight - g_RectangleProgress),
		-rectWidth, -rectHeight
	};

	Rectf yellowRect{
		(g_WindowWidth - g_RectangleProgress),
		(0.0f + g_RectangleProgress),
		-rectWidth, rectHeight
	};

	// Draw black borders
	SetColor(0.0f, 0.0f, 0.0f, 0.5f);
	DrawRect(redRect, 2.0f);
	DrawRect(greenRect, 2.0f);
	DrawRect(blueRect, 2.0f);
	DrawRect(yellowRect, 2.0f);

	// Red rectangle
	SetColor(1.0f, 0.0f, 0.0f, 0.5f);
	FillRect(redRect);

	// Green rectangle
	SetColor(0.0f, 1.0f, 0.0f, 0.5f);
	FillRect(greenRect);

	// Blue rectangle
	SetColor(0.0f, 0.0f, 1.0f, 0.5f);
	FillRect(blueRect);

	// Yellow rectangle
	SetColor(1.0f, 1.0f, 0.0f, 0.5f);
	FillRect(yellowRect);
}
#pragma endregion ownDefinitions