namespace ns_mirror_binary_tree
{
	struct TreeNode
	{
	public:
		TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}

		int data;
		TreeNode* left;
		TreeNode* right;
	};

	bool IfMirrorBinaryTree(TreeNode* root1, TreeNode* root2)
	{
		if (!root1 && !root2)
		{
			return true;
		}

		if (!root1 || !root2)
		{
			return false;
		}

		if (root1->data != root2->data)
		{
			return false;
		}

		// different from equal binary tree
		// mirror binary tree:  1.left, 2.right
		// 			2.left, 1.right
		// equal binary tree:  1.left, 2.left
		//		       1.right, 2.right
		return (IfMirrorBinaryTree(root1->left, root2->right)
			&& IfMirrorBinaryTree(root2->left, root1->right));
	}
	bool IfMirrorBinaryTree(TreeNode* root)
	{
		return IfMirrorBinaryTree(root, root);
	}
	
	bool isSymmetric(TreeNode* root) {
		return check(root, root);
	}

	bool ifMirrorTree(TreeNode* root1, TreeNode* root2)
	{
		std::queue<TreeNode*> queue;
		queue.push(root1);
		queue.push(root2);

		while (!queue.empty())
		{
			root1 = queue.front();
			queue.pop();
			root2 = queue.front();
			queue.pop();

			if (!root1 && !root2)
			{
				continue;
			}

			if (!root1 || !root2 || root1->data != root2->data)
			{
				return false;
			}

			queue.push(root1->left);
			queue.push(root2->right);
			queue.push(root1->right);
			queue.push(root2->left);
		}

		return true;
	}
// simple test
//          0
//        /   \
//       1     1
//      /       \
//     2          2
	void IfMirrorBinaryTree_test()
	{
		TreeNode* p0 = new TreeNode(0);
		TreeNode* p1 = new TreeNode(1);
		TreeNode* p2 = new TreeNode(1);
		TreeNode* p3 = new TreeNode(2);
		TreeNode* p4 = new TreeNode(2);
		p0->left = p1;
		p0->right = p2;
		p1->left = p3;
		p2->right = p4;
		bool res = IfMirrorBinaryTree(p0);  //  res = true
		res = res;
	}
};
