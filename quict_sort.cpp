#include <vector>
#include <iostream>

int div_sub_arr(int arr[], int left, int right)
{
	// 将arr[left] as pivot
	int i = left + 1;
	int j = right;
	int tmp = arr[left];

	while (i <= j)
	{
		// find the element > pivot from left
		while (arr[i] < tmp)
		{
			i++;
		}
		// find the element < pivot from right
		while (arr[j] > tmp)
		{
			j--;
		}

		// swap the two elements, and move both index
		if (i < j)
			std::swap(arr[i++], arr[j--]);
		else i++;
	}

	// just the index of the pivot
	std::swap(arr[j], arr[left]);
	// return the pivot's new index
	return j;
}

void quick_sort(int arr[], int left, int right)
{
	if (left > right)
		return;

	// divided the arr, middle index is j
	int j = div_sub_arr(arr, left, right);
	// deal with the two sub arr
	// not j--, j++. pay attention!!!
	quick_sort(arr, left, j - 1);
	quick_sort(arr, j + 1, right);
}

// for test
int main()
{
	int iCount = 6;
	int arr[] = {1, 3, 2, 6, 5, 4};

	for (int i = 0; i < iCount; ++i)
	{
		std::cout << arr[i] << "\t";
	}
	std::cout << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	quick_sort(arr, 0, iCount - 1);

	for (int i = 0; i < iCount; ++i)
	{
		std::cout << arr[i] << "\t";
	}
	std::cout << std::endl;
        return 0;
}

// time complexity O(nlogn)
