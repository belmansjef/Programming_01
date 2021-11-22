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

const float g_BallRadius{ 20.0f };
Point2f g_BallPos{ g_WindowWidth / 2.0f, g_WindowHeight / 2.0f };
Point2f g_BallVelocity{ 100.0f, 80.0f };

bool isGravityEnabled{ false };
const float g_FreeFallSize{ 20.0f };
float g_FreeFallTime{ 0.0f };
Point2f g_FreeFallPos{ g_WindowWidth / 2.0f, g_WindowHeight - (g_FreeFallSize + 5.0f) };
Point2f g_Gravity{ 0.0f, -9.81f };

void UpdateNrFrames();
void UpdateAccumulatedTime(const float deltaTime);
void UpdateFramerate(const float deltaTime);
void PrintFrameStats();

void UpdateBall(const float deltaTime);
void DrawBall();

void UpdateFreeFall(const float deltaTime);
void DrawFreeFall();
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
