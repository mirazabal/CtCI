#include <memory>

using namespace std;

class Node
{
	public:
		Node(int d) : data_(d) , next(nullptr), previous(nullptr)
		{
	
		};
	int data_;
	unique_ptr<Node> next;
	Node* previous;
};

class LinkedList
{
	public:
		LinkedList() : root(nullptr)
		{
		
		};

	void addNode(int data)
	{
		if(root == nullptr)
			root = make_unique<Node>(data);
		else{
			Node* n = root.get();
			while(n->next != nullptr)
				n = n->next.get();

			n->next = make_unique<Node>(data);
			n->next->previous = n;
		}
	};


	void nthToK(int k) // 2 iterators trick
	{
		if(root == nullptr)
			return;
		
		int nodeNumber{1};
		Node* n = root.get();
		Node* n2 = root.get();
		
		while(nodeNumber != k){
			if(n->next == nullptr)
				return;
			n = n->next.get();
			nodeNumber++;
		}

		while(n->next != nullptr){
				n = n->next.get();
				n2 = n2->next.get();
		}

		// print k2 values???

	};


	Node* nthToK_2(int k,int& i, Node* n)
	{
		if(n == nullptr)
			return nullptr;

		auto val = nthToK_2(k,i,n->next.get());
		if(val == nullptr){
			i++;
			if(i == k)
				return n;
			else
				return nullptr;
		
		}else
			return val;
	};

	void nthToK_2(int k)
	{
		int i = 0;
		Node* n = root.get();
		if(n == nullptr)
			return;
		auto a = nthToK_2(k,i,n);
	};

	unique_ptr<Node> root;

};



int main()
{

	LinkedList l;
	l.addNode(0);
	l.addNode(56);
	l.addNode(156);

	l.nthToK(2);
	return 0;
};

