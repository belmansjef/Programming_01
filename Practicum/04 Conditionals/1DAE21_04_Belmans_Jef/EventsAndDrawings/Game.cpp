#include "pch.h"
#include "Game.h"

#pragma region gameFunctions											
void Start()
{

}

void Draw()
{
	ClearBackground(0.2f, 0.2f, 0.5f);
	DrawClickRect();
	DrawBouncingLine();
}

void Update(float elapsedSec)
{
	MoveClickRect();
	UpdateBouncingLine();
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
	case SDLK_l :
		g_IsLineEnabled = !g_IsLineEnabled;
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
void DrawBouncingLine()
{
	if (!g_IsLineEnabled) return;

	SetColor(1.0f, 1.0f, 0.0f);
	DrawLine4f(g_BouncingLine);
}

// Note: there are a thousand better ways to tackle this moving line, but I am lazy rn so am taking the easy route
void UpdateBouncingLine()
{
	if (!g_IsLineEnabled) return;

	g_BouncingLine.p1.x += g_MovementP1.x;
	g_BouncingLine.p1.y += g_MovementP1.y;

	g_BouncingLine.p2.x += g_MovementP2.x;
	g_BouncingLine.p2.y += g_MovementP2.y;

	CheckIfOutOfBound(g_BouncingLine.p1, g_MovementP1);
	CheckIfOutOfBound(g_BouncingLine.p2, g_MovementP2);
}

void CheckIfOutOfBound(Point2f p, Point2f& movement)
{
	if (p.x <= 0.0f || p.x >= g_WindowWidth)
	{
		movement.x = -movement.x;
	}
	
	if (p.y <= 0.0f || p.y >= g_WindowHeight)
	{
		movement.y = -movement.y;
	}
}
#pragma endregion ownDefinitions