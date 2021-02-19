	// pay attention to this *& type
	void ConvertNodeType(TreeNode* pNode, TreeNode *&list_last)
	{
		if (!pNode)
		{
			return;
		}

		if (pNode->left)
		{
			ConvertNodeType(pNode->left, list_last);
		}

		pNode->left = list_last;
		if (list_last)
		{
			list_last->right = pNode;
		}
		list_last = pNode;

		if (pNode->right)
		{
			ConvertNodeType(pNode->right, list_last);
		}
	}

	TreeNode* ConvertBinarySearchTree2LinkedList(TreeNode* root)
	{
		if (!root)
		{
			return nullptr;
		}

		TreeNode* list_last = nullptr;
		ConvertNodeType(root, list_last);

		// 找到并返回head
		while (list_last->left)
		{
			list_last = list_last->left;
		}

		return list_last;
	}

	void ConvertBinarySearchTree2LinkedList_test()
	{
		TreeNode* p0 = new TreeNode(3);
		TreeNode* p1 = new TreeNode(2);
		TreeNode* p2 = new TreeNode(4);

		p0->left = p1;
		p0->right = p2;

		TreeNode* res = ConvertBinarySearchTree2LinkedList(p0);
		std::cout << res->data << std::endl;                   //  2->3->4
		std::cout << res->right->data << std::endl;
		std::cout << res->right->right->data << std::endl;
	}
