#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "../Engine/PCH.h"

namespace Quantum
{
#define _Node std::shared_ptr<Node<T>>

	template <typename T>
	class Node
	{
	public:
		Node();
		Node(T data);
		~Node();

		//Data stored in the node
		T Data;
		//Pointer to next node in the list
		_Node Next = nullptr;
	};

	template <typename T>
	class LinkedList
	{
	public:
		LinkedList();
		~LinkedList();
		
		//Returns the data at the position
		T operator[](int index);

		//Concatenates two lists together into a single list
		void operator+=(LinkedList Other);

		//Returns the node at index
		_Node GetNode(int index);

		//Returns the position of the node in the list. Returns -1 if list does not contain node
		int FindNodePosition(_Node TargetNode);

		//Checks if list contains a node
		bool Contains(_Node TargetNode);

		//Checks if list contains an object
		bool Contains(T Object);

		//Returns the length of the list
		int Length();

		//Pushes a new node to the back of the list
		void PushBack(T Data);

		//Pushes a new node to the front of the list
		void PushFront(T Data);

		//Removes a node a position
		void Remove(int index);

		//Removes a given node
		void Remove(_Node TargetNode);

		//Clears the list
		void Clear();

		//Returns the head of the list
		_Node Head() const;
		//Retunes the tail of the list
		_Node Tail() const;

	private:
		_Node head;
		_Node tail;

		_Node CreateNode(T data);
	};
}

#include "Source/LinkedList.tpp"

#endif //!LINKEDLIST_H