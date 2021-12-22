#pragma once
#include "pch.h"

class Sprite
{
private:
	utils::Texture m_Texture{};
	int m_Cols{};
	int m_Rows{};
	float m_FrameSec{};
	float m_AccuSec{};
	int m_ActFrame{};
	
	float m_Scale{};

public:
	Sprite(const std::string& filename, int nrCols, int nrRows, float frameSec, float scale);
	~Sprite();
	
	float GetFrameWidth();
	float GetFrameHeight();

	void Update(float deltaTime);
	void Draw(const Point2f& pos);
};

