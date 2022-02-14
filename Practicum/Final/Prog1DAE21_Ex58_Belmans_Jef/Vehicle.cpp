#include "pch.h"
#include "Vehicle.h"

Vehicle::Vehicle(int id)
	: m_MinSpeed{ 20 }
	, m_MaxSpeed{ 200 }
	, m_Speed{ utils::GenerateRandomNumber(m_MinSpeed, m_MaxSpeed) }
	, m_Position{ 0.0f, 0.0f }
	, m_IsActive{ false }
{
	std::string path{"Resources/car-truck" + std::to_string(id) + ".bmp" };
	utils::TextureFromFile(path, m_Texture);
}

void Vehicle::Reset()
{
	m_Position.x = utils::GenerateRandomNumber(-300.0f, 0.0f);
	m_Speed = utils::GenerateRandomNumber(m_MinSpeed, m_MaxSpeed);
	m_IsActive = true;
}

Vehicle::~Vehicle()
{
	// Throws error on close
	// utils::DeleteTexture(m_Texture);
}

void Vehicle::Update(float elapsedSec, float windowWidth)
{
	if (!m_IsActive) return;

	m_Position.x += m_Speed * elapsedSec;
	if (m_Position.x >= windowWidth)
	{
		m_Position.x = 0.0f;
	}
}

void Vehicle::Draw()
{
	utils::DrawTexture(m_Texture, m_Position);
}

bool Vehicle::IsIntersecting(const Point2f& pt)
{
	return
		pt.x <= m_Position.x + m_Texture.width
		&& pt.x >= m_Position.x
		&& pt.y <= m_Position.y + m_Texture.height
		&& pt.y >= m_Position.y;
}

void Vehicle::SetActive(bool isActive)
{
	m_IsActive = isActive;
}

void Vehicle::SetYPos(float posY)
{
	m_Position.y = posY;
}