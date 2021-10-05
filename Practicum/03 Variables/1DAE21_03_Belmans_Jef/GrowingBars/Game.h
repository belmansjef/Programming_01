#pragma once
using namespace utils;
#pragma region gameInformation
std::string g_WindowTitle{ "Growing Bars - Belmans, Jef - 1DAE21" };

float g_WindowWidth{ 1024 };
float g_WindowHeight{ 576 };
#pragma endregion gameInformation



#pragma region ownDeclarations
const int g_Padding{ 20 };
int g_NrFrames{};

const Point2f g_PaddedWindowDimensions{ g_WindowWidth - (2.0f * g_Padding), g_WindowHeight - (2.0f * g_Padding) };
const Point2f g_BarDimensions{ g_PaddedWindowDimensions.x, g_PaddedWindowDimensions.y / 3.0f };

void DrawRedBar();
void DrawYellowBar();
void UpdateFrameCount();
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
