#include <memory>

class TreeNode{

	public:
		TreeNode() : left{nullptr}, right{nullptr}
		{
		}

		std::unique_ptr<TreeNode> left;
		std::unique_ptr<TreeNode> right;
};

class Tree{
	public:
		std::unique_ptr<TreeNode> root;

};





bool checkIfTreeBalanced(Tree const& t)
{
	return numberOfNodes(t->root.get()) != -1;
}

int numberOfNodes(TreeNode* tNode)
{
	if( tNode == nullptr)
		return 0;

	int leftNumber = numberOfNodes( tNode->left.get() );
	int rightNumber = numberOfNodes( tNode->right.get() );

	if( leftNumber == -1 || rightNumber == -1 
			|| std::abs(leftNumber-rightNumber) > 1 ) 
		return -1;

	return leftNumber + rightNumber + 1;
}


int main()
{
	return 0;
}
