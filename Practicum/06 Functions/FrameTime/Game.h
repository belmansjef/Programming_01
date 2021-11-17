#pragma once
using namespace utils;
using namespace std;
#pragma region gameInformation
std::string g_WindowTitle{ "Frametime - Belmans, Jef - 1DAE21" };

float g_WindowWidth{ 600 };
float g_WindowHeight{ 400 };
#pragma endregion gameInformation



#pragma region ownDeclarations
int g_NrFrames{};
float g_AccumulatedTime{};
float g_AvgFrameRate{};
float g_AvgFrameTime{};

void UpdateNrFrames();
void UpdateAccumulatedTime(const float deltaTime);
void UpdateFramerate(const float deltaTime);

void PrintFrameStats();
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
