#pragma once
using namespace utils;
#pragma region gameInformation
std::string g_WindowTitle{ "Game Functions - Belmans, Jef - 1DAE21" };

float g_WindowWidth{ 600 };
float g_WindowHeight{ 400 };
#pragma endregion gameInformation

#pragma region ownDeclarations
Point2f g_MousePos{};
Circlef g_Circle{};
Rectf g_Rect{};

void UpdateMouseRectf(Rectf& rect);
void UpdateMouseCirclef(Circlef& circle);

void TestIsPointInCircle();
void TestPointInRect();
void TestIsOverlapping();
#pragma endregion ownDeclarations

#pragma region gameFunctions											
void Start();
void Draw();
void Update(float elapsedSec);
void End();
#pragma endregion gameFunctions

#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key);
void OnKeyUpEvent(SDL_Keycode key);
void OnMouseMotionEvent(const SDL_MouseMotionEvent& e);
void OnMouseDownEvent(const SDL_MouseButtonEvent& e);
void OnMouseUpEvent(const SDL_MouseButtonEvent& e);
#pragma endregion inputHandling
