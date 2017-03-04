#include <memory>
#include <iostream> 

using namespace std;

class Node{

	public:
	Node(size_t data) : left(nullptr), rigth(nullptr) , data_{data} , number_{0}
	{
	
	}

	unique_ptr<Node> left;
	unique_ptr<Node> rigth;
	size_t number_;
	size_t data_;
};

class BST{
	public:
	BST() : root{nullptr}
	{
	
	}
	
	void add(size_t data){
		if(root == nullptr){
			root= make_unique<Node>(data);
			return;
		}

		Node* pre = root.get();
		Node* next = root.get();

		while( next != nullptr){
			pre = next;
			if(data <= next->data){
				next->number_++;	
				next = next->left.get();
			}
			else
				next = next->rigth.get();
		}



	}

	private:
	unique_ptr<Node> root;


};

void rank(size_t )
{
	static BST;


}

int getRankOfNumber(size_t number){


}



int main()
{
	cout << sizeof(Node) << '\n';
	return 0;
}
