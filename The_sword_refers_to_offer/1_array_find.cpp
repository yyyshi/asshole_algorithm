#include <iostream>
#include <vector>

bool find_number_in_array(std::vector<std::vector<int>>& vec, int target)
{
	// from vec[max_row][0]:  6
	int r = vec.size() - 1, c = 0;
	// max row, column
	while (c >= 0 && r < vec[0].size())
	{
		// == find it 
		if (vec[c][r] == target)
			return true;

		// !=, adjust
		if (vec[c][r] > target)
			r--;
		else
			c++;
	}

	// not found
	return false;
}

// simple test
int main()
{
	std::vector<std::vector<int>> vec = {
		{ 1, 2, 8, 9 },
		{ 2, 4, 9, 12 },
		{ 4, 7, 10, 13 },
		{ 6, 8, 11, 15 }
	};
	int target = 5;

	std::cout << "found " << target << "in 2 binary array, if find the target : " << find_number_in_array(vec, target) << std::endl;
  return 0;
}
