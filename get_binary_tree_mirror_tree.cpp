void get_binary_tree_mirror_tree(TreeNode* root)
{
  if (!root)
  {
    return;
  }
  
  if (!root->left || !root->right)
  {
    return;
  }
  
  std::swap(root->left, root->right);
  get_binary_tree_mirror_tree(root->left);
  get_binary_tree_mirror_tree(root->right);
}

void simple_test()
{
/*        0            |              0
        /   \          |            /  \
       1     2         |           2     1
      /  \             |                /  \
     3    4            |               4    3  
*/
  TreeNode* p0 = new TreeNode(0);
  TreeNode* p1 = new TreeNode(1);
  TreeNode* p2 = new TreeNode(2);
  TreeNode* p3 = new TreeNode(3);
  TreeNode* p4 = new TreeNode(4);
  
  p0->left = p1;
  p0->right = p2;
  p1->left = p3;
  p1->right = p4;
  
  get_binary_tree_mirror_tree(p0);
  printTree(p0);
}
