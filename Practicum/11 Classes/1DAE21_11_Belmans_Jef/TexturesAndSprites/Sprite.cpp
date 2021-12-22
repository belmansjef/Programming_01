#include "Sprite.h"

Sprite::Sprite(const std::string& filename, int nrCols, int nrRows, float frameSec, float scale)
	: m_Cols{nrCols}
	, m_Rows{nrRows}
	, m_FrameSec{frameSec}
	, m_AccuSec{0.0f}
	, m_ActFrame{0}
	, m_Scale{scale}
{
	utils::TextureFromFile(filename, m_Texture);
}

Sprite::~Sprite()
{
	utils::DeleteTexture(m_Texture);
}

float Sprite::GetFrameWidth()
{
	return m_Texture.width / m_Cols;
}

float Sprite::GetFrameHeight()
{
	return m_Texture.height / m_Rows;
}

void Sprite::Update(float deltaTime)
{
	m_AccuSec += deltaTime;
	if (m_AccuSec > m_FrameSec)
	{
		++m_ActFrame %= m_Rows * m_Cols;
		m_AccuSec -= m_FrameSec;
	}
}

void Sprite::Draw(const Point2f& pos)
{
	Rectf srcRect{};
	srcRect.width = m_Texture.width / m_Cols;
	srcRect.height = m_Texture.height / m_Rows;
	srcRect.left = (m_ActFrame % m_Cols) * srcRect.width;
	srcRect.bottom = (m_ActFrame / m_Cols + 1) * srcRect.height;

	Rectf dstRect{};
	dstRect.left = pos.x;
	dstRect.bottom = pos.y;
	dstRect.width = srcRect.width * m_Scale;
	dstRect.height = srcRect.height * m_Scale;

	utils::DrawTexture(m_Texture, dstRect, srcRect);
}
