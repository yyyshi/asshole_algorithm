struct MListNode
{
public:
	MListNode(int v) : data(v), next(nullptr) {}
	int data;
	MListNode* next;
};

// recursive func
MListNode* Recursive_Merge_List(MListNode* l1, MListNode* l2)
{
	if (!l1)
	{
		return l2;
	}
	else if (!l2)
	{
		return l1;
	}
	
	if (l1->data < l2->data)
	{
		l1->next = Recursive_Merge_List(l1->next, l2);
		return l1;
	}
	else
	{
		l2->next = Recursive_Merge_List(l1, l2->next);
		return l2;
	}
}

// iteration func
MListNode* Iteration_merge_sorted_list(MListNode* l1, MListNode* l2)
{
	if (!l1)
	{
		return l2;
	}

	if (!l2)
	{
		return l1;
	}

	struct __DummyDeleter
	{
	public:
		__DummyDeleter(MListNode* p) : pNode(p) {}
		~__DummyDeleter() { if (pNode) delete pNode; pNode = nullptr; }

	private:
		MListNode* pNode;
	};
	MListNode* dummy = new MListNode(-1);
	__DummyDeleter deleter(dummy);

	MListNode* head = dummy;
	while (l1 && l2)
	{
		if (l1->data < l2->data)
		{
			head->next = l1;
			l1 = l1->next;
		}
		else
		{
			head->next = l2;
			l2 = l2->next;
		}
		head = head->next;
	}

	head->next = (l1 == nullptr) ? l2 : l1;
	return dummy->next;
}

// simple test
void main()
{
	MListNode* p01 = new MListNode(1);
	MListNode* p02 = new MListNode(3);
	MListNode* p03 = new MListNode(5);
	p01->next = p02;
	p02->next = p03;

	MListNode* p11 = new MListNode(2);
	MListNode* p12 = new MListNode(4);
	MListNode* p13 = new MListNode(6);
	p11->next = p12;
	p12->next = p13;

	// 1. recursive
	MListNode* res = Recursive_Merge_List(p01, p11);
	// 2. iteration
	// MListNode* res = Iteration_merge_sorted_list(p01, p11);
	print(res);
}
