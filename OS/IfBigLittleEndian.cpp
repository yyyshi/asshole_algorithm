	// int reinterpret_cast to char
	void BigLittleEndian()
	{
		int a = 1;
		int* pa = &a;
		// low address save to pch
		char* pch = reinterpret_cast<char*>(pa);
		if (*pch == 1)
		{
			std::cout << "little endian" << std::endl;
		}
		else
		{
			std::cout << "big enidan" << std::endl;
		}
	}

	// different data in one union, address is the same
	void BigLittleEndian()
	{
		union MyUnion
		{
			int iData;
			char cData;
		};

		MyUnion uData;
		uData.iData = 1;
		if (uData.cData == 1)
		{
			std::cout << "little endian" << std::endl;
		}
		else
		{
			std::cout << "big endian" << std::endl;
		}
	}
  
  // simple test
  in main()
  {
    BigLittleEndian();
    return 0;
  }
