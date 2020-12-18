#include <iostream>

// 两个有序数组合并
void Merge(int r1[], int r2[], int s, int m, int t)
{
	int i = s;
	int j = m + 1;
	int tmp = s;

	while (i <= m && j <= t)
	{
		if (r1[i] <= r1[j])
		{
			r2[tmp++] = r1[i++];
		}
		else
		{
			r2[tmp++] = r1[j++];
		}
	}

	while (i <= m)
		r2[tmp++] = r1[i++];
	while (j <= t)
		r2[tmp++] = r1[j++];

	// 排序结果保存在r1中
	for (int n = s; n <= t; n++)
	{
		r1[n] = r2[n];
	}
}

// 数组1，数组2，开始index，尾部index。最后排序结果也存储在数组1中
void MergeSort(int r1[], int r2[], int s, int t)
{
	// start < tail
	if (s < t)
	{
		// 一个序列数据一分为二
		int m = (s + t) / 2;
		// 递归处理子序列
		MergeSort(r1, r2, s, m);
		MergeSort(r1, r2, m + 1, t);
		// 将分割后排序的子序列做merge
		Merge(r1, r2, s, m, t);
	}
}

// 测试
void main()
{
#define  Max_size  7;
	int r1[Max_size] = {3, 4, 5, 8, 2, 7, 9}, r2[Max_size] = {0};
	MergeSort(r1, r2, 0, 6);
	std::cout << "--------------------------------------------" << std::ends;
	for (int i = 0; i < Max_size; i++)
		std::cout << r1[i] << std::ends;
}
