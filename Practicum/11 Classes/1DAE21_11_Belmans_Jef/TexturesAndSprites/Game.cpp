#include "pch.h"
#include "Game.h"
#include "Sprite.h"

#pragma region gameFunctions
void Start()
{
	InitTextures();
	InitSprites();
}

void Draw()
{
	ClearBackground(0.0f, 0.0f, 0.0f);
	DrawTextures();
	DrawSprites();
}

void Update(float elapsedSec)
{
	UpdateSprites(elapsedSec);
}

void End()
{
	DeleteTextures();
	DeleteSprites();
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
void InitTextures()
{
	TextureFromString("Hello", "resources/font.otf", 32, Color4f(1.0f, 1.0f, 0.0f), g_Text);
	TextureFromFile("resources/dae.png", g_DaeLogo);
}

void DrawTextures()
{
	const int nrTimesText{ 3 };
	const Point2f textPos{ 20.0f, 20.0f };
	for (int i = 0; i < nrTimesText; i++)
	{
		const Point2f currPos{ textPos.x + ((g_Text.width + 20.0f) * i), textPos.y };
		DrawTexture(g_Text, currPos);
	}

	const int nrTimesLogo{ 3 };
	Rectf dstRect{ 20.0f, g_Text.height + 40.0f, (g_WindowWidth - 60.0f) / 3.0f, g_DaeLogo.height };

	DrawTexture(g_DaeLogo, dstRect);
	
	dstRect.left += dstRect.width + 20.0f;
	dstRect.width -= 20.0f;

	DrawTexture(g_DaeLogo, dstRect);

	dstRect.left += dstRect.width + 20.0f;
	dstRect.width -= 20.0f;

	DrawTexture(g_DaeLogo, dstRect);
}

void DeleteTextures()
{
	DeleteTexture(g_DaeLogo);
	DeleteTexture(g_Text);
}

void InitSprites()
{
	g_pArrSprites[0] = new Sprite("resources/RunningKnight.png", 8, 1, 1/10.0f, 2.0f);
	g_pArrSprites[1] = new Sprite("resources/RunningKnight.png", 8, 1, 1/10.0f, 1.5f);
	g_pArrSprites[2] = new Sprite("resources/RunningKnight.png", 8, 1, 1/10.0f, 1.0f);
	g_pArrSprites[3] = new Sprite("resources/Tibo.png", 5, 5, 1/10.0f, 1.0f);
	g_pArrSprites[4] = new Sprite("resources/Tibo.png", 5, 5, 1/10.0f, 1.0f);

}

void UpdateSprites(float deltaTime)
{
	for (int i = 0; i < g_NrSprites; i++)
	{
		g_pArrSprites[i]->Update(deltaTime);
	}
}

void DrawSprites()
{
	const Point2f pos{ 20.0f, g_Text.height + g_DaeLogo.height + 60.0f };
	for (int i = 0; i < g_NrSprites; i++)
	{
		const Point2f spritePos{ pos.x + (120.0f * i), pos.y};
		g_pArrSprites[i]->Draw(spritePos);
	}
}

void DeleteSprites()
{
	for (int i = 0; i < g_NrSprites; i++)
	{
		delete g_pArrSprites[i];
	}
}
#pragma endregion ownDefinitions