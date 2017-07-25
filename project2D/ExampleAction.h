#pragma once
#include "BehaviourNode.h"
#include <iostream>
#include "Input.h"
using namespace aie;
using namespace std;

class ExampleAction : public BehaviourNode
{
public:
	ExampleAction(char* text)
	{
		m_szText = text;
	}

	EBehaviourResult Execute()
	{
		cout << m_szText << endl;
		return EBHAVIOUR_SUCCESS;
	}

private:
	char* m_szText;
};