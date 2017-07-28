#pragma once
#include "BTComposite.h"
#include "BTBaseNode.h"

// And
class BTSequence : public BTComposite
{
public:
	EBehaviourResult Execute(Entity* pEntity, float deltaTime)
	{
		BTBaseNode* child = pendingNode;

		unsigned int i = -1;

		if (!child)
			i = 0;

		for (; i < children.Size(); ++i)
		{
			if (i >= 0)
				child = children[i];

			EBehaviourResult result = child->Execute(pEntity, deltaTime);

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