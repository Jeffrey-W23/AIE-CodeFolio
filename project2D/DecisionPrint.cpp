#include "DecisionPrint.h"
#include <iostream>
using namespace std;

DecisionPrint::DecisionPrint()
{
	m_timer = 0.0f;
}

DecisionPrint::~DecisionPrint()
{
}

void DecisionPrint::MakeDecision(BaseAgent* pAgent, float deltaTime)
{
	m_timer += deltaTime;

	system("cls");
	cout << "Space has been pressed for " << m_timer << " seconds." << endl;
}