	void Insert_1(int arr[], int newIdx)
	{
		// 此次insert要操作的值
		int newValue = arr[newIdx];
		// 一直比较到根节点
		while (newIdx > 0)
		{
			// 找到父节点
			int parentIdx = (newIdx - 1) / 2;
			// 需要插入的元素小于(当前是小根堆)该父节点
			if (newValue < arr[parentIdx])
			{
				// 那么父节点下移
				arr[newIdx] = arr[parentIdx];
				// 继续向上检查当前节点的父节点是否平衡，直到检查到根节点
				newIdx = parentIdx;
				// 如果发现已经检查到了根节点, 更新根节点的值
				if (newIdx == 0)
					arr[0] = newValue;
			}
			else
			{
				// 当前节点处于平衡状态
				// 之前只是修改了子节点，最后在平衡的时候要修改父节点为新插入的值
				arr[newIdx] = newValue;
				break;
			}
		}
	}
	void CreateMinHeap(int arr[], int count)
	{
		// n times insert to create min_heap
		for (int i = 0; i < count; i++)
			Insert_1(arr, i);

		// print min_heap
		print_min_heap(arr, count);
	}

	// simple test
	int main()
	{
		int arr[] = {6, 3, 2, 1, 5, 0};
		CreateMinHeap(arr, 6);
		return 0;
	}
