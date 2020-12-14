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
		while(true)
		{
			if (current->Value == targetValue)
			{
				return current;
			}
			if (current->Next)
			{
				current = current->Next;
			}
			else
			{
				return nullptr;
			}
		}
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

	void AddAfter(T nodeValue, T addValue)
	{
		std::shared_ptr<Node<T>> targetNode = Search(nodeValue);
		if (!targetNode)
		{
			return;
		}
		if (!Head)
		{
			AddFirst(addValue);
		}
		else if (targetNode == Tail)
		{
			AddLast(addValue);
		}
		else
		{
			std::shared_ptr<Node<T>> temp = std::move(targetNode->Next);
			targetNode->Next = std::make_shared<Node<T>>(addValue);
			targetNode->Next->Previous = targetNode;
			targetNode->Next->Next = temp;
			temp->Previous = targetNode->Next;
			count++;
		}
	}

	void AddBefore(T nodeValue, T addValue)
	{
		std::shared_ptr<Node<T>> targetNode = Search(nodeValue);
		if (!targetNode)
		{
			return;
		}
		if (!Head || targetNode == Head)
		{
			AddFirst(addValue);
		}
		else
		{
			AddAfter(targetNode->Previous.lock()->Value, addValue);
		}
	}

	bool Remove(T removeValue)
	{
		std::shared_ptr<Node<T>> targetNode = Search(removeValue);
		if (!targetNode)
		{
			return false;
		}
		if (targetNode == Head) 
		{

		}
		else if (targetNode == Tail)
		{

		}
		else
		{
			targetNode->Previous.lock()->Next = targetNode->Next;
			targetNode->Next->Previous = targetNode->Previous.lock();
		}


		count--;
		return true;
	}
};

