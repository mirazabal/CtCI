// implement queue with 2 stacks
//
//
#include <exception>

template<typename T>
class Stack{

	struct Node{

		Node* next;
		Node(T val) : t{val}, next{nullptr}{} 

		T t;
	};


	Node* root;


	public:
	Stack() : root{nullptr}
	{

	};

	~Stack()
	{
		while(root != nullptr){
			Node* temp = root;
			root = root->next;
			delete temp;
		}
	}


	void push(T t)
	{
		Node* temp = new Node(t);
		temp->next = root;
		root = temp;
	}
	bool isEmpty()
	{
		return root == nullptr;
	}


	T pop()
	{
		if(root == nullptr){
			throw;
		}

		Node* temp = root;
		root = root->next; 

		T retVal = temp->t;
		delete temp;
		return retVal;
	}


};



template<typename T>
class MyQueue{


	Stack<T> s1;
	Stack<T> s2;
	bool s1OrS2;

	public:
	MyQueue() : s1OrS2(true)
	{
	
	}

	void enqueue(T t)
	{
		if(!s1OrS2){
			while(!s2.isEmpty()){
				s1.push(s2.pop());
			}
			s1OrS2 = true;
		}
		s1.push(t);
	}


	T deque()
	{
		if(s1OrS2){
			while(!s1.isEmpty() ){
			s2.push(s1.pop());
			}
			s1OrS2 = false;
		}
		s2.pop();
	}




};




int main()
{

	MyQueue<int> m;

	m.enqueue(122);
	m.enqueue(123);
	m.enqueue(124);
	m.enqueue(125);


	for(int i = 0; i < 2; i++){
		auto val = m.deque();
	
	}


	return 0;
};
