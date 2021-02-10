	/*			 5
			  /		\
			 2		  6
			/  \
		   1    3
	*/
	// {1, 3, 2, 6, 5}                  0         4
	bool IfBstBackSeq(vector<int>& vec, int left, int right) {
		if (left >= right)
		{
			return true;
		}

		int i = left;
		while (i < right)
		{
			if (vec[i] > vec[right])
			{
				break;
			}

			i++;
		}

		for (int j = i + 1; j < right; j++) {
			if (vec[j] <= vec[right])
			{
				return false;
			}
		}
		return IfBstBackSeq(vec, left, i - 1) && IfBstBackSeq(vec, i, right - 1);
	}

	bool IfBinarySearchTreeBackwardSequence(std::vector<int>& vec)
	{
		if (vec.empty())
		{
			return true;
		}
		return IfBstBackSeq(vec, 0, vec.size() - 1);
	}

	void IfBinarySearchTreeBackwardSequence_test()
	{
		std::vector<int> vec = {1, 3, 2, 6, 5};
		std::vector<int> vec2 = { 1, 6, 3, 2, 5 };
		_ASSERTE(IfBinarySearchTreeBackwardSequence(vec));
		_ASSERTE(!IfBinarySearchTreeBackwardSequence(vec2));
	}
