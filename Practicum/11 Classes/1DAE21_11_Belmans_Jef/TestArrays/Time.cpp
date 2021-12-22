#include "pch.h"
#include "Time.h"
#include <iomanip>
#include <iostream>

Time::Time(int seconds) : m_Seconds{ seconds }
{
}

Time::Time(int seconds, int minutes) : m_Seconds{ seconds + (minutes * 60) }
{
}

Time::Time(int seconds, int minutes, int hours) : m_Seconds{ seconds + (minutes * 60) + (hours * 3600) }
{
}

void Time::Print()
{
	std::cout << std::setfill('0') << std::setw(2);
	std::cout << "Time: " 
		<< std::setfill('0') << std::setw(2) << GetHours() 
		<< ":" << std::setfill('0') << std::setw(2) << GetMinutes() 
		<< ":" << std::setfill('0') << std::setw(2) << GetSeconds()
		<< std::endl;
}

const int Time::GetSeconds()
{
	return (m_Seconds - ((GetHours() * 3600) + GetMinutes() * 60));
}

const int Time::GetMinutes()
{
	return (m_Seconds - (GetHours() * 3600)) / 60;
}

const int Time::GetHours()
{
	return m_Seconds / 3600;
}

const void Time::AddSeconds(int deltaSeconds)
{
	m_Seconds += deltaSeconds;
}

const void Time::AddMinutes(int deltaMinutes)
{
	m_Seconds += deltaMinutes * 60;
}

const void Time::AddHours(int deltaHours)
{
	m_Seconds += deltaHours * 3600;
}
