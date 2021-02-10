#include <list>
#include <unordered_map>
using std::list;
using std::unordered_map;

class LruCache {
public:
	LruCache(int capacity) : capcity_(capacity) {}
	~LruCache()
	{
		capcity_ = 0;
		list_.clear();
		map_.clear();
	}

	bool get(int key, int* value)
	{
		auto it = map_.find(key);
		// not found
		if (it == map_.end())
		{
			return false;
		}

		// found, adjust position
		auto oldPair = it->second;
		*value = oldPair->second;
		std::pair<int, int> newPair{ oldPair->first, oldPair->second };
		// adjust list position
		list_.push_front(newPair);
		list_.erase(oldPair);
		// adjust map position
		map_.erase(key);
		map_.emplace(key, list_.begin());

		return true;
	}

	void put(int key, int value)
	{
		auto it = map_.find(key);
		// if found, clear old position
		if (it != map_.end())
		{
			list_.erase(it->second);
			map_.erase(key);
		}

		// insert absolutly
		std::pair<int, int> newPair{ key, value };
		list_.push_front(newPair);
		map_.emplace(key, list_ .begin());

		// remove the tail if list full
		if (list_.size() > capcity_)
		{
			map_.erase(list_.back().first);
			list_.pop_back();
		}
	}

private:
	size_t capcity_;
	std::list<std::pair<int, int>> list_;
	std::unordered_map<int, std::list<std::pair<int, int>>::iterator> map_;
};
