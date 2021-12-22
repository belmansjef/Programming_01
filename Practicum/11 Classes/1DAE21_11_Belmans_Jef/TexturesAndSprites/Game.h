#pragma once
using namespace utils;
#pragma region gameInformation
std::string g_WindowTitle{ "Textures and Sprites - Belmans, Jef - 1DAE21" };

float g_WindowWidth{ 600 };
float g_WindowHeight{ 400 };
#pragma endregion gameInformation

#pragma region ownDeclarations
class Sprite;

Texture g_Text{};
Texture g_DaeLogo{};

const int g_NrSprites{ 5 };
Sprite* g_pArrSprites[g_NrSprites]{};

void InitTextures();
void DrawTextures();
void DeleteTextures();

void InitSprites();
void UpdateSprites(float deltaTime);
void DrawSprites();
void DeleteSprites();
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
