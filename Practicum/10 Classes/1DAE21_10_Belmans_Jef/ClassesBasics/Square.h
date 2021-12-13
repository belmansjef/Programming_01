#pragma once
class Square
{
private:
	float m_Left{};
	float m_Bottom{};
	float m_Size{};

	float GetArea();
	float GetPerimiter();
public:
	Square(float size);
	Square(float left, float bottom, float size);
	~Square();

	void Print();
	const void Translate(float deltaLeft, float deltaBottom);
	const void SetSize(float newSize);

};
