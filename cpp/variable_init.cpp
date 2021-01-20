	struct Scyc
	{
		float f1;
		float f2;
	};

	void test_not_init()
	{
		Scyc cyc;
    // use cyc to caculate result, the data will be dirty if not inited
		std::cout << cyc.f1 << std::endl;
		std::cout << cyc.f2 << std::endl;
	}
  
  //  the right way_1, use constructure to init data
  struct Scyc
	{
		float f1;
		float f2;
  
  public:
    Scyc() : f1(0), f2(0) {}
	};

	void test_not_init()
	{
		Scyc cyc;
		std::cout << cyc.f1 << std::endl;
		std::cout << cyc.f2 << std::endl;
	}
  
  //  the right way_2, use memset or {} to init data
  struct Scyc
	{
		float f1;
		float f2;
	};

	void test_not_init()
	{
		Scyc cyc = {};
    // or memeset(0, &cyc);
		std::cout << cyc.f1 << std::endl;
		std::cout << cyc.f2 << std::endl;
	}

/*
变量的声明和初始化，声明的时候只是为这个变量申请内存，如果只对变量进行声明而没有进行初始化操作，那么这个变量指向的数据就是随机的，初始化操作就是将当前变量绑定到初始化指定的值上面，后面可以通过操作此变量来操作对应的数据。
如果没有进行初始化操作，那么指向的随机数据可能导致程序的错误。
int i;  // 声明并定义i
extern int i; // 只声明而非定义i
*/
