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

// a better bubble_sort
void bubble_sort_better(int arr[], int num)
{
	for (int i = 0; i < num; ++i)
	{
		bool sorted = true;
		for (int j = 0; j < num - i - 1; ++j)
		{
			if (arr[j] < arr[j + 1])
			{
				std::swap(arr[j], arr[j + 1]);
				sorted = false;
			}			
		}
		if (sorted) break;
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
