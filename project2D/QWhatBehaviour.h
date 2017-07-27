#pragma once
#include "BaseQuestion.h"

class QWhatBehaviour : public BaseQuestion
{
public:
	QWhatBehaviour();
	~QWhatBehaviour();
	void MakeDecision(Entity* pEntity, float deltaTime);

private:
	bool m_bBehaviour;
};