namespace ns_skiplist
{
	// real data in skiplist
	struct robj
	{
		// some data structures
	};

	// node structure
	typedef struct zskiplistNode {
		robj *obj;
		double score;
		// backward pointer
		struct zskiplistNode *backward;
		// 一个几点可能存在于多个层中，level[]表示当前节点所处的每层
		struct zskiplistLevel {
			// 每一层中的前向指针
			struct zskiplistNode *forward;
			// x.level[i].span 表示节点x在第i层到其下一个节点需跳过的节点数。注：两个相邻节点span为1
			unsigned int span;
		} level[];
	} zskiplistNode;

	// list structure
	typedef struct zskiplist {
		struct zskiplistNode *header, *tail;
		// list total nodes
		unsigned long length;
		// list total levels
		int level;
	} zskiplis;

	// simple test
	void skiplist_test()
	{
		robj data = {};
		// create some nodes
		zskiplistNode* header = new zskiplistNode();
		zskiplistNode* tail = new zskiplistNode();
		header->obj = &data;
		header->score = 0;
		header->backward = tail;
		// data of each level
		header->level[0].forward = 0;

		// create a list
		zskiplist list;
		list.header = header;
		list.tail = tail;
		list.level = 0;
		list.length = 10;
	}
};
