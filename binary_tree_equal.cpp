namespace ns_binary_tree_equal
{
	bool IfBinaryTreeEqual(TreeNode* root1, TreeNode* root2)
	{
		if (!root1 && !root2)
		{
			return true;
		}

		if (!root1 || !root2)
		{
			return false;
		}

		if (root1->data == root2->data)
		{
			// different from mirror_binary_tree is:
			// mirror tree: 1.left, 2.right
			//              2.left, 1.right
			// equal  tree: 1.left, 2.left
			//              1.right, 2.right
			if (IfBinaryTreeEqual(root1->left, root2->left)
				&& IfBinaryTreeEqual(root1->right, root2->right)
				|| IfBinaryTreeEqual(root1->left, root2->right)
				&& IfBinaryTreeEqual(root1->right, root2->left))
			{
				return true;
			}
		}

		return false;
	}

	// somple test
	void IfBinaryTreeEqual_test()
	{
		// tree1
		//     0
		//   /   \
		//  1     2
		TreeNode* p0 = new TreeNode(0);
		TreeNode* p1 = new TreeNode(1);
		TreeNode* p2 = new TreeNode(2);
		p0->left = p1;
		p0->right = p2;

		// tree2
		//    0
		//  /   \
		//  1
		//   \
		//    2
		TreeNode* s0 = new TreeNode(0);
		TreeNode* s1 = new TreeNode(1);
		TreeNode* s2 = new TreeNode(2);
		s0->left = s1;
		s1->right = s2;
		// cmp
		bool equal = IfBinaryTreeEqual(p0, s0);   // false
		equal = equal;
	}
};
