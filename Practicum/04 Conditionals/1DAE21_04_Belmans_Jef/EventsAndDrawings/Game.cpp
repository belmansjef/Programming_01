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
	MoveClickRect();
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
	switch (key)
	{
	case SDLK_r:
		g_IsRectMoving = !g_IsRectMoving;
		break;
	default:
		break;
	}
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
	FillRect(g_ExtraRect);
}

void ProcessMouseInput(int mouseX, int mouseY)
{
	// Check if mouse click is on rect collider
	if ((mouseX >= g_Rect.left) && (mouseX <= (g_Rect.left + g_Rect.width))
		|| (mouseX >= g_ExtraRect.left) && (mouseX <= (g_ExtraRect.left + g_ExtraRect.width)))
	{
		if ((mouseY >= g_Rect.bottom) && (mouseY <= (g_Rect.bottom + g_Rect.height))
			|| (mouseY >= g_ExtraRect.bottom) && (mouseY <= (g_ExtraRect.bottom + g_ExtraRect.height)))
		{
			switch (g_RectState)
			{
			case RectangleState::idle:
				g_RectState = RectangleState::active;
				break;
			case RectangleState::active:
				g_Rect = GenerateRandomRect(60.0f, 40.0f, 50.0f);
				g_ExtraRect = Rectf{};
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
	float width{ GenerateRandomNumber(minWidth, g_WindowWidth - (2 * padding)) };
	float height{ GenerateRandomNumber(minHeight, g_WindowHeight - (2 * padding)) };

	return Rectf
	{
		GenerateRandomNumber(padding, g_WindowWidth - width - padding),
		GenerateRandomNumber(padding, g_WindowHeight - height - padding),
		width,
		height
	};
}

void MoveClickRect()
{
	if (g_IsRectMoving)
	{
		g_Rect.left = static_cast<float>(int(++g_Rect.left) % int(g_WindowWidth));
		if (g_Rect.left + g_Rect.width > g_WindowWidth)
		{
			g_ExtraRect = Rectf
			{
				0.0f,
				g_Rect.bottom,
				(g_Rect.left + g_Rect.width) - g_WindowWidth,
				g_Rect.height
			};
		}
		else
		{
			g_ExtraRect = Rectf{};
		}
	}
}
#pragma endregion ownDefinitions