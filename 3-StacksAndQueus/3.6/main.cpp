
class Cat {

};

class Dog {

};



class CatAndDogs {


	class Node{

		public:

		Node()
		{
		
		};

		Node* next;
		Node* previous;
	};

	Node* first;
	Node* last;


	CatAndDogs(){
	
	};

	void enqueue(Cat const& c){
	
	}

	void enqueue(Dog const& d){
	
	}


	void dequeany() {
	
	}

	Cat dequeCat() {
	
	}

	Dog dequeDog() {
	
	}


};




int main()
{
	CatAndDogs catDogs;

	catDogs.enqueue(Cat());
	catDogs.enqueue(Dog());

	return 0;
}
