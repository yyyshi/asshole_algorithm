// iteration func
int binarySearchIteration(int array[], int left, int right, int value)
{
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		// find it
		if (value == array[mid])
		{
			return mid;
		}
		// keep left part
		else if (value < array[mid])
		{
			right = mid - 1;
		}
		// keep right part
		else if (value > array[mid])
		{
			left = mid + 1;
		}
	}

	// not found
	return -1;
}

int binarySearchRecursive(int arr[], int left, int right, int value)
{
	int mid = left + (right - left) / 2;
	// not found
	if (left > right)
	{
		return -1;
	}

	// find it
	if (arr[mid] == value)
	{
		return mid;
	}
	// keep left part
	else if (arr[mid] > value)
	{
		return binarySearchRecursive(arr, left, mid - 1, value);
	}
	// keep right part
	else
	{
		return binarySearchRecursive(arr, mid + 1, right, value);
	}
}

// simple test
int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int pos = binarySearchRecursive(arr, 0, 9, 4);
	pos = pos;

	int pos2 = binarySearchIteration(arr, 0, 9, 4);
	pos2 = pos2;
  return 1;
}

// time complexity O(log n)
