		std::string reverseWords(std::string str) {
			std::istringstream it(str);
			std::string res, word;
			while (it >> word)
			{
				res = word + ' ' + res;
			}

			return res.substr(0, str.size());
		}

		void reverseWords_test()
		{
			std::string str = "hello world yshi";
			std::cout << reverseWords(str) << std::endl;
		}
