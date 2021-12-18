#include "DaeEllipse.h"
#include <iostream>

DaeEllipse::DaeEllipse(const Point2f& center, float radX, float radY, const Color4f& fillColor)
	: m_Center{center}
	, m_RadX{radX}
	, m_RadY{radY}
	, m_FillColor{fillColor}
	, m_IsActive{false}
{
	m_Area = CalculateArea();
}

float DaeEllipse::CalculateArea()
{
	return m_RadX * m_RadY * 3.14159f;
}

void DaeEllipse::Draw()
{
	if (m_IsActive) m_FillColor.a = 1.0f;
	else m_FillColor.a = 0.4f;

	utils::SetColor(m_FillColor);
	utils::FillEllipse(m_Center, m_RadX, m_RadY);
}

void DaeEllipse::ActivateTest(const Point2f& pos)
{
	float p = float((powf(pos.x - m_Center.x, 2.0f) / powf(m_RadX, 2.0f)) + (powf(pos.y - m_Center.y, 2.0f) / powf(m_RadY, 2.0f)));
	m_IsActive = p <= 1.0f;
	if(m_IsActive) std::cout << "Area: " << m_Area << std::endl;
}
