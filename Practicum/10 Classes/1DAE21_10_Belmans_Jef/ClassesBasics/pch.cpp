#include "pch.h"

void DoSquareTests()
{
	Square* pSq1 = new Square(10.0f);
	Square* pSq2 = new Square(10.0f, 250.0f, 20.0f);

	pSq1->Print();
	pSq2->Print();

	TestSquare(pSq1);
	pSq2->SetSize(100.0f);

	pSq1->Print();
	pSq2->Print();

	delete pSq1;
	delete pSq2;
	pSq1 = pSq2 = nullptr;
}

void TestSquare(Square* pSquare)
{
	pSquare->Translate(20.0f, 10.0f);
}

void DoTimeTests()
{
	Time* pClock = new Time{ 3600 };
	pClock->Print();
	delete pClock;

	pClock = new Time{ 3600, 65 };
	pClock->Print();
	delete pClock;

	pClock = new Time{ 24, 12, 45 };
	pClock->Print();
	delete pClock;

	pClock = new Time{ 0 };

	pClock->AddSeconds(45);
	pClock->AddMinutes(21);
	pClock->AddHours(3);

	pClock->Print();

	delete pClock;
	pClock = nullptr;
}
