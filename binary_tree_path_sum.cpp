		void nodesAddSum(TreeNode* root, int sum, std::vector<std::vector<int>>& res, std::vector<int>& tmp) {
			recursion(root, sum, res, tmp);
		}
		void recursion(TreeNode *root, int sum, std::vector<std::vector<int>>& res, std::vector<int>& tmp)
		{
			if (!root)
			{
				return;
			}
			tmp.push_back(root->data);
			sum -= root->data;
			// 已经到达叶子节点，同时此条路径长度恰好=sum
			if (sum == 0 && !root->left && !root->right)
			{
				res.push_back(tmp);
			}

			recursion(root->left, sum, res, tmp);
			recursion(root->right, sum, res, tmp);
			tmp.pop_back();
		}

/*
          10
         /   \
        5     12
       /  \
      4    7

*/
		void nodesAddSum_test()
		{
			TreeNode* p0 = new TreeNode(10);
			TreeNode* p1 = new TreeNode(5);
			TreeNode* p2 = new TreeNode(12);
			TreeNode* p3 = new TreeNode(4);
			TreeNode* p4 = new TreeNode(7);
			p0->left = p1;
			p0->right = p2;
			p1->left = p3;
			p1->right = p4;

			int sum = 22;
			std::vector<std::vector<int>> res = {};
			std::vector<int> tmp = {};
			nodesAddSum(p0, sum, res, tmp);
			printVecVec(res);
		}
