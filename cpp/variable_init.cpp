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
