#include <iostream>

// merge two sub arr
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

	// save result to r1
	for (int n = s; n <= t; n++)
	{
		r1[n] = r2[n];
	}
}

// arr1，arr2，start index，tail index
void MergeSort(int r1[], int r2[], int s, int t)
{
	// start < tail
	if (s < t)
	{
		// divided to 2 parts
		int m = (s + t) / 2;
		// deal with each sub sequence
		MergeSort(r1, r2, s, m);
		MergeSort(r1, r2, m + 1, t);
		// do merge on two sub sequence
		Merge(r1, r2, s, m, t);
	}
}

// simple test
void main()
{
#define  Max_size  7;
	int r1[Max_size] = {3, 4, 5, 8, 2, 7, 9}, r2[Max_size] = {0};
	MergeSort(r1, r2, 0, 6);
	std::cout << "--------------------------------------------" << std::ends;
	for (int i = 0; i < Max_size; i++)
		std::cout << r1[i] << std::ends;
}
