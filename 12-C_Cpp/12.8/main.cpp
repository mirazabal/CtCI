#include <iostream>
#include <set>

struct Node{
	Node(int v) : val_{v}, n1{nullptr}, n2{nullptr}
	{

	}
	int val_;

	Node* n1;
	Node* n2;
};


Node* copyStructure(Node* oldSturcture, std::set<Node*>& s)
{
	auto it = s.find(oldSturcture);
	if(it != s.end())
		return *it;

	s.insert(oldSturcture);

	Node* newStructure = new Node(oldSturcture->val_);
	if(oldSturcture->n1 != nullptr){
		newStructure->n1 = copyStructure(oldSturcture->n1, s);			
	}
	if(oldSturcture->n2 != nullptr){
		newStructure->n2 = copyStructure(oldSturcture->n2, s);
	}

	return newStructure;
}

Node* copyStructure(Node* n)
{
	if(n == nullptr)
		return nullptr;

	std::set<Node*> s;
	return copyStructure(n,s);
}



int main()
{
	Node n11(1);
	Node n12(2);
	Node n13(3);
	Node n14(4);
	Node n15(5);
	Node n16(6);
	Node n17(7);
	Node n18(18);


	n11.n1 = &n12;
	n11.n2 = &n13;

	n12.n1 = &n14;
	n12.n2 = &n15;

	n13.n1 = &n16;
	n13.n2 = &n17;

	n14.n1 = &n18;


	auto retVal = copyStructure(&n11);

	std::cout << retVal->n2->n1->val_ << std::endl;	

	return 0;
}
