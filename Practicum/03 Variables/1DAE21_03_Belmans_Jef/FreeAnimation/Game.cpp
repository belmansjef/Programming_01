#include "pch.h"
#include "Game.h"

#pragma region gameFunctions											
void Start()
{

}

void Draw()
{
	ClearBackground(0.0f, 0.0f, 0.0f);
	ChargeShot();
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
	mousePos.x = float(e.x);
	mousePos.y = float(g_WindowHeight - e.y);
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	Point2f pMousePos(float(e.x), float(g_WindowHeight - e.y));

	switch (e.button)
	{
		case SDL_BUTTON_RIGHT:
			g_IsCharging = true;
			break;
		default:
			break;
	}
}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	switch (e.button)
	{
		case SDL_BUTTON_RIGHT:
			g_IsCharging = false;
			g_ChargeTimer = 0;
			break;
		default:
			break;
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
void ChargeShot()
{
	float angleOutlineEllipse{ (g_ChargeTimer % 360) * (g_Pi / 180.0f) };
	float angleFilledEllipse{ ((90 + g_ChargeTimer) % 360) * (g_Pi / 180.0f) };
	float bigSine{ sinf( angleOutlineEllipse ) + 1.0f };
	float smallSine{ sinf( angleOutlineEllipse + angleFilledEllipse) + 2.0f };
	float combinedSine = bigSine * smallSine;

	float sineFilledEllipse{ sinf( angleOutlineEllipse) + 1.0f };

	float radiusBig{ 20.0f * combinedSine };
	float radiusSmall{ 17.5f * sineFilledEllipse };
	Ellipsef innerRadius{ mousePos, radiusBig, radiusBig };
	Ellipsef chargeVfx{ mousePos, radiusSmall, radiusSmall };

	if (g_IsCharging)
	{
		++g_ChargeTimer;
		SetColor(0.45f, 0.25f, 0.65f);
		DrawEllipse(innerRadius);
		SetColor(0.65f, 0.25f, 0.45f);
		FillEllipse(chargeVfx);
	}
}
#pragma endregion ownDefinitions