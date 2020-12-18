#include <iostream>

void bubble_sort(int arr[], int num)
{
	for (int i = 0; i < num; ++i)
	{
		for (int j = i; j < num; ++j)
		{
			if (arr[i] > arr[j])
			{
				std::swap(arr[i], arr[j]);
			}
		}
	}
}

void print(int arr[], int num)
{
	for (int i = 0; i < num; ++i)
	{
		std::cout << arr[i] << "\t";
	}

	std::cout << std::endl;
}

void test_bubble_sort()
{
	int arr[] = {1, 4, 5, 3, 7};
	int num = 5;
	std::cout << "before sort: " << std::endl;
	print(arr, num);

	bubble_sort(arr, 5);
	std::cout << "after  sort: " << std::endl;
	print(arr, num);
}
