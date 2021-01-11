### 1. 存储区域不同导致的语法层面上数据是否可读写的性质不同

* char* pCh = "hello world";    //  pCh存储在字符串常量区，所以不能进行写操作
* char ch[] = "hello world";    //  ch存储在栈区，可以写

`std::cout << ch << std::endl;`
