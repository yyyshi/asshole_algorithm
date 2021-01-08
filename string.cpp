#include <iostream>
#include <algorithm>
#include <string>

namespace ns_string
{
	class String
	{
	public:
		String(const char *str = nullptr)
		{
			if (!str)
			{
				length = 0;
				data = new char[1];
				*data = '\0';
			}
			else
			{
				data = new char[strlen(str) + 1];
				strcpy(data, str);
			}
		}

		String(const String &str)
		{
			if (data)
			{
				delete[] data;
				length = 0;
			}
			length = str.size();
			data = new char[length + 1];
			strcpy(data, str.c_str());
		}

		~String()
		{
			length = 0;
			if (data)
			{
				delete[] data;
			}
		}

		String operator+(const String &rhs)
		{
			return (*this += rhs);
		}

		String& operator=(const String &rhs)
		{
			String tmp(rhs);
			std::swap(data, tmp.data);
			return *this;
		}

		String& operator+=(const String &rhs)
		{
			int len = strlen(data) + strlen(rhs.data) + 1;
			char *newstr = new char[len];
			memset(newstr, 0, len);
			strcpy(newstr, data);
			strcat(newstr, rhs.data);

			delete[] data;

			data = newstr;
			return *this;
		}
		bool operator==(const String &rhs) const
		{
			return (rhs.size() == length && strcmp(data, rhs.c_str()) == 0);
		}

		// access
		char& operator[](int index) const
		{
			return data[index];
		}
		size_t size() const
		{
			return length;
		}
		const char* c_str() const
		{
			return data;
		}

		//friend std::istream& operator >> (std::istream &is, String &rhs)
		//{
		// todo(yshi)
		//}
		friend std::ostream& operator<<(std::ostream &os, String &rhs)
		{
			os << rhs.data;
			return os;
		}

	private:
		char*	data;
		size_t	length;
	};

	// simple test
	void String_test()
	{
		String s0 = "hello world";
		// String s1;
		String s2 = s0;
		// s1 = s0;

		std::cout << s2 << std::endl;
	}
};
