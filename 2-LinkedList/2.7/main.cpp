#include <cstdint>
#include <map>
#include <memory>
#include <utility>


using namespace std;

class Node{
	public:
		Node(size_t v) : val{v}, next{nullptr} {};
	size_t val;
	unique_ptr<Node> next;
};


class LinkedList{
	public:
		LinkedList(){};
		unique_ptr<Node> root;
		
		void addVal(size_t val){
		
			if(root == nullptr){
				root = make_unique<Node>(val);
				return;
			}


			Node* n = root.get();
			while(n->next != nullptr ){
				n = n->next.get();
			}
			n->next = make_unique<Node>(val);
		};

};




Node* intersectsLinkedLists( LinkedList const& l1, LinkedList const& l2){
	
	std::map< uintptr_t , size_t> m1;

	size_t pos{0};
	Node* n = l1.root.get();
	while( n != nullptr){
		uintptr_t add = reinterpret_cast<uintptr_t>(n);		
		m1.emplace( std::make_pair( add , pos) );
		
		pos++;

		n = n->next.get();
	}

	
	n = l2.root.get();
	while( n != nullptr){
		
		uintptr_t add = reinterpret_cast<uintptr_t>(n);
		auto it = m1.find(add);

		if( it != m1.end() )
			break;

		n = n->next.get();
	}

	
	return n;
};


int main(){

	LinkedList l1;
	l1.addVal(2);
	l1.addVal(23);

	LinkedList l2;
	l2.addVal(2);
	l2.addVal(6);



	auto ret = intersectsLinkedLists(l1,l2);




	return 0;
}
