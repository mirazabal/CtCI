#include <memory>

using namespace std;

template<typename T>
class Stack{
	class Node{
		public:
		Node(T val ): t{val}, next{nullptr} {};
		unique_ptr<Node> next;
		T t;

	};


	unique_ptr<Node> root;
	unique_ptr<Node> minroot;


	void push_min_stack(T t){
	
		if(minroot ==  nullptr){
			minroot = make_unique<Node>(t);
			return;
		}


		if(t <= minroot->t){
			unique_ptr<Node> temp = make_unique<Node>(t);
			temp->next = std::move(minroot);
			minroot = std::move(temp);
		}
	}

	public:
	void push(T&& t){
		push_min_stack(t);
		
		unique_ptr<Node> temp = make_unique<Node>(t);
		temp->next = std::move(root);
		root = std::move(temp);
	}

	T& min(){
		return minroot->t;
	}

	void pop(){
		if(root->t == minroot->t)
			minroot = std::move(minroot->next);
		
		root = std::move(root->next);
	}

};





int main(){

	Stack<size_t> ss;

	ss.push(12);
	ss.push(10);
	ss.push(25);
	ss.push(50);

	auto a = ss.min();

	ss.pop();
	ss.pop();
	auto b = ss.min();
	ss.pop();
	auto c = ss.min();
	return 0;
}
