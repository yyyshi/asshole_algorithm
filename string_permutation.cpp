namespace ns_permutation
{
	void permutation(char* pStr, char* pBegin)
	{
		if (*pBegin == '\0')
		{
			std::cout << pStr << std::endl;
		}
		else
		{
			for (char* it = pBegin; *it != '\0'; ++it)
			{
				std::swap(*it, *pBegin);
				permutation(pStr, pBegin + 1);
				std::swap(*it, *pBegin);
			}
		}
	}
	void permutation(char* pStr)
	{
		if (!pStr)
		{
			return;
		}

		permutation(pStr, pStr);
	}

	// simple test
	void permutation_test()
	{
		char ch[] = "abc";
		permutation(ch);
	}
};
