#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

//P156-P166




//本章重点
//为什么存在动态内存分配
//动态内存函数的介绍
//	malloc
//	free
//	calloc
//	realloc
//常见的动态内存错误
//几个经典的笔试题
//柔性数组



//我们已经掌握的内存开辟方式有：
//int main()
//{
//	int val = 20;			//在栈空间上开辟四个字节
//	char arr[10] = { 0 };	//在栈空间上开辟10个字节的连续空间
//	return 0;
//}
//上述的开辟空间的方式有两个特点：
//	1.空间开辟的大小是固定的。
//	2.数组在申请的时候，必须指定数组的长度，他所需要的内存在编译时分配。
//但是对于空间的需求，不仅仅是上述的情况。
//有时候我们需要的空间大小在程序运行的时候才能知道，那数组的编译时开辟空间的方式就不能满足了。这时候就只能试试动态开辟了。


//栈区						局部变量、函数形参
//堆区						动态内存开辟	malloc、calloc、free、realloc
//静态区/数据段				全局变量、静态变量




//动态内存的开辟
//void* malloc(size_t size);		//开辟成功了，给你返回一个地址，开辟失败给你返回一个空指针

//int main()
//{
//	// 假设开设10个整形的空间
//	int arr[10];						// 栈区
//	//动态内存开辟的
//	//int* p = (int*)malloc(INT_MAX);	// 测试动态内存开辟失败
//	int* p = (int*)malloc(10 * sizeof(int));
//	// 使用这些空间的时候
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		printf("malloc error\n");
//		perror("main");
//		return 1;
//	}
//	// 可以使用了
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", p[i]);			// p[i] --> *(p+i)
//	}
//	// 回收空间
//	free(p);							// free() --> #include<stdlib.h>
//	p = NULL;							// 自己动手把p置成空指针
//
//	return 0;
//}
//malloc函数向内存申请一块连续可用的空间，并返回指向这块空间的指针
//	1.如果开辟成功，则返回一个指向开辟好空间的指针。
//	2.如果开辟失败，则返回一个NULL指针，因此malloc的返回值一定要做检查。
//	3.返回值的类型是void*，所以malloc函数并不知道开辟空间的类型，具体在使用时候使用者自己来决定。
//	4.如果参数size为0，malloc的行为是标准是未定义的，取决于编译器。
//C语言提供了另外一个函数free，专门是用来做动态内存的释放和回收的，函数原型如下：
//void free(void* ptr);
//free函数用来释放动态开辟的内存。
//	1.如果参数ptr指向的空间不是动态开辟的那free函数的行为是未定义的。
//	2.如果参数ptr是NULL指针，则函数什么事情都不做。



//calloc
//void* calloc(size_t num, size_t size);

//int main()
//{
//	// malloc
//	int* p = malloc(40);
//	if (p == NULL)
//	{
//		return 1;
//	}
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d\n", *(p + i));
//	}
//	free(p);
//	p = NULL;
//
//	// calloc
//	p = calloc(10,sizeof(int));
//	if (p == NULL)
//	{
//		return 1;
//	}
//	i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d\n", *(p + i));
//	}
//	free(p);
//	p = NULL;
//
//	return 0;
//}
//calloc函数的功能是为num个大小为size的元素开辟一块空间，并且把空间的每个字节初始化为0。
//与函数malloc的区别只是在于calloc会在返回地址之前把申请的空间的每个字节初始化为全0。




//realloc
//realloc函数的出现让动态内存管理更加灵活。
//有时候我们发现过去申请的空间太小了，有时候我们又会觉得申请的空间太大了，
//那为了合理的分配内存，我们一定会对内存的大小做灵活的调整
//那realloc函数就可以做到对动态开辟内存大小的调整。
//void* realloc(void* ptr, size_t size);
//ptr是要调整的内存地址
//size调整之后新大小
//返回值为调整之后的内存起始位置
//这个函数调整原内存空间大小的基础上，还会将原来内存中的数据移动到新的空间
//realloc在调整内存空间的时候存在两种情况：
//	1.情况1：原有空间之后有足够大的空间
//	2.情况2：原有空间之后没有足够大的空间
//情况1：要扩展内存就直接在原有内存之后直接追加空间，原来空间的数据不发生变化。
//情况2：原有空间之后没有足够多的空间时，扩展的方法是：在堆空间上另找一个合适大小的连续空间来使用。
//		 这样函数返回的是一个新的内存地址。
//int main()
//{
//	// calloc
//	int* p = calloc(10,sizeof(int));
//	if (p == NULL)
//	{
//		perror("main");
//		return 1;
//	}
//	// 使用
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = 5;
//	}
//	// 这里需要p指向的空间更大，需要20个int空间
//	// realloc调整空间
//	int* ptr = realloc(p, 20 * sizeof(int));	// 防止realloc申请失败，污染p指针
//	if (ptr != NULL)
//	{
//		p = ptr;
//	}
//
//	free(p);
//	p = NULL;
//
//	p = (int*)realloc(NULL, 40);				// 当传入NULL时候，这里的功能类似与malloc，就是直接在堆区开辟40个字节
//	free(p);
//	p = NULL;
//
//	return 0;
//}




//动态内存开辟常见的错误
//1.对NULL指针的解引用操作
//2.对动态开辟空间的越界访问
//3.使用free释放非动态开辟的空间
//4.使用free释放动态内存中的一部分
//5.对同一块动态开辟的空间，多次释放
//6.动态开辟的空间忘记释放 - 内存泄露 - 比较严重


//1.对NULL指针的解引用操作
//int main()
//{
//	int* p = (int*)malloc(100000000000);
//
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;	// 如果p的值是NULL,就会出问题
//	}
//
//	return 0;
//}

// 2.对动态开辟空间的越界访问
//int main()
//{
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (p == NULL)
//	{
//		return 1;
//	}
//	int i = 0;
//	for (i = 0; i <= 10; i++)
//	{
//		*(p + i) = i;		// 越界访问
//	}
//	free(p);
//	return 0;
//}

//3.使用free释放非动态开辟的空间
//int main()
//{
//	int arr[10] = { 0 };	// 栈区
//	int* p = arr;
//
//	free(p);				// 使用free释放非动态开辟的空间		free头文件include<stdlib.h>
//	p = NULL;
//	return 0;
//}

//4.使用free释放动态内存中的一部分
//int main()
//{
//	int* p = malloc(10 * sizeof(int));
//	if (p == NULL)
//	{
//		return 1;
//	}
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		*p++ = i;
//	}
//
//	free(p);
//	p = NULL;
//	return 0;
//}

//5.对同一块动态开辟的空间，多次释放
//int main()
//{
//	int* p = (int*)malloc(1000);
//	// 使用
//	// 释放
//	free(p);
//	p = NULL;
//	// free（NULL）	free函数释放空指针，什么事情都不会发生
//
//	// 释放
//	free(p);			// 不能多次释放
//	return 0;
//}

//// 6.动态开辟的空间忘记释放
//void test()
//{
//	int* p = (int*)malloc(1000);
//	if (p == NULL)
//	{
//		return;
//	}
//	// 使用
//
//	// 忘记释放
//}
//
//int main()
//{
//	test();
//	// ...
//	// 当使用完test，局部变量销毁，动态开辟的空间就失联了，造成了内存泄漏
//
//	return 0;
//}

//动态开辟的空间，2中回收方式
//1.主动free
//2.程序结束



//作业
//void GetMemory(char* p)
//{
//	p = (char*)malloc(100);			//因为是值传递，所以当函数调用完毕的时候，指向这个指针的函数会销毁，导致内存泄露
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(str);					//值传递		传递了str的一个临时拷贝
//	strcpy(str, "hello world");		//此时str还是空指针，"hello world"放进空指针会出错
//	printf(str);
//}
//int main()
//{
//	Test();
//
//	return 0;
//}
//str传给GetMemory函数的时候是值传递，所以GetMemory函数的形参p是str的一份临时拷贝。
//在GetMemory函数内部动态申请空间的地址，存放在p中，不会影响外边str，所以当GetMemory函数返回之后，str依然是空指针，。所以strcpy会失败。
//当GetMemory函数返回之后，形参p销毁，使得动态开辟的100个字节错存在内存泄漏，无法释放。

//// 改1：
//char* GetMemory(char* p)
//{
//	p = (char*)malloc(100);			//因为是值传递，所以当函数调用完毕的时候，指向这个指针的函数会销毁，导致内存泄露
//	return p;
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory(str);			//值传递		传递了str的一个临时拷贝
//	strcpy(str, "hello world");		//此时str还是空指针，"hello world"放进空指针会出错
//	printf(str);					//strc是字符指针，指向h的地址
//	free(str);
//	str = NULL;
//}
//int main()
//{
//	Test();
//
//	return 0;
//}
//// 改2：
//void GetMemory(char** p)
//{
//	*p = (char*)malloc(100);			//因为是值传递，所以当函数调用完毕的时候，指向这个指针的函数会销毁，导致内存泄露
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str);			//值传递		传递了str的一个临时拷贝
//	strcpy(str, "hello world");		//此时str还是空指针，"hello world"放进空指针会出错
//	printf(str);					//strc是字符指针，指向h的地址
//	free(str);
//	str = NULL;
//}
//int main()
//{
//	Test();
//
//	return 0;
//}

//int main()
//{
//	printf("hello world\n");
//	char* p = "hello world\n";
//	printf(p);
//	printf("%s", p);
//
//	return 0;
//}

////作业
//char* GetMemory(void)
//{
//	// 返回栈空间的问题
//	char p[] = "hello world";			// 出了这个函数，这个数组就被释放了
//	return p;
//}
//
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//}
//
//int main()
//{
//	Test();
//	return 0;
//}
//GetMemory 函数内部创建的数组是在栈区上创建的
//出了函数，p数组的空间就还给了操作系统
//返回的地址是没有实际的意义，如果通过返回的地址，去访问内存就是非法访问内存的



//作业
//int* f2(void)
//{
//	int* ptr;			//野指针问题
//	*ptr = 10;			//p指针没有初始化，10不知道放在哪
//	return ptr;
//}


//《高质量的C++编程》


// 作业
//void GetMemory(char** p, int num)
//{
//	*p = (char*)malloc(num);
//}
//
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);
//
//	//需要进行free
//	free(str);
//	str = NULL;
//}
//
//int main()
//{
//	Test();
//
//	return 0;
//}
//没有free，造成内存泄漏



//C/C++内存分配的几个区域
//1.栈区（stack）：	在执行函数时，函数内局部变量的存储单元都可以在栈上创建，函数执行结束时，这些存储单元自动被释放。
//					栈内存分配运算内置于处理器的指令集中，效率很高，但是分配的内存容量有限。
//					栈区主要存放运行函数而分配的局部变量、函数参数、返回数据、返回地址等。
//2.堆区（heap）：	一般由程序员分配释放，若程序员不释放，程序结束时可能由OS回收。分配方式类似于链表。
//3.数据段（静态区）（stack）存放全局变量、静态数据。程序结束后由系统释放。
//4.代码段：存放函数体（类成员函数和全局函数）的二进制代码。
//
//实际上，普通的局部变量是在栈区分配空间的，栈区的特点是在上面创建的变量出了作用域就销毁。
//但是被static修饰的变量存放在数据段（静态区），数据段的特点是在上面创建的变量，直到程序结束才销毁。
//所以生命周期变长。



//作业	文件中定义的四个变量，哪个变量不是指针类型
//#define INT_PTR int*
//typedef int* int_ptr;
//INT_PTR a, b;				//#define是替换，INT_PTR相当于int*
//							//int* a,b;				这个语句，a是int*类型，是指针，b是int类型，不是指针
//							//要想a，b都是指针，	int *a，*b；	这样才可以，这样a，b都是int*类型指针
//int_ptr c, d;				//typedef是重定义		将int*重定义成int_ptr




//柔性数组
//也许你从来没有听说过柔性数组（flexible array）这个概念，但是他确实存在。
//C99中，结构中的最后一个元素允许是未知大小的数组，这就叫做【柔性数组】成员
//struct S
//{
//	int n;
//	int arr[];			//大小是未知的
//};
////arr数组就叫柔性数组
//struct S
//{
//	int n;
//	int arr[0];			// 大小是未知的
//};
//////arr[0]	也可以将数组置成0
//int main()
//{
//	struct S s = { 0 };
//	printf("%d\n", sizeof(s));			// sizeof返回的这种结构大小不包括柔性数组的内存
//
//	// 期望arr的大小是10个整型
//	struct S* ps = (struct S*)malloc(sizeof(struct S) + 10 * sizeof(int));
//	ps->n = 10;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		ps->arr[i] = i;
//	}
//
//	// 增加
//	struct S* ptr = (struct S*)realloc(ps, sizeof(struct S) + 20 * sizeof(int));	// 再增加20个int空间
//	if (ptr != NULL)
//	{
//		ps = ptr;
//	}
//	// 使用
//
//	// 释放
//	free(ps);
//	ps = NULL;
//
//	return 0;
//}

//柔性数组的特点
//1.结构中的柔性数组成员前面必须至少一个其他成员
//2.sizeof返回的这种结构大小不包括柔性数组的内存。
//3.包含柔性数组成员的结构用malloc（）函数进行内存的动态分配，并且分配的内存应该大于结构的大小，以适应柔性数组的预期大小。

//// 用指针的方式达到柔性数组的模样
//struct S
//{
//	int n;
//	int* arr;			// 以指针的方式指向柔性数组
//};
//
//int main()
//{
//	struct S* ps = (struct S*)malloc(sizeof(struct S));
//	if (ps == NULL)
//	{
//		return 1;
//	}
//	ps->arr = (int*)malloc(10 * sizeof(int));		//单独为柔性数组开辟空间
//	if (ps->arr == NULL)
//	{
//		return 1;
//	}
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		ps->arr[i] = i;
//	}
//
//	//增加
//	int* ptr = realloc(ps->arr, 20 * sizeof(int));	//如果空间不够，可以单独为柔性数组开辟空间
//	if (ptr != NULL)
//	{
//		ps->arr = ptr;
//	}
//	//使用
//
//	//释放
//	free(ps->arr);			//必须先释放后开辟的ps->arr，再释放ps
//	ps->arr = NULL;
//	free(ps);				//要是先释放ps，那么ps->arr就找不到了，造成内存泄漏
//	ps = NULL;
//
//	return 0;
//}
//这种方式malloc两次，free两次，不如柔性数组只malloc一次，free一次方便
//这种方式多次开辟空间，在空间中产生多个内存碎片，虽然不大，但是再次利用的可能性极低。使得内存利用率降低。
//频繁开辟空间，会降低运行效率

//柔性数组的优势
//1.方便内存释放
//	如果我们的代码是在一个给别人用的函数中，你在里面做了一个内存分配，并把整个结构体返回给用户。
//	用户调用free可以释放结构体，但是用户并不知道这个结构体内的成员也需要free，所以你不能指望用户来发现这个事。
//	如果我们把结构体的内存以及其成员要的内存一次性分配好了，并返回用户一个结构体指针，用户做一次free就可以把所有的内存也给释放掉。
//2.有利于访问速度
//	连续的内存有益于提高访问速度，也有益于减少内存碎片。




//作业	打印用“*”组成的X形图案
//多组输入，一个整数（2-20），表示输出的行数，也表示“x”的反斜线和正斜线的长度
//int main()
//{
//	int n = 0;
//	while (scanf("%d", &n) != EOF)
//	{
//		int i = 0;
//		for (i = 0; i < n; i++)
//		{
//			int j = 0;
//			for (j = 0; j < n; j++)
//			{
//				if (i == j)
//					printf("*");
//				else if (i + j == n - 1)
//					printf("*");
//				else
//					printf(" ");
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}


//作业
//有七个考官，从键盘输入若干组成绩，每组7个分数（百分制），去掉一个最高分，去掉一个最低分，输出每组的平均成绩。
//输入描述：一行，输入7个整数（0-100），代表7个成绩，用空格分割
//输出描述：输出去掉最高分和最低分的平均成绩，小数点后保留2位，每行输出后换行
//int main()
//{
//	int score = 0;
//	int sum = 0;
//	int i = 0;
//	int max = 0;
//	int min = 100;
//
//	for (i = 0; i < 7; i++)
//	{
//		scanf("%d", &score);
//		sum += score;
//		if (max < score)
//			max = score;
//		if (min > score)
//			min = score;
//	}
//	printf("%.2f\n", (sum - max - min) / 5.0);
//	return 0;
//}




//作业
//编程实现，输入年份和月份，计算这一年这个月有多少天
//int main()
//{
//	int y = 0;
//	int m = 0;
//	int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };		//所有可能性，闰年在2月加一天，第一个数为0是为了让下标和月份统一
//	while (scanf("%d %d", &y, &m) != EOF)
//	{
//		int day = days[m];
//		if(m==2)
//		{
//			if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
//			{
//				day += 1;
//			}
//		}
//		printf("%d\n", day);
//	}
//
//	return 0;
//}



//作业
//有一个有序数字序列，从小到大排序，将一个新输入的数插入到序列中，保证插入新数后，序列任然是升序。
//第一行输入一个整数（0<=N<=50）
//第二行输入N个升序排列的整数，输入用空格分隔的N个整数
//第三行输入想要进行插入的一个整数
//int main()
//{
//	int arr[51] = { 0 };
//	//输入
//	int n = 0;
//	//n的输入
//	scanf("%d", &n);
//	int i = 0;
//	//n个数的输入
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	//输入要插入的数据
//	int m = 0;
//	scanf("%d", &m);
//	for (i = n - 1; i >= 0; i--)
//	{
//		if (m > arr[i])
//		{
//			arr[i + 1] = m;
//			break;
//		}
//		else
//		{
//			arr[i + 1] = arr[i];
//		}
//	}
//	if (i < 0)
//		arr[0] = m;						//当插入的是最小的
//	//输出
//	for (i = 0; i < n + 1; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}