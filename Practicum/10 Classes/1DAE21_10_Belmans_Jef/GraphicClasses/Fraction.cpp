#include "Fraction.h"
#include "pch.h"

Fraction::Fraction(int numerator, int denominator) : m_Numerator{numerator}, m_Denominator{denominator}
{
}

void Fraction::Draw(const Point2f& pos, float size)
{
	for (int i = 0; i < m_Denominator; i++)
	{
		utils::SetColor(1.0f, 1.0f, 1.0f);
		utils::DrawRect(pos.x + (i * size), pos.y, size, size, 2.0f);
		if (i < m_Numerator)
		{
			utils::SetColor(0.2f, 0.7f, 1.0f);
			utils::FillRect(pos.x + (i * size), pos.y, size, size);
		}
	}
}

const float Fraction::GetValue()
{
	return float(m_Numerator) / float(m_Denominator);
}
