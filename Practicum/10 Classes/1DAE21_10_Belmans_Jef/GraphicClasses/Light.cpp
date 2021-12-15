#include "pch.h"
#include "Light.h"

Light::Light(const Rectf& rect, const Color4f& color) : m_Rect{ rect }, m_Color{ color }, m_IsOn{ false }
{
}

const void Light::Draw()
{
	utils::SetColor(1.0f, 1.0f, 1.0f);
	utils::DrawRect(m_Rect, 2.0f);

	if (m_IsOn)
	{
		utils::SetColor(m_Color);
		utils::FillRect(m_Rect);
	}
	else
	{
		utils::SetColor(0.3f, 0.3f, 0.3f);
		utils::FillRect(m_Rect);
	}
}

const bool Light::IsOn()
{
	return m_IsOn;
}

bool Light::IsHit(const Point2f& pos)
{
	if ( pos.x > m_Rect.left
		&& pos.x < m_Rect.left + m_Rect.width
		&& pos.y > m_Rect.bottom
		&& pos.y < m_Rect.bottom + m_Rect.height )
	{
		m_IsOn = !m_IsOn;
	}
	
	return m_IsOn;
}
