### 二叉查找树，二叉排序树，二叉搜索树：
* 左孩子小于根几点，右孩子大于根节点的二叉树。在极端情况下，树的形状会极不平衡，甚至退化成链表。即容易"失衡"
* 插入：如果树为空，直接创建根节点，否则先查找要插入的位置，之后作为叶子节点插入到树中
* 删除：找到中序遍历时，要删除节点的后继节点，这个后继节点应该是一个叶子节点，将要删除节点与后继叶子节点互换位置，之后删除掉叶子节点所在位置的节点即可完成删除操作
* 查找：根据定义，从根开始查，如果相等返回查找成功，如果小于根节点，到左分支继续查找，如果大于根节点，到右分支继续查找
* 查找和插入的时间复杂度都是O(logn), 在二叉树退化成链表的时候，复杂度为O(n)
* 如果搜索树的高度总是O(logn)，那么我们就能保证查找，插入，删除操作的时间为O(logn)
* 平衡二叉树：最坏情况下树的高度为O(logn)的树称为平衡树

###  AVL树（树的名字为数据结构创建作者名字）：
* 首先是平衡二叉树的一种实例，同时左右子树的高度差绝对值不超过1，左右子树同为二叉平衡树。相比二叉搜索树，平衡二叉树需要调整树结构保持'平衡'状态，目的是为了减少树的高度
* 平衡二叉树是一种高度平衡的二叉树，需要维护和调整树的平衡，在插入和删除操作时候，需要检查在增删借点时候，树的结构是否发生了不平衡，从而进行结构的调整
* 涉及到节点的左旋右旋
* 查询复杂度： O(logn)
* 插入复杂度： 插入的话可能会导致树失衡，4中失衡情况，最多需要2次旋转。先查找O(logn)，再旋转(O(1))
* 删除复杂度： 删除操作可能会导致树失衡，可能需要从要删除节点的父节点开始不断的进行回溯到根节点，以进行平衡性调整。
* 严格的二叉搜索树，左右子树的高度差必须不超过1
* 适用于插入和删除节点较少但是查找比较多的场景

###  红黑树： 和AVL树一样，首先是平衡二叉树的一种。
* 追求局部平衡而非严格的整体平衡。如果场景中插入删除不频繁，查找频繁，AVL树性能要优于红黑树
* 弱平衡二叉树，在相同节点的情况下，红黑树的树高度要高于AVL树
* AVL树和红黑树都是为了减少二叉搜索树的高度，维护树的平衡性，所采取的不同的优化，本质上都是平衡二叉树，不同之处在于，为了维护平衡采用不同的方式

###  B(没有B-树)， 属于多路搜索树
###  B+: 在B树基础上做了优化
* B和B+多用于数据库索引设计
