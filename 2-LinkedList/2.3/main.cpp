#include <iostream>
#include <memory>
#include <string>


using namespace std;

class Node
{
	public:
	Node(int data) : data_(data), next(nullptr), previous(nullptr)
	{
	
	};

	unique_ptr<Node> next;
	Node* previous;

	int data_;
};

class LinkedList
{
	public:
	LinkedList(): root(nullptr)
	{
	
	};

	void addNode(int data)
	{
		if(root == nullptr)
			root = make_unique<Node>(data);
		else{
			Node* n = root.get();
			while(n->next != nullptr){
				n = n->next.get();
			}

			n->next = make_unique<Node>(data);
			n->next->previous = n;
		}
	};

	void deleteNode(int data){
		
		if(root == nullptr)
			return;
		
		Node* n = root.get();
		while(n->data_ != data){
			if(n->next == nullptr)
				return;

			n = n->next.get();
		}

		if(n->next != nullptr){
			n->next->previous = n->previous;
			n->previous->next = std::move(n->next);
		}else{
			n->previous->next = nullptr;
		}

	};

	string printList()
	{
		string s;
		Node* n = root.get();
		while(n != nullptr){
			s = s + to_string(n->data_) + " ";
			n = n->next.get();
		}
		return s;
	};

	unique_ptr<Node> root;

};



int main()
{
	LinkedList l;
	l.addNode(23);
	l.addNode(46);
	l.addNode(50);
	l.addNode(55);
	l.addNode(500);	
	l.deleteNode(50);
	l.deleteNode(55);
	

	cout << l.printList() << endl;
	
	return 0;
};



