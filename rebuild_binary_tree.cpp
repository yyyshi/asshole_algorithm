	// 根据先序遍历、中序遍历构建二叉树
	ListNode* reBuildBinaryTree(int preArray[], int preStart, int preEnd, int midArray[], int midStart, int midEnd)
	{ 
		// 非法
		if (preStart > preEnd || midStart > midEnd || preEnd - preStart != midEnd - midStart)
			return NULL;

		// 1. 确定根节点：先序遍历preArray的第一个元素为根节点
		ListNode* pNode = new ListNode(preArray[preStart]);
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
			int TreeNodeCount = rootIdx - midStart;
			pNode->left = reBuildBinaryTree(preArray, preStart + 1, preStart + 1 + TreeNodeCount - 1, midArray, midStart, midStart + TreeNodeCount - 1);
		}
		// 5. 如果存在右子树，递归构建右子树
		if (rootIdx < midEnd)
		{
			int TreeNodeCount = midEnd - rootIdx;
			pNode->right = reBuildBinaryTree(preArray, preEnd - TreeNodeCount + 1, preEnd, midArray, midEnd - TreeNodeCount + 1, midEnd);
		}
		return pNode;
	}

	void LevelOrderPrint(ListNode* pTree)
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
		ListNode* pTree = reBuildBinaryTree(preOrder, 0, 3, midOrder, 0, 3);
		LevelOrderPrint(pTree);
	}
