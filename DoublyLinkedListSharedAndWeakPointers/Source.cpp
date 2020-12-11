#include<string>
#include<array>
#include<iostream>
#include<memory>
#include"Node.h"
#include"LinkedList.h"

int main()
{
	LinkedList<int> list = LinkedList<int>();

	list.AddFirst(26);
	list.AddLast(27);
	;
	list.AddFirst(25);
	list.AddLast(28);
	;
	std::shared_ptr<Node<int>> result1 = list.Search(27);

	;

	return 0;
}