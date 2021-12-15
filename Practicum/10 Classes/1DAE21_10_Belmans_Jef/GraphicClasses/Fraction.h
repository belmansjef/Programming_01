#include "structs.h"

class Fraction
{
private:
	int m_Numerator{};
	int m_Denominator{};

public:
	Fraction(int numerator, int denominator);
	void Draw(const Point2f& pos, float size);
	const float GetValue();
};

