#include <memory>

using namespace std;

class Node
{
	public:
		Node(int d) : data_(d), next(nullptr), previous(nullptr)
		{

		};
	
		shared_ptr<Node> next;
		Node* previous;

		int data_;
};

class LinkedList
{
	public:
		LinkedList()
		{

		};
		
		void addNode(int data)
		{
			if(root == nullptr)
				root = make_shared<Node>(data);
			else{
			
				Node* n = root.get();
				while(n->next != nullptr)
					n = n->next.get();

				n->next = make_shared<Node>(data);
				n->next->previous = n;
			}
		};

		Node* partition(int data)
		{
			if(root == nullptr)
				return nullptr;

			shared_ptr<Node> it2 = root;
			while(it2->data_ < data ){
					if(it2 == nullptr)
						return nullptr;
					it2 = it2->next;
				}

			shared_ptr<Node> it = it2->next;
			
			while(it != nullptr){
				if(it->data_ < data){
					
					shared_ptr<Node> temp = make_shared<Node>(-1);
					temp->next = it->next;
					temp->previous = it->previous;	
				
					shared_ptr<Node> temp2 = make_shared<Node>(-1);
					temp2->next = it2->next;
					temp2->previous = it2->previous;

					it->next->previous = temp2.get();
					it->previous->next = temp2;

					it2->previous->next = temp;
					it2->next->previous = temp.get();


					it->next = temp2->next;
					it->previous = temp2->previous;

					it2->next = temp->next;
					it2->previous = temp->previous;

					it = it2;
				}	

				it = it->next;
			}
					
			return it2.get();
		};

	shared_ptr<Node> root;
};



int main()
{
	LinkedList l;
	
	l.addNode(1);
	l.addNode(8);
	l.addNode(7);
	l.addNode(2);
	l.addNode(5);
	l.addNode(9);


	l.partition(5);
	
	
	
	return 0;

};
