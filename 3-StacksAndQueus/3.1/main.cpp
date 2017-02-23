#include <memory>

using namespace std;

template<typename T>
class Stack{
	
	class Node{
		public:
			Node(T t) : val{t}, next{nullptr}{};
		T val;
		unique_ptr<Node> next;
	};

public:
		void push(T item){
			if(root == nullptr){
				root = make_unique<Node>(item);
				return;
			}
			unique_ptr<Node> temp  = make_unique<Node>(item);
			temp->next = std::move(root);
			root = std::move(temp);
		};
		void pop()
		{
			root = std::move(root->next);
		}

		T& peek()
		{
			return root->val;			
		}

		bool empty()
		{
			return root == nullptr;
		};

	private:

	unique_ptr<Node> root;

};

int main(){

	Stack<size_t> ss;
	ss.push(5);
	ss.push(10);

	auto a = ss.peek();
	ss.pop();
	auto b = ss.peek();

	return 0;
}
