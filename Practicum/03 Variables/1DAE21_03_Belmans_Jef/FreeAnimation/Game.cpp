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
	g_MousePos.x = float(e.x);
	g_MousePos.y = float(g_WindowHeight - e.y);
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
			g_IsCharging = g_IsFullyCharged = false;
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
	const float radius{ 30.0f };
	const float angle{ (270 + g_ChargeTimer) % 360 * (g_Pi / 180.0f) };

	g_IsFullyCharged |= angle <= (g_Pi / 2.0f);

	const float warmupSine{ (sinf(angle) + 1.0f) };
	const float chargedSine{ (sinf(5.0f * angle) + 5.0f) / 5.0f };
	const float secondaryWarmupSine{ sinf(2.5f * angle) + 1.0f };
	const float secondaryChargedSine{ (sinf(5.0f * angle + 1.5f) + 6.0f) / 6.0f };
	const Ellipsef ellipseChargeVFX
	{
		g_MousePos,
		(radius / 1.75f) * (g_IsFullyCharged ? chargedSine : warmupSine),
		(radius / 1.75f) * (g_IsFullyCharged ? chargedSine : warmupSine) 
	};
	const Ellipsef secondaryEllipseVFX
	{
		g_MousePos,
		radius * (g_IsFullyCharged ? secondaryChargedSine : secondaryWarmupSine),
		radius * (g_IsFullyCharged ? secondaryChargedSine : secondaryWarmupSine)
	};

	if (g_IsCharging)
	{
		++g_ChargeTimer;

		SetColor(0.8f, 0.25f, 0.8f);
		DrawEllipse(ellipseChargeVFX);
		SetColor(0.8f, 0.8f, 0.0f);
		DrawEllipse(secondaryEllipseVFX);
	}
}
#pragma endregion ownDefinitions