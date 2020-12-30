namespace ns_binary_tree_traversal
{
	struct ListNode
	{
	public:
		ListNode(int v) : data(v), left(nullptr), right(nullptr) {}

		int data;
		ListNode* left;
		ListNode* right;
	};

	class BinaryTree
	{
	public:
    // for simple test
    //      0
    //   1      2
		BinaryTree() {
			root = new ListNode(0);
			ListNode* left = new ListNode(1);
			ListNode* right = new ListNode(2);
			root->left = left;
			root->right = right;
		}

		ListNode* GetRoot()
		{
			return root;
		}
		void Access(ListNode* pNode)
		{
			std::cout << pNode->data << std::endl;
		}

		void PreOrderPrint(ListNode* root)
		{
			if (!root)
			{
				return;
			}

			// access root first
			Access(root);
			if (root->left)
			{
				PreOrderPrint(root->left);
			}

			if (root->right)
			{
				PreOrderPrint(root->right);
			}
		}

		void MidOrderPrint(ListNode* root)
		{
			if (!root)
			{
				return;
			}

			if (root->left)
			{
				MidOrderPrint(root->left);
			}

			// access root secondly
			Access(root);
			if (root->right)
			{
				MidOrderPrint(root->right);
			}
		}

		void SuffixOrderPrint(ListNode* root)
		{
			if (!root)
			{
				return;
			}

			if (root->left)
			{
				SuffixOrderPrint(root->left);
			}
			if (root->right)
			{
				SuffixOrderPrint(root->right);
			}

			// access root last
			Access(root);
		}

		void LayerPrint(ListNode* root)
		{
			std::queue<ListNode*> que;
			if (!root)
			{
				return;
			}

			que.push(root);
			while (!que.empty())
			{
				ListNode* tmp = que.front();
				Access(tmp);
				que.pop();
				if (tmp->left)
				{
					que.push(tmp->left);
				}
				if (tmp->right)
				{
					que.push(tmp->right);
				}
			}
		}

	private:
		ListNode* root;
	};

	void binary_print_test()
	{
		BinaryTree bt;
		bt.PreOrderPrint(bt.GetRoot());		// 0, 1, 2
		bt.MidOrderPrint(bt.GetRoot());		// 1, 0, 2
		bt.SuffixOrderPrint(bt.GetRoot());  // 1, 2, 0
		bt.LayerPrint(bt.GetRoot());		// 0, 1, 2
	}
};
