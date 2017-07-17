#pragma once
#include "DynamicArray.h"
#include <math.h>

template <typename T>
class Heap
{
public:
	void Push(T data)
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

				if (m_Data[current] < m_Data[parent])
				{
					T swap = m_Data[current];
					m_Data[current] = m_Data[parent];
					m_Data[parent] = swap;

					current = parent;
				}

				else
					break;
		}	
	}

	T Pop()
	{
		int result = m_Data[0];

		// Replace first element with last element.
		int last = m_Data.Size() - 1;
		m_Data[0] = m_Data[last];

		// Swap first element with smaller child if child is smaller.
		int current = 0;
		
		while (true)
		{
			int child0 = GetChildIndex(current, 0);

			if (child0 > last)
				break;

			int child1 = GetChildIndex(current, 1);
			int smallerChild = child0;

			if (child1 <= last && m_Data[child1] < m_Data[smallerChild])
				smallerChild = child1;

			// Check if smaller than parent, if so swap.
			if (m_Data[smallerChild] < m_Data[current])
			{
				T swap = m_Data[current];
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

	void Clear()
	{
		m_Data.Clear();
	}

	int GetSize() 
	{
		return (int)m_Data.Size();
	}

	int GetParentIndex(int child)
	{
		return (child - 1) / 2;
	}

	int GetChildIndex(int parent, int whichChild)
	{
		return (2 * parent) + whichChild;
	}

private:
	DynamicArray<T> m_Data;

};