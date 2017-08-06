// #includes, using, etc
#pragma once
#include "BTComposite.h"
#include "BTBaseNode.h"

//--------------------------------------------------------------------------------------
// BTSelector object. Inheritance from BTComposite. OR
//--------------------------------------------------------------------------------------
class BTSelector : public BTComposite
{
public:

	//--------------------------------------------------------------------------------------
	// Execute: A virtual function to update objects over time.
	//
	// Returns:
	//		EBehaviourResult: An enum of success, fail or pending.
	// Param:
	//		deltaTime: Pass in deltaTime. A number that updates per second.
	//		pEntity: A pointer to an entity.
	//--------------------------------------------------------------------------------------
	EBehaviourResult Execute(Entity* pEntity, float deltaTime)
	{
		// Set the child to pending.
		BTBaseNode* child = pendingNode;

		unsigned int i = -1;

		if (!child)
			i = 0;

		for (; i < children.Size(); ++i)
		{
			if (i >= 0)
				child = children[i];

			// Get the result of each child.
			EBehaviourResult result = child->Execute(pEntity, deltaTime);

			// Check result of children.
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

		// if passes if statements then return success.
		pendingNode = nullptr;
		return EBHAVIOUR_FAILURE;
	}
};