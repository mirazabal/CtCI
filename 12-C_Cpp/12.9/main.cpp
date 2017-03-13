#include <atomic>
#include <iostream>
#include <thread>

//static std::atomic<int> refCount = 0;

template<class T>
class Shared_ptr{
	public:
	Shared_ptr()
	{
		val = new T();
		refCount = new size_t();
		*refCount = 1;
	}

	~Shared_ptr( )
	{
		if(*refCount == 1){
			delete val;
			delete refCount;
		}
		*refCount--;
	}

	Shared_ptr( Shared_ptr<T>& other){
		if(this == &other)
			return;
	
		this->refCount = other.refCount;
		this->val = other.val;

		*this->refCount += 1; //(*this->refCount)++;
	}

	Shared_ptr<T>& operator=(Shared_ptr<T>& other){
		if(*this == other)
			return *this;

		this->refCount = other.refCount;
		this->val = other.val;
		
		*this->refCount += 1; //(*this->refCount)++;
	}

	T* get()
	{
		return val;
	}

	size_t* refCount;

	private:
	T* val;
};




int main()
{
	Shared_ptr<int> sp;
	*sp.get() = 100 ;
	

	auto b = sp;
	auto c = b;
	std::cout << *c.refCount << std::endl;
	auto d{b};
	std::cout << *d.refCount << std::endl;

	return 0;
}
