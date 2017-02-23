#include <memory>
#include <stack>


using namespace std;

class Node{

	public:
		Node(size_t value) : val(value), next(nullptr){}

	size_t val;
	unique_ptr<Node> next;

};

class LinkedList{
	
	public:
		LinkedList( ): root(nullptr) {};
		unique_ptr<Node> root;
		void addVal(size_t val){
			if(root == nullptr){
				root = make_unique<Node>(val);
			}

			Node* n = root.get();
			while( n->next != nullptr){
				n = n->next.get();
			}

			n->next = make_unique<Node>(val);
		}
};




bool isPalindrome(LinkedList const& l1)
{
	Node* fast = l1.root.get();
	Node* slow = l1.root.get();
	stack<size_t> s;


	while( fast->next != nullptr && fast->next->next != nullptr){
		s.push(slow->val);
		slow = slow->next.get();
		fast = fast->next->next.get();
	}

	if( fast->next == nullptr){
		s.pop();
	}

	while(s.size() != 0){
		slow = slow->next.get();
		if(s.top() != slow->val)
			return false;

		s.pop();
	}

	return true;
}




int main()
{

	return 0;
}





