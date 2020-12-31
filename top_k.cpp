#pragma once
#include <iostream>
#include <queue>

// binary heap is complete binary tree
namespace ns_little_heap
{
  // use STL::priority_queue
	void little_heap()
	{
		auto vec = {1, 2, 3, 4 ,5 ,6};
		std::priority_queue<int> heap;
		for (auto i : vec)
		{
			heap.push(i);
		}

		auto newVec = {10 , 7, 13};
		for (auto i : newVec)
		{
			heap.push(i);
		}

		while (!heap.empty())
		{
			std::cout << heap.top() << std::endl;
			heap.pop();
		}
	}
  
  // todo(shiying)
};
