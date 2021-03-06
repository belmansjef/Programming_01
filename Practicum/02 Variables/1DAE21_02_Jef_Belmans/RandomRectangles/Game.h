#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Random Rectangles - Belmans, Jef - 1DAE21" };

// Change the window dimensions here
float g_WindowWidth{ 1024 };
float g_WindowHeight{ 576 };
#pragma endregion gameInformation



#pragma region ownDeclarations
const int g_Padding{ 10 };

void DrawRandomRectangle(int padding);
Color4f RandomColor();
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
