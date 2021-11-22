#ifndef PCH_H
#define PCH_H

#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

void Print(const int value, const char delimiter = ' ');

void CalcCosSin(const float& angle, float& cos, float& sin);
void TestCalcCosSin();
float GetRand(const float lower = 0.0f, const float upper = 1.0f);

#endif
