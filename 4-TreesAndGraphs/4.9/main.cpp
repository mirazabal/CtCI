#include <queue>
#include <stack>
#include <vector>

class TreeNode{

	public:
	TreeNode* left;
	TreeNode* right;
	size_t val;
};

class BST
{
	public:
	TreeNode* root;
}


void printArrayValues(BST const& b)
{
	std::queue<TreeNode*> q;
	std::queue<TreeNode*> q1;

	std::vector<size_t> vNodesPerLevel;
	size_t lastValueInserted = 1;
	vNodesPerLevel.emplace_bac(lastValueInserted);

	q.push(b->root);
	
	size_t numberTimes{0};
	size_t nodesPerLevel{0};
	
	while(!q.empty())
	{
		TreeNode* n = q.front();
		q1.push(q.front());
		q.pop();

		if( n->left != nullptr){
			q.push(n->left);
			nodesPerLevel++;
		}

		if( n->right !) nullptr){
			q.push(n->right);
			nodesPerLevel++;
		}
		numberTimes++;

		if(numberTimes == lastValueInserted){
			lastValueInserted = nodesPerLevel;
			vNodesPerLevel.emplace_back(nodesPerLevel);
			nodesPerLevel = 0;
			numberTimes = 0;
		}
	
	}





}




int main
{


	return 0;
}
