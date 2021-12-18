#pragma once
using namespace utils;
#pragma region gameInformation
std::string g_WindowTitle{ "Graphic Classes - Belmans, Jef - 1DAE21" };

float g_WindowWidth{ 1280 };
float g_WindowHeight{ 720 };
#pragma endregion gameInformation



#pragma region ownDeclarations
class Fraction;
class Light;
class DaeEllipse;

Fraction* g_pFraction1{ nullptr };
Fraction* g_pFraction2{ nullptr };
Fraction* g_pFraction3{ nullptr };
Fraction* g_pFraction4{ nullptr };
Fraction* g_pFraction5{ nullptr };
Fraction* g_pFraction6{ nullptr };

void InitFractions();
void PrintFractionsSum();
void DrawFractions();
void DeleteFractions();

Light* g_pLight1{ nullptr };
Light* g_pLight2{ nullptr };
Light* g_pLight3{ nullptr };
Light* g_pLight4{ nullptr };
Light* g_pLight5{ nullptr };
Light* g_pLight6{ nullptr };
Light* g_pLight7{ nullptr };
Light* g_pLight8{ nullptr };

void InitLights();
void DrawLights();
void HitLights(const Point2f& pos);
void DeleteLights();

DaeEllipse* g_pEllipse1{ nullptr };
DaeEllipse* g_pEllipse2{ nullptr };
DaeEllipse* g_pEllipse3{ nullptr };

void InitEllipses();
void DrawEllipses();
void HitEllipses(const Point2f& pos);
void DeleteEllipses();
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
