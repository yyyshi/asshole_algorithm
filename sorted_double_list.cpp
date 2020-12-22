#include <vector>
#include <iostream>
namespace ns_double_list {
	struct ListNode
	{
	public:
		ListNode(int data) : data(data), next(nullptr), pre(nullptr) {}
		int data;
		ListNode* pre;
		ListNode* next;
	};

	void print(ListNode* head)
	{
		ListNode* p = head->next;
		while (p)
		{
			std::cout << p->data << "\t";
			p = p->next;
		}
		std::cout << std::endl;
	}

	// 在head中查找value，找到的话返回value的位置pPos
	bool find(ListNode* head, int value, ListNode*& pPos)
	{
		pPos = nullptr;
		ListNode* p = head->next;

		while (p)
		{
			if (p->data == value)
			{
				// 成功找到要查询的元素
				pPos = p;
				return true;
			}
			else if (p->data > value)
			{
				// 遇到比find元素大的元素，查找失败，返回当前元素的pos
				pPos = p;
				return false;
			}
			else
			{
				// 比当前元素小的话，继续向后查找
				p = p->next;
			}
		}

		// 当前链表中不存在比value大的元素，即该元素应该被插入到链表的最尾部
		return false;
	}

	void insert(ListNode* head, ListNode* tail, int value)
	{
		ListNode* pPos = nullptr;
		bool found = find(head, value, pPos);
		// 如果节点已经存在，不需要再插入
		if (!found)
		{
			// false时表示当前链表中不存在value值，需要进行插入操作
			ListNode* pNew = new ListNode(value);
			// 非尾部插入
			ListNode* pFront = nullptr;
			ListNode* pBack = nullptr;
			if (pPos)
			{
				pFront = pPos->pre;
				pBack = pPos;
			}
			else {
				// 尾部插入，插入到p和tail之间
				pFront = tail->pre;
				pBack = tail;
			}

			// 新节点要插入到front和back位置之间
			pNew->next = pBack;
			pBack->pre = pNew;

			pFront->next = pNew;
			pNew->pre = pFront;
		}
	}

	void remove(ListNode* head, int value)
	{
		ListNode* pPos = nullptr;
		bool found = find(head, value, pPos);
		// 如果当前节点实际上就不存在要删除的节点，那么不做任何操作
		if (found)
		{
			// 忽略pPos节点，直接将pPos的前后节点直接连接
			ListNode* p = pPos->pre;
			ListNode* q = pPos->next;
			p->next = q;
			q->pre = p;
		}
	}

	void destory(ListNode* head)
	{
		ListNode* p = head;
		while (p)
		{
			ListNode* q = p->next;
			delete p;
			p = q;
		}
	}

	int main()
	{
		// create head and tail Nodes
		ListNode* head = new ListNode(-1);
		ListNode* tail = new ListNode(-1);
		head->next = tail;
		tail->pre = head;
		std::cout << "empty double list---------------------" << std::endl;
		print(head);    //  0 , 0

		// insert {6, 2, 1, 3, 5};
		std::vector<int> vec = { 6, 2, 1, 3, 5 };
		for (auto v : vec)
		{
			insert(head, tail, v);
		}
		std::cout << "after insert operation----------------" << std::endl;
		print(head);     //  1, 2, 3, 5, 6

		// find value 3 in double list
		int findElement = 3;
		ListNode* pPlaceHolder = nullptr;
		bool res = find(head, findElement, pPlaceHolder);
		if (res)
		{
			std::cout << "find value 3 in double list------" << std::endl;
		}

		// remove value 3 in double
		int delElement = 3;
		remove(head, delElement);
		std::cout << "after delete value 3operation------" << std::endl;
		print(head);

		// destory double list
		destory(head);
    
                return 0;
	}
};
