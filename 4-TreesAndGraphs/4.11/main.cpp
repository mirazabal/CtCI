#include <memory>
#include <random>

using namespace std;

class TreeNode{
	public:
		TreeNode(int val) : left{nullptr}, right{nullptr}, val_{val}, size_{1} {
		
		}

		int val_;
		int size_;
		unique_ptr<TreeNode> left;
		unique_ptr<TreeNode> right;
};

class Tree{
	public:
		Tree() : root{nullptr}
		{

		}

		void insert(int val )
		{
			if(root == nullptr){
				root = make_unique<TreeNode>(val);
				return;
			}

			TreeNode* n = root.get();

		}

		bool find(int val)
		{

		}

		void delete(int val)
		{

		}

		TreeNode* getRandomNode( )
		{
			if(root == nullptr)
				return nullptr;

			return getRandomNode(root);
		}

	private:
		
		TreeNode* getRandomNode( TreeNode* root)
		{
			std::mt19937 rng;
			rng.seed(std::random_device()());
			std::uniform_int_distribution<std::mt19937::result_type> dist(1,root->size_); // distribution in range [1, 6]
			auto val = dist(rng);
		
			if(val == 1){
				return root;
			} else if( root->left != nullptr && root->left->size_ < val)
				return getRandomNode(root->left);
			else{
				return getRandomNode(root->right);
			}
		}

		void insert( int val, TreeNode* n1)
		{
			if( val < n1->val_ ){
				n1->size_++;
				
				if(n1->left == nullptr){
					n1->left = make_unique<TreeNode>(val);
					return;
				}
				insert(val,n1->left.get());
			} else {
				n1->size_++;
				if(n1->right == nullptr){
					n1->right = make_unique<TreeNode>(val);
					return;
				}
				insert(val, n1->right.get());
			}
		}
		unique_ptr<TreeNode> root;

};

int main()
{

	return 0;
}
