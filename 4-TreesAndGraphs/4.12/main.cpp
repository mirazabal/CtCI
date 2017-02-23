#include <unordered_map>


class TreeNode{
	public:
	int val;
	TreeNode* right;
	TreeNode* left;
};

class Tree{
	public:
		TreeNode* root;
};


void checkData(TreeNode* n, int sumSoFar, std::unordered_map<int,size_t>& uM)
{
	if(uM.count(sumSoFar + n->val ) == 0 )
		uM.insert(std::pair<int,size_t>(sumSoFar + n->val ,0) ),
	else
		uM.at(sumSoFar + n->val )++;
	


}



void findSumsInTree(int val)
{


}





int main()
{

	return 0;
}
