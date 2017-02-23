#include <array>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

template<typename T>
class Stack{
	class Node{
		Node(T val ): t{val}, next{nullptr} {};
		unique_ptr<Node> next;
		T t;
	};

	
	size_t size_;
	size_t capacity;

	vector<array<T, 5>> vecStacks;

	void growVector(){
		vecStacks.emplace_back(array<T,5>());
		capacity += 5;
	}

	public:
		Stack() : size_{0}
	   	{
			vecStacks.emplace_back(array<T,5>());
			capacity = 5;
		
		}
		size_t size()
		{
			return size_;
		}

		void push(T t){
			if(size_ == capacity)
				growVector();		
			
			vecStacks[ size_/5 ][ size_%5] = t;
			size_++;

		}

		T pop(){
			if(size_ == 0)
				throw std::runtime_error("size is null");

			T retVal = vecStacks[size_-1 /5][size_%5];
			size_--;
			return retVal;
		}

		T& valAt(size_t pos){
			if(pos > size_ || pos < 0)
				throw std::runtime_error("bound exceeded");
			return vecStacks[pos/5][pos%5];
		}
};







int main()
{
	Stack<size_t> ss;

	for(int i = 0; i < 100; i ++){
		ss.push(i+10);
	}


	
	
	auto a = ss.size();

	for(int i = 0; i < 10; ++i){
		auto val = ss.pop();
		std::cout << val << std::endl;
	}



	


};
