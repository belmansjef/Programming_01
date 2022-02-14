#pragma once
using namespace utils;
#pragma region gameInformation
std::string g_WindowTitle{ "Ex58 - Belmans, Jef - 1DAE21" };

float g_WindowWidth{ 1920 };
float g_WindowHeight{ 1080 };
#pragma endregion gameInformation

#pragma region ownDeclarations
class Vehicle;

enum class GameState
{
	reset,
	play,
	pause,
	win,
	lose
};

struct Chicken
{
	Texture image{};
	Point2f position;
	float speed{};

	float width{};
	float height{};

	bool isMovingDown{};
	bool isMovingRight{};
	bool isMovingLeft{};
};

GameState g_CurrentState{ GameState::reset };
Chicken g_PlayerChicken{};

const int g_NumVehicles{ 5 };
Vehicle* g_pVehicles[g_NumVehicles];

Texture g_StreetTexture{};
Texture g_WinText{};
Texture g_LoseText{};
Texture g_PauseText{};

void InitializeResources();
void FreeResources();

void StopChicken();
void ResetChicken();

void ResetVehicles();

void PauseGame();

void PrintInstructions();
void DrawFrame();
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
