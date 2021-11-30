#include "pch.h"
#include "Game.h"

#pragma region gameFunctions											
void Start()
{

}

void Draw()
{
	ClearBackground(0.0f, 0.0f, 0.0f);
	DrawVerts(g_Verts, g_Size);
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
	g_MousePos.x = float(e.x);
	g_MousePos.y = float(g_WindowHeight - e.y);
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	AddNewVert(g_MousePos, g_Verts, g_Size);
}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{

}
#pragma endregion inputHandling

#pragma region ownDefinitions
void AddNewVert(const Point2f& clickedPos, Point2f* pArray, const int size)
{
	if (g_NextVertIdx == g_Size)
	{
		ShiftArray(pArray, size);
		pArray[g_NextVertIdx - 1] = clickedPos;
		return;
	}

	pArray[g_NextVertIdx] = clickedPos;
	++g_NextVertIdx;
}

void DrawVerts(const Point2f* pVertArray, const int size)
{
	for (int i = 0; i < size; i++)
	{
		if (!isEmpty(pVertArray[i]))
		{
			if (!isEmpty(pVertArray[i + 1]))
			{
				SetColor(0.4f, 0.4f, 0.4f);
				DrawLine(pVertArray[i], pVertArray[i + 1], 2.0f);
			}

			SetColor(0.9f, 0.2f, 0.2f);
			FillEllipse(pVertArray[i], g_VertRadius, g_VertRadius);
		}
	}
}

void ShiftArray(Point2f* pArray, const int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		pArray[i] = pArray[i + 1];
	}
}

bool isEmpty(const Point2f& point)
{
	return point.x == 0 && point.y == 0;
}
#pragma endregion ownDefinitions