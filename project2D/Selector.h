#pragma once
#include "Composite.h"
#include "BehaviourNode.h"

// Or
class Selector : public Composite
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

			if (result == EBHAVIOUR_SUCCESS)
			{
				pendingNode = nullptr;
				return EBHAVIOUR_SUCCESS;
			}

			if (result == EBHAVIOUR_PENDING)
			{
				pendingNode = child;
				return EBHAVIOUR_PENDING;
			}
		}

		pendingNode = nullptr;
		return EBHAVIOUR_FAILURE;
	}
};