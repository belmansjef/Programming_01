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

const int g_VertArraySize{ 10 };
const float g_VertRadius{ 10.0f };
int g_NextVertIdx{ 0 };
Point2f g_Verts[g_VertArraySize]{};

void AddNewVert(const Point2f& clickedPos, Point2f* pArray, const int size);
void DrawVerts(const Point2f* pVertArray, const int size);
void ShiftArray(Point2f* pArray, const int size);
bool isEmpty(const Point2f& point);

const int g_PentagramArraySize{ 5 };
Pentagramf g_Pentagrams[g_PentagramArraySize]{};

void InitPentagrams(Pentagramf* pPentagramArray, const int size);
void UpdatePentagrams(Pentagramf* pPentagramArray, const int size, const float deltaTime);
void DrawPentagrams(const Pentagramf* pPentagramArray, const int size);

const int g_RandomArraySize{ 6 };
int g_RandStats[g_RandomArraySize]{};
Texture g_TextTextures[g_RandomArraySize]{};

void InitTextures(Texture* pTextureArray, const int size);
void UpdateRandStats(int* pRandStatsArray, const int size);
void DrawRandStats(const int* pRandStatsArray, const Texture* pTextureArray, const int size);
void DeleteTextures(Texture* pTextureArray, const int size);

const int g_MousePosArraySize{ 10 };
const float g_MousePointRadius{ 10.0f };
int g_NextMousePosIdx{ 0 };
Point2f g_MousePosArray[g_MousePosArraySize]{};

void AddMousePos(Point2f* pMousePosArray, const int size);
void DrawMousePoints(const Point2f* pMousePosArray, const int size);
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
