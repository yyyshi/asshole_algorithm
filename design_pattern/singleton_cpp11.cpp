// static way in c++11
// it's thread safety in c++11 while init static avariable
class Singleton
{
public:
	~Singleton() {
		std::cout << "descrusture called." << std::endl;
	}

	static Singleton& GetInstacne()
	{
		static Singleton instance;
		return instance;
	}

private:
	Singleton()
	{
		std::cout << "conscrusture called." << std::endl;
	}
	Singleton(const Singleton& s) = delete;
	void operator=(const Singleton& s) = delete;
};

// simple test
void Singleton_test()
{
	Singleton& s1 = Singleton::GetInstacne();
	Singleton& s2 = Singleton::GetInstacne();
}

// std::call_once in c++11
class Singleton2 {
public:
	static Singleton2& GetInstance() {
		static std::once_flag sflag;
		std::call_once(sflag, [&]() {
			pInstance.reset(new Singleton2);
		});

		return *pInstance;
	}

	~Singleton2() = default;

	void PrintAddress() const {
		std::cout << this << std::endl;
	}

private:
	Singleton2() = default;

	Singleton2(const Singleton2&) = delete;
	Singleton2& operator=(const Singleton2&) = delete;

private:
	static std::unique_ptr<Singleton2> pInstance;
};

std::unique_ptr<Singleton2> Singleton2::pInstance;

void Singleton2_test() {
	Singleton2& s1 = Singleton2::GetInstance();
	s1.PrintAddress();

	Singleton2& s2 = Singleton2::GetInstance();
	s2.PrintAddress();
}
