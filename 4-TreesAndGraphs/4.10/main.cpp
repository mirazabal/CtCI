#include <queue>


class TreeNode{
	public:
	TreeNode* left;
	TreeNode* right;
	int val;
};

class Tree{
	public:
	TreeNode* root;

};

bool sameSubstructure (TreeNode* n1, TreeNode* n2)
{
	if(n1 == nullptr && n2 == nullptr)
		return true;

	if((n1 == nullptr && n2 != nullptr) || (n1 != nullptr && n2 == nullptr) )
		return false;

	if(n1->val == n2->val){
		return ( sameSubstructure(n1->left, n2->left)  && sameSubstructure(n1->right, n2->right) );
	} 
	return false;
}


bool isSubtree(Tree const& t1, Tree const& t2){

	std::queue<TreeNode*> q;
	q.push(t1.root);	
	
	while(!q.empty()){
		TreeNode* n = q.front();
		
		if( n->val == t2.root->val){
 			if( sameSubstructure(n, t2.root) )
				return true;
		}
		
		q.pop();

		if(n->left != nullptr)
			q.push(n->left);

		if(n->right != nullptr)
			q.push(n->right);

	}


	return false;
}




int main()
{
	return 0;
}
