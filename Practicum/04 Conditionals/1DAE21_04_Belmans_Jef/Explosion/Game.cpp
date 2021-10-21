#include "pch.h"
#include "Game.h"

#pragma region gameFunctions											
void Start()
{

}

void Draw()
{
	ClearBackground(0.4f, 0.4f, 0.4f);
	DrawExplosion();
}

void Update(float elapsedSec)
{
	UpdateExplosion();
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
	ProcessMouseClick(Point2f(float(e.x), float(g_WindowHeight - e.y)));
}
#pragma endregion inputHandling

#pragma region ownDefinitions
void ProcessMouseClick(Point2f mousePos)
{
	if (
		mousePos.x >= ((g_WindowWidth / 2.0f) - (g_Bomb.width / 2.0f)) &&
		mousePos.x <= ((g_WindowWidth / 2.0f) + (g_Bomb.width / 2.0f)) &&
		mousePos.y >= ((g_WindowHeight / 2.0f) - (g_Bomb.height / 2.0f)) &&
		mousePos.y <= ((g_WindowHeight / 2.0f) + (g_Bomb.height / 2.0f))
		)
	{
		switch (g_CurrentState)
		{
		case BombState::ticking:
			g_Explosion[0] = Rectf((g_WindowWidth / 2.0f) + bombSize / 2.0f, (g_WindowHeight / 2.0f) - bombSize / 2.0f, -bombSize, bombSize );
			g_Explosion[1] = Rectf((g_WindowWidth / 2.0f) - bombSize / 2.0f, (g_WindowHeight / 2.0f) - bombSize / 2.0f, bombSize, bombSize );
			g_Explosion[2] = Rectf((g_WindowWidth / 2.0f) - bombSize / 2.0f, (g_WindowHeight / 2.0f) + bombSize / 2.0f, bombSize, -bombSize );
			g_Explosion[3] = Rectf((g_WindowWidth / 2.0f) + bombSize / 2.0f, (g_WindowHeight / 2.0f) + bombSize / 2.0f, -bombSize, -bombSize );
			g_CurrentState = BombState::exploding;
			break;
		default:
			cout << "Bomb already exploding" << endl;
			break;
		}
	}
}

void UpdateExplosion()
{
	bool isExplosionInvisible{ false };
	if (g_CurrentState == BombState::ticking) return;

	for (int i = 0; i < 4; i++)
	{
		switch (i)
		{
		case 0:
			--g_Explosion[i].left;
			++g_Explosion[i].bottom;

			isExplosionInvisible = g_Explosion[i].left <= 0.0f && g_Explosion[i].bottom >= g_WindowHeight;
			break;
		case 1:
			++g_Explosion[i].left;
			++g_Explosion[i].bottom;
			break;
		case 2:
			++g_Explosion[i].left;
			--g_Explosion[i].bottom;
			break;
		case 3:
			--g_Explosion[i].left;
			--g_Explosion[i].bottom;
			break;
		default:
			cout << "Error updating explosion" << endl;
			break;
		}
	}

	if (isExplosionInvisible)
	{
		g_CurrentState = BombState::ticking;
	}
}

void DrawExplosion()
{
	if (g_CurrentState == BombState::ticking)
	{
		SetColor(0.0f, 0.0f, 0.0f);
		FillRect(g_Bomb);
	}
	else if (g_CurrentState == BombState::exploding)
	{
		SetColor(1.0f, 0.1f, 0.1f);
		for (Rectf explosion : g_Explosion)
		{
			FillRect(explosion);
		}

		SetColor(0.0f, 0.0f, 0.0f, 0.5f);
		FillRect(g_Bomb);
	}
}
#pragma endregion ownDefinitions