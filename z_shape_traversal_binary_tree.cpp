#include <vector>
#include <queue>
#include <list>
#include <iostream>

namespace ns_z_traversal_binary_tree
{
	struct TreeNode
	{
		int data;
		TreeNode* left;
		TreeNode* right;
	public:
		TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
	};

	// z shape traversal binary tree
	std::vector<std::vector<int>>  z_traversal_binary_tree(TreeNode* root)
	{
		std::vector<std::vector<int>>  allLevel;
		if (!root)
		{
			return allLevel;
		}

		std::queue<TreeNode*> queue;
		queue.push(root);
		bool bFromLeft = false;

		while (!queue.empty())
		{
			int currentSize = queue.size();
			std::list<int> currentLevel = {};
			for (int i = 0; i < currentSize; ++i)
			{
				TreeNode* tmp = queue.front();
				if (bFromLeft)
				{
					currentLevel.push_back(tmp->data);
				}
				else
				{
					currentLevel.push_front(tmp->data);
				}

				if (tmp->left)
				{
					queue.push(tmp->left);
				}
				if (tmp->right)
				{
					queue.push(tmp->right);
				}
				queue.pop();
			}

			allLevel.emplace_back(std::vector<int>{currentLevel.begin(), currentLevel.end()});
			bFromLeft = !bFromLeft;
		}

		return allLevel;
	}

	// level get binary tree
	std::vector<std::vector<int>> LevelGetBinaryTree(TreeNode* root)
	{
		std::vector<std::vector<int>> alllevelData = {};
		if (!root)
		{
			return alllevelData;
		}

		std::queue<TreeNode*> queue;
		queue.push(root);
		while (!queue.empty())
		{
			int currentLevelSize = queue.size();
			std::list<int> currentLevelData = {};
			for (int i = 0; i < currentLevelSize; ++i)
			{
				TreeNode* tmp = queue.front();
				queue.pop();
				currentLevelData.push_back(tmp->data);
				if (tmp->left)
				{
					queue.push(tmp->left);
				}

				if (tmp->right)
				{
					queue.push(tmp->right);
				}
			}

			alllevelData.emplace_back(std::vector<int>(currentLevelData.begin(), currentLevelData.end()));
		}

		return alllevelData;
	}

	void print(const std::vector<std::vector<int>>& allLevel)
	{
		for (auto vec : allLevel)
		{
			for (auto element : vec)
			{
				std::cout << element << "\t";
			}

			std::cout << std::endl;
		}
	}
  
  // simple test, test case like this:
	/*						0
						/		\
					    1		2
				      /	         \
					 3			  4
					/  \           \
				    5   6           7
	*/
	void z_traversal_binary_tree_test()
	{
		TreeNode* p0 = new TreeNode(0);
		TreeNode* p1 = new TreeNode(1);
		TreeNode* p2 = new TreeNode(2);
		TreeNode* p3 = new TreeNode(3);
		TreeNode* p4 = new TreeNode(4);
		TreeNode* p5 = new TreeNode(5);
		TreeNode* p6 = new TreeNode(6);
		TreeNode* p7 = new TreeNode(7);

		p0->left = p1;
		p0->right = p2;
		p1->left = p3;
		p2->right = p4;
		p3->left = p5;
		p3->right = p6;
		p4->right = p7;


		std::vector<std::vector<int>> allLevel = z_traversal_binary_tree(p0);
		print(allLevel);				//   {{0}, {1, 2}, {4, 3}, {5, 6, 7}}
	}
};
