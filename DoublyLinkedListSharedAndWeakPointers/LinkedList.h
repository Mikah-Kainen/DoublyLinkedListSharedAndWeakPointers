#pragma once
#include<string>
#include<array>
#include<iostream>
#include<memory>
#include"Node.h"

 template <typename T>
class LinkedList
{
private:

public:
	std::shared_ptr<Node<T>> Head{};
	std::shared_ptr<Node<T>> Tail{};
	int count{};

	LinkedList()
	{
	}

	std::shared_ptr<Node<T>> Search(T targetValue)
	{
		std::shared_ptr<Node<T>> current = Head;
		for (size_t i = 0; i < count; i ++)
		{
			if (current->Value == targetValue)
			{
				return current;
			}
			current = current->Next;
		}
		return nullptr;
	}

	void AddFirst(T value)
	{
		if (!Head)
		{
			Head = std::make_shared<Node<T>>(value);
			Tail = Head;
		}
		else
		{
			std::shared_ptr<Node<T>> temp = std::move(Head);
			Head = std::make_shared<Node<T>>(value);
			Head->Next = temp;
			temp->Previous = Head;
		}
		count++;
	}

	void AddLast(T value)
	{
		if (!Head)
		{
			AddFirst(value);
		}
		else
		{
			std::shared_ptr<Node<T>> newTail = std::make_shared<Node<T>>(value);
			Tail->Next = newTail;
			newTail->Previous = Tail;
			Tail = newTail;
			count++;
		}
	}

	void AddBefore(std::shared_ptr<Node<T>> targetNode, T targetValue)
	{
		if (!Head)
		{
			AddFirst(targetValue);
		}
		else if (targetNode == Tail)
		{
			AddLast(targetValue);
		}
		else
		{
			std::shared_ptr<Node<T>> temp = std::move(targetNode->Next);
			targetNode->Next = std::make_shared<Node<T>>(targetValue);
			targetNode->Next->Previous = targetNode;
			targetNode->Next->Next = temp;
			temp->Previous = targetNode.Next;
			count++;
		}
	}

	void AddAfter(std::shared_ptr<Node<T>> targetNode, T targetValue)
	{
		if (!Head || targetNode == Head)
		{
			AddFirst(targetNode);
		}
		else
		{
			AddBefore(targetNode.Previous.lock(), targetValue);
		}
	}

	bool Remove()
	{
		
	}
};

