#include <memory>

using namespace std;

class Node{
	public:
		Node( size_t v) : next{nullptr}, val{v}{};

		unique_ptr<Node> next;
		size_t val;
};



class LinkedList{
	public:
		LinkedList(): root{nullptr}
		{
		
		};

		unique_ptr<Node> root;

		void addVal(size_t val){
		
			if(root == nullptr){
				root = make_unique<Node>(val);
				return;
			}
		
			Node* n = root.get();
			while(n->next != nullptr){
				n = n->next.get();
			}

			n->next = make_unique<Node>(val);
		}

};


Node* checkCycle(LinkedList const& l1){

	Node* fastIt = l1.root.get();
	Node* slowIt = l1.root.get();


	while( fastIt != slowIt  ){

		if(fastIt->next->next == nullptr)
			return nullptr;

		slowIt = slowIt->next.get();
		fastIt = fastIt->next->next.get();
	}


	slowIt = l1.root.get();

	while( fastIt != slowIt){
		slowIt = slowIt->next.get();
		fastIt = fastIt->next.get();
	}

	return fastIt;
};



int main()
{



	return 0;
}
