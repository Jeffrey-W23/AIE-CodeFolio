// #include, using, etc
#pragma once
#include "DynamicArray.h"
#include "AStarNode.h"
#include <math.h>

//--------------------------------------------------------------------------------------
// Heap object
//--------------------------------------------------------------------------------------
class Heap //template <typename T>
{
public:

	//--------------------------------------------------------------------------------------
	// Push: Push Node to the heap.
	//
	// Param:
	//		data: An AStarNode pointer.s
	//--------------------------------------------------------------------------------------
	void Push(AStarNode* data)
	{
		// Add data to end of array.
		m_Data.PushBack(data);

		// Loop through and swap data with parent if data is smaller.
		int current = m_Data.Size() - 1;
		
		while (true)
		{
			if (current == 0)
				break;

			int parent = GetParentIndex(current);

				if (m_Data[current]->m_nFScore < m_Data[parent]->m_nFScore)
				{
					AStarNode* swap = m_Data[current];
					m_Data[current] = m_Data[parent];
					m_Data[parent] = swap;

					current = parent;
				}

				else
					break;
		}	
	}

	//--------------------------------------------------------------------------------------
	// Pop: Pop a Node from the heap.
	//
	// Return:
	//		AStarNode*: Returns an AStarNode pointer.
	//--------------------------------------------------------------------------------------
	AStarNode* Pop()
	{
		AStarNode* result = m_Data[0];

		// Replace first element with last element.
		int last = m_Data.Size() - 1;
		m_Data[0] = m_Data[last];

		// Swap first element with smaller child if child is smaller.
		int current = 0;
		
		while (true)
		{
			int child0 = GetChildIndex(current, 1);

			if (child0 > last)
				break;

			int child1 = GetChildIndex(current, 2);
			int smallerChild = child0;

			if (child1 <= last && m_Data[child1]->m_nFScore < m_Data[smallerChild]->m_nFScore)
				smallerChild = child1;

			// Check if smaller than parent, if so swap.
			if (m_Data[smallerChild]->m_nFScore < m_Data[current]->m_nFScore)
			{
				AStarNode* swap = m_Data[current];
				m_Data[current] = m_Data[smallerChild];
				m_Data[smallerChild] = swap;

				current = smallerChild;
			}
			else
				break;
		}

		m_Data.PopBack();
		return result;
	}

	//--------------------------------------------------------------------------------------
	// Clear: Clear the heap.
	//--------------------------------------------------------------------------------------
	void Clear()
	{
		m_Data.Clear();
	}

	//--------------------------------------------------------------------------------------
	// GetSize: Get the size of the Heap.
	//
	// Return:
	//		int: Returns an Int for the size of the Heap.
	//--------------------------------------------------------------------------------------
	int GetSize() 
	{
		return (int)m_Data.Size();
	}

	//--------------------------------------------------------------------------------------
	// GetParentIndex: Returns what the parent is of a child in the heap.
	//
	// Return:
	//		int: Returns an int for the parent index.
	// Param:
	//		child: An int for what child you want to get a parent for.
	//--------------------------------------------------------------------------------------
	int GetParentIndex(int child)
	{
		return (child - 1) / 2;
	}

	//--------------------------------------------------------------------------------------
	// GetChildIndex: Returns what the child index is in the heap.
	//
	// Return:
	//		int: Returns an int child index.
	// Param:
	//		parent: An int parent.
	//		whichChild: An int for which child you want.
	//--------------------------------------------------------------------------------------
	int GetChildIndex(int parent, int whichChild)
	{
		return (2 * parent) + whichChild;
	}

	//--------------------------------------------------------------------------------------
	// Contains: Check if the Heap contains a ceartain node.
	//
	// Return:
	//		int: Returns the index of the node you are checking.
	// Param:
	//		pData: The AStarNode you want to check is in the Heap.
	//--------------------------------------------------------------------------------------
	int Contains(AStarNode* pData)
	{
		for (int i = 0; i < m_Data.Size(); ++i)
		{
			if (m_Data[i] == pData)
				return i;
		}

		return -1;
	}

	//--------------------------------------------------------------------------------------
	// Resort: Resort the heap by index.
	//
	// Param:
	//		index: index to sort in the heap.
	//--------------------------------------------------------------------------------------
	void Resort(int index)
	{
		if (index == 0)
			return;

		int nNodeIndex = index;
		int nParent = GetParentIndex(index);

		//Check if node has a lower F value than parent, if so then swap.
		while (nParent >= 0 && m_Data[nNodeIndex]->m_nFScore < m_Data[nParent]->m_nFScore)
		{
			//Swap
			AStarNode* temp = m_Data[nParent];
			m_Data[nParent] = m_Data[nNodeIndex];
			m_Data[nNodeIndex] = temp;

			nNodeIndex = nParent;
			nParent = GetParentIndex(nNodeIndex);
		}
	}

private:

	//--------------------------------------------------------------------------------------
	// A DynamicArray of AStarNode pointers.
	//--------------------------------------------------------------------------------------
	DynamicArray<AStarNode*> m_Data;
};