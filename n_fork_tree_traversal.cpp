	// n fork print, recursive, pre order
	void nForkPrintPreOrderRevursive(MulTreeNode* root)
	{
		if (!root)
		{
			return;
		}

		std::cout << root->data << std::endl;
		for (int i = 0; i < root->children.size(); ++i)
		{
			nForkPrintPreOrderRevursive(root->children[i]);
		}
	}

	// n fork print, recursive, backward order
	void nForkBackwardOrderRevursive(MulTreeNode* root)
	{
		if (!root)
		{
			return;
		}

		for (int i = 0; i < root->children.size(); ++i)
		{
			nForkBackwardOrderRevursive(root->children[i]);
		}
    std::cout << root->data << std::endl;
	}
  
  	// n fork tree traversal, dfs with stack
	std::vector<int> nForkTreeTraversalDfs(MulTreeNode* root)
	{
		std::vector<int> res = {};
		if (!root)
		{
			return res;
		}

		std::stack<MulTreeNode*> stack;
		stack.push(root);

		while (!stack.empty())
		{
			MulTreeNode* tmp = stack.top();
			stack.pop();
			res.push_back(tmp->data);

			for (int i = tmp->children.size() - 1; i >= 0; --i)
			{
				if (tmp->children[i])
				{
					stack.push(tmp->children[i]);
				}
			}
		}

		return res;
	}

	// n fork tree traversal, bfs with queue
	std::vector<int> nForkTreeBfs(MulTreeNode* root)
	{
		std::vector<int> res = {};
		if (!root)
		{
			return res;
		}

		std::queue<MulTreeNode*> queue;
		queue.push(root);
		while (!queue.empty())
		{
			MulTreeNode* tmp = queue.front();
			queue.pop();
			res.push_back(tmp->data);
			for (int i = tmp->children.size() - 1; i >= 0; --i)
			{
				if (tmp->children[i])
				{
					queue.push(tmp->children[i]);
				}
			}
		}

		return res;
	}
