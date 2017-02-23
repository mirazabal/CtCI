#include <memory>

class TreeNode
{
	public:
		TreeNode(int key) : key_{key}
		{
		}
		std::unique_ptr<TreeNode> right;
		std::unique_ptr<TreeNode> left;
		int key_;
};

class Tree{
	std::unique_ptr<TreeNode> root;
};


int biggesKeyVal(TreeNode* node)
{
	if(node == null_ptr)
		return 0;


	int valLeft = biggesKeyVal(node->left.get());
	int valRight = biggesKeyVal(node->right.get())

	if (valLeft >= node.key_ || node.key_  >= valRight ){
		
	}

	auto retVal = std::max();

	return valRight;
}




bool isBSTAcomplished(TreeNode* t, int& min, int& max)
{
	if(t == nullptr)
		return true;


	return( isBSTAcomplished(t->left.get(), min, t->key_ ) && isBSTAcomplished( t->right.get(), t->key_, max )  )
}



bool isBST(Tree const& t)
{
	


}









int main()
{

}
