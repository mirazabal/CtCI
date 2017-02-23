#include <list>
#include <memory>
#include <queue>
#include <vector>

class TreeNode{

	public:
		TreeNode(size_t level) : level_{level}, visited(false)
		{
		}

		std::unique_ptr<TreeNode> left;
		std::unique_ptr<TreeNode> right;
};



class BST{

	public:
	std::unique_ptr<TreeNode> root;
};



std::vector< std::list<TreeNode const&> > returnLevelsFromTree(BST const& bst)
{
	std::vector<std::list<TreeNode const& > > retVal;
	std::queue<TreeNode*>  qParent;
	std::queue<TreeNode*> qChildren;

	qParent.push(bst->root.get());

	while( !qParent.empty() && !qChildren.empty()){

		std::list<TreeNode*> l;
		while(!qParent.empty()){

			TreeNode* n = q.front();
			q.pop();

			l.add(n);

			qChildren.push( n->left.get() );	
			qChildren.push( n->right.get() );
		}
		qParent = qChildren;
		retVal.add(l);
	}


	return retVal;
}



int main()
{
	return 0;
}
