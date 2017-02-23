#include <memory>

using namespace std;

class Node{
	public:	

	Node(unsigned val) : value(val) { };
	unsigned value;
	unique_ptr<Node> next;

};


class LinkedList{

	public:
	unique_ptr<Node> root;
	LinkedList() : root(nullptr), size{0} {};
	unsigned size;

	void addVal(unsigned val)
	{
		size++;
		if(root == nullptr){
			root = make_unique<Node>(val);
			return;
		}

		Node* n = root.get();
		while( n->next != nullptr )
			n = n->next.get();

		n->next = make_unique<Node>(val);
	}

};


void recursiveSum(Node* n1, Node* n2, LinkedList& result, unsigned addOver ){

	if( n1 == nullptr && n2 == nullptr && addOver == 0)
		return;

	unsigned val1{0};
	Node* temp1 = nullptr;
	if(n1 != nullptr){
		val1 = n1->value;
		temp1 = n1->next.get();
	}

	unsigned val2{0};
	Node* temp2{nullptr};
	if(n2 != nullptr){
		val2 = n2->value;
		temp2 = n2->next.get();
	}

	unsigned sum = val1 + val2 + addOver;
	result.addVal(sum % 10);
	unsigned addOverflow = sum < 9 ? 0 : 1;
	recursiveSum( temp1, temp2, result, addOverflow);
};



LinkedList sumLinkedLists(LinkedList const& l1, LinkedList const& l2)
{
	LinkedList result;
	recursiveSum(l1.root.get(), l2.root.get(), result, 0);
	return result;	
	
};


LinkedList sumLinkedListBackwards( LinkedList const& l1, LinkedList const& l2){

	LinkedList retList;


	return retList;
};





int main()
{
	LinkedList l1;
	l1.addVal(5);
	l1.addVal(3);
	l1.addVal(0);

	LinkedList l2;

	l2.addVal(2);
	l2.addVal(3);
	l2.addVal(0);

	auto val = sumLinkedLists(l1, l2);

	return 0;
}
