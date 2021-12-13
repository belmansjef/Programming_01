#include "pch.h"
#include "Square.h"

Square::Square(float size) :m_Left{ 10.0f }, m_Bottom{ 10.0f }, m_Size{ size }
{
}

Square::Square(float left, float bottom, float size) :m_Left{ left }, m_Bottom{ bottom }, m_Size{ size }
{
}

Square::~Square()
{
	std::cout << "Square deconstructor: release the resources" << std::endl;
}

float Square::GetArea()
{
	return powf(m_Size, 2.0f);
}

float Square::GetPerimiter()
{
	return m_Size * 4.0f;
}

void Square::Print()
{
	std::cout << "Left: " << m_Left << ", bottom: " << m_Bottom << std::endl;
	std::cout << "Size: " << m_Size << std::endl;
	std::cout << "Perimiter: " << GetPerimiter() << std::endl;
	std::cout << "Area: " << GetArea() << std::endl << std::endl;
}

const void Square::Translate(float deltaLeft, float deltaBottom)
{
	m_Left += deltaLeft;
	m_Bottom += deltaBottom;
}

const void Square::SetSize(float newSize)
{
	m_Size = newSize;
}
