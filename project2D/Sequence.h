#pragma once
#include "Composite.h"
#include "BehaviourNode.h"

// Or
class Sequence : public Composite
{
public:
	EBehaviourResult Execute()
	{
		BehaviourNode* child = pendingNode;

		unsigned int i = -1;

		if (!child)
			i = 0;

		for (; i < children.Size(); ++i)
		{
			if (i >= 0)
				child = children[i];

			EBehaviourResult result = child->Execute();

			if (result == EBHAVIOUR_FAILURE)
			{
				pendingNode = nullptr;
				return EBHAVIOUR_FAILURE;
			}

			if (result == EBHAVIOUR_PENDING)
			{
				pendingNode = child;
				return EBHAVIOUR_PENDING;
			}
		}

		pendingNode = nullptr;
		return EBHAVIOUR_SUCCESS;
	}
};