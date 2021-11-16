#include "pch.h"

Point2f::Point2f()
	:Point2f{ 0.0f, 0.0f }
{
}
Point2f::Point2f(float x, float y)
	: x{ x }, y{ y }
{
}