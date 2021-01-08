namespace ns_fast_slow_pointer
{
	// find k_th node
	ListNode* FindNumberK_Node(ListNode* head, int k)
	{
		// fast pointer movw k step first
		ListNode* pFast = head;
		for (int i = 0; i < k - 1; ++i)
		{
			pFast = pFast->next;
		}

		// then both pointer move together at step 1 each time
		ListNode* pSlow = head;
		while (pFast->next)
		{
			pFast = pFast->next;
			pSlow = pSlow->next;
		}

		// while pFast at tail, pSlow is the wanted node
		return pSlow;
	}

// simple test
	void FindNumberK_Node_test()
	{
		ListNode* p0 = new ListNode(0);
		ListNode* p1 = new ListNode(1);
		ListNode* p2 = new ListNode(2);
		ListNode* p3 = new ListNode(3);
		ListNode* p4 = new ListNode(4);
		ListNode* p5 = new ListNode(5);
		p0->next = p1;
		p1->next = p2;
		p2->next = p3;
		p3->next = p4;
		p4->next = p5;

		ListNode* pRes = FindNumberK_Node(p0, 1);   //  5
		std::cout << pRes->data << std::endl;

		pRes = FindNumberK_Node(p0, 3);			        //  3
		std::cout << pRes->data << std::endl;
	}
};
