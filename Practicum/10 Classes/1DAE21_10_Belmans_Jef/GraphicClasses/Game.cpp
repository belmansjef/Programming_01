#include "pch.h"
#include "Game.h"
#include "Fraction.h"
#include "Light.h"
#include "DaeEllipse.h"
#include <iostream>
#include <iomanip>

#pragma region gameFunctions
void Start()
{
	InitFractions();
	PrintFractionsSum();

	InitLights();

	InitEllipses();
}

void Draw()
{
	ClearBackground(0.0f, 0.0f, 0.0f);
	DrawFractions();
	DrawLights();
	DrawEllipses();
}

void Update(float elapsedSec)
{
	
}

void End()
{
	DeleteFractions();
	DeleteLights();
	DeleteEllipses();
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
	const Point2f mousePos{ float(e.x), float(g_WindowHeight - e.y) };
	HitLights(mousePos);
	HitEllipses(mousePos);
}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{

}
#pragma endregion inputHandling

#pragma region ownDefinitions
void InitFractions()
{
	g_pFraction1 = new Fraction{ 4, 5 };
	g_pFraction2 = new Fraction{ 2, 4 };
	g_pFraction3 = new Fraction{ 1, 2 };
	g_pFraction4 = new Fraction{ 3, 3 };
	g_pFraction5 = new Fraction{ 1, 4 };
	g_pFraction6 = new Fraction{ 2, 3 };
}

void PrintFractionsSum()
{
	float sum{};
	sum += g_pFraction1->GetValue();
	sum += g_pFraction2->GetValue();
	sum += g_pFraction3->GetValue();
	sum += g_pFraction4->GetValue();
	sum += g_pFraction5->GetValue();
	sum += g_pFraction6->GetValue();

	std::cout << std::setprecision(2) << std::fixed;
	std::cout << "Total value of created fraction objects: " << sum << std::endl;
}

void DrawFractions()
{
	const float size{ (((((g_WindowHeight / 5.0f) * 3.0f) / 6.0f) / 4.0f) * 3.0f) };
	const float spacing{ size / 3.0f };
	const Point2f pos{ 10.0f, 10.0f };

	g_pFraction1->Draw(Point2f(pos.x, pos.y), size);
	g_pFraction2->Draw(Point2f(pos.x, pos.y + (spacing + size)), size);
	g_pFraction3->Draw(Point2f(pos.x, pos.y + (spacing + size) * 2), size);
	g_pFraction4->Draw(Point2f(pos.x, pos.y + (spacing + size) * 3), size);
	g_pFraction5->Draw(Point2f(pos.x, pos.y + (spacing + size) * 4), size);
	g_pFraction6->Draw(Point2f(pos.x, pos.y + (spacing + size) * 5), size);
}

void DeleteFractions()
{
	delete g_pFraction1;
	delete g_pFraction2;
	delete g_pFraction3;
	delete g_pFraction4;
	delete g_pFraction5;
	delete g_pFraction6;

	g_pFraction1 = nullptr;
	g_pFraction2 = nullptr;
	g_pFraction3 = nullptr;
	g_pFraction4 = nullptr;
	g_pFraction5 = nullptr;
	g_pFraction6 = nullptr;
}

void InitLights()
{
	const Point2f pos{(g_WindowWidth / 8.0f) * 2.0f, 10.0f};

	Rectf rect{};
	float width{};

	rect.height = 50.0f;

	rect.left = pos.x;
	rect.bottom = pos.y;
	width = GenerateRandomNumber(10.0f, g_WindowWidth / 10.0f);
	rect.width = width;
	g_pLight1 = new Light{ rect, GenerateRandomColor4f() };

	rect.left = pos.x + (width + 20.0f);
	rect.bottom = pos.y;
	width = GenerateRandomNumber(10.0f, (g_WindowWidth / 10.0f) - (width + 10.0f));
	rect.width = width;
	g_pLight2 = new Light{ rect, GenerateRandomColor4f() };

	rect.left = pos.x;
	rect.bottom = pos.y + rect.height + 20.0f;
	width = GenerateRandomNumber(10.0f, g_WindowWidth / 10.0f);
	rect.width = width;
	g_pLight3 = new Light{ rect, GenerateRandomColor4f() };

	rect.left = pos.x + (width + 20.0f);
	rect.bottom = pos.y + rect.height + 20.0f;
	width = GenerateRandomNumber(10.0f, (g_WindowWidth / 10.0f) - (width + 10.0f));
	rect.width = width;
	g_pLight4 = new Light{ rect, GenerateRandomColor4f() };

	rect.left = pos.x;
	rect.bottom = pos.y + (rect.height + 20.0f) * 2;
	width = GenerateRandomNumber(10.0f, g_WindowWidth / 10.0f);
	rect.width = width;
	g_pLight5 = new Light{ rect, GenerateRandomColor4f() };

	rect.left = pos.x + (width + 20.0f);
	rect.bottom = pos.y + (rect.height + 20.0f) * 2;
	width = GenerateRandomNumber(10.0f, (g_WindowWidth / 10.0f) - (width + 10.0f));
	rect.width = width;
	g_pLight6 = new Light{ rect, GenerateRandomColor4f() };

	rect.left = pos.x;
	rect.bottom = pos.y + (rect.height + 20.0f) * 3;
	width = GenerateRandomNumber(10.0f, g_WindowWidth / 10.0f);
	rect.width = width;
	g_pLight7 = new Light{ rect, GenerateRandomColor4f() };

	rect.left = pos.x + (width + 20.0f);
	rect.bottom = pos.y + (rect.height + 20.0f) * 3;
	width = GenerateRandomNumber(10.0f, (g_WindowWidth / 10.0f) - (width + 10.0f));
	rect.width = width;
	g_pLight8 = new Light{ rect, GenerateRandomColor4f() };
}

void DrawLights()
{
	g_pLight1->Draw();
	g_pLight2->Draw();
	g_pLight3->Draw();
	g_pLight4->Draw();
	g_pLight5->Draw();
	g_pLight6->Draw();
	g_pLight7->Draw();
	g_pLight8->Draw();
}

void HitLights(const Point2f& pos)
{
	int sum{};

	sum += g_pLight1->IsHit(pos);
	sum +=  g_pLight2->IsHit(pos);
	sum +=  g_pLight3->IsHit(pos);
	sum +=  g_pLight4->IsHit(pos);
	sum +=  g_pLight5->IsHit(pos);
	sum +=  g_pLight6->IsHit(pos);
	sum +=  g_pLight7->IsHit(pos);
	sum +=  g_pLight8->IsHit(pos);

	std::cout << sum << " lights are on" << std::endl;
}

void DeleteLights()
{
	delete g_pLight1;
	delete g_pLight2;
	delete g_pLight3;
	delete g_pLight4;
	delete g_pLight5;
	delete g_pLight6;
	delete g_pLight7;
	delete g_pLight8;

	g_pLight1 = nullptr;
	g_pLight2 = nullptr;
	g_pLight3 = nullptr;
	g_pLight4 = nullptr;
	g_pLight5 = nullptr;
	g_pLight6 = nullptr;
	g_pLight7 = nullptr;
	g_pLight8 = nullptr;
}

void InitEllipses()
{
	g_pEllipse1 = new DaeEllipse(Point2f(60.0f, g_WindowHeight - 70.0f), 40.0f, 50.0f, Color4f(1.0f, 0.0f, 0.0f));
	g_pEllipse2 = new DaeEllipse(Point2f(320.0f, g_WindowHeight - 160.0f), 210.0f, 140.0f, Color4f(0.0f, 1.0f, 0.0f));
	g_pEllipse3 = new DaeEllipse(Point2f(g_WindowWidth / 6.0f * 4.0f, g_WindowHeight / 2.0f), (g_WindowWidth / 4.0f) - 40.0f, (g_WindowHeight / 2.0f) - 40.0f, Color4f(1.0f, 1.0f, 0.0f));
}

void DrawEllipses()
{
	g_pEllipse1->Draw();
	g_pEllipse2->Draw();
	g_pEllipse3->Draw();
}

void HitEllipses(const Point2f& pos)
{
	g_pEllipse1->ActivateTest(pos);
	g_pEllipse2->ActivateTest(pos);
	g_pEllipse3->ActivateTest(pos);
}

void DeleteEllipses()
{
	delete g_pEllipse1;
	delete g_pEllipse2;
	delete g_pEllipse3;

	g_pEllipse1 = nullptr;
	g_pEllipse2 = nullptr;
	g_pEllipse3 = nullptr;
}
#pragma endregion ownDefinitions