class TreeNode{


	TreeNode* right;
	TreeNode* left;
};



TreeNode* DFS( TreeNode* t, TreeNode* commonParent, bool& upperPart)
{
	
	if(t == nullptr)
		return nullptr;

	bool valueChanged = false;
	if(t == n1 || t == n2)
	{
		if( commonParent == nullptr)
			commonParent = t;
		else

		valueChanged = true;
	}

	if( t->left != nullptr)
		DFS(t->left);



	
	if( t->right != nullptr)
		DFS(t->right);





	if(t == n1){
	
	 commonParent = t;
	} else if( t == n2){
		commonParent = t;
	} 




}


TreeNode* commonNode( TreeNode n1, TreeNode n2)
{
	

}


int main()
{
	
	return 0;
}
