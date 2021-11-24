#include "pch.h"
#include "Game.h"

#pragma region gameFunctions											
void Start()
{
	cout << ToString(g_MainVector) << endl;
}

void Draw()
{
	ClearBackground(0.0f, 0.0f, 0.0f);

	SetColor(0.0f, 1.0f, 0.0f);
	DrawVector(g_MainVector);
	DrawVector(g_SecondaryVector, Point2f(g_MainVector.x, g_MainVector.y));
	DrawVector(Add(g_MainVector, g_SecondaryVector));

	SetColor(1.0f, 1.0f, 1.0f);
	DrawVector(Vector2f(100.0f, 100.0f), Point2f(150.0f, 150.0f));
	DrawVector(Vector2f(240.0f, 75.0f), Point2f(150.0f, 150.0f));
	DrawVector(Substract(Vector2f(100.0f, 100.0f), Vector2f(240.0f, 75.0f)), Point2f(250.0f, 250.0f));
}

void Update(float elapsedSec)
{

}

void End()
{

}
#pragma endregion gameFunctions

#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{

}

void OnKeyUpEvent(SDL_Keycode key)
{
	
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{

}
#pragma endregion inputHandling

#pragma region ownDefinitions
Vector2f Add(const Vector2f& v1, const Vector2f& v2)
{
	return Vector2f(v1.x + v2.x, v1.y + v2.y);
}

Vector2f Substract(const Vector2f& v1, const Vector2f& v2)
{
	return Vector2f(v2.x - v1.x, v2.y - v1.y);
}

Vector2f Scale(const float& scalar, const Vector2f& v1)
{
	return Vector2f();
}

Vector2f Normalize(const Vector2f& v1)
{
	return Vector2f();
}

bool AreEqual(const Vector2f& v1, const Vector2f& v2)
{
	return false;
}

float DotProduct(const Vector2f& v1, const Vector2f& v2)
{
	return 0.0f;
}

float CrossProduct(const Vector2f& v1, const Vector2f& v2)
{
	return 0.0f;
}

float Length(const Vector2f& v1)
{
	return sqrtf(powf(v1.x, 2.0f) + powf(v1.y, 2.0f));
}

float AngleBetween(const Vector2f& v1, const Vector2f& v2)
{
	return 0.0f;
}

string ToString(const Vector2f& v1)
{
	return "[" + to_string(v1.x) + ", " + to_string(v1.y) + "]";
}

void DrawVector(Vector2f v1, Point2f startPos)
{
	float angle { atan2f(v1.y, v1.x) };
	float length { Length(v1) };
	Vector2f newVector { (length - 10.0f) * cosf(angle) + startPos.x, (length - 10.0f) * sinf(angle) + startPos.y };

	DrawLine(newVector.x, newVector.y, startPos.x, startPos.y);

	Point2f p1{ newVector.x + (5.0f * cosf(angle + (g_Pi / 2.0f))), newVector.y + (5.0f * sinf(angle + (g_Pi / 2.0f))) };
	Point2f p2{ newVector.x - (5.0f * cosf(angle + (g_Pi / 2.0f))), newVector.y - (5.0f * sinf(angle + (g_Pi / 2.0f))) };
	Point2f p3{ v1.x + startPos.x, v1.y + startPos.y };
	FillTriangle(p1, p2, p3);
}

#pragma endregion ownDefinitions
