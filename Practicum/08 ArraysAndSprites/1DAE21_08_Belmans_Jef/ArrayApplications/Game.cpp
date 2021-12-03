#include "pch.h"
#include "Game.h"

#pragma region gameFunctions
void Start()
{
	InitPentagrams(g_Pentagrams, g_PentagramArraySize);
	InitTextures(g_TextTextures, g_RandomArraySize);
}

void Draw()
{
	ClearBackground(0.0f, 0.0f, 0.0f);
	DrawVerts(g_Verts, g_VertArraySize);
	DrawPentagrams(g_Pentagrams, g_PentagramArraySize);
	DrawRandStats(g_RandStats, g_TextTextures, g_RandomArraySize);
	DrawMousePoints(g_MousePosArray, g_MousePosArraySize);
}

void Update(float elapsedSec)
{
	UpdatePentagrams(g_Pentagrams, g_PentagramArraySize, elapsedSec);
	UpdateRandStats(g_RandStats, g_RandomArraySize);
}

void End()
{
	DeleteTextures(g_TextTextures, g_RandomArraySize);
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
	AddMousePos(g_MousePosArray, g_MousePosArraySize);
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	AddNewVert(g_MousePos, g_Verts, g_VertArraySize);
}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{

}
#pragma endregion inputHandling

#pragma region ownDefinitions
void AddNewVert(const Point2f& clickedPos, Point2f* pArray, const int size)
{
	if (g_NextVertIdx == g_VertArraySize)
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
void InitPentagrams(Pentagramf* pPentagramArray, const int size)
{
	for (int i = 0; i < size; i++)
	{
		pPentagramArray[i].angleSpeed.speed = GenerateRandomNumber(0.2f, 1.1f);
		pPentagramArray[i].center.x = g_WindowWidth - 200.0f;
		pPentagramArray[i].center.y = 200.0f;
		pPentagramArray[i].radius = 150.0f;
	}
}
void UpdatePentagrams(Pentagramf* pPentagramArray, const int size, const float deltaTime)
{
	for (int i = 0; i < size; i++)
	{
		pPentagramArray[i].angleSpeed.angle += pPentagramArray[i].angleSpeed.speed * deltaTime;
	}
}
void DrawPentagrams(const Pentagramf* pPentagramArray, const int size)
{
	SetColor(0.1f, 1.0f, 0.1f);
	for (int i = 0; i < size; i++)
	{
		DrawPentagram(pPentagramArray[i]);
	}
}

void InitTextures(Texture* pTextureArray, const int size)
{
	for (int i = 0; i < size; i++)
	{
		TextureFromString(to_string(i), "resources/DIN-Light.otf", 24, Color4f(1.0f, 1.0f, 0.0f), pTextureArray[i]);
	}
}
void UpdateRandStats(int* pRandStatsArray, const int size)
{
	const int rnd{ rand() % size };
	++pRandStatsArray[rnd];
}
void DrawRandStats(const int* pRandStatsArray, const Texture* pTextureArray, const int size)
{
	for (int i = 0; i < size; i++)
	{
		DrawTexture(pTextureArray[i], Point2f(10.0f, g_WindowHeight - 40.0f * (i + 1)));
		SetColor(1.0f, 1.0f, 0.0f);
		FillRect(40.0f, g_WindowHeight - 39.5f * (i + 1), float(pRandStatsArray[i]), 24.0f);
	}
}
void DeleteTextures(Texture* pTextureArray, const int size)
{
	for (int i = 0; i < size; i++)
	{
		DeleteTexture(pTextureArray[i]);
	}
}

void AddMousePos(Point2f* pMousePosArray, const int size)
{
	pMousePosArray[g_NextMousePosIdx] = g_MousePos;
	g_NextMousePosIdx = ++g_NextMousePosIdx % size;
}
void DrawMousePoints(const Point2f* pMousePosArray, const int size)
{
	for (int i = 0; i < size; i++)
	{
		const int idx{ (g_NextMousePosIdx + i) % size };
		if (!isEmpty(pMousePosArray[idx]))
		{
			SetColor(0.2f, 0.2f, 1.0f, 0.2f + (idx * 0.1f));
			FillEllipse(pMousePosArray[idx], g_MousePointRadius + (idx * 2.0f), g_MousePointRadius + (idx * 2.0f));
		}
	}
}
#pragma endregion ownDefinitions