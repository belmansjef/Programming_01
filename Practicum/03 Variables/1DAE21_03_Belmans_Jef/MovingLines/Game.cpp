#include "pch.h"
#include "Game.h"

//Basic game functions
#pragma region gameFunctions											
void Start()
{

}

void Draw()
{
	ClearBackground(0.35f, 0.0f, 0.75f);
	DrawLines();
}

void Update(float elapsedSec)
{
	g_LineProgress = float(int(++g_LineProgress) % int(g_WindowWidth));
	cout << "Line progress: " << g_LineProgress << endl;
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
void DrawLines()
{
	Point2f verts[4][2];

	// Horizontal upward line
	verts[0][0] = Point2f(0.0f, g_LineProgress);
	verts[0][1] = Point2f(g_WindowWidth, g_LineProgress);

	// Horizontal downward line
	verts[1][0] = Point2f(g_WindowWidth, g_WindowWidth - g_LineProgress);
	verts[1][1] = Point2f(0.0f, g_WindowWidth - g_LineProgress);

	// Vertical rightward line
	verts[2][0] = Point2f(g_LineProgress, 0.0f);
	verts[2][1] = Point2f(g_LineProgress, g_WindowHeight);

	// Vertical leftward line
	verts[3][0] = Point2f(g_WindowWidth - g_LineProgress, g_WindowHeight);
	verts[3][1] = Point2f(g_WindowWidth - g_LineProgress, 0.0f);

	SetColor(1.0f, 1.0f, 1.0f);
	for (int i = 0; i < 4; i++)
	{
		DrawLine(verts[i][0], verts[i][1]);
	}

	SetColor(1.0f, 1.0f, 0.0f);
	DrawLine(verts[2][0], verts[0][1]);
	DrawLine(verts[0][1], verts[3][0]);
	DrawLine(verts[3][0], verts[1][1]);
	DrawLine(verts[1][1], verts[2][0]);
}
#pragma endregion ownDefinitions