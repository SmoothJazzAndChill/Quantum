#pragma once

namespace Quantum
{
	template <typename T>
	Node<T>::Node()
	{}

	template <typename T>
	Node<T>::Node(T data)
	{
		Data = data;
	}

	template <typename T>
	Node<T>::~Node()
	{
		Next = nullptr;
	}

	template <typename T>
	LinkedList<T>::LinkedList()
	{
		head = nullptr;
		tail = nullptr;
	}

	template <typename T>
	LinkedList<T>::~LinkedList()
	{
		Clear();
	}

	template <typename T>
	T LinkedList<T>::operator[](int index)
	{
		return GetNode(index)->Data;
	}

	template <typename T>
	void LinkedList<T>::operator+=(LinkedList Other)
	{
		tail->Next = Other.head;
		tail = Other.tail;
	}

	template <typename T>
	_Node LinkedList<T>::GetNode(int index)
	{
		_Node CurrentNode = head;

		for (int i = 0; i <= index; i++)
		{
			CurrentNode = CurrentNode->Next;
		}

		return CurrentNode;
	}

	template <typename T>
	int LinkedList<T>::FindNodePosition(_Node TargetNode)
	{
		_Node Current = head;
		int Position = 0;
		while (Current != nullptr)
		{
			if (Current == TargetNode)
			{
				return Position;
			}

			Position++;
			Current = Current->Next;
		}

		return -1;
	}

	template <typename T>
	bool LinkedList<T>::Contains(_Node TargetNode)
	{
		if (FindNodePosition() != -1)
			return true;

		return false;
	}

	template <typename T>
	bool LinkedList<T>::Contains(T Object)
	{
		_Node Current = head;
		while (Current != nullptr)
		{
			if (Current->Data == Object) return true;
			Current = Current->Next;
		}

		return false;
	}

	template <typename T>
	int LinkedList<T>::Length()
	{
		_Node Current = head;
		int Result;

		while (Current != nullptr)
		{
			Current = Current->Next;
			Result++;
		}

		return Result;
	}

	template <typename T>
	void LinkedList<T>::PushBack(T Data)
	{
		_Node NewNode = CreateNode(Data);

		if (head == nullptr)
		{
			head = NewNode;
			tail = NewNode;
		}
		else
		{
			tail->Next = NewNode;
			tail = NewNode;
		}
	}

	template <typename T>
	void LinkedList<T>::PushFront(T Data)
	{
		_Node NewNode = CreateNode(Data);

		if (head == nullptr)
		{
			head = NewNode;
			tail = NewNode;
		}
		else
		{
			NewNode->Next = head;
			head = NewNode;
		}
	}

	template <typename T>
	void LinkedList<T>::Remove(int index)
	{
		if (index > 0)
		{
			_Node Previous = GetNode(index - 1);
			_Node Condemned = Previous->Next;
			Previous->Next = Condemned->Next;
		}
		else
		{
			head = head->Next;
		}
	}

	template <typename T>
	void LinkedList<T>::Remove(_Node TargetNode)
	{
		Remove(FindNodePosition(TargetNode));
	}

	template <typename T>
	void LinkedList<T>::Clear()
	{
		_Node Current = head;
		while (Current != nullptr)
		{
			_Node Previous = Current;
			Current = Current->Next;
			Previous->Next = nullptr;
		}

		head = nullptr;
		tail = nullptr;
	}

	template <typename T>
	_Node LinkedList<T>::Head() const
	{
		return head;
	}

	template <typename T>
	_Node LinkedList<T>::Tail() const
	{
		return tail;
	}

	template <typename T>
	_Node LinkedList<T>::CreateNode(T data)
	{
		_Node NewNode = _Node(new Node<T>(data));

		return NewNode;
	}
}