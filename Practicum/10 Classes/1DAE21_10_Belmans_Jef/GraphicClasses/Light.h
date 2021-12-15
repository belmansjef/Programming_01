#include "structs.h"

class Light
{
private:
	Rectf m_Rect{};
	bool m_IsOn{};
	Color4f m_Color{};

public:
	Light(const Rectf& rect, const Color4f& color);
	const void Draw();
	const bool IsOn();
	bool IsHit(const Point2f& pos);
};

