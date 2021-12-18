#pragma once
#include "pch.h"

class DaeEllipse
{
private:
	Point2f m_Center{};
	float m_RadX{};
	float m_RadY{};
	Color4f m_FillColor{};
	float m_Area{};
	bool m_IsActive{};

public:
	DaeEllipse(const Point2f& center, float radX, float radY, const Color4f& fillColor);
	
	float CalculateArea();
	void Draw();
	void ActivateTest(const Point2f& pos);
};

