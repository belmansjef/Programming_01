#pragma once
using namespace utils;
#pragma region gameInformation
std::string g_WindowTitle{ "Recursion - Belmans, Jef - 1DAE21" };

float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation

#pragma region ownDeclarations
void DrawSierpinskiTriangle(const Point2f& left, const Point2f& top, const Point2f& right, const int n = 16);
Point2f GetMidPoint(const Point2f& p1, const Point2f& p2);
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
