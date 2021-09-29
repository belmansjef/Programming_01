#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "StaticDrawing - Belmans, Jef - 1DAE21" };

// Change the window dimensions here
// float g_WindowWidth{ 1024 };
// float g_WindowHeight{ 576 };
float g_WindowWidth{ 1000 };
float g_WindowHeight{ 700 };
#pragma endregion gameInformation



#pragma region ownDeclarations
const int g_CellPadding{ 20 };
const int g_CheckerRows{ 3 };
const int g_CheckerCollumns{ 3 };
const int g_NumColorBands{ 9 };

float g_ColorbandWidth{ 0.0f };

const Color4f g_ColorRed{ 1.0f, 0.0f, 0.0f, 1.0f };
const Color4f g_ColorGreen{ 0.0f, 1.0f, 0.0f, 1.0f };
const Color4f g_ColorBlue{ 0.0f, 0.0f, 1.0f, 1.0f };
const Color4f g_ColorYellow{ 1.0f, 1.0f, 0.0f, 1.0f };
const Color4f g_ColorCyan{ 0.0f, 1.0f, 1.0f, 1.0f };
const Color4f g_ColorMagenta{ 1.0f, 0.0f, 1.0f, 1.0f };
const Color4f g_ColorWhite{ 1.0f, 1.0f, 1.0f, 1.0f };
const Color4f g_ColorBlack{ 0.0f, 0.0f, 0.0f, 1.0f };
const Color4f g_ColorGray{ 0.3f, 0.3f, 0.3f, 1.0f };
const Color4f g_ColorBlackTransparent{ 0.0f, 0.0f, 0.0f, 0.45f };
Color4f g_ColorBandColors[g_NumColorBands];

void DrawHouse(Point2f pos, float width, float height);
void DrawFlag(Point2f pos, float width, float height);
void DrawCheckerPattern(Point2f pos, float width, float height);
void DrawColorBand(Point2f pos, float width);
void DrawPentagram(Point2f center, float radius);
void DrawColumnChart(Point2f pos, float colWidth, float percentages[]);
void CalculateColorBandRatios(float maxWidth, float maxHeight);
void GenerateColorBandColors();
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
