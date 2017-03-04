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


class S
{
    public:
        static S& getInstance_S()
        {
            static S    instance; // Guaranteed to be destroyed.
                                  // Instantiated on first use.
            return instance;
        }
    private:
        S() {}                    // Constructor? (the {} brackets) are needed here.

         // C++ 11
        // =======
        // We can use the better technique of deleting the methods
        // we don't want.
    public:
        S(S const&)               = delete;
        void operator=(S const&)  = delete;

        // Note: Scott Meyers mentions in his Effective Modern
        //       C++ book, that deleted functions should generally
        //       be public as it results in better error messages
        //       due to the compilers behavior to check accessibility
        //       before deleted status
};


class BST{
	public:

	static BST& getInstance(){
		static BST b;
		return b;
	}


	BST(BST const&) = delete;
	void operator=(BST const&) = delete;
	
	void add(size_t data){
		if(root == nullptr){
			root= make_unique<Node>(data);
			return;
		}

		Node* next = root.get();

		while( true ){
			if(data <= next->data_){
				next->number_++;	
				if(next->left != nullptr)
					next = next->left.get();
				else {
					next->left = make_unique<Node>(data);
					break;
				}
			}
			else{
				if(next->rigth != nullptr)
					next = next->rigth.get();
				else {
					next->rigth = make_unique<Node>(data);
					break;
				}

			}
		}
	}


	int getRankOfNumber(size_t data){
		
		if(root == nullptr)
			return -1;

		Node* n = root.get();

		size_t accVal{0};
		for(;;){
		
			if(data == n->data_)
				return n->number_ + accVal;
			
			if(data < n->data_){
				
				if(n->left == nullptr)
					return -1;
				
				n = n->left.get();

			} else {
				
				if(n->rigth == nullptr)
					return -1;
				
				accVal += n->number_ + 1;
				n = n->rigth.get();
			}
		}

	}

	private:
	BST() : root{nullptr}
	{	

	}
	unique_ptr<Node> root;

};

void rank_(size_t data)
{
	auto& b = BST::getInstance();
	b.add(data);
}

int getRankOfNumber(size_t data){
		
	auto& b = BST::getInstance();
	return b.getRankOfNumber(data);
}

int main()
{
	for(size_t i = 0; i < 10000 ; i++){
		for(size_t j = 0; j < 3; j++)
			rank_(i);
	}

   	cout << getRankOfNumber(100) << '\n';
	
	return 0;
}
