#include "pch.h"
#include "Game.h"
#include <iomanip>

#pragma region gameFunctions											
void Start()
{
	g_NormalizedVector = Normalize(Vector2f(22.5f, 12.5f));

	cout << fixed << setprecision(5) << endl;
	cout << ToString(g_MainVector) << endl;

	cout << endl << "Dot product:" << endl;
	float dotProduct = DotProduct(Vector2f(80.0f, 0.0f), Vector2f(0.0f, 50.0f));
	cout << "Hor = [80.00000, 0.00000]\tver = [0.00000, 50.00000]\tDot Product: " << dotProduct << endl;

	dotProduct = DotProduct(Vector2f(80.0f, 0.0f), Vector2f(25.0f, 0.0f));
	cout << "Hor = [80.00000, 0.00000]\tpara = [25.00000, 0.00000]\tDot Product: " << dotProduct << endl;

	cout << endl << "Cross product:" << endl;
	float crossProduct = CrossProduct(Vector2f(80.0f, 0.0f), Vector2f(0.0f, 50.0f));
	cout << "Hor = [80.00000, 0.00000]\tver = [0.00000, 50.00000]\tCross Product: " << crossProduct << endl;

	crossProduct = CrossProduct(Vector2f(00.0f, 50.0f), Vector2f(80.0f, 0.0f));
	cout << "Hor = [80.00000, 0.00000]\tver = [0.00000, 50.00000]\tCross Product: " << crossProduct << endl;

	cout << endl << "Length of [100.00000, 30.00000] is " << Length(Vector2f(100.0f, 30.0f)) << endl;

	Vector2f scaled = Scale(0.1f, Vector2f(100.0f, 30.0f));
	cout << endl << "Scaled [100.00000, 30.00000] is [" << scaled.x << ", " << scaled.y << "]" << endl;

	Vector2f normalized = Normalize(Vector2f(10.0f, 30.0f));
	cout << endl << "Normalized [10.00000, 30.00000] is [" << normalized.x << ", " << normalized.y << "] its length is " << Length(normalized) << endl;

	float angleRad = AngleBetween(Vector2f(10.0f, 0.0f), Vector2f(10.0f, 10.0f));
	cout << endl << "Angle between [10.00000, 0.00000] and [10.00000, 10.00000] is: " << angleRad << " radians, or " << angleRad * (180.0f / g_Pi) << " degrees" << endl;

	cout << AreEqual(Vector2f(10.0f, 0.0f), Vector2f(10.0001f, 0.0f)) << endl;
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

	SetColor(1.0f, 1.0f, 1.0f);
	DrawVector(g_ProjectionVector, Point2f(g_WindowWidth / 2.0f, g_WindowHeight / 2.0f));
	SetColor(1.0f, 0.0f, 0.0f);
	DrawVector(g_ProjectedVector, Point2f(g_WindowWidth / 2.0f, g_WindowHeight / 2.0f));
}

void Update(float elapsedSec)
{
	g_CurrentAngle += (45.0f * (g_Pi / 180.0f) * elapsedSec);
	g_ProjectionVector.x = 50.0f * cosf(g_CurrentAngle);
	g_ProjectionVector.y = 50.0f * sinf(g_CurrentAngle);

	const float dp{ DotProduct(g_ProjectionVector, g_NormalizedVector) };
	g_ProjectedVector = Vector2f(g_NormalizedVector.x * dp, g_NormalizedVector.y * dp);
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
	return Vector2f(v1.x * scalar, v1.y * scalar);
}

Vector2f Normalize(const Vector2f& v1)
{
	return Vector2f(v1.x / Length(v1), v1.y / Length(v1));
}

bool AreEqual(const Vector2f& v1, const Vector2f& v2)
{
	return abs(v1.x - v2.x) <= 0.001f && abs(v1.y - v2.y) < 0.001f;
}

float DotProduct(const Vector2f& v1, const Vector2f& v2)
{
	return (v1.x * v2.x) + (v1.y * v2.y);
}

float CrossProduct(const Vector2f& v1, const Vector2f& v2)
{
	return (v1.x * v2.y) - (v1.y * v2.x);
}

float Length(const Vector2f& v1)
{
	return sqrtf(powf(v1.x, 2.0f) + powf(v1.y, 2.0f));
}

float AngleBetween(const Vector2f& v1, const Vector2f& v2)
{
	return atan2f(CrossProduct(v1, v2), DotProduct(v1, v2));
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
