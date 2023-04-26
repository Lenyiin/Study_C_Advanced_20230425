#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//P106-P

//编码的三种境界
//1.看代码就是代码
//2.开代码就是内存
//3.看代码还是代码


//指针的进阶
// 1.字符指针
// 2.数组指针
// 3.指针数组
// 4.数组传参和指针传参
// 5.函数指针
// 6.函数指针数组
// 7.指向函数指针数组的指针
// 8.回调函数
// 9.指针和数组面试题的解析


//指针概念
//1.指针就是个变量，用来存放地址，地址唯一标识一块内存空间。
//2.指针的大小是固定的4/8字节（32位平台/64位平台）。
//3.指针是有类型，指针的类型决定了指针的+-正数的步长，指针解引用操作的时候的权限。
//4.指针的运算。



//字符指针
//int main()
//{
//	char ch = 'q';
//	char* pc = &ch;
//
//	char* ps = "hello world";			//这种赋值本质上是将"hello world"这个字符串的首字符的地址存储在了ps中
//	printf("%c\n", *ps);
//	//*ps = "w";						err	常量字符串不能改
//
//	char arr[] = "hello world";
//	printf("%s\n", ps);
//	printf("%s\n", arr);
//	return 0;
//}


//int main()
//{
//	char str1[] = "hello world";
//	char str2[] = "hello world";
//	char* str3 = "hello world";
//	char* str4 = "hello world";
//
//	if (str1 == str2)								//str1和str2是两个不同数组，存放在不同的空间，地址不同
//	{
//		printf("str1 and str2 are same\n");
//	}
//	else
//	{
//		printf("str1 and str2 are not same\n");
//	}
//	if (str3 == str4)								//str3和str4是常量字符串，存的都是"hello world"的首字符地址
//	{
//		printf("str3 and str4 are same\n");
//	}
//	else
//	{
//		printf("str3 and str4 are not same\n");
//	}
//	return 0;
//}



//指针数组：本质上是数组，存放指针的数组
//int main()
//{
//	//数组 - 数组中存放的是指针（地址）
//	//int* arr[3];			//存放整形指针的数组
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	int* arr[3] = { &a,&b,&c };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("%d\n", *(arr[i]));
//	}
//
//	int* arr1[10];			//整型指针的数组
//	char* arr2[4];			//一级字符指针的数组
//	char** arr3[5];			//二级字符指针的数组
//
//	return 0;
//}

//int main()
//{
//	int a[5] = { 1,2,3,4,5 };
//	int b[] = { 2,3,4,5,6 };
//	int c[] = { 3,4,5,6,7 };
//
//	int* arr[3] = { a,b,c };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			//printf("%d ", *(arr[i] + j));
//			printf("%d ", arr[i][j]);			//这种写法也可以
//		}
//		printf("\n");
//	}
//	return 0;
//}



//数组指针：是一种指针，指向数组的指针
//整型指针 - 是指向整型的指针
//字符指针 - 是指向字符的指针
//int main()
//{
//	int a = 10;
//	int* p = &a;			//整型指针
//
//	char ch = 'w';
//	char* pc = &ch;			//字符指针
//
//	int arr[10] = { 1,2,3 };
//	//arr数组名是字符串首元素地址 - arr[0]的地址
//	//&arr取出的是数组的地址
//	int(*parr)[10] = &arr;
//	//parr 就是一个数组指针 - 其中存放的是数组的地址
//
//	double* d[5];
//	double* (*pd)[5] = &d;		//pd就是一个数组指针
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 0 };
//
//	int* p1 = arr;
//	int(*p2)[10] = &arr;
//
//	printf("%p\n", p1);
//	printf("%p\n", p1+1);
//
//	printf("%p\n", p2);
//	printf("%p\n", p2+1);
//	return 0;
//}
//数组名是数组首元素的地址
//但是有2个例外：
//1.sizeof（数组名） - 数组名表示整个数组，计算的是整个数组大小，单位是字节
//2.&数组名 - 数组名表示整个数组，取出的是整个数组的地址

//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	int(*pa)[10] = &arr;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *((*pa) + i));			//一维数组不是很方便，一般不会这么写
//	}
//	return 0;
//}


//void print1(int arr[3][5], int r, int c)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < r; i++)
//	{
//		for (j = 0; j < c; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//}
//void print2(int(*p)[5], int r, int c)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < r; i++)
//	{
//		for (j = 0; j < c; j++)
//		{
//			printf("%d ", *(*(p + i) + j));
//		}
//		printf("\n");
//	}
//	printf("\n");
//}
//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
//	print1(arr, 3, 5);
//	print2(arr, 3, 5);			//arr数组名表示首元素的地址
//	return 0;
//}


//int main()
//{
//	int arr[5];					//整型数组
//
//	int* parr1[10];				//整型指针的数组
//
//	int(*parr2)[10];			//数组指针，该指针能够指向一个数组，数组10个元素，每个元素的类型是int
//
//	int(*parr3[10])[5];			//parr3是一个存储数组指针的数组，该数组能够存放10个数组指针
//								//每个数组指针能够指向一个数组，数组5个元素，每个元素是int类型
//	return 0;
//}


//数组参数、指针参数
//一维数组传参
//void test1_1(int arr[])
//{
//
//}
//void test1_2(int arr[10])
//{
//
//}
//void test1_3(int* arr)
//{
//
//}
//void test2_1(int* arr[20])
//{
//
//}
//void test2_2(int** arr)
//{
//
//}
//int main()
//{
//	int arr[10] = { 0 };
//	int* arr2[20] = { 0 };
//
//	test1_1(arr);
//	test1_2(arr);
//	test1_3(arr);
//	test2_1(arr2);
//	test2_2(arr2);
//	return 0;
//}

//二维数组传参
//void test1(int arr[3][5])
//{
//
//}
//void test2(int arr[][]){}			//err	二维数组传参，函数形参的设计只能省略第一个[]的数字
//void test3(int arr[][5])
//{
//
//}
//void test4(int* arr) {}				//err	二维数组名传参传的是首元素地址，第一行的地址
//void test5(int* arr[5]){}			//err	
//void test6(int(*arr)[5])
//{
//
//}
//void test7(int** arr) {}			//err
//int main()
//{
//	int arr[3][5] = { 0 };
//	test1(arr);
//	test2(arr);
//	test3(arr);
//	test4(arr);
//	test5(arr);
//	test6(arr);
//	test7(arr);
//	return 0;
//}



//作业
//int i;					//i是全局变量，不初始化，默认是0
//int main()
//{
//	i--;
//	//sizeof这个操作符，算出的结果的类型是unsigned int
//	if (i > sizeof(i))			//有符号数和无符号数比较的时候，会先将有符号数转化为无符号数，再进行比较。
//								//-1的无符号数将被解读成很大的数
//	{
//		printf(">\n");
//	}
//	else
//	{
//		printf("<\n");
//	}
//	return 0;
//}


//作业：求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字
//例如：2+22+222+2222+22222
//int main()
//{
//	//由a组成前n项之和 - 不考虑溢出
//	int a = 0;
//	int n = 0;
//	scanf("%d %d", &a, &n);
//	int i = 0;
//	int sum = 0;
//	int ret = 0;
//	for (i = 0; i < n; i++)
//	{
//		//算出一项
//		ret = ret * 10 + a;
//		sum = sum + ret;
//	}
//	printf("sum=%d\n", sum);
//	return 0;
//}


//作业：写一个函数，打印arr数组的内容，不使用数组下标，使用指针。
//arr是一个整形一维数组
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = arr;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//方法1
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *p);
//		p++;
//	}
//	printf("\n");
//	//方法2
//	int* pend = arr + sz - 1;
//	p = arr;
//	while (p <= pend)
//	{
//		printf("%d ", *p);
//		p++;
//	}
//	//知道循环次数用for，不知道循环次数用while
//	printf("\n");
//	return 0;
//}


//作业：求出0~100000之间的所有的“水仙花数”并输出。
//“水仙花数”是指一个n位数，其各位数字的n次方之和确好等于该数本身，
//如：153=1^3+5^3+3^3,则153是一个“水仙花数”。
#include<math.h>
//int main()
//{
//	int i = 0;
//	for (i = 0; i <= 100000; i++)
//	{
//		//判断i是否为自幂数
//		//1.计算i的位数 - n
//		int j = i;
//		int n = 1;
//		while (j / 10)
//		{
//			n++;
//			j = j / 10;
//		}
//		//2.计算i的每一位的n次方之和
//		j = i;
//		int sum = 0;
//		while (j)
//		{
//			//pow是用来求次方数的
//			sum = sum + pow(j % 10, n);
//			j = j / 10;
//		}
//		/*while (j)
//		{
//			sum = sum + (j % 10) ^ n;
//			j = j / 10;
//		}*/
//		//3.判断
//		//int count = 0;
//		if (sum == i)
//		{
//			printf("%d\n", i);
//			//count++;
//		}
//
//	}
//	return 0;
//}


//int main()
//{
//	unsigned long pulArray[] = { 6,7,8,9,10 };
//	unsigned long* pulPtr;
//	pulPtr = pulArray;
//	*(pulPtr + 3) += 3;
//	printf("%d , %d\n", *pulPtr, *(pulPtr + 3));
//	return 0;
//}


//struct stu
//{
//	int num;
//	char name[10];
//	int age;
//};
//void fun(struct stu* p)
//{
//	printf("%s\n", (*p).name);
//	return;
//}
//int main()
//{
//	struct stu students[3] = {
//		{9801,"zhang",20},
//		{9802,"wang",19},
//		{9803,"zhao",18}
//	};
//	fun(students + 1);
//	return 0;
//}


//作业：写一个函数，来逆序一个字符串的内容
#include<assert.h>
//void reverse(char* str)
//{
//	assert(str != NULL);
//	int len = strlen(str);
//	char* left = str;
//	char* right = str + len - 1;
//
//	while (left < right)
//	{
//		char tmp = *right;
//		*right = *left;
//		*left = tmp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	char arr[] = "abcdef";
//	reverse(arr);
//	printf("%s\n", arr);
//	return 0;
//}



//作业：打印菱形
//int main()
//{
//	int line = 0;
//	scanf("%d", &line);
//	int i = 0;
//	for (i = 0; i < line; i++)
//	{
//		int j = 0;
//		for (j = 0; j < line - 1 - i; j++)
//		{
//			printf(" ");
//		}
//		for (j = 0; j < 2 * i + 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	for (i = 0; i < line - 1; i++)
//	{
//		int j = 0;
//		for (j = 0; j <= i; j++)
//		{
//			printf(" ");
//		}
//		for (j = 0; j < 2*line-2*i-3; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//
//	}
//	return 0;
//}


//作业：喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以喝多少汽水（编程实现）
//int main()
//{
//	int money = 0;
//	scanf("%d", &money);
//	int total = money;
//	int empty = money;
//	//开始置换
//	while (empty >= 2)
//	{
//		total += empty / 2;
//		empty = empty / 2 + empty % 2;
//	}
//	printf("%d\n", total);
//	return 0;
//}
//int main()
//{
//	int money = 0;
//	int total = 0;
//	scanf("%d", &money);
//	if (money > 0)
//	{
//		total = 2 * money - 1;
//	}
//	printf("%d\n", total);
//	return 0;
//}

//作业：输入一个整数数组，实现一个函数，
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，所有偶数位于数组的后半部分
//void print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//void move(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//
//	while(left<right)
//	{
//		//从前往后找一个偶数
//		while ((left<right)&&(arr[left] % 2 == 1))			//当初始数组是全奇数或者全偶数，会导致越界访问，
//															//因此加入这条限制语句left<right
//		{
//			left++;
//		}
//		//从后往前找一个奇数
//		while ((left < right) && (arr[right] % 2 == 0))
//		{
//			right--;
//		}
//		if (left < right)
//		{
//			int tmp = arr[left];
//			arr[left] = arr[right];
//			arr[right] = tmp;
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	move(arr, sz);
//	print(arr, sz);
//	return 0;
//}


//作业
//int main()
//{
//	//unsigned char 0~255
//	unsigned char a = 200;
//	//00000000 00000000 00000000 11001000
//	//11001000
//	unsigned char b = 100;
//	//00000000 00000000 00000000 01100100
//	//01100100
//	unsigned char c = 0;
//	//相加的时候，a和b要发生整型提升
//	//无符号char整型提升，高位补0
//	//a=00000000 00000000 00000000 11001000
//	//b=00000000 00000000 00000000 01100100
//	//c=00000000 00000000 00000001 00101100
//	//  00101100									存储	高位溢出，丢了
//	c = a + b;
//	printf("%d %d\n", a + b, c);
//	return 0;
//}

//作业：打印杨辉三角
//void print(int arr[10][10])
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 10; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			printf("%3d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[10][10] = { 0 };
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 10; i++)
//	{
//		arr[i][i] = 1;
//		arr[i][0] = 1;
//		for (j = 1; j < i; j++)
//		{
//			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//		}
//	}
//	print(arr);
//	return 0;
//}


//int main()
//{
//	char killer = 0;
//	for (killer = 'A'; killer <= 'D'; killer++)
//	{
//		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3)
//		{
//			printf("%c\n", killer);
//		}
//	}
//	return 0;
//}


//作业：猜名次
//5位运动员参加10米台跳水比赛，有人让他们预测比赛结果：
//A说：B第二，我第三
//B说：我第二，E第四
//C说：我第一，D第二
//D说：C最后，我第三
//E说：我第四，A第一
//每位选手都说对了一半，请编程确定比赛名次

//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	int e = 0;
//	for (a = 1; a <= 5; a++)
//	{
//		for (b = 1; b <= 5; b++)
//		{
//			for (c = 1; c <= 5; c++)
//			{
//				for (d = 1; d <= 5; d++)
//				{
//					for (e = 1; e <= 5; e++)
//					{
//						if (
//							((b == 2) + (a == 3) == 1) && 
//							((b == 2) + (e == 4) == 1) && 
//							((c == 1) + (d == 2) == 1) && 
//							((c == 5) + (d == 3) == 1) && 
//							((e == 4) + (a == 1) == 1)
//							)
//						{
//							if(a*b*c*d*e==120)
//							{
//								printf("a=%d b=%d c=%d d=%d e=%d\n", a, b, c, d, e);
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}





//一级指针传参
//void print(int* ptr, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(ptr + i));
//	}
//	printf("\n");
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = arr;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//p是一级指针
//	print(arr, sz);
//	return 0;
//}

//二级指针传参
//void test(int** ptr)
//{
//	**ptr = 20;
//}
//int main()
//{
//	int a = 10;
//	int* pa = &a;		//pa是一级指针
//	int** ppa = &pa;	//ppa是二级指针
//
//	//把二级指针进行传参
//	test(ppa);
//	//二级指针还可以传哪些
//	test(&pa);
//	printf("%d\n", a);
//
//	int* arr[10] = { 0 };
//	test(arr);				//传存放一级指针的数组也可以
//	
//	return 0;
//}


/*
一级指针
int*p;			整型指针 - 指向整型的指针
char*pc;		字符指针 - 指向字符的指针
void*pv;		无类型的指针

二级指针
char**p;		
int**p;

数组指针：指向数组的指针
int(*p)[4];

*/

/*
数组：
一维数组
二维数组

指针数组 - 存放指针的数组

*/


//函数指针：指向函数的指针！存放函数地址的指针
//int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int a = 10;
//	int* pa = &a;				//整型指针
//
//	char ch = 'w';
//	char* pc = &ch;				//字符指针
//
//	int arr[10] = { 0 };
//	int(*parr)[10] = &arr;		//取出数组的地址
//	//parr 是指向数组的指针 - 存放的是数组的地址
//
//	//函数指针 - 存放函数地址的指针
//	printf("%p\n", &Add);		//&函数名 - 取到的就是函数的地址
//	printf("%p\n", Add);		//与上面的意义完全一样
//	//数组名 !=& 数组名
//	//函数名 ==& 函数名
//
//	int (*pf)(int, int) = &Add;			//pf 就是一个函数指针变量
//	return 0;
//}


//void test(char* str)
//{
//
//}
//int main()
//{
//	void (*pt)(char*) = &test;
//	return 0;
//}


//int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int (*pf1)(int, int) = &Add;			//pf 就是一个函数指针变量
//	int (*pf)(int, int) = Add;				//由于Add和&Add一个意思，因此，这表达式也可以
//	//Add==pf
//
//	//函数的调用
//	int ret1=(*pf)(3, 5);
//	printf("%d\n", ret1);
//
//	int ret2=Add(3, 5);
//	printf("%d\n", ret2);
//
//	int ret3=pf(3, 5);						//这两种通过函数指针去调用函数的方法都可以，实际上*为摆设
//	printf("%d\n", ret3);
//	//int ret3 = *pf(3, 5);	//err
//	return 0;
//}


//阅读两段有趣的代码
//int main()
//{
//	(*(void(*)())0)();
//	//调用0地址处的函数
//	//该函数无参，返回类型是void
//	//1.void(*)() - 函数指针类型
//	//2.(void(*)())0 - 对0进行强制类型转换，被解释为一个函数的地址
//	//3.*(void(*)())0 - 对0地址进行了解引用操作
//	//4.(*(void(*)())0)() - 调用0地址处的函数
//	//《c陷阱和缺陷》
//	return 0;
//}

//void (*signal(int, void(*)(int)))(int);
////1.signal和（）先结合，说明signal是函数名
////2.signal函数的第一个参数的类型是int，第二个参数的类型是函数指针
////	该函数指针，指向一个参数为int，返回类型是void的函数
////3.signal函数的返回类型也是一个函数指针
////	该函数指针，指向一个参数为int，返回类型是void的函数
////	signal是一个函数的声明
//
////typedef - 对类型进行重定义
//typedef void(*pfun_t)(int);			//对void(*)(int)的函数指针类型重命名为pfun_t
//typedef unsigned int uint;			//对unsigned int的函数类型重命名为 uint
//
////所以上面signal的函数声明可以写成
//pfun_t signal(int, pfun_t);




//函数指针数组 - 存放函数指针的数组
// 
//整型指针		int*
//整型指针数组	int* arr[5]
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int main()
//{
//	int (*pf1)(int, int) = Add;
//	int (*pf2)(int, int) = Sub;
//
//	int (*pfArr[2])(int, int) = { Add,Sub };		//pfArr 就是函数指针数组，存放同类型函数指针
//
//	return 0;
//}





//函数指针的应用
//void menu()
//{
//	printf("**************************************\n");
//	printf("********    1.add    2.sub    ********\n");
//	printf("********    3.mul    4.div    ********\n");
//	printf("********        0.exit        ********\n");
//	printf("**************************************\n");
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//常规实现方法
//int main()
//{
//	int input = 0;
//	//计算器 - 计算整型变量的加、减、乘、除
//	do {
//		menu();
//		printf("欢迎使用本款计算器，请选择：\n");
//		int i = 0;
//		int j = 0;
//		scanf("%d", &input);
//		int ret = 0;
//		switch (input)
//		{
//		case 1:
//			printf("请输入两个操作数：\n");
//			scanf("%d %d", &i, &j);
//			ret = Add(i, j);
//			printf("%d\n\n", ret);
//			break;
//		case 2:
//			printf("请输入两个操作数：\n");
//			scanf("%d %d", &i, &j);
//			ret = Sub(i, j);
//			printf("%d\n\n", ret);
//			break;
//		case 3:
//			printf("请输入两个操作数：\n");
//			scanf("%d %d", &i, &j);
//			ret = Mul(i, j);
//			printf("%d\n\n", ret);
//			break;
//		case 4:
//			printf("请输入两个操作数：\n");
//			scanf("%d %d", &i, &j);
//			ret = Div(i, j);
//			printf("%d\n\n", ret);
//			break;
//		case 0:
//			printf("正在退出程序，请稍后……\n");
//			break;
//		default:
//			printf("你的输入有误，请重新输入：\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}

//函数指针方法
//int main()
//{
//	int input = 0;
//	//计算器 - 计算整型变量的加、减、乘、除
//	do {
//		menu();
//		printf("欢迎使用本款计算器，请选择：\n");
//		int i = 0;
//		int j = 0;
//		scanf("%d", &input);
//		int ret = 0;
//
//		//pfArr就是函数指针数组
//		//转移表 - 《C和指针》
//		int (*pfArr[5])(int, int) = { NULL,Add,Sub,Mul,Div };
//
//		if(input>=1&&input<=4)
//		{
//			printf("请输入两个操作数：\n");
//			scanf("%d %d", &i, &j);
//			ret = (pfArr[input])(i, j);
//			printf("%d\n\n", ret);
//		}
//		else if(input==0)
//		{
//			printf("正在退出程序，请稍后……\n");
//			break;
//		}
//		else
//		{
//			printf("你的输入有误，请重新输入：\n");
//		}
//		
//	} while (input);
//	return 0;
//}




//指向函数指针数组的指针
//函数指针的数组 - 数组
//取出函数指针数组的地址

/*
整型数组
int arr[5];
int (*p1)[5]=&arr;

整型指针的数组
int* arr[5];
int* (*p2)[5]=&arr;
p2是指向【整型指针数组】的指针


函数指针数组
&函数指针数组
int(*p)(int,int);					//函数指针
int(* p2[4])(int,int);				//函数指针的数组
int(* (*p3)[4])(int,int)=&p2；		//取出的是函数指针数组的地址
									//p3就是一个指向【函数指针的数组】的指针
*/

//int main()
//{
//	int arr[10];
//	//数组元素类型 - int
//	//arr 数组的类型是 int [10]
//
//	return 0;
//}





//回调函数
/*
回调函数就是一个通过函数指针调用的函数。如果你把函数的指针（地址）作为参数传递给另一个函数，
当这个指针被用来调用其所指向的函数时，我们就说这是回调函数。回调函数不是由该函数的实现方式直接调用，
而是在特定的事件或条件发生时由另外的一方调用的，用于对该事件或条件进行响应。
*/

//回调函数应用
//void menu()
//{
//	printf("**************************************\n");
//	printf("********    1.add    2.sub    ********\n");
//	printf("********    3.mul    4.div    ********\n");
//	printf("********        0.exit        ********\n");
//	printf("**************************************\n");
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//int Calc(int (*pf)(int, int))
//{
//	int i = 0;
//	int j = 0;
//	printf("请输入两个操作数：\n");
//	scanf("%d %d", &i, &j);
//	return pf(i, j);
//}
//int main()
//{
//	int input = 0;
//	//计算器 - 计算整型变量的加、减、乘、除
//	do {
//		menu();
//		printf("欢迎使用本款计算器，请选择：\n");
//		int i = 0;
//		int j = 0;
//		scanf("%d", &input);
//		int ret = 0;
//		switch (input)
//		{
//		case 1:
//			ret = Calc(Add);				//回调函数
//			printf("%d\n\n", ret);
//			break;
//		case 2:
//			ret = Calc(Sub);
//			printf("%d\n\n", ret);
//			break;
//		case 3:
//			ret = Calc(Mul);
//			printf("%d\n\n", ret);
//			break;
//		case 4:
//			ret = Calc(Div);
//			printf("%d\n\n", ret);
//			break;
//		case 0:
//			printf("正在退出程序，请稍后……\n");
//			break;
//		default:
//			printf("你的输入有误，请重新输入：\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}