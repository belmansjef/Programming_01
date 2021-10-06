#include "pch.h"
#include "Game.h"

#pragma region gameFunctions											
void Start()
{

}

void Draw()
{
	ClearBackground(0.0f, 0.0f, 0.0f);
}

void Update(float elapsedSec)
{
	++g_NrFrames;
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
	Point2f pMousePos(float(e.x), float(g_WindowHeight - e.y));

	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
		cout << "Mouse position: ( " << pMousePos.x << ", " << pMousePos.y << " )" << endl;
		break;
	default:
		break;
	}
}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{

}
#pragma endregion inputHandling

#pragma region ownDefinitions

#pragma endregion ownDefinitions