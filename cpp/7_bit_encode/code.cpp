// 将一个四字节的整形数值压缩成1~5个字节
bool Encode(unsigned int i, char *buf, size_t &len)
{
    len = 0;
    for (int a = 4; a >= 0; a--)
    {
        char c;
        c = i >> (a * 7) & 0x7f;
        if (c == 0x00 && len == 0)
            continue;
        if (a == 0)
            c &= 0x7f;
        else
            c |= 0x80;
        buf[len] = c;
        len++;
    }
    if (len == 0)
    {
        len++;
        buf[0] = 0;
    }
    cout << "Encode:" << i << endl;
    cout << "Encode len:" << len << endl;
    return true;
}

// 将一个1~5个字节的值还原成四字节的整形值
bool Decode(char *buf, size_t len, unsigned int &i)
{
    i = 0;
    for (int index = 0; index < (int)len; index++)
    {
        char c = *(buf + index);
        i = i << 7;
        c &= 0x7f;
        i |= c;
    }
    cout << "Decode:" << i << endl;
    return true;
}

void Compress_UnCompress_test()
{
	int iint = 256;
	char buf[2];
	size_t data_size = 0;
	Encode(iint, buf, data_size);

	unsigned int iRead = 0;
	Decode(buf, data_size, iRead);

	// des      bin                         添加标记位之后								        需要几个字节来存储
	// 127		  // 0 1111111				          0^111111											            1
 	// 256		  // 10 0000000				          1^0000010		0^0000000						        	2
	// 50000    // 11 0000110 1010000	      	1^0000011		1^0000110		0^1010000		    	3
}
