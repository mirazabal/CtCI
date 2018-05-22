#include <iostream>
#include <stack>
#include <string>
#include <map>
#include <vector>

struct node{

	node(std::string name, size_t val ) : val_{std::move(val)}, name_{std::move(name)}, visited_{false} 
	{
	
	}

	std::size_t val_;
	std::string name_;
	bool visited_;
	std::vector<node*> nexts_;
};

std::map<std::string, node> createGraph( std::vector< std::pair<std::string, size_t > > const & vecName )
{
	std::map<std::string, node> retVal;
	for(auto const& pair_ : vecName ){
		retVal.insert(std::make_pair(pair_.first, node(pair_.first, pair_.second) ) );
	}

	return retVal;
}	

void addEdge(std::vector<std::pair<std::string, std::string > > const & vecSin , std::map<std::string, node>& graph ){
	
	for(auto const& pair_ : vecSin ){
		auto it1 = graph.find( pair_.first );
		auto it2 = graph.find( pair_.second);
		it1->second.nexts_.emplace_back( &( it2->second ) );
		it2->second.nexts_.emplace_back( &( it1->second ) );
	}
}

size_t DFS(node* n)
{
	size_t retVal {0};
	n->visited_ = true;
	for( auto next : n->nexts_ ){
		if(  next->visited_ == false ) 
			retVal += DFS(next);
	}

	return n->val_ + retVal;
}

std::map<std::string, size_t> getRealNames( std::map<std::string, node> & graph)
{
	std::map<std::string, size_t> retVal;

	for( auto& pair_ : graph ){
		if( pair_.second.visited_ ==  false){
			auto numberRealNames = DFS(&(pair_.second));
			retVal.insert( std::make_pair(pair_.first, numberRealNames) );
		}
	}
	return retVal;
}

int main()
{
	std::vector< std::pair<std::string, size_t > > vecNames = { { "John", 15 }, {"Jon", 12 }, { "Chris", 13}, { "Kris", 4}, { "Christopher", 19}  };
	std::vector< std::pair<std::string, std::string > > vecSin = { { "Jon", "John"  },{ "John", "Johnny" }, { "Chris", "Kris" } , { "Chris", "Christopher" }   };

	auto graph = createGraph(vecNames );
  addEdge( vecSin, graph );	

	std::map<std::string, size_t> realNames = getRealNames(graph);

	for(auto const& pair_ : realNames ){
		std::cout << "Name = " << pair_.first << " number = " << pair_.second << '\n'; 
	}
	return 0;
}
