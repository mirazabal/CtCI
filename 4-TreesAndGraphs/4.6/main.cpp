#include <iostream>

class TreeNode{

	public:
	TreeNode* right;
	TreeNode* left;
	TreeNode* parent;
	int value_;
};


class Tree{
	public:
		TreeNode* root;

};



void printOrder(Tree const& t)
{

}

void printInOrder( TreeNode* n)
{
	if(n == nullptr)
		return;

	printInOrder(n->left);
	std::cout << n->value_ << '\n';
	printInOrder(n->right);
}



TreeNode* nextNodeInOrder(TreeNode const& t)
{	

	if( t->right != nullptr){
		TreeNode* n = t->right;
		while( n->left != nullptr)
			n = n->left;

		return n;
	} else {
		Node* p = t->parent;
		while( p != nullptr && p->value_ < t->value_){
				p = p->parent;
		}
		return p;
	}
}


int main()
{
	return 0;
}


