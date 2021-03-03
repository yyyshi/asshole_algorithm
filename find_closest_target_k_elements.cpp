	std::vector<int> findClosestTargetKElements(const std::vector<int>& vec, int k, int target) {
		int left = 0;
		int right = vec.size() - k - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (target - vec[mid] > vec[mid + k] - target)
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}

		return std::vector<int>(vec.begin() + left, vec.begin() + left + k);
	}

	void findClosestTargetKElements_test()
	{
		std::vector<int> vec = {1, 2, 3, 4, 7, 8, 9, 10};
		int target = 4;
		int k = 3;
		std::vector<int> res = findClosestTargetKElements(vec, k, target);
		for (const auto& it : res)
		{
			std::cout << it << '\t';
		}
		std::cout << std::endl;			//  2, 3, 4
	}
