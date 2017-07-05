#pragma once
#include "LinkedLists.h"

template <typename T>
class GraphNode
{
public:
	GraphNode() 
	{
		m_bTraversed = false;
	}

	GraphNode(T data)
	{
		m_Data = data;
		m_bTraversed = false;
	}

	~GraphNode() {}

	//Add
	void AddConnection(GraphNode<T>* other)
	{
		m_Edges.PushBack(other);
	}

	//Remove
	void RemoveConnection(GraphNode<T>* other)
	{
		m_Edges.Remove(other);
	}

	LinkedLists<GraphNode<T>*> m_Edges;
	T m_Data;
	bool m_bTraversed;
};