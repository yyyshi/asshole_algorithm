	// 根据先序遍历、中序遍历构建二叉树
	TreeNode* reBuildBinaryTree(int preArray[], int preStart, int preEnd, int midArray[], int midStart, int midEnd)
	{ 
		// 非法
		if (preStart > preEnd || midStart > midEnd || preEnd - preStart != midEnd - midStart)
			return NULL;

		// 1. 确定根节点：先序遍历preArray的第一个元素为根节点
		TreeNode* pNode = new TreeNode(preArray[preStart]);
		// 如果是单个节点的树
		if (preStart == preEnd)
			return pNode;

		// 2. 在中序遍历midArray中找到根节点
		bool foundRoot = false;
		int rootIdx = 0;
		for (rootIdx = midStart; rootIdx <= midEnd; rootIdx++)
		{
			if (midArray[rootIdx] == preArray[preStart])
			{
				foundRoot = true;
				break;
			}
		}
		// 3. 若未找到，返回空
		if (!foundRoot)
			return NULL;

		// 4. 如果存在左子树，递归构建左子树
		if (rootIdx > midStart)
		{
			// left: start
			int TreeNodeCount = rootIdx - midStart;
			pNode->left = reBuildBinaryTree(preArray, preStart + 1, preStart + 1 + (TreeNodeCount - 1), midArray, midStart, midStart + (TreeNodeCount - 1));
		}
		// 5. 如果存在右子树，递归构建右子树
		if (rootIdx < midEnd)
		{
			// right: end
			int TreeNodeCount = midEnd - rootIdx;
			pNode->right = reBuildBinaryTree(preArray, preEnd - (TreeNodeCount - 1), preEnd, midArray, midEnd - (TreeNodeCount - 1), midEnd);
		}
		return pNode;
	}

TreeNode* rebuildTree(std::vector<int>& preOrder, std::vector<int>& midOrder) {
	if (!preOrder.size()) {
		return nullptr;
	}
	TreeNode* root = new TreeNode(preOrder[0]);
	std::stack<TreeNode*> stack;
	stack.push(root);

	int rootIdz = 0;
	for (int i = 1; i < preOrder.size(); ++i)
	{
		TreeNode* pNode = stack.top();
		if (pNode->data != midOrder[rootIdz])
		{
			pNode->left = new TreeNode(preOrder[i]);
			stack.push(pNode->left);
		}
		else
		{
			while (!stack.empty() && stack.top()->data == midOrder[rootIdz])
			{
				pNode = stack.top();
				stack.pop();
				++rootIdz;
			}
			pNode->right = new TreeNode(preOrder[i]);
			stack.push(pNode->right);
		}
	}
	return root;
}

void rebuildTree_test()
{
	std::vector<int> preArr = {0, 1, 3, 2};
	std::vector<int> midArr = {3, 1, 0, 2};
	TreeNode* root = rebuildTree(preArr, midArr);

	LevelPrintTree(root);  //  0, 1, 2, 3
}
	void LevelOrderPrint(TreeNode* pTree)
	{
		if (!pTree)
		{
			return;
		}
		
		// simple test
		// binary tree
		/*		1
			  /   \
			2	      3
			  \
			   4
		*/
		std::cout << pTree->data << std::endl;
		std::cout << pTree->left->data << std::endl;
		std::cout << pTree->right->data << std::endl;
		std::cout << pTree->left->right->data << std::endl;
	}

	void reBuildBinaryTree_test()
	{
		int preOrder[] = {1, 2, 4, 3};
		int midOrder[] = { 2, 4, 1, 3};
		TreeNode* pTree = reBuildBinaryTree(preOrder, 0, 3, midOrder, 0, 3);
		LevelOrderPrint(pTree);
	}
