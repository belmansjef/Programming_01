#pragma once
class Time
{
private:
	int m_Seconds{};
public:
	Time(int seconds);
	Time(int seconds, int minutes);
	Time(int seconds, int minutes, int hours);

	void Print();

	const int GetSeconds();
	const int GetMinutes();
	const int GetHours();

	const void AddSeconds(int deltaSeconds);
	const void AddMinutes(int deltaMinutes);
	const void AddHours(int deltaHours);
};

