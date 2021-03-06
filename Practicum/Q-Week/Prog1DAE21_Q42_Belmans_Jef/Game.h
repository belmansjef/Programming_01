#pragma once
using namespace utils;

#pragma region gameInformation
std::string g_WindowTitle{ "Q42 - Belmans, Jef - 1DAE21" };

float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
enum class CircleState
{
	growing,
	shrinking,
	waiting
};

float g_Speed{ 1.0f };
int g_MaxRadius{ 50 };

CircleState g_CurrentCircleState{ CircleState::waiting };
Ellipsef g_CurrentCircle{};
Color4f g_CurrentColor{};

void PrintLetters();
void GenerateNewCircle(const Point2f center);
void UpdateCircle();
void DrawCircle();
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
