#include <iostream>

void print_min_heap(int arr[], int count)
	{
		for (int i = 0; i < count; ++i)
		{
			std::cout << arr[i] << "\t";
		}
		std::cout << std::endl;
	}

	void Insert(int arr[], int index)
	{
		int insert = arr[index];
		// compare with parent node
		while (index > 0)
		{
			int parentIdx = (index - 1) / 2;
			if (insert < arr[parentIdx])
			{
				// parent node down
				arr[index] = arr[parentIdx];
				index = parentIdx;
				if (index == 0)
				{
					arr[index] = insert;
				}
			}
			else // no need to move any node
			{
				// arr[index] = insert;
				break;
			}
		}
	}

	// n times insert to create min_heap
	void CreateMinHeap(int arr[], int count)
	{
		for (int i = 1; i < count; i++)
			Insert(arr, i);

		// print min_heap
		print_min_heap(arr, count);
	}

	// simple test
	void CreateMinHeap_test()
	{
		int arr[] = {6, 3, 2, 1, 5, 0};
		CreateMinHeap(arr, 6);
	}
