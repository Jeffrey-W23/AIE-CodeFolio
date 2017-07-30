#pragma once
#include "BaseQuestion.h"

enum EWhatBehaviour
{
	EWHATBHAVIOUR_SEEK,
	EWHATBHAVIOUR_FLEE,
	EWHATBHAVIOUR_STOP
};

class QWhatBehaviour : public BaseQuestion
{
public:
	QWhatBehaviour();
	~QWhatBehaviour();
	void MakeDecision(Entity* pEntity, float deltaTime);

private:
	EWhatBehaviour m_bBehaviour;
};