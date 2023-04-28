#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>

//P135-P139


//本章重点：重点介绍处理字符和字符串的库函数的使用和注意事项
//求字符串长度
//	strlen
//长度不受限制的字符串函数
//	strcpy
//	strcat
//	strcmp
//长度受限制的字符串函数介绍
//	strncpy
//	strncat
//	strncmp
//字符串查找
//	strstr
//	strtok
//错误信息报告
//	strerror
//字符操作
//内存操作函数
//	memcpy
//	memmove
//	memset
//	memcmp


//测试库函数strlen
//int main()								//#include<stdio.h>
//{
//	char arr[] = "abc";
//	int len = strlen(arr);				//#include<string.h>
//	printf("%d\n", len);
//
//	char arr1[] = { 'a','b','c' };		//arr1里面存放的没有 \0 因此strlen函数求取的长度为随机值
//	int len1 = strlen(arr1);
//	printf("%d\n", len1);
//	return 0;
//}
//字符串以“\0”作为结束标志，strlen函数返回的是在字符串“\0”前面出现的字符数（不包括"\0"）。
//参数指向的字符串必须要以'\0'结束。
//注意函数的返回值为size_t，是无符号的。		size_t <==> unsigned int



//模拟库函数strlen
//方法一	计数器版本
//int my_strlen(const char* str)			//加const 更安全
//{
//	assert(str != NULL);				//#include<assert.h>
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
////方法二	递归版本
////方法三	指针-指针
//int main()
//{
//	char arr[] = "abc";					//默认结尾有	/0
//	//char arr[] = { 'a','b','c' };
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}



//测试库函数strcpy
char* strcpy(char* destination, const char* source);
//int main()
//{
//	char arr[20] = "########";
//	//arr = "hello";				//这种写法是错误的
//	char* p = "hello";				//这种写法允许，将“hello”的h的地址存放在p指针里
//	printf("%s\n", arr);
//	strcpy(arr, "hello");			//将“hello”存放在arr数组里		'\0'是strcpy拷贝停止的终止条件
//	printf("%s\n", arr);
//
//	char arr1[] = { 'a','b','c' };	//数组arr2中未存储 '\0'
//	strcpy(arr, arr1);				//'\0'是strcpy拷贝停止的终止条件		arr2字符串中无'\0',所以不知道何时停止
//	printf("%s\n", arr);
//
//	char* p1 = "hello world";
//	char arr2[5] = "####";
//	strcpy(arr2, p1);				//p1指针访问的内容大于arr2数组长度，虽然最后能正常打印出来，但是却溢出报错了
//	printf("%s\n", arr2);
//
//	char* str = "############";
//	strcpy(str, p);					//目标字符串必须可以修改才能存入，而str是常量字符串，不能修改
//	printf("%s\n", str);
//	return 0;
//}
//源字符串必须以‘\0’结束
//会将源字符串中的‘\0’拷贝到目标空间
//目标空间必须足够大，以确保能存放源字符串
//目标空间必须可变
//学会模拟实现




//strcat		字符串追加
char* strcat(char* destination, const char* source);
//int main()
//{
//	char arr[20] = "hello ";		//后面追加个world
//	strcat(arr, "world");			//字符串追加（链接）
//	printf("%s\n", arr);
//
//	char arr2[] = " world";
//	strcat(arr, arr2);				//可以直接传过来，或者存放在一个字符串里传过来
//	printf("%s\n", arr);
//	return 0;
//}
//源字符串必须以‘\0’结束
//目标空间必须足够大，能容纳下源字符串的内容
//目标空间必须可修改


//strcat 模拟实现
//char* my_strcat(char* destination, const char* source)
//{
//	assert(destination != NULL);
//	assert(source != NULL);
//
//	char* ret = destination;
//	int i = 0;
//	while (*destination != '\0')
//	{
//		destination++;
//	}
//	while (*source != '\0')
//	{
//		*destination = *source;
//		destination++;
//		source++;
//	}
//	//*destination = '\0';
//
//	//第二个while循环也可以写成
//	//while ((*destination++ = *source++) != '\0');		//一行代码直接搞定
//
//	return ret;					//返回的是目标空间的起始地址
//}
//int main()
//{
//	char arr1[20] = "hello ";
//	char arr2[] = "world";
//	my_strcat(arr1, arr2);
//	printf("%s\n", arr1);
//	printf("%s\n", my_strcat(arr1, arr2));		//因为my_strcat返回的是目标字符串的起始地址，因此也可以这样使用
//
//	//my_strcat(arr1, arr1);
//	//从底层逻辑上讲，strcat（）函数无法自己追加自己，因为在第一次追加的时候，已经将arr1里的结束标志‘\0’给覆盖掉了
//	return 0;
//}



//strcmp	字符串比较函数
int strcmp(const char* str1, const char* str2);
//int main()
//{
//	char* p = "obc";
//	char* q = "abcdef";
//	if (p > q)					//这种比较不行，这是在比较地址
//	{
//		printf(">\n");
//	}
//	else
//	{
//		printf("<=\n");
//	}
//
//	if ("obc" > "abcdef")		//这种比较也不行，这也是在比较‘o’和‘a’的地址的大小
//	{
//
//	}
//
//	//strcmp	字符串比较大小的函数
//	int ret1 = strcmp("abbb", "abq");
//	printf("%d\n", ret1);					//小于返回 -1
//
//	int ret2 = strcmp("aaa", "aaa");
//	printf("%d\n", ret2);					//等于返回 0
//
//	int ret3 = strcmp("aqq", "abc");
//	printf("%d\n", ret3);					//大于返回 1
//	return 0;
//}


//模拟实现 strcmp
//int my_strcmp(const char* s1, const char* s2)
//{
//	assert(s1 != NULL && s2 != NULL);
//
//	while (*s1 == *s2)
//	{
//		if (*s1 == '\0')
//		{
//			return 0;
//		}
//		s1++;
//		s2++;
//	}
//	if (*s1 > *s2)
//	{
//		return 1;
//	}
//	else
//	{
//		return -1;
//	}
//	//另一种写法，将上面if else语句换成		return *s1-*s2;
//	//return *s1 - *s2;
//}
//int main()
//{
//	char* p = "abcdef";
//	char* q = "abbbb";
//	//char* q = "abcdef";
//	//char* q = "adaa";
//	int ret = my_strcmp(p, q);
//	if (ret > 0)
//	{
//		printf("%s > %s\n", p, q);
//	}
//	else if (ret == 0)
//	{
//		printf("%s = %s\n", p, q);
//	}
//	else
//	{
//		printf("%s < %s\n", p, q);
//	}
//
//	return 0;
//}


/*
strcpy
strcat
strcmp
长度不受限制的字符串函数，一直拷贝（追加、比较）完才停止

*/

/*
strncpy
strncat
strncmp
长度受限制的字符串函数

*/


//strncpy   测试
//char strncpy(char* destination, const char* source, size_t num);

//int main()
//{
//	char arr1[20] = "abcdef";
//	char arr2[] = "qwer";
//
//	//strcpy(arr1, arr2);
//	strncpy(arr1, arr2, 2);
//
//	printf("%s\n", arr1);
//	return 0;
//}

//strncpy 实现
//char* my_strncpy(char* dest, const char* src, size_t count)
//{
//	char* start = dest;
//	while (count && (*dest++ = *src++) != '\0')
//		count--;
//	if (count)
//		while (--count)
//			*dest++='\0';
//	return start;
//}
//int main()
//{
//	char arr1[20] = "abcdef";
//	char arr2[] = "qwer";
//
//	//strcpy(arr1, arr2);
//	my_strncpy(arr1, arr2, 2);
//
//	printf("%s\n", arr1);
//	return 0;
//}



//strncat		追加字符串
char* strncat(char* destination, const char* source, size_t num);
//
//int main()
//{
//	char arr1[20] = "hello ";
//	char arr2[] = "world";
//
//	strncat(arr1, arr2, 6);
//	printf("%s\n", arr1);
//
//	return 0;
//}

//strncat	实现
//char* my_strncat(char* front, const char* back, size_t count)
//{
//	char* start = front;
//	while (*front++);
//	front--;
//	while (count--)
//		if ((*front++ = *back++) == 0)
//			return start;
//	*front = '\0';
//	return start;
//}
//int main()
//{
//	char arr1[20] = "hello ";
//	char arr2[] = "world";
//
//	my_strncat(arr1, arr2, 6);
//	printf("%s\n", arr1);
//
//	return 0;
//}




//strncmp   比较n个字符			测试
//int main()
//{
//	char* p = "abcdef";
//	char* q = "abcqwert";
//	int ret1 = strcmp(p, q);
//	printf("%d\n", ret1);
//	if (ret1 > 0)
//	{
//		printf("%s > %s\n", p, q);
//	}
//	else if (ret1 == 0)
//	{
//		printf("%s = %s\n", p, q);
//	}
//	else
//	{
//		printf("%s < %s\n", p, q);
//	}
//
//	int ret2 = strncmp(p, q, 3);
//	printf("%d\n", ret2);
//	if (ret2 > 0)
//	{
//		printf("%s > %s\n", p, q);
//	}
//	else if (ret2 == 0)
//	{
//		printf("%s = %s\n", p, q);
//	}
//	else
//	{
//		printf("%s < %s\n", p, q);
//	}
//
//	return 0;
//}



//strstr	在一个字符串中查找另一个字符串
//int main()
//{
//	char arr1[] = "abcdefabcdef";
//	char arr2[] = "bcd";
//	//在arr1中查找是否包含arr2数组
//	char* ret = strstr(arr1, arr2);			//在arr1中找arr2字符串，找到了，返回第一次找到的位置，没找到返回空指针
//	if (ret == NULL)
//	{
//		printf("没找到\n");
//	}
//	else
//	{
//		printf("找到了：%s\n", ret);
//	}
//	return 0;
//}


//strstr实现
//char* my_strstr(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//
//	const char* s1 = NULL;
//	const char* s2 = NULL;
//	const char* cp = str1;
//	while (*cp)
//	{
//		s1 = cp;
//		s2 = str2;
//		while (*s1&&*s2&&(*s1 == *s2))
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//		{
//			return (char*)cp;
//		}
//		cp++;
//	}
//	return NULL;
//}
//int main()
//{
//	char arr1[] = "abbbcdefabcdef";
//	char arr2[] = "bbc";
//	//在arr1中查找是否包含arr2数组
//	char* ret = my_strstr(arr1, arr2);			//在arr1中找arr2字符串，找到了，返回第一次找到的位置，没找到返回空指针
//	if (ret == NULL)
//	{
//		printf("没找到\n");
//	}
//	else
//	{
//		printf("找到了：%s\n", ret);
//	}
//	return 0;
//}


//KMP - 字符串查找算法



//strtok		切割字符串
char* strtok(char* str, const char* sep);
//sep参数是个字符串，定义了用作分隔符的字符集合
//第一个参数指定一个字符串，它包含了0个或者多个由sep字符串中的一个或者多个分隔符分割的标记。
//strtok函数找到str中的下一个标记，并将其用\0结尾，返回一个指向这个标记的指针。
//注：strtok函数会改变被操作的字符串，所以在使用strtok函数切分的字符串一般都是临时拷贝的内容并且可修改
//strtok函数的第一个参数不为NULL，函数将找到str中第一个标记，strtok函数将保存它在字符串中的位置。
//strtok函数的第一个参数为NULL，函数将在同一个字符串中被保存的位置开始，查找下一个标记点。
//如果字符串中不存在更多的标记，则返回NULL指针。

//strtok		测试
//int main()
//{
//	char arr[] = "zpw@bitedu.tech";
//	char* p = "@.";						//分隔符集合
//
//	char tmp[20] = { 20 };
//	strcpy(tmp, arr);					//由于strtok函数会修改被操作数，因此先最好临时拷贝一份
//
//	char* ret = NULL;
//	ret=strtok(tmp, p);					//将"zpw@bitedu.tech" --> "zpw\0bitedu.tech" ，并返回z地址
//	printf("%s\n", ret);
//
//	ret = strtok(NULL, p);				//bitedu.tech -->bitedu\0tech，并返回b地址
//	printf("%s\n", ret);
//
//	ret = strtok(NULL, p);				//tech -->返回t地址
//	printf("%s\n", ret);
//
//	ret = strtok(NULL, p);				//如果字符串中不存在更多的标记，则返回NULL指针
//	printf("%s\n", ret);
//
//	return 0;
//}

//int main()
//{
//	char arr[] = "zpw@bitedu.tech hehe";
//	char* p = "@. ";						//分隔符集合
//
//	char tmp[30] = { 0 };
//	strcpy(tmp, arr);					//由于strtok函数会修改被操作数，因此先最好临时拷贝一份
//
//	char* ret = NULL;
//	
//	for (ret = strtok(tmp, p); ret != NULL; ret = strtok(NULL, p))
//	{
//		printf("%s\n", ret);
//	}
//
//	return 0;
//}





//strerror			
//使用库函数的时候
//调用库函数失败的时候，都会设置错误码
//全局错误码


//int errno;	//5

#include<errno.h>
//int main()
//{
//	printf("%s\n", strerror(0));
//	printf("%s\n", strerror(1));
//	printf("%s\n", strerror(2));
//	printf("%s\n", strerror(3));
//	printf("%s\n", strerror(4));
//	printf("%s\n", strerror(5));
//
//	FILE* pf = fopen("test.txt", "r");		//打开文件成功，会返回一个有效的指针
//											//打开文件失败，会返回NULL
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));	//strerror --> #include<string.h>	errno --> #include<errno.h>
//		perror("foppen");					//这个函数不需要主动传	errno
//											//把给定的自定义信息打印，加上：，再打印错误信息
//		return 1;
//	}
//	//读文件
//	//
//	//关闭文件
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//	return 0;
//}

//strerror			把错误码转换为错误信息
//perror			直接打印错误信息