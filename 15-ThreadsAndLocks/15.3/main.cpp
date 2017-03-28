#include <chrono>
#include <iostream>
#include <memory>
#include <mutex>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <thread>
#include <time.h>       /* time */
#include <vector>

using namespace std;

class ChopStick{

	public:
		ChopStick(size_t num): num_{num}
		{
		}

		bool getChopStick(){
			return m.try_lock();
		}
	
		void releaseChopStick()
		{
			m.unlock();
		}

		size_t num_;
	private:
		mutex m;
};

class Philosopher{
	public:

		Philosopher(size_t num) : philNumber{num}
		{
		}
		
		void eat( unique_ptr<ChopStick>& l, unique_ptr<ChopStick>& r){
			cout << " into eat from Philosopher =  " << philNumber  << "left chopstick = " << l->num_ << "rigth chopstick = " << r->num_<< endl;
			
			while(true){	
				
				if( tryGetChopStick(l) && tryGetChopStick(r)){
					cout << " philosopher " << philNumber << " ate " << endl;
					l->releaseChopStick();
					r->releaseChopStick();
					break;
				}
			}
		}

		bool tryGetChopStick( unique_ptr<ChopStick>& c){	

			for(int i = 0; i < 100; ++i){
				srand(time(NULL));
				int val = rand() % 1000;
				this_thread::sleep_for(chrono::milliseconds(10*val) );
				if(c->getChopStick())
					return true;	
			}
			return false;
		}

	private:
		size_t philNumber;
};

vector< unique_ptr<ChopStick> > cSticks;

int main()
{
	vector<Philosopher> p;
	vector<thread> vThreads;

	size_t numThreads = 5;

	for(size_t i = 0; i < numThreads; ++i){
		unique_ptr<ChopStick> uP = make_unique<ChopStick>(i);
		cSticks.emplace_back( move(uP) );
		p.emplace_back(Philosopher(i));
	}

	for(size_t i = 0; i < numThreads; ++i){
		if(i == numThreads-1)
			vThreads.push_back( std::thread( [&](){ 
					   int a = i;
				   	   p[a].eat(cSticks[a], cSticks[0]); } ) );
		else 
			vThreads.push_back( std::thread( [&](){ 
						int a = i;
						p[a].eat(cSticks[a], cSticks[a+1]); } )  );
	}

	cout << "Threads init" << endl;

	this_thread::sleep_for(chrono::milliseconds(1000000));
	cout << "After sleeping "<< endl;

	for(auto& t: vThreads)
		t.join();
	
	return 0;
}
