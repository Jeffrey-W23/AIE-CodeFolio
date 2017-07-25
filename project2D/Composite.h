#pragma once
#include "BehaviourNode.h"
#include "DynamicArray.h"

class Composite : public BehaviourNode
{
public: // Added an add and remove child function so this can be changed back to protected
	virtual ~Composite()
	{
		for (unsigned int i = 0; i < children.Size(); ++i)
		{
			delete children[i];
		}
	}
	
	DynamicArray<BehaviourNode*> children;
	BehaviourNode* pendingNode = nullptr;
};