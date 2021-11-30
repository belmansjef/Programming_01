#pragma once
using namespace utils;
using namespace std;

#pragma region gameInformation
std::string g_WindowTitle{ "Array Applications - Belmans, Jef - 1DAE21" };

float g_WindowWidth{ 800 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation

#pragma region ownDeclarations
Point2f g_MousePos{};

const int g_Size{ 10 };
int g_NextVertIdx{ 0 };
const float g_VertRadius{ 10.0f };
Point2f g_Verts[g_Size]{};

bool isEmpty(const Point2f& point);

void AddNewVert(const Point2f& clickedPos, Point2f* pArray, const int size);
void DrawVerts(const Point2f* pVertArray, const int size);
void ShiftArray(Point2f* pArray, const int size);
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
