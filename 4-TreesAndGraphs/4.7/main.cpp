#include <iostream>
#include <stdlib.h>
#include <stack>


struct AdjListNode{
	int dest;
	struct AdjListNode* next;
};

struct AdjList{
	struct AdjListNode* head;
};

struct Graph{
	int v;
	struct AdjList* arr;
};

struct AdjListNode* newAdjListNode(int dest){

	struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof( struct AdjListNode ) );
	newNode->dest = dest;
	newNode->next = NULL;
}



struct Graph* createAGraph(int V)
{
	struct Graph* newGraph = (struct Graph*)malloc(sizeof(struct Graph) );
	newGraph->v = V;

	newGraph->arr = (struct AdjList*)malloc(V*sizeof( struct AdjList) );
	for(int i = 0; i < V; ++i){
		newGraph->arr[i].head = NULL;
	}
	return newGraph;
}

void addEdge(Graph* g, int ori, int des ){

	if(g->arr[ori].head == NULL ){
		g->arr[ori].head = (struct AdjListNode*)malloc( sizeof(struct AdjListNode ) );
		g->arr[ori].head->dest = des;
		g->arr[ori].head->next = NULL; 
	}else {
		struct AdjListNode* n = g->arr[ori].head; 
		while(n->next != NULL){
			n = n->next;
		}
		n->next = (struct AdjListNode*)malloc( sizeof(struct AdjListNode ) );
		n->next->dest =des;
		n->next->next = NULL;
	}
}


void topologicalSort(size_t i, bool visited[], std::stack<int>& st , struct AdjListNode* n)
{
	if(visited[i])
		return;

	visited[i] = true;
	if(n->next != NULL){
		topologicalSort(n->dest, visited, st, n->next );
	}

	st.push(i);
}


void topologicalSort(Graph* g)
{
	struct AdjList* list = g->arr;
	

	bool* visited = new bool[g->v];

	for(int i = 0; i < g->v; ++i){
		visited[i]= false;
	}

	std::stack<int> st;
	int arrVal{0};
	for( struct AdjList* list  = g->arr; list != NULL ; ++list ){
	
		if(list->head != NULL)
			topologicalSort( arrVal , visited , st, list->head );

		arrVal++;
	}

	while(!st.empty()){
		std::cout << st.top() << std::endl;
		st.pop();
	}
	delete[] visited;

}


int main()
{
	int V = 6;
	struct Graph* g = createAGraph(V);

	addEdge(g,3,0);
	addEdge(g,1,5);
	addEdge(g,3,1);
	addEdge(g,0,5);
	addEdge(g,2,3);


	return 0;	
}
