#pragma once
using namespace utils;
using namespace std;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Explosion - Belmans, Jef - 1DAE21" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation



#pragma region ownDeclarations
enum class BombState
{
	ticking,
	exploding
};

float bombSize{ 100.0f };

BombState g_CurrentState{ BombState::ticking };

Rectf g_Bomb{ (g_WindowWidth / 2.0f) - bombSize / 2.0f, (g_WindowHeight / 2.0f) - bombSize / 2.0f, bombSize, bombSize };
Rectf g_Explosion[4]{};

void ProcessMouseClick(Point2f mousePos);
void UpdateExplosion();
void DrawExplosion();
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
