#pragma once
using namespace utils;
#pragma region gameInformation
std::string g_WindowTitle{ "Shuffle Cards - Belmans, Jef - 1DAE21" };

float g_WindowWidth{ 910 };
float g_WindowHeight{ 380 };
#pragma endregion gameInformation

#pragma region ownDeclarations
const int g_NrCards{ 52 };
Texture g_Cards[g_NrCards]{};

void InitCards(Texture* pCards, const int size);
void DeleteCards(Texture* pCards, const int size);
void DrawCards(const Texture* pCards, const int size);
void ShuffleCards(Texture* pCards, const int size, const int nrShuffles);
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
