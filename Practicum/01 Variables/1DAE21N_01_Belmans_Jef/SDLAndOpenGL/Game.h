#pragma once
using namespace utils;
#pragma region gameInformation
std::string g_WindowTitle{ "SDL & OpenGL - Belmans, Jef - 1DAE21" };

float g_WindowWidth{ 1024.0f };
float g_WindowHeight{ 400.0f };
#pragma endregion gameInformation



#pragma region ownDeclarations
Point2f g_OriginPoint{ 0.0f, 0.0f };

Color4f g_ColorRed{ 1.0f, 0.0f, 0.0f, 1.0f };
Color4f g_ColorGreen{ 0.0f, 1.0f, 0.0f, 1.0f };
Color4f g_ColorBlue{ 0.0f, 0.0f, 1.0f, 1.0f };
Color4f g_ColorWhite{ 1.0f, 1.0f, 1.0f, 1.0f };

char g_NumHorizontalLines{ 2 };
char g_NumVerticalLines{ 2 };

float g_HorLineDistance{ g_WindowHeight / (g_NumHorizontalLines + 1) };
float g_VerLineDistance{ g_WindowWidth / (g_NumVerticalLines + 1) };
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
