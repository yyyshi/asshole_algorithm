	void myReplaceSpace(char*& str, int length)
	{
		int spaceCount = 0;
		for (int i = 0; i < length; ++i)
		{
			if (str[i] == ' ')
			{
				spaceCount++;
			}
		}

		int newLength = length + spaceCount * 2;
		char* newStr = new char[newLength];
		newStr[newLength - 1] = '\0';
		for (int i = length - 1; i >=0; --i)
		{
			if (str[i] == ' ')
			{
				newStr[newLength--] = '0';
				newStr[newLength--] = '2';
				newStr[newLength--] = '%';
			}
			else
			{
				newStr[--newLength] = str[i];
			}
		}

		str = newStr;
	}
  // simple test
	void replaceSpace_test()
	{
		char* ch = "i am boy";
		std::cout << ch << std::endl;
		myReplaceSpace(ch, 9);
		std::cout << ch << std::endl;
		// todo: release source after not use yet
	}
