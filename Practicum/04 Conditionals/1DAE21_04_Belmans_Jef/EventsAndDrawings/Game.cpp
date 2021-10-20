#include "pch.h"
#include "Game.h"

#pragma region gameFunctions											
void Start()
{

}

void Draw()
{
	ClearBackground();
	DrawClickRect();
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
	ProcessMouseInput(int(e.x), int(g_WindowHeight - e.y));
}
#pragma endregion inputHandling

#pragma region ownDefinitions
void DrawClickRect()
{
	static Color4f colorGray { 0.2f, 0.2f, 0.2f, 1.0f };
	static Color4f colorGreen { 0.1f, 1.0f, 0.1f, 1.0f };

	switch (g_RectState)
	{
	case RectangleState::idle:
		SetColor(colorGray);
		break;
	case RectangleState::active:
		SetColor(colorGreen);
		break;
	default:
		cout << "Error setting color" << endl;
		break;
	}

	FillRect(g_Rect);
}

void ProcessMouseInput(int mouseX, int mouseY)
{
	// Check if mouse click is on rect collider
	if ((mouseX >= g_Rect.left) && (mouseX <= (g_Rect.left + g_Rect.width)))
	{
		if ((mouseY >= g_Rect.bottom) && (mouseY <= (g_Rect.bottom + g_Rect.height)))
		{
			switch (g_RectState)
			{
			case RectangleState::idle:
				g_RectState = RectangleState::active;
				break;
			case RectangleState::active:
				g_Rect = GenerateRandomRect(60.0f, 40.0f, 50.0f);
				g_RectState = RectangleState::idle;
				break;
			default:
				break;
			}
		} 
		else { return; }
	}
	else { return; }
}

Rectf GenerateRandomRect(float minWidth, float minHeight, float padding)
{
	float width{ GenerateRandomNumber(minWidth, g_WindowWidth - padding) };
	float height{ GenerateRandomNumber(minHeight, g_WindowHeight - padding) };

	return Rectf
	{
		GenerateRandomNumber(padding, g_WindowWidth - width - padding),
		GenerateRandomNumber(padding, g_WindowHeight - height - padding),
		width,
		height
	};
}
#pragma endregion ownDefinitions