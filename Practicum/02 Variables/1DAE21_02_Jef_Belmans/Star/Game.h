#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Star - Belmans, Jef - 1DAE21" };

// Change the window dimensions here
float g_WindowWidth{ 500.0f };
float g_WindowHeight{ 500.0f };
#pragma endregion gameInformation



#pragma region ownDeclarations
float g_Radius{ 200.0f };

void DrawStar();
void CalculateVerts();
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
