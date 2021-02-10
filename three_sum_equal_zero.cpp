#include <iostream>
#include <vector>
using std::vector;
  
vector<vector<int>> threeSumEqualZero2(vector<int>& nums) {
	vector<vector<int>> res;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i++)
	{
		// 排序后如果最小的元素大于0，直接返回{}
		if (nums[i] > 0)
		{
			return res;
		}
		int left = i + 1;
		int right = nums.size() - 1;
		// 去重
		if (i > 0 && nums[i] == nums[i - 1])
		{
			continue;
		}

		// 寻找与nums[i]配对的其余两个数
		while (left < right)
		{
			int tmpSum = nums[i] + nums[left] + nums[right];
			if (tmpSum > 0)
			{
				right--;
			}
			else if (tmpSum < 0)
			{
				left++;
			}
			else
			{
				res.push_back(vector<int>{nums[i], nums[left], nums[right]});
				while (nums[left + 1] == nums[left] && left + 1 < right)
				{
					left++;
				}

				while (nums[right] == nums[right - 1] && left < right - 1)
				{
					right--;
				}
				left++;
				right--;
			}
		}
	}
	return res;
}

void threeSumEqualZero_test()
{
	vector<int> vec = {-1, 0, 1, 2, -1, -4};
	vector<vector<int>> res = threeSumEqualZero2(vec);

	// print
	for (int i = 0; i < res.size(); ++i)
	{
		for (int j = 0; j < res[i].size(); ++j)
		{
			std::cout << res[i][j] << '\t';
		}

		std::cout << std::endl;
	}
}
