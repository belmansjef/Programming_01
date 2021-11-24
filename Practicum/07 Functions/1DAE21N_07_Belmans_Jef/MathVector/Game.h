#pragma once
using namespace utils;
using namespace std;
#pragma region gameInformation
std::string g_WindowTitle{ "Math Vector - Belmans, Jef - 1DAE21" };

float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
const Vector2f g_MainVector{100.0f, 100.0f};
const Vector2f g_SecondaryVector{60.0f, 20.0f};

Vector2f Add(const Vector2f& v1, const Vector2f& v2);
Vector2f Substract(const Vector2f& v1, const Vector2f& v2);
Vector2f Scale(const float& scalar, const Vector2f& v1);
Vector2f Normalize(const Vector2f& v1);

bool AreEqual(const Vector2f& v1, const Vector2f& v2);

float DotProduct(const Vector2f& v1, const Vector2f&  v2);
float CrossProduct(const Vector2f& v1, const Vector2f& v2);
float Length(const Vector2f& v1);
float AngleBetween(const Vector2f& v1, const Vector2f& v2);

string ToString(const Vector2f& v1);

void DrawVector(Vector2f v1, Point2f startPos = Point2f(0.0f, 0.0f));
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
