#include <queue>
#include <string>
#include <vector>

class Node{
	public:
		Node(std::string const& str) : name{str} , visited{false} {

		};
		bool visited;
		std::vector<Node*> adj;
		std::string name;

		bool operator==(Node const&n){
			return this == &n;
		}
};

class Graph{

	std::vector<Node> vNodes;

	public:
	Graph()
	{

	}

	void addNode(Node const& n){
		vNodes.emplace_back(n);
	}

	bool routeBetweenNodes(Node& n1, Node& n2)
	{
		if(n1 == n2)
			return true;

		std::queue<Node*> q;

		q.push(&n1);
		while( !q.empty() ){

			auto pNode = q.front();
			q.pop();
			for(auto p: pNode->adj){
				if(*p == n2 )
					return true;

				if(!p->visited)
					q.push(p);
			}
			pNode->visited = true;
		}
		return false;
	}
};






int main()
{
	Node n1("a");
	Node n2("b");
	Node n3("c");
	Node n4("d");
	Node n5("e");
	Node n6("f");



	n1.adj.emplace_back(&n2);
	n1.adj.emplace_back(&n3);
	n1.adj.emplace_back(&n4);
	n1.adj.emplace_back(&n5);

	n2.adj.emplace_back(&n4);
	n2.adj.emplace_back(&n5);

	n4.adj.emplace_back(&n6);

	Graph g;
	
	auto a = g.routeBetweenNodes(n1,n6);


	return 0;
}
