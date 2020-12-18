struct ListNode
{
public:
	ListNode(int value) : data(value), next(nullptr) {}
	int data;
	ListNode* next;
};

ListNode* list_reserve(ListNode* head)
{
	ListNode* current = nullptr;
	ListNode* pre = head;

	while (pre != nullptr)
	{
		ListNode* tmp = pre->next;
		pre->next = current;
		current = pre;
		pre = tmp;
	}

	return current;
}

// simple test
int main()
{
	// constructure simple list
	ListNode* p1 = new ListNode(1);
	ListNode* p2 = new ListNode(2);
	p1->next = p2;
	ListNode* p3 = new ListNode(3);
	p2->next = p3;
	p3->next = nullptr;

	// 1->2->3
	print(p1);
	ListNode* res = list_reserve(p1);
	// 3->2->1
	print(res);

	// release data
	delete p1;
	delete p2;
	delete p3;
  return 0;
}
