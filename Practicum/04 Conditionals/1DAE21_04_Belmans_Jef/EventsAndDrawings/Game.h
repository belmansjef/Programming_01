#pragma once
using namespace utils;
using namespace std;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Events and Drawings - Belmans, Jef - 1DAE21" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
enum class RectangleState
{
	idle,
	active
};

bool g_IsRectMoving{ false };
bool g_IsLineEnabled{ false };

Rectf GenerateRandomRect(float minWidth, float minHeight, float padding);
RectangleState g_RectState{ RectangleState::idle };
Rectf g_Rect{ GenerateRandomRect(60.0f, 40.0f, 50.0f) };
Rectf g_ExtraRect{ };

void DrawClickRect();
void ProcessMouseInput(int mouseX, int mouseY);
void MoveClickRect();

Line4f g_BouncingLine{};
Point2f g_MovementP1{ 2.0f, 2.0f };
Point2f g_MovementP2{ 1.5f, 1.5f };

void DrawBouncingLine();
void UpdateBouncingLine();
void CheckIfOutOfBound(Point2f p, Point2f& movement);
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
