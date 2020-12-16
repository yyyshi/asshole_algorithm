int div_sub_arr(int arr[], int left, int right)
{
	// 将arr[left]作为基准
	int i = left + 1;
	int j = right;
	int temp = arr[left];

	while (i <= j)
	{
		// 从左边部分找到大于基准的元素
		while (arr[i] < temp)
		{
			i++;
		}
		// 从右边部分找到小于基准的元素
		while (arr[j] > temp)
		{
			j--;
		}

		// 两个元素交换位置，同时分别向左向右移动i和j
		if (i < j)
			std::swap(arr[i++], arr[j--]);
		else i++;
	}

	// 移动基准到正确位置
	std::swap(arr[j], arr[left]);
	// 返回基准的index，这个index将原本的arr[]分割成两个部分
	return j;
}

void quick_sort(int arr[], int left, int right)
{
	if (left > right)
		return;

	// 分割arr，分隔元素index为j
	int j = div_sub_arr(arr, left, right);
	// 以j为分隔线递归分割后的两个子数组
	quick_sort(arr, left, j - 1);
	quick_sort(arr, j + 1, right);
}

// 测试
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
