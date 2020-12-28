// dynamic plan
int FrogJump(int n) {
	std::vector<int> dp(n + 1);
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}

// recusive func
int FrogJump(int n)
{
	if (n == 1)
	{
		return 1;
	}

	if (n == 2)
	{
		return 2;
	}

	return FrogJump(n - 1) + FrogJump(n - 2);
}

void main()
{
	int res = FrogJump(7);
	_ASSERTE(res == 21);
}
