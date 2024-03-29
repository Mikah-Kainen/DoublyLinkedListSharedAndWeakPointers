#include<string>
#include<array>
#include<iostream>
#include<memory>
#include"Node.h"
#include"LinkedList.h"

int main()
{
	LinkedList<int> list = LinkedList<int>();

	list.AddFirst(25);
	list.AddLast(27);
	;
	list.AddFirst(24);
	list.AddLast(29);
	;
	std::shared_ptr<Node<int>> result1 = list.Search(27);
	std::shared_ptr<Node<int>> test = list.Search(100);
	;
	int otherThing = list.Search(27)->Next->Previous.lock()->Previous.lock()->Value;
	list.AddBefore(27, 26);
	;
	otherThing = list.Search(27)->Next->Previous.lock()->Previous.lock()->Value;
	list.AddBefore(29, 28);
	list.AddBefore(24, 23);
	list.AddAfter(29, 30);
	list.AddAfter(1234, 123);

	bool result11 = list.Remove(23);
	bool result2 = list.Remove(28);
	bool result3 = list.Remove(30);
	bool result4 = list.Remove(321);

	for (size_t i = 0; i < 5000; i++)
	{
		list.AddLast(i);
	}

	return 0;
}