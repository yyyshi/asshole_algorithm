namespace ns_my_string
{
	class String
	{
	public:
		String();
		String(const char* data);
		String(const String& rhs);
		String& operator=(const String& rhs);
		friend std::ostream& operator<<(std::ostream& os, String& rhs);
		char* c_str();
		size_t size();

		~String();

	private:
		char* m_data;
	};

	String::String() : m_data(new char[1])
	{
		*m_data = '\0';
	}

	String::String(const char *str) : m_data(new char[strlen(str) + 1])
	{
		strcpy(m_data, str);
	}

	String::String(const String& rhs) : m_data(new char[strlen(rhs.m_data) + 1])
	{
		strcpy(m_data, rhs.m_data);
	}

	// self assignment
	String& String::operator=(const String& rhs)
	{
		String tmp(rhs);
		std::swap(tmp.m_data, this->m_data);
		return *this;
	}
	
	// pass by value
	String& String::operator=(String rhs)
	{
		std::swap(rhs.m_data, this->m_data);
		return *this;
	}

	// no need to specified like String::operator<<
	std::ostream& operator<<(std::ostream& os, String& rhs)
	{
		os << rhs.m_data;
		return os;
	}

	char* String::c_str()
	{
		return m_data;
	}

	size_t String::size()
	{
		return strlen(m_data);
	}

	String::~String()
	{
		delete[] m_data;
	}

	// simple test
	void String_test()
	{
		String s0;							//  String() {}
		String s1 = "hello world";					//  String(const char* str) {}
		String s2 = s1;							//  String(const String& rhs) {} 
		s0 = s1;							//  operator=(const String&rhs) {}

		std::cout << "s0 = " << s0 << '\t' << "s1 = " << s1 << '\t' << "s2 = " << s2 << '\t' << std::endl;
		while (1) {}
	}
};
