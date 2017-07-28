#pragma once
#include "BTBaseNode.h"
#include "DynamicArray.h"

class BTComposite : public BTBaseNode
{
public:
	virtual ~BTComposite()
	{
		for (unsigned int i = 0; i < children.Size(); ++i)
		{
			delete children[i];
		}
	}
	
//protected:
	DynamicArray<BTBaseNode*> children;
	BTBaseNode* pendingNode = nullptr;
};