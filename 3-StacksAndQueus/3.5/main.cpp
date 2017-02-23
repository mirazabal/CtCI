#include <array>

template<typename T, typename length>
class min_heap{
	
	array<T,length> arr;
	size_t size_;


	void swap(size_t pos1, size_t pos2)
	{
		T temp = arr[pos1];
		arr[pos1] = arr[pos2];
		arr[pos2] = temp;
	}

	void heapyfy(size_t pos)
	{
		if(arr[pos] < arr[(pos+1)/2]){
			swap(pos,(pos+1)/2);
			heapyfy(pos);
		}
	}

	void heapify_down(size_t pos)
	{

		auto left = arr[(pos+1)*2-1 ];
		auto right = arr[(pos+1)*2];
		size_t smallest = pos;
		if( arr[left] < arr[pos]])
			smallest = left;

		if(arr[right] < arr[smallest])
			smallest = right;

		if( smallest != pos){
			swap(smalles,pos);
			heapify_down(smallest);
		}
	}

	public:
	
	min_heap(): size_(0)
	{
	
	}
	
	void push(T const& t)
	{
		arr[size_] = t;
		heapyfy(size_);	
		size_++;
	}

	T pop()
	{
		if(size_ == 0)
			throw;

		T temp = arr[0];
		heapify_down(0);
		size_--;
		return temp;
	}
	
};




template< typename T>
class Stack{






};


int main()
{
	return 0;
}
