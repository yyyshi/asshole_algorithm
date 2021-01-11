namespace ns_permutation
{
	void permutation(char* str, char* strBegin)
	{
		if (*strBegin == '\0')
		{
			std::cout << str << std::endl;
		}
		else
		{
			for (char* it = strBegin; *it != '\0'; ++it)
			{
				std::swap(*it, *strBegin);
				permutation(str, strBegin + 1);
				std::swap(*it, *strBegin);
			}
		}
	}
	void permutation(char* str)
	{
		if (!str)
		{
			return;
		}

		permutation(str, str);
	}

	// simple test
	void permutation_test()
	{
		char ch[] = "abc";
		permutation(ch);
	}
};
