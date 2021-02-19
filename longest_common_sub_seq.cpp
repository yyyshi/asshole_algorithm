int longestCommonSubSeq(const std::string& str1, const std::string& str2, int size1, int size2)
{
	if (size1 == 0 || size2 == 0)
	{
		return 0;
	}

	if (str1[size1 - 1] == str2[size2 - 1])
	{
		return longestCommonSubSeq(str1, str2, size1 - 1, size2 - 1) + 1;
	}
	else
	{
		return std::max(longestCommonSubSeq(str1, str2, size1, size2 - 1), longestCommonSubSeq(str1, str2, size1 - 1, size2));
	}
}

int longestCommonSubSeq(const std::string &str1, const std::string &str2)
{
	int size1 = str1.size();
	int size2 = str2.size();
	std::vector<std::vector<int>> dp(size1 + 1, std::vector<int>(size2 + 1));
	for (int i = 1; i <= size1; ++i)
	{
		for (int j = 1; j <= size2; ++j)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	return dp[size1][size2];
}

void longestCommonSubSeq_test()
{
	std::string str1 = "abcde";
	std::string str2 = "abe";

	std::cout << "should be 3: " << longestCommonSubSeq(str1, str2) << std::endl;
}
