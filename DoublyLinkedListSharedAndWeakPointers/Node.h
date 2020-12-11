#pragma once
#include<string>
#include<array>
#include<iostream>
#include<memory>

 template <typename T>
class Node
{
public:
	std::shared_ptr<Node<T>> Next{};
	std::weak_ptr<Node<T>> Previous{};
	T Value{};

	Node(T Value) : Value(Value)
	{
	}


};

