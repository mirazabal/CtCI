#include <array>
#include <memory>

class TreeNode{
	public:
		TreeNode(int val): val_{val}
		{
		
		};

		std::unique_ptr<TreeNode> left;
		std::unique_ptr<TreeNode> right;
	private:
		int val_;
};

class BST{
	public:
	std::unique_ptr<TreeNode> root;
};


std::unique_ptr<TreeNode> createTreeNode(size_t beg, size_t end, std::array<int, 10> const& arr)
{
	if( end <= beg)
		return nullptr;

	size_t median = (end-beg)/2;
	std::unique_ptr<TreeNode> retVal = std::make_unique<TreeNode>(arr[median]);
	retVal->left = createTreeNode(beg, median - 1 ,arr);
	retVal->right = createTreeNode(median + 1, end ,arr);
	return std::move(retVal);	
}


BST createFromSortedArray(std::array<int,10> const& arr)
{
	BST bst;
	bst.root = createTreeNode(0, arr.size()-1, arr);
	return bst;
}



int main()
{
	std::array<int,10> arr{ 0,1,2,3,4,5,6,7,8,9};
	auto val = createFromSortedArray(arr);
	return 0;
}
