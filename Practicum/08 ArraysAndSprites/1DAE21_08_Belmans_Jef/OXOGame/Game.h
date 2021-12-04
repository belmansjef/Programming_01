#pragma once
using namespace utils;
#pragma region gameInformation
std::string g_WindowTitle{ "OXO- Belmans, Jef - 1DAE21" };

float g_WindowWidth{ 572 };
float g_WindowHeight{ 480 };
#pragma endregion gameInformation

#pragma region ownDeclarations
enum class TextureType
{
	background,
	whiteO,
	whiteX,
	greenO,
	greenX,
	emtypCell,
	winCell
};

struct Cell
{
	Cell();
	explicit Cell(Texture texture, TextureType type, Rectf dstRect);

	Texture texture;
	TextureType type;
	Rectf dstRect;
};

const int g_NrTextures{ 7 };
Texture g_Textures[g_NrTextures]{};

const int g_NrCells{ 9 };
Cell g_BoardCells[g_NrCells]{ };
Cell g_PlayerCells[2]{};

int g_ActivePlayer{ 0 };

bool IsEmpty(const TextureType& type);
bool IsGameWon();

void LoadTextures(Texture* pTextures);
void FreeResources(Texture* pTextures, const int size);
void CheckUIClicked(const Point2f& clickedPos, Cell* pBoardCells, const int size);
void SwitchPlayerSprite(const SDL_Keycode& pressedKey);
void CreateCells(Cell* pCells, const int size);

void DrawCells(Cell* pCells, const int size);
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
