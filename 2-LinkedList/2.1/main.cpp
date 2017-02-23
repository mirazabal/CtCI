#include <memory>

class Node
{
	public:
	explicit Node(int d) : data(d)
		{
			next = nullptr;
			previous = nullptr;
		};
		std::unique_ptr<Node> next;
		Node* previous;
		int data;

};

class LinkedList
{
	public:
		LinkedList()
		{
			root = nullptr;	
		};
		void removeDuplicates()
		{
			// without extra space
			if(root == nullptr)
				return;		
			
			for(Node* n = root.get(); n != nullptr; n = n->next.get() ){
				for(Node* m = n->next.get(); m != nullptr; m = m->next.get() ){
					if(n->data == m->data){
						Node* nextNode = m->next.get();
						if(nextNode != nullptr)
							m->next->previous = m->previous;				
						m->previous->next = std::move(m->next);
						m = m->previous; 
					}
				}
			}
				

		};
		void addNode(int data)
		{
			if(root == nullptr){
				root = std::make_unique<Node>(data);
			}else{
				Node* n = root.get();
				while(n->next != nullptr){
					n = n->next.get();
				}
				std::unique_ptr<Node> nextNode = std::make_unique<Node>(data);
				nextNode->previous = n;
				n->next = std::move(nextNode);
			}
		};

	private:
		std::unique_ptr<Node> root;
};


int main()
{
	LinkedList l;
	l.addNode(0);
	l.addNode(1);
	l.addNode(0);
	l.addNode(50);
	l.removeDuplicates();


	return 0;
};

