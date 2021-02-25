
		void reverseString(std::string& str) {
			int left = 0;
			int right = str.size() - 1;

			while (left < right)
			{
				std::swap(str[left], str[right]);
				left++, right--;
			}
		}

		void reverseString_test()
		{
			std::string str = "hello world";
			reverseString(str);
			std::cout << str << std::endl;
		}
