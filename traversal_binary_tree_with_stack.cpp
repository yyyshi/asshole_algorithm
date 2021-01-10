		struct ListNode
	{
	public:
		ListNode(int data) : data(data), left(nullptr), right(nullptr) {}

		int data;
		ListNode* left;
		ListNode* right;
	};
  // pre order tarversal binary tree with self stack
	void PreOrderBinaryTreeWithStack(ListNode* root)
	{
		if (!root)
		{
			return;
		}

		std::stack<ListNode*> stack;
		stack.push(root);
		while (!stack.empty())
		{
			ListNode* tmp = stack.top();
			stack.pop();
			std::cout << tmp->data << std::endl;

			if (tmp->right)
			{
				stack.push(tmp->right);
			}
			if (tmp->left)
			{
				stack.push(tmp->left);
			}
		}
	}
  
  	// mid order traversal binary tree with self stack
	void MidOrderBinaryTreeWithStack(ListNode* root)
	{
		if (!root)
		{
			return;
		}

		std::stack<ListNode*> stack;
		// root node in stack
		stack.push(root);

		// all left node out
		while (!stack.empty())
		{
			// all left node in stack
			while (stack.top()->left)
			{
				stack.push(stack.top()->left);
			}

			// if right node exist, stop to push new left sub node to stack
			while (!stack.empty())
			{
				ListNode* tmp = stack.top();
				std::cout << tmp->data << std::endl;
				stack.pop();
				if (tmp->right)
				{
					stack.push(tmp->right);
					// if right node exists, current node should be regarded as a sub tree like root: push current sub tree's left node to stack and so on... 
					break;
				}
			}
		}
	}
  
// simple test
	void PreOrderBinaryTreeWithStack_test()
	{
		ListNode* p0 = new ListNode(0);
		ListNode* p1 = new ListNode(1);
		ListNode* p2 = new ListNode(2);
    ListNode* p3 = new ListNode(3);
		p0->left = p1;
		p0->right = p2;
    p1->left = p3;
		PreOrderBinaryTreeWithStack(p0);    //  0, 1, 3, 2
	}

	void MidOrderBinaryTreeWithStack_test()
	{
		ListNode* p0 = new ListNode(0);
		ListNode* p1 = new ListNode(1);
		ListNode* p2 = new ListNode(2);
		ListNode* p3 = new ListNode(3);
		p0->left = p1;
		p0->right = p2;
		p1->left = p3;
		MidOrderBinaryTreeWithStack(p0);			//    3, 1, 0, 2
	}
