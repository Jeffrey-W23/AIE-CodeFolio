// #include, using, etc
#pragma once
#include "LinkedLists.h"
#include "GraphNode.h"
#include "Stack.h"

//--------------------------------------------------------------------------------------
// Graph object. Incomplete.
//--------------------------------------------------------------------------------------
template <typename T>
class Graph
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	Graph() {}

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~Graph() {}

	//--------------------------------------------------------------------------------------
	// Insert: Insert something into the graph.
	//
	// Param:
	//		node: a GraphNode pointer taking in T. What you want to insert into the graph.
	//--------------------------------------------------------------------------------------
	void Insert(GraphNode<T>* node)
	{
		m_Nodes.PushBack(node);
	}

	//--------------------------------------------------------------------------------------
	// RemoveByNode: Remove a Node from the Graph.
	//
	// Param:
	//		node: a GraphNode pointer taking in T. What you want to remove from the graph
	//--------------------------------------------------------------------------------------
	void RemoveByNode(GraphNode<T>* node)
	{
	
	}

	//--------------------------------------------------------------------------------------
	// Remove: Remove something from the Graph
	//
	// Param:
	//		data: taking in type T for the data you want to remove.
	//--------------------------------------------------------------------------------------
	void Remove(T data)
	{
	
	}

	//--------------------------------------------------------------------------------------
	// DrawGraph: Draw the graph.
	//--------------------------------------------------------------------------------------
	void DrawGraph()
	{
		for (int i = 0; i < m_Nodes.Size(); ++i)
		{
			m_Nodes[i]->m_bTraversed = false;
		}

		Stack<GraphNode<T>*> stack;

		stack.Push(m_Nodes[0]);

		while (!stack.IsEmpty())
		{
			GraphNode<T>* current = stack.Pop();
			current->m_bTraversed = true;

			for (int i = 0; i < current->m_Edges.Size(); ++i)
			{
				if (!current->m_Edges[i]->m_bTraversed)
					stack->Push(current->m_Edges[i]);
			}
		}
	}
	
private:

	//--------------------------------------------------------------------------------------
	// A LinkedList of GraphNode pointers taking in T.
	//--------------------------------------------------------------------------------------
	LinkedLists<GraphNode<T>*> m_Nodes;
};