// #includes, using, etc
#pragma once
#include "BTBaseNode.h"
#include "DynamicArray.h"

//--------------------------------------------------------------------------------------
// BTComposite object. Inheritance from BTBaseNode.
//--------------------------------------------------------------------------------------
class BTComposite : public BTBaseNode
{
public:

	//--------------------------------------------------------------------------------------
	// Virtual Default Destructor
	//--------------------------------------------------------------------------------------
	virtual ~BTComposite()
	{
		for (unsigned int i = 0; i < children.Size(); ++i)
		{
			delete children[i];
		}
	}
	
	//--------------------------------------------------------------------------------------
	// A Dynamic Array of BTBaseNode pointers. children in the tree.
	//--------------------------------------------------------------------------------------
	DynamicArray<BTBaseNode*> children;

	//--------------------------------------------------------------------------------------
	// A BTBaseNode pointer pendingNode. Starting at null.
	//--------------------------------------------------------------------------------------
	BTBaseNode* pendingNode = nullptr;
};