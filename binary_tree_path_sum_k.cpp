	// n tree pre order traversal
	//struct MulTreeNode {
	//	int data;
	//	std::vector<MulTreeNode*> children;
	//	MulTreeNode(int data) : data(data) {}
	//	MulTreeNode(int data, std::vector<MulTreeNode*> children) : data(data), children(children) {}
	//};
	std::vector<int> preorder(MulTreeNode* root) {
		std::vector<int> res;
		if (!root)
		{
			return res;
		}
		std::stack<MulTreeNode*> stack;
		stack.push(root);
		while (!stack.empty()) {
			MulTreeNode* tmp = stack.top();
			stack.pop();
			res.push_back(tmp->data);
			for (int i = tmp->children.size() - 1; i >= 0; i--) {
				if (tmp->children[i])
				{
					stack.push(tmp->children[i]);
				}
			}
		}
		return res;
	}
