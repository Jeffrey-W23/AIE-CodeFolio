// #include, using, etc
#pragma once
#include "ListNode.h"

//--------------------------------------------------------------------------------------
// LinkedLists object
//--------------------------------------------------------------------------------------
template<typename T>
class LinkedLists
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	LinkedLists()
	{
		start = new ListNode<T>();
		end = new ListNode<T>();

		start->next = end;
		start->prev = nullptr;

		end->next = nullptr;
		end->prev = start;
	};

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~LinkedLists()
	{
		delete start;
		delete end;
	};

	//--------------------------------------------------------------------------------------
	// insert: Insert a value into the LinkedList
	//
	// Param:
	//		value: the value you want to add.
	//		prev: the previous node.
	//		next: the next node.
	//--------------------------------------------------------------------------------------
	void insert(T value, ListNode<T>* prev, ListNode<T>* next)
	{
		ListNode<T>* n1 = new ListNode<T>();

		n1->data = value;
		n1->next = next;
		prev->next = n1;
		next->prev = n1;
		n1->prev = prev;
		++nodeCount;
	}

	//--------------------------------------------------------------------------------------
	// PushBack: Push a value onto the back of the LinkedList
	//
	// Param:
	//		value: A Type T for what the data is you want to push.
	//--------------------------------------------------------------------------------------
	void PushBack(T value)
	{
		insert(value, end->prev, end);
	}

	//--------------------------------------------------------------------------------------
	// PushFront: Push a value onto the front of the LinkedList
	//
	// Param:
	//		value: A Type T for what the data is you want to push.
	//--------------------------------------------------------------------------------------
	void PushFront(T value)
	{
		insert(value, start, start->next);
	}

	//--------------------------------------------------------------------------------------
	// IndexInsert: Insert data at an index in the LinkedList
	//
	// Param:
	//		index: an int for where to insert the data in the linkedlist.
	//		value: A Type T for what data you want to insert.
	//--------------------------------------------------------------------------------------
	void IndexInsert(int index, T value)
	{
		ListNode<T>* current = start;
		
		for (int i = 0; i < index; ++i)
		{
			if (current->next == end)
				return;

			current = current->next;
		}
		
		insert(value, current, current->next);
	}

	//--------------------------------------------------------------------------------------
	// First: Get the first one in the LinkedList
	//
	// Returns:
	//		T: Returns T for the first one in the LinkedList.
	//--------------------------------------------------------------------------------------
	T First()
	{
		if (start->next == end)
		{
			//TODO: print an error message that this is empty.
			return default;
		}
		else
		{
			T value = start->next->data;
			return value;
		}
	}

	//--------------------------------------------------------------------------------------
	// Last: Get the last one in the LinkedList
	//
	// Returns:
	//		T: Returns T for the last one in the LinkedList.
	//--------------------------------------------------------------------------------------
	T Last()
	{
		if (start->next == end)
		{
			//TODO: print an error message that this is empty.
			return default;
		}
		else
		{
			T value = end->prev->data;
			return value;
		}
	}

	//--------------------------------------------------------------------------------------
	// Size: Check the size of the LinkedList
	//
	// Returns:
	//		Int: returns the value of how many are in the linkedlist.
	//--------------------------------------------------------------------------------------
	int Size()
	{
		return nodeCount;
	}

	//--------------------------------------------------------------------------------------
	// Empty: Check if a Linkedlist is empty.
	//
	// Returns:
	//		bool: Returns a bool if it is empty or not.
	//--------------------------------------------------------------------------------------
	bool Empty()
	{
		if (start->next == end)
			return true;
		else
			return false;
	}

	//--------------------------------------------------------------------------------------
	// PopBack: Pop a value from the back.
	//
	// Returns:
	//		T: Returns T for whats its poping back to.
	//--------------------------------------------------------------------------------------
	T PopBack()
	{
		ListNode<T>* n = end->prev;
		T tempData = n->data;

		if (n != start)
		{
			n->prev->next = end;
			end->prev = n->prev;
			
			delete n;
			
			--nodeCount;
			
			return tempData;
		}

		else
			return default;
	}

	//--------------------------------------------------------------------------------------
	// PopFront: Pop a value from the front.
	//
	// Returns:
	//		T: Returns T for whats its poping back to.
	//--------------------------------------------------------------------------------------
	T PopFront()
	{
		ListNode<T>* n = start->next;
		T tempData = n->data;

		if (n != end)
		{
			n->next->prev = start;
			start->next = n->next;

			delete n;

			--nodeCount;

			return tempData;
		}

		else
			return default;
	}

	//--------------------------------------------------------------------------------------
	// Clear: Clear the linked list.
	//--------------------------------------------------------------------------------------
	void Clear()
	{
		while (start->next != end)
			popBack();
	}

	//--------------------------------------------------------------------------------------
	// Erase: Erase the LinkedList.
	//
	// Param:
	//		index: where to start erase from.
	//--------------------------------------------------------------------------------------
	void Erase(int index)
	{
		ListNode<T>* current = start;

		for (int i = 0; i < index; ++i)
		{
			if (current->next == end)
			{
				cout << "Invalid index location!" << endl;

				return;
			}

			current = current->next;
		}
		
		if (current == start || current == end)
		{
			cout << "Cannot delete start and end!" << endl;

			return;
		}

		current->next->prev = current->prev;
		current->prev->next = current->next;

		delete current;

		--nodeCount;
	}

	//--------------------------------------------------------------------------------------
	// Remove: Remove an item from the LinkedList
	//
	// Param:
	//		value: the data youy want to remove.
	//--------------------------------------------------------------------------------------
	void Remove(T value)
	{
		ListNode<T>* temp = nullptr;
		ListNode<T>* current = start->next;

		while (current->next != end)
		{
			if (current->next == end)
			{
				cout << "Invalid index location!" << endl;

				return;
			}

			if (current->data == value)
			{
				temp = current->prev;
				current->next->prev = current->prev;
				current->prev->next = current->next;

				delete current;

				current = temp;
				--nodeCount;
			}

			current = current->next;
		}
	}

	//--------------------------------------------------------------------------------------
	// PrintList: Print the linked list.
	//--------------------------------------------------------------------------------------
	void PrintList()
	{
		ListNode<T>* current = start->next;

		while (current->next != end)
		{
			cout << current->data << endl;
			current = current->next;
		}
	}

	//--------------------------------------------------------------------------------------
	// A varaible T default.
	//--------------------------------------------------------------------------------------
	T default;

	//--------------------------------------------------------------------------------------
	// A int for the node count.
	//--------------------------------------------------------------------------------------
	int nodeCount = 0;

	//--------------------------------------------------------------------------------------
	// A ListNode pointer of T. Representing the start of the linkedlist
	//--------------------------------------------------------------------------------------
	ListNode<T>* start;

	//--------------------------------------------------------------------------------------
	// A ListNode pointer of T. Representing the end of the linked list
	//--------------------------------------------------------------------------------------
	ListNode<T>* end;
};
