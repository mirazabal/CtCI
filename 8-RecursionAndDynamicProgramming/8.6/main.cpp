#include <stdio.h>
#include <stack>

class Tower
{
	public:
	
	int& top()
	{
		return s.top();
	}

	void pop()
	{
		s.pop();
	}

	void push(int i)
	{
		s.push(i);
	}

	private:
	std::stack<int> s;	

};




void moveFromTop( Tower&  origin, Tower& destination)
{
	auto disk = origin.top();
	origin.pop();
	destination.push(disk);
}


void moveDisks(size_t n, Tower& origin, Tower& destination, Tower& buffer)
{
	if(n == 0) return;

	moveDisks( n-1, origin, buffer, destination);
	moveFromTop( origin, destination);
	moveDisks( n-1, buffer, destination, buffer);

}



int main()
{
	return 0;
}
