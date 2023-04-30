#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

//P156-P




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
void* malloc(size_t size);		//开辟成功了，给你返回一个地址，开辟失败给你返回一个空指针

//int main()
//{
//	//假设开设10个整形的空间
//	int arr[10];				//栈区
//	//动态内存开辟的
//	int* p = (int*)malloc(10 * sizeof(int));
//	//使用这些空间的时候
//	if (p == NULL)
//	{
//		printf("malloc error\n");
//		perror("main");
//		return 0;
//	}
//	//可以使用了
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", p[i]);	//p[i] --> *(p+i)
//	}
//	//回收空间
//	free(p);					//free() --> #include<stdlib.h>
//	p = NULL;					//自己动手把p置成空指针
//
//	return 0;
//}
//malloc函数向内存申请一块连续可用的空间，并返回指向这块空间的指针
//	1.如果开辟成功，则返回一个指向开辟好空间的指针。
//	2.如果开辟失败，则返回一个NULL指针，因此malloc的返回值一定要做检查。
//	3.返回值的类型是void*，所以malloc函数并不知道开辟空间的类型，具体在使用时候使用者自己来决定。
//	4.如果参数size为0，malloc的行为是标准是未定义的，取决于编译器。
//C语言提供了另外一个函数free，专门是用来做动态内存的释放和回收的，函数原型如下：
void free(void* ptr);
//free函数用来释放动态开辟的内存。
//	1.如果参数ptr指向的空间不是动态开辟的那free函数的行为是未定义的。
//	2.如果参数ptr是NULL指针，则函数什么事情都不做。



//calloc
void* calloc(size_t num, size_t size);

//int main()
//{
//	//malloc
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
//	//calloc
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
void* realloc(void* ptr, size_t size);
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
//	//calloc
//	int* p = calloc(10,sizeof(int));
//	if (p == NULL)
//	{
//		perror("main");
//		return 1;
//	}
//	//使用
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = 5;
//	}
//	//这里需要p指向的空间更大，需要20个int空间
//	//realloc调整空间
//	int* ptr = realloc(p, 20 * sizeof(int));		//防止realloc申请失败，污染p指针
//	if (ptr != NULL)
//	{
//		p = ptr;
//	}
//
//	free(p);
//	p = NULL;
//
//	p = (int*)realloc(NULL, 40);		//当传入NULL时候，这里的功能类似与malloc，就是直接在堆区开辟40个字节
//	free(p);
//	p = NULL;
//
//	return 0;
//}
