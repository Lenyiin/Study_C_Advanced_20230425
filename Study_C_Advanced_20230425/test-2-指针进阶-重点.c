#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//P106-P134

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

//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 2,3,4,5,6 };
//	int arr3[] = { 3,4,5,6,7 };
//
//	int* parr[3] = { arr1,arr2,arr3 };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			//printf("%d ", *(parr[i] + j));
//			printf("%d ", parr[i][j]);			// *(p+i) == p[i]
//		}
//		printf("\n");
//	}
//
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
//	printf("%p\n", arr);
//	printf("%p\n", arr+1);
//	printf("\n");
//	printf("%p\n", &arr[0]);
//	printf("%p\n", &arr[0]+1);
//	printf("\n");
//	printf("%p\n", &arr);
//	printf("%p\n", &arr+1);
//	printf("\n");
//
//	int* p1 = arr;			
//	int(*p2)[10] = &arr;	// 数组指针是用来存放数组的地址的
//
//	printf("%p\n", p1);
//	printf("%p\n", p1+1);
//	printf("\n");
//
//	printf("%p\n", p2);
//	printf("%p\n", p2+1);
//	printf("\n");
//
//	int sz = sizeof(arr);
//	printf("%d\n", sz);
//	printf("\n");
//
//	return 0;
//}
//数组名是数组首元素的地址
//但是有2个例外：
//1.sizeof（数组名） - 数组名表示整个数组，计算的是整个数组大小，单位是字节
//2.&数组名 - 数组名表示整个数组，取出的是整个数组的地址

//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i = 0;
//	int* p = arr;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//
//	int(*pa)[10] = &arr;
//	for (i = 0; i < 10; i++)
//	{
//		// p指向数组的，*p其实就相当于数组名，数组名又是数组首元素的地址，*p本质上就是数组首元素地址
//		// 一维数组不是很方便，一般不会这么写
//		printf("%d ", *((*pa) + i));	
//	}
//
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
//
//void print2(int(*p)[5], int r, int c)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < r; i++)
//	{
//		for (j = 0; j < c; j++)
//		{
//			// printf("%d ", *(*(p + i) + j));
//			printf("%d ", p[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//}
//
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
//	// unsigned char 0~255
//	unsigned char a = 200;
//	// 00000000 00000000 00000000 11001000
//	//							  11001000
//	unsigned char b = 100;
//	// 00000000 00000000 00000000 01100100
//	//							  01100100
//	unsigned char c = 0;
//	// 相加的时候，a和b要发生整型提升
//	// 无符号char整型提升，高位补0
//	// a = 00000000 00000000 00000000 11001000
//	// b = 00000000 00000000 00000000 01100100
//	// c = 00000000 00000000 00000001 00101100
//	//								  00101100			存储	高位溢出，丢了
//	c = a + b;
//	printf("%d %d\n", a + b, c);	// 300 44
//	return 0;
//}

////作业：打印杨辉三角
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
//
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
//
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

//void test(int** ptr)
//{
//	printf("num = %d\n", **ptr);
//}
//
//int main()
//{
//	int n = 10;
//	int* p = &n;
//	int **pp = &p;
//
//	test(pp);
//	test(&p);
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
//	int ret = (*pf)(2, 3);
//	printf("%d\n", ret);
//	ret = pf(2, 3);
//	printf("%d\n", ret);
//
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

//int test(const char* str)
//{
//	printf("test()\n");
//	return 0;
//}
//
//int main()
//{
//	// 函数指针 - 也是一种指针，是指向函数的指针
//	printf("%p\n", &test);
//	printf("%p\n", test);
//
//	int (*p)(const char*) = test;
//	
//	(*p)("hello world");
//	test("hello world");
//	p("hello world");
//
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
//
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int Sub(int x, int y)
//{
//	return x - y;
//}
//
//int Mul(int x, int y)
//{
//	return x * y;
//}
//
//int Div(int x, int y)
//{
//	return x / y;
//}

// 常规实现方法
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

// 函数指针方法
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




//qsort函数 - 快速排序

////冒泡排序
//void bubble_sort(int arr[], int sz)
//{
//	int i = 0;
//	int j = 0;
//
//	for (i = 0; i < sz - 1; i++)
//	{
//		int flag = 1;	// 假设数组是排好序的
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//
//				flag = 0;
//			}
//		}
//		if (flag == 1)
//		{
//			break;
//		}
//	}
//}
//void print_arr(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
// 
//int main()
//{
//	//升序
//	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print_arr(arr, sz);
//
//	bubble_sort(arr, sz);
//
//	print_arr(arr, sz);
//
//	return 0;
//}

//qsort()是库函数，不挑类型，什么类型都可以排序		整型数据	字符串数据	结构体数据
/*
void qsort(
			void* base,				//void* 是无具体类型的指针		base 中存放的是待排序数据中第一个对象的地址
			size_t num,				//num   排序数据元素的个数
			size_t size,			//size	数据中一个元素的大小
			int (*compar)(const void*, const void*)		//用来比较待排序数据中的2个元素的函数
);

*/

//int main()
//{
//	int a = 10;
//	char* pa = &a;	// warning 从“int * ”到“char* ”的类型不兼容
//
//	void* pv = &a;	// void* 是无具体类型的指针，可以接受任意类型的地址
//	// void* 是无具体类型的指针，所以不能解引用操作，也不能 +- 整数操作
//
//	return 0;
//}

//#include<stdlib.h>
//#include<string.h>
//
//void print_arr(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//int cmp_int(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//
//void test1()
//{
//	// 整型数据的排序
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	// 排序
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//	// 打印
//	print_arr(arr, sz);
//}
//
//struct Stu
//{
//	char name[20];
//	int age;
//};
//
//int sort_by_age(const void* e1, const void* e2)
//{
//	//return (*(struct Stu*)e1).age - (*(struct Stu*)e2).age;
//	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;			// 这两种写法都可以
//}
//
//int sort_by_name(const void* e1, const void* e2)
//{
//	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
//}
//
//void test2()
//{
//	// 使用qsort函数排序结构体数据
//	struct Stu s[] = { {"zhangsan",30},{"lisi",34},{"wangwu",20} };
//	int sz = sizeof(s) / sizeof(s[0]);
//
//	// 按照年龄排序
//	qsort(s, sz, sizeof(s[0]), sort_by_age);
//	// 按照名字来排序
//	qsort(s, sz, sizeof(s[0]), sort_by_name);
//}
//
//int main()
//{
//	test1();
//	test2();
//
//	return 0;
//}





////模仿qsort实现一个冒泡排序的通用算法
//int cmp_int(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//
//void print_arr(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//void Swap(char* buf1, char* buf2, int width)
//{
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{
//		char tmp = *buf1;
//		*buf1 = *buf2;
//		*buf2 = tmp;
//		buf1++;
//		buf2++;
//	}
//}
//
//void bubble_sort(
//	void* base,
//	int sz,
//	int width,
//	int (*cmp)(const void* e1, const void* e2)
//)
//{
//	int i = 0;
//	// 趟数
//	for (i = 0; i < sz - 1; i++)
//	{
//		int flag = 1;	// 假设数组是排好序的
//		// 一趟的排序
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
//			{
//				// 交换
//				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
//				flag = 0;
//			}
//		}
//		if (flag == 1)
//		{
//			break;
//		}
//	}
//}
//
//void test3()
//{
//	// 整型数据的排序
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	// 排序
//	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);			// 使用自己开发的排序
//	// 打印
//	print_arr(arr, sz);
//}
//
//struct Stu
//{
//	char name[20];
//	int age;
//};
//
//int sort_by_age(const void* e1, const void* e2)
//{
//	// return (*(struct Stu*)e1).age - (*(struct Stu*)e2).age;
//	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;	// 这两种写法都可以
//}
//
//int sort_by_name(const void* e1, const void* e2)
//{
//	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
//}
//
//void test4()
//{
//	// 使用自己的函数排序结构体数据
//	struct Stu s[] = { {"zhangsan",30},{"lisi",34},{"wangwu",20} };
//	int sz = sizeof(s) / sizeof(s[0]);
//
//	// 按照年龄排序
//	bubble_sort(s, sz, sizeof(s[0]), sort_by_age);
//	// 按照名字来排序
//	bubble_sort(s, sz, sizeof(s[0]), sort_by_name);
//}
//
//int main()
//{
//	test3();
//	test4();
//
//	return 0;
//}


//int main()
//{
//	int a = 10;
//	char ch = 'w';
//	void* p = &a;			//void 无具体类型，可以随意指向，存放任意类型
//	*p;						//err	但是不能解引用		访问几个字节？
//	p++；					//err						跳过几个字节？
//							//只能先强制转换相应的类型，再来解引用
//	p = &ch;
//	return 0;
//}




//作业		P124
//sizeof(数组名） - 数组名表示整个数组的 - 计算的是整个数组的大小
//&数组名 - 数组名表示整个数组，取出的是整个数组的地址
//除此之外，其他情况，所有的数组名都是数组首元素的地址
//int main()
//{
//	int a[] = { 1,2,3,4 };
//
//	printf("%d\n", sizeof(a));		//4*4=16
//	printf("%d\n", sizeof(a+0));	//4or8			a+0是第一个元素的地址，sizeof（a+0）计算的是第一个地址的大小
//	printf("%d\n", sizeof(*a));		//4				首元素地址的解引用，就是第一个元素，第一个元素是int类型
//	printf("%d\n", sizeof(a+1));	//4or8			a+1是第二个元素的地址
//	printf("%d\n", sizeof(a[1]));	//4				计算的是第二个元素的大小
//
//	printf("%d\n", sizeof(&a));		//4or8			取整个数组的地址，虽然是数组的地址，但是也是地址，sizeof（&a）计算的是一个地址的大小
//	printf("%d\n", sizeof(*&a));	//4*4			&a取地址取的是整个数组的地址，*&a解引用，找到的是整个数组
//													//&取地址和*解引用，可以理解为低效的效果，sizeof（*&a）==sizeof（a）
//	printf("%d\n", sizeof(&a+1));	//4or8			&a+1，跳过了这个数组的下一个空间的地址，还是一个地址的大小
//	printf("%d\n", sizeof(&a[0]));	//4or8			取出的是第一个元素的地址
//	printf("%d\n", sizeof(&a[0]+1));//4or8			取出的是第二个元素的地址
//
//
//	char arr[] = { 'a','b','c','d','e','f' };
//	//只有字符串才有\0结尾，字符无\0
//
//	printf("%d\n", sizeof(arr));		//6			6个元素，一个元素大小1个字节
//	printf("%d\n", sizeof(arr+0));		//4or8		字符首元素地址
//	printf("%d\n", sizeof(*arr));		//1			解引用第一个元素，大小1个字节
//	printf("%d\n", sizeof(arr[1]));		//1			解引用第二个元素，大小1个字节
//	printf("%d\n", sizeof(&arr));		//4or8		整个字符数组的地址，
//	printf("%d\n", sizeof(&arr+1));		//4or8		整个字符数组的下个空间地址
//	printf("%d\n", sizeof(&arr[0]+1));	//4or8		第二个元素的地址
//	
//	printf("%d\n", strlen(arr));		//长度不定		arr首元素地址		数组没有\0,
//	printf("%d\n", strlen(arr+0));		//长度不定		arr+0首元素地址		结果和上面一样
//	//printf("%d\n", strlen(*arr));		//err			*arr传地址传的有问题，代码会出错
//	//printf("%d\n", strlen(arr[1]));		//err			arr[1]是b，ASCⅡ是98，传的不是地址，代码出错
//	printf("%d\n", strlen(&arr));		//长度不定		&arr整个数组的地址，strlen还是看作首地址
//	printf("%d\n", strlen(&arr+1));		//长度不定		&arr+1跳过一个数组的随机值		随机值-6
//	printf("%d\n", strlen(&arr[0]+1));	//长度不定		随机值-1
//
//
//	char arr1[] = "abcdef";				//字符串结束标志是 \0 ，所以结尾默认放置\0
//	//[ a b c d e f \0 ]
//
//	printf("%d\n", sizeof(arr1));		//7				6个元素 +‘\0’
//	printf("%d\n", sizeof(arr1 + 0));	//4or8			首元素地址
//	printf("%d\n", sizeof(*arr1));		//1				第一个元素大小
//	printf("%d\n", sizeof(arr1[1]));	//1				第二个元素的大小
//	printf("%d\n", sizeof(&arr1));		//4or8			整个数组地址
//	printf("%d\n", sizeof(&arr1+1));	//4or8			整个数组下个空间的地址
//	printf("%d\n", sizeof(&arr1[0]+1));	//4or8			第二个元素的地址
//
//	printf("%d\n", strlen(arr1));		//6				数到‘\0’就会停止
//	printf("%d\n", strlen(arr1 + 0));	//6
//	//printf("%d\n", strlen(*arr1));		//err			将第一个元素a的ASCⅡ码97传给strlen当作地址，会出错
//	//printf("%d\n", strlen(arr1[1]));	//err			将第二个元素b的ASCⅡ码98传给strlen当作地址，会出错
//	printf("%d\n", strlen(&arr1));		//6
//	printf("%d\n", strlen(&arr1+1));	//随机值
//	printf("%d\n", strlen(&arr1[0]+1));	//5
//
//
//	char* p = "abcdef";					//字符串结束标志是 \0 ，所以结尾默认放置\0
//	//[ a b c d e f \0 ]
//
//	printf("%d\n", sizeof(p));			//4or8			字符串的地址
//	printf("%d\n", sizeof(p + 1));		//4or8			b的地址
//	printf("%d\n", sizeof(*p));			//1				a
//	printf("%d\n", sizeof(p[0]));		//1				p[0] --> *(p+0) 还是a
//	printf("%d\n", sizeof(&p));			//4or8			
//	printf("%d\n", sizeof(&p+1));		//4or8
//	printf("%d\n", sizeof(&p[0]+1));	//4or8			p的地址
//
//	printf("%d\n", strlen(p));			//6				6个元素
//	printf("%d\n", strlen(p + 1));		//5				5个元素
//	//printf("%d\n", strlen(*p));			//err
//	//printf("%d\n", strlen(p[0]));		//err
//	printf("%d\n", strlen(&p));			//6				？
//	printf("%d\n", strlen(&p + 1));		//随机值
//	printf("%d\n", strlen(&p[0] + 1));	//5
//
//
//	int b[3][4] = { 0 };
//
//	printf("%d\n", sizeof(b));				//3*4*4=48			整个数组大小
//	printf("%d\n", sizeof(b[0][0]));		//4					第一行第一个元素大小
//	printf("%d\n", sizeof(b[0]));			//4*4=16			第一行4个元素的大小		b[0]可以理解为第一行的数组名
//	printf("%d\n", sizeof(b[0]+1));			//4or8				第一行的第二个元素的地址
//	//b[0] 作为数组名并没有单独放在sizeof内部，也没有取地址，所以b[0]就是第一行第一个元素的地址，b[0]+1是第一行第二个元素的地址
//	printf("%d\n", sizeof(*(b[0] + 1)));	//4					第一行第二个元素的地址解引用
//	printf("%d\n", sizeof(b + 1));			//4or8				b+1 就是第二行的地址
//	//b作为二维数组的数组名，并没有取地址，也没有单独放在sizeof内部，所以b就表示二维数组首元素的地址，即第一行的地址
//	printf("%d\n", sizeof(*(b + 1)));		//4*4=16			第二行四个元素的大小	*(b + 1) ==b[1]
//	//b + 1 表示第二行的地址，*(b + 1) 表示第二行的元素
//	printf("%d\n", sizeof(&b[0]+1));		//4or8				b[0] 第一行数组名，&b[0] 第一行地址，&b[0]+1 第二行地址
//	printf("%d\n", sizeof(*(&b[0] + 1)));	//4*4				
//	printf("%d\n", sizeof(*b));				//4*4				第一行地址		计算第一行大小
//	//b作为二维数组名，没有取地址，没有单独放在sizeof内部，b就是首元素地址，即第一行的地址，所以*b就是第一行，
//	printf("%d\n", sizeof(b[3]));			//4*4				表达式：1.值属性	2.类型属性
//	//并没有计算，只是推测		b[3] -->int [4]		b[3]其实是第四行数组名（如果有的话），即使不存在，也能通过类型计算大小
//	//sizeof() 内部的表达式是不计算的！
//
//	return 0;
//}


//int main()
//{
//	short s = 5;
//	int a = 4;
//	printf("%d\n", sizeof(s = a + 6));			//2			人在屋檐下
//	printf("%d\n", s);							//5			sizeof() 内部的表达式是不计算的！
//	return 0;
//}


//总结：数组名的意义
//1.sizeof（数组名），这里的数组名表示整个数组，计算的是整个数组的大小
//2.&数组名，这里的数组名表示整个数组，取出的是整个数组的地址
//3.除此之外所有的数组名都表示首元素的地址


//作业
//int main()
//{
//	int a[5] = { 1,2,3,4,5 };
//	int* ptr = (int*)(&a + 1);			  //&a 取的是整个数组的地址，&a+1 就是数组后面的下一个空间的地址
//	printf("%d,%d", *(a + 1), *(ptr - 1));//数组名a就是数组首字母地址,a+1就是第二个元素的地址,*(a+1)就是第二个元素的值
//										  //ptr是数组下个空间的首地址，ptr - 1就是数组最后一个元素的地址
//
//	return 0;
//}


//作业
//考察指针类型，决定了指针的运算
//struct Test
//{
//	int Num;
//	char* pcName;
//	short sDate;
//	char cha[2];
//	short sBa[4];
//}*p = (struct Test*)0x100000;
//// 假设p的值是0x100000.如下表表达式的值分别为多少？
//// 已知，结构体Test类型的变量大小是20个字节
//// x86
//
//int main()
//{
//	printf("%p\n", p + 0x1);						// +1其实+的是20个字节 0x100000+0x1=0x100014
//	printf("%p\n", (unsigned long)p + 0x1);			// 强制转换成unsigned long，加的就是1，0x100001
//	printf("%p\n", (unsigned int*)p + 0x1);			// 强制转换成unsigned int*，加1加的就是4字节，0x100004
//
//	return 0;
//}


//作业
//int main()
//{
//	int a[4] = { 1,2,3,4 };
//	int* ptr1 = (int*)(&a + 1);
//	int* ptr2 = (int*)((int*)a + 1);
//	//(int*)a + 1 首元素往后跳1个字节
//
//	printf("%x,%x", ptr1[-1], *ptr2);
//
//	return 0;
//}


//作业
//int main()
//{
//	int a[3][2] = { (0,1),(2,3),(4,5) };			//这个表达式用小括号，（），逗号表达式，结果为最后一个表达式
//	//这个数组存的是：	1 3		5 0		0 0
//	int* p;
//	p = a[0];
//	printf("%d", p[0]);
//
//	return 0;
//}


//作业
//int main()
//{
//	int a[5][5];
//	int(*p)[4];
//	p = a;
//
//	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
//
//	return 0;
//}


//作业
//int main()
//{
//	int aa[2][5] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* ptr1 = (int*)(&aa + 1);						// &aa取整个数组地址，&aa + 1跳过了整个数组
//	int* ptr2 = (int*)(*(aa + 1));						// aa为第一行地址，aa + 1指向第二行。
//														// *(aa + 1)相当于aa[1]，也就是6的地址
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));			// 10	5
//
//	return 0;
//}


//作业
//int main()
//{
//	char* a[] = { "work","at","alibaba" };
//	char** pa = a;
//	pa++;
//	printf("%s\n", *pa);	// at
//
//	return 0;
//}



//作业
//int main()
//{
//	char* c[] = { "ENTER","NEW","POINT","FIRST" };
//	char** cp[] = { c + 3,c + 2,c + 1,c };
//	char*** cpp = cp;
//
//	printf("%s\n", **++cpp);			//++cpp -->cp[1]的地址，*++cpp -->c+2 -->c[2]的地址，**++cpp -->c[2]的内容，POINT
//	printf("%s\n", *-- * ++cpp + 3);	//++cpp -->cp[2]的地址，*++cpp -->c+1 -->c[1]的地址，--*++cpp  -->c[0]的地址,
//										//*--*++cpp -->ENTER，*--*++cpp+3 -->ER
//	printf("%s\n", *cpp[-2] + 3);		//cpp[-2] -->cp[0]的内容 -->c+3 -->c[3]的地址 -->FORST的地址，
//										//*cpp[-2] -->c[3]的内容 -->FORST，*cpp[-2]+3 -->ST
//										//其中，cpp[-2] <==> *(cpp-2)
//	printf("%s\n", cpp[-1][-1] + 1);	//cpp[-1] <==> *(cpp-1)，cpp[-1][-1] <==> *(*(cpp-1)-1)，cpp[-1][-1]+1 <==>*(*(cpp-1)-1)+1
//										//cpp[-1] -->*(cpp-1) -->cp[1]的内容 -->c+2 -->c[2]的地址,
//										//cpp[-1][-1] -->*(*(cpp-1)-1) -->c[1]的内容 -->NEW
//										//cpp[-1][-1]+1 -->EW
//
//	//int i = 0;
//	//printf("%d\n", ++i);
//	//printf("%d\n", ++i);
//	//printf("%d\n", ++i);
//
//	return 0;
//}



//作业
/*
int a=10;				//4个字节空间
int arr[10]={0};		//40个字节空间
一般这种申请了就无法更改了

动态内存开辟：
p=malloc();
申请：malloc
使用
释放：free(p);
p=NULL;

*/


//作业		杨氏矩阵
//有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的
//请编写程序在这样的矩阵中查找某个数字是否存在。
//要求：时间复杂度小于o（N）

////1 2 3
////4 5 6
////7 8 9
//int main()
//{
//	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };		// N - 查找的次数最坏的情况下是N次，2N 3N
//	// N*N   N*(N-1)  --  o(N^2)					o(1) -- 指的是不管N是几，遍历次数为常数次
//	// 查找一个数字，比如说找：7
//	//遍历的方法时间复杂度o(N^2)，不满足要求
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 3; j++)
//		{
//			if (arr[i][j] == 7)
//			{
//				;
//			}
//		}
//	}
//	return 0;
//}
//
//int find_num(int arr[3][3], int r, int c,int k)
//{
//	int i = 0;
//	int j = c - 1;
//	while (i < r && j >= 0)
//	{
//		if (arr[i][j] < k)
//		{
//			i++;
//		}
//		else if(arr[i][j]>k)
//		{
//			j--;
//		}
//		else
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//
//int find_num(int arr[3][3], int* pr, int* pc, int k)
//{
//	int i = 0;
//	int j = *pc - 1;
//	while (i < *pr && j >= 0)
//	{
//		if (arr[i][j] < k)
//		{
//			i++;
//		}
//		else if (arr[i][j] > k)
//		{
//			j--;
//		}
//		else
//		{
//			*pr = i;
//			*pc = j;
//			return 1;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
//	int k = 7;
//	//如果找到了，返回1，没找到返回0；
//	int i = 3;
//	int j = 3;
//
//	int ret = find_num(arr, &i, &j, k);
//	if (ret == 1)
//	{
//		printf("找到了\n");
//		printf("元素下标是：%d %d\n", i, j);
//	}
//	else
//	{
//		printf("找不到\n");
//	}
//	return 0;
//}


//数组
//字符串
//数据结构

// 方法一
//void left_rotate(char arr[], int k)
//{
//	int sz = strlen(arr);
//	k %= sz;
//	while (k--)
//	{
//		int tmp = arr[0];
//		int i = 0;
//		for (i = 0; i < sz - 1; i++)
//		{
//			arr[i] = arr[i + 1];
//		}
//		arr[i] = tmp;
//	}
//}

// 方法二		三步翻转法
//#include <assert.h>
//void reverse(char* left, char* right)
//{
//	assert(left && right);
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//
//void left_rotate(char arr[], int k)
//{
//	int sz = strlen(arr);
//	k %= sz;
//	// 1. 先整体逆序
//	reverse(arr, arr + k - 1);
//	reverse(arr + k, arr + sz - 1);
//	reverse(arr, arr + sz - 1);
//}
//
//int main()
//{
//	char arr[] = "abcdef";	// cdefab
//	int k = 0;
//	scanf("%d", &k);
//	left_rotate(arr, k);
//	printf("%s\n", arr);
//
//	return 0;
//}



//作业		字符串左旋
//题目内容：实现一个函数，可以左旋字符串中的k个字符。
//例如：ABCD左旋一个字符得到BCDA
//		ABCD左旋两个字符得到CDAB
//void string_left_rotate1(char* str, int k)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < k; i++)
//	{
//		int j = 0;
//		char tmp = str[j];
//		for (j = 0; j < strlen(str)-1; j++)
//		{
//			str[j] = str[j + 1];
//		}
//		str[j] = tmp;
//	}
//}
////方法二		三步翻转法
//#include<assert.h>
//void reverse(char* left, char* right)
//{
//	assert(left);
//	assert(right);
//	while(left<right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//void string_left_rotate2(char* str, int k)
//{
//	assert(str);
//	int sz = strlen(str);
//	reverse(str, str + k - 1);				//左边逆序
//	reverse(str + k, str + sz - 1);			//右边逆序
//	reverse(str, str + sz - 1);				//整体逆序
//}
//int main()
//{
//	char arr[10] = "ABCDEF";
//	int k = 4;
//	string_left_rotate1(arr, k);
//	printf("%s\n", arr);
//
//	string_left_rotate2(arr, k);
//	printf("%s\n", arr);
//
//	return 0;
//}


//作业
//写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1=AABCD和s2=BCDAA，返回1
//		给定s1=abcd 和s2=ACBD， 返回0
//#include<assert.h>
//#include<stdlib.h>
//int is_string_rotate(char* str1, char* str2)
//{
//	assert(str1);
//	assert(str2);
//	int sz = strlen(str1);
//	
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < sz; i++)
//	{
//		int j = 0;
//		char tmp = str1[j];
//		for (j = 0; j < sz-1; j++)
//		{
//			str1[j] = str1[j + 1];
//		}
//		str1[j] = tmp;
//		if (strcmp(str1 , str2)==0)
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//
//int main()
//{
//	char arr1[] = "AABCD";
//	char arr2[] = "BCDAA";
//	int ret = is_string_rotate(arr1, arr2);
//	if (ret == 1)
//	{
//		printf("yes\n");
//	}
//	else
//	{
//		printf("no\n");
//	}
//
//	return 0;
//}


//int main()
//{
//	char arr[20] = "hello ";
//	strcat(arr, "world");			//strcat 能在一个字符串的后面追加另一段字符串
//	printf("%s\n", arr);
//	//strcat(arr, arr);				//这个函数不能自己后面追加自己
//	strncat(arr, arr, 5);			//这个函数可以后面追加自己，第三个参数是追加几位
//	printf("%s\n", arr);
//	return 0;
//}

//于是上上面的代码改进为：
//#include<assert.h>
//#include<stdlib.h>
//#include<string.h>
//int is_string_rotate(char* str1, char* str2)
//{
//	assert(str1);
//	assert(str2);
//
//	// 长度不相等，肯定不是旋转得到
//	if (strlen(str1) != strlen(str2))
//	{
//		return 0;
//	}
//	// 1. str1字符串的后面追加一个str1
//	int sz = strlen(str1);
//	strncat(str1, str1, sz);			// 将str1字符串后面再追加一串str1内容
//	// printf("%s\n", str1);
//	// 2. 判断str2是否为str1的字串
//	char* ret = strstr(str1, str2);		// 如果是字串，返回地址，如果不是，返回空指针
//	/*if (ret == NULL)
//	{
//		return 0;
//	}
//	else
//	{
//		return 1;
//	}*/
//	//或者，上面的判断语句写成：
//
//	return ret != NULL;
//}
//int main()
//{
//	char arr1[20] = "AABCD";
//	char arr2[] = "BCDAA";
//	int ret = is_string_rotate(arr1, arr2);
//	if (ret == 1)
//	{
//		printf("yes\n");
//	}
//	else
//	{
//		printf("no\n");
//	}
//
//	return 0;
//}


/*
指针
一级指针
二级指针

整型指针
字符指针

数组指针
函数指针
回调函数

*/

/*
数组
一维数组
二维数组

整型数组
字符数组

指针数组

*/

/*
指针运算：
解引用
指针+-整数
指针-指针
指针的关系运算

*/

/*
指针必须学好

数据结构：
CPP -> C实现简单的数据结构
指针+结构体+动态管理

*/

