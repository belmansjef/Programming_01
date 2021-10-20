#pragma once
using namespace utils;
using namespace std;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Project name - Name, firstname - 1DAExx" };

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

Rectf GenerateRandomRect(float minWidth, float minHeight, float padding);

bool g_IsRectMoving{ false };

RectangleState g_RectState{ RectangleState::idle };
Rectf g_Rect{ GenerateRandomRect(60.0f, 40.0f, 50.0f) };
Rectf g_ExtraRect{ };

void DrawClickRect();
void ProcessMouseInput(int mouseX, int mouseY);
void MoveClickRect();
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
