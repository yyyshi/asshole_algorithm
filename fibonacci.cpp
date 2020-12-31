#pragma once
#include <assert.h>

namespace ns_graph
{
  // recusive func
	int Fib_Recusion(int n)
	{
		if (n == 0)
		{
			return 0;
		}

		if (n == 2 || n == 1)
		{
			return 1;
		}

		return Fib_Recusion(n - 1) + Fib_Recusion(n - 2);
	}

  // iteration func
	int Fib_Iteration(int n)
	{
		if (n == 0)
		{
			return 0;
		}

		if (n == 2 || n == 1)
		{
			return 1;
		}

		int f1 = 1;
		int f2 = 1;
		int sum = 0;
		for (int i = 3; i <= n; ++i)
		{
			sum = f1 + f2;
			f1 = f2;
			f2 = sum;
		}

		return sum;
	}

  // simple test
	void Fib_test()
	{
		int fib0 = (Fib_Recusion(0) == 0);
		int fib1 = (Fib_Recusion(1) == 1);
		int fib2 = (Fib_Recusion(2) == 1);
		int fib3 = (Fib_Recusion(3) == 2);
		int fib4 = (Fib_Recusion(4) == 3);
		int fib5 = (Fib_Recusion(5) == 5);
		int fib6 = (Fib_Recusion(6) == 8);

		assert(fib0);
		assert(fib1);
		assert(fib2);
		assert(fib3);
		assert(fib4);
		assert(fib5);
		assert(fib6);
	}
};
