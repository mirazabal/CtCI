#include <iostream>

class Node
{
	public:
	Node(int i) : i_{i}, next{nullptr}
	{

	}

	int i_;
	Node* next;
};

Node* reverseLinkedList(Node* first)
{
	if(first->next == nullptr)
		return first;

	Node* n = first;
	Node* n2 = first->next;
	Node* n3 = first->next->next;

	n->next = nullptr;

	while(n3 != nullptr){
		n2->next = n;
		n = n2;
		n2 = n3;
		n3 = n3->next;
	}

	n2->next = n;
	return n2;
}

int main()
{
	Node n1(1);
	Node n2(2);
	Node n3(3);
	Node n4(4);

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;

	auto retNode = reverseLinkedList(&n1);

	while( retNode != nullptr){
		std::cout << retNode->i_ << std::endl;
		retNode = retNode->next;
	}


	std::cout << sizeof(sensor) << std::endl;

}
