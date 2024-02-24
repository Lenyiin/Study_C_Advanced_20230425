#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>


//P172-P


//本章重点
//1.程序的翻译环境
//2.程序的执行环境
//3.详解：C语言程序的编译+链接
//4.预定义符号介绍
//5.预处理指令#define
//6.宏和函数的对比
//7.预处理操作符#和##的介绍
//8.命令定义
//9.预处理指令#include
//10.预处理指令#underf
//11.条件编译


//1.程序的翻译环境
//1.1预处理阶段完成了头文件的包含#include、#define定义的符号和宏的替换、注释删除		- 文本操作
//1.2编译阶段，把C语言代码转化成汇编代码。1.语法分析，2.词法分析，3.语义分析，4.符号汇总。
//1.3汇编阶段，把汇编代码转换成了机器指令（二进制指令）。1.生成符号表，readelf工具能看懂
//1.4连接阶段，把多个目标文件和链接库进行链接。1.合并段表，2.符号表的合并和重定位


//Linux	- 操作系统
//vim	- 编辑器 - 非常强大
//gcc	- 编译器


//2.3运行环境
//程序执行的过程：1.程序必须载入内存中。在有操作系统的环境中：一般这个由操作系统完成。
//					在独立的环境中，程序的载入必须由手工安排，也可能是通过可执行代码置入只读内存来完成。
//				  2.程序执行便开始。接着调用main函数。
//				  3.开始执行程序代码。这个时候程序将使用一个运行时堆栈（stack），存储函数的局部变量和返回地址。
//					程序同时也可以使用静态（static）内存，存储于静态内存中的变量在程序的整个执行过程中一直保留它们的值。
//				  4.终止程序。正常终止main函数；也有可能是意外终止。

//《程序员的自我修养》



//3.预处理详解
//3.1 预定义符号
//		__FILE__			进行编译的源文件
//		__LINE__			文档当前的行号
//		__DATE__			文档被编译的日期
//		__TIME__			文档被编译的时间
//		__STDC__			如果编译器遵循ANSI C，其值为1，否则未定义
//		__FUNCTION__		当前进行编译的函数

//int main()
//{
//	printf("%s\n", __FILE__);
//	printf("%d\n", __LINE__);
//	printf("%s\n", __DATE__);
//	printf("%s\n", __TIME__);
//	printf("%s\n", __FUNCTION__);
//	//printf("%s\n", __STDC__);
//
//	int i = 0;
//	FILE* pf = fopen("log.txt", "a+");
//	if (pf == NULL)
//	{
//		perror("fopen\n");
//		return 1;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		fprintf(pf, "%s %d %s %s %d\n", __FILE__, __LINE__, __DATE__, __TIME__, i);
//	}
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//int main()
//{
//	printf("%s\n", __STDC__);
//
//	return 0;
//}

//3.2 #define
//3.2.1	#define定义标识符
//		#define是定义符号的
//3.2.2 #define定义宏			允许把参数替换到文本中
//		注意：参数列表的左括号必须与name紧邻。如果两者之间有任何空白存在，参数列表就会被解释为stuff的一部分
//3.2.3 #define替换规则
//		在程序中拓展#define定义符号和宏时，需要涉及几个步骤。
//		1.在调用宏时，首先对参数进行检查，看看是否包含任何有#define定义的符号。如果有，他们首先被替换。
//		2.替换文本随后被插入到程序中原来文本的位置。对于宏，参数名被他们的值替换。
//		3.最后，再次对结果文件进行扫描，看看他们是否包含任何由#define定义的符号。如果有，就重复上述处理过程。
//		注意：	1.宏参数和#define定义中可以出现其他#define定义的变量。但对于宏，不能出现递归。
//				2.当预处理器搜索#define定义的符号的时候，字符串常量的内容并不被搜索
//3.2.4 #和##					可以把参数插入到字符串中
//		使用#，把一个宏参数变成对应的字符串
//		##可以把位于它两边的符号合成一个符合，它允许宏定义从分离的文本片段创建标识符。
//3.2.5 带副作用的宏参数
//		当宏参数在宏定义中出现超过一次的时候，如果参数带有副作用，那么你在使用这个宏的时候就可能出现危险，导致不可预测的后果。
//		副作用就是表达式求值的时候出现永久性效果。
//3.2.6 宏和函数的对比
//		宏通常被应用于执行简单的运算。比如在两个数中找出较大的一个。
//	为什么不用函数来完成这个任务？
//		1.	用于调用函数和从函数返回的代码可能比实际执行这个小型计算工作所需的时间更多。所以宏比函数在程序的规模和速度方面更胜一筹。
//		2.	更重要的是函数的参数必须申明成特定的类型。所以函数只能在类型合适的表达式上使用。
//			反之，这个宏则可适用于整型、长整型、浮点型等可以用于>来比较的类型。宏是类型无关的。
//	宏相比函数的劣势的地方
//		1.	每次使用宏的时候，一份宏定义的代码将插入到程序中。除非宏比较短，否则可能大幅度增加程序的长度。
//		2.	宏是没法调试的
//		3.	宏由于类型无关，也就不够严谨
//		4.	宏可能会带来运算符优先级的问题，导致程序容易出错。
//		宏有时候可以做到函数做不到的事情。比如：宏的参数可以出现类型，但是函数做不到。
//	命名约定
//		一般来讲，函数和宏的使用语法很相似。所以语言本身没法帮我们区分二者。那我们平时的一个习惯是：
//			把宏名全部大写
//			函数名不要全部大写



//#define M 1000
//#define reg register			//将register 定义成reg
//#define do_forever for(;;)		//定义一个死循环
//#define CASE break;case
//#define STR "hello world"
//#define print printf("你好")	// 也不建议加分号
//
//int main()
//{
//	reg int num = 0;
//	int m = M;
//	printf("%d\n", m);
//
//	printf("%s\n", STR);
//
//	print;
//
//	//do_forever;
//
//	int n = 0;
//	switch (n)
//	{
//	case 1 :
//	CASE 2 :
//	CASE 3 : ;
//	}
//
//	return 0;
//}

//#define 定义宏
//#define SQUARE(X) X*X				// 为了严谨起见，应将宏写成	#define SQUARE(X) （（X）*（X））
//int main()
//{
//	printf("%d\n", SQUARE(3));		// 这段代码会被替换成	printf("%d\n", 3*3);
//
//	printf("%d\n", SQUARE(3+1));	// 这段代码会被替换成	printf("%d\n", 3+1*3+1);	结果是7
//
//	return 0;
//}
// 宏的参数是不经过任何计算，直接就传进去了

//#define SQUARE(X) ((X)*(X))
//#define DOUBLE(X) (X)+(X)			// 为了严谨起见，应将宏写成	#define DOUBLE(X) （(X)+(X)）
//int main()
//{
//	printf("%d\n", 10*DOUBLE(4));	// 这段代码会被替换成	printf("%d\n", 10*(4+4));	结果是44
//
//	printf("%d\n", SQUARE(3 + 1));	// 这段代码会被替换成	printf("%d\n", (3+1)*(3+1));结果是16
//
//	return 0;
//}


//#define M 100
//#define MAX(X,Y) ((X)>(Y)?(X):(Y))
//int main()
//{
//	int max = MAX(99, M);
//	printf("%d\n", max);
//
//	return 0;
//}

//// 在X前面加上#，X的参数不会替换成他本身，而是会转换成她所对应的字符串
//#define PRINT(X,FORMAT) printf("the value of "#X" is "FORMAT"\n",X)
//
//int main()
//{
//	printf("hello world\n");
//	printf("hello " "world\n");	// 写法不同，但是这两个“”引号的字符串会天然连接到一起
//
//	int a = 10;
//	PRINT(a,"%d");				// 这段代码会被替换成	printf("the value of "“a”" is %d\n",a)
//
//	int b = 20;
//	PRINT(b, "%d");
//	int c = 30;
//	PRINT(c, "%d");
//
//	float d = 5.5;
//	PRINT(d, "%f");
//
//	return 0;
//}

//#define CAT(X,Y) X##Y
//int main()
//{
//	int class101 = 100;
//	printf("%d\n", CAT(class, 101));	// 这段代码会被替换成		printf("%d\n",  class101);
//										// ## 相当于把两个符号连接在一起
//
//	return 0;
//}


//// 带副作用的宏参数
//#define MAX(X,Y) ((X)>(Y)?(X):(Y))
//int main()
//{
//	int a = 5;	// 6 7
//	int b = 4;	// 5
//	int m = MAX(a++, b++);
//	// 这段代码会被替换成	int m = ((a++)>(b++)?(a++):(b++));
//	//							6		5 > 4	？ 6
//
//	printf("m=%d\n", m);		// 6
//	printf("a=%d b=%d\n", a,b);	// 7 5
//
//	return 0;
//}



//#define MALLOC(num,type) (type*)malloc(num*sizeof(type))
//int main()
//{
//	int* p = MALLOC(10, int);	// 这单代码会被替换成	int* p = (int*)malloc(10 * sizeof(int));
//
//	return 0;
//}


//内联函数	inline		结合了宏的优点，和函数的优点





//3.3 #undef		这条指令用于移除一个宏定义

//#define M 100
//int main()
//{
//	int a = M;
//
//	printf("%d\n", M);
//#undef M						//取消宏定义
//	return 0;
//}




//3.4 命令行定义
//		许多C的编译器提供了一种能力，允许在命令行中定义符号。用于启动编译过程。

//3.5 条件编译
//		在编译一个程序的时候，我们如果要将一条语句（一组语句）编译或者放弃是很方便的。因为我们有条件编译指令。

//#define PRINT		// 定义了这个，下面条件就为真，就会被编译，没定义，下面的条件就为假，就不会被编译
//int main()
//{
//
//#ifdef PRINT
//	printf("hehe\n");
//#endif
//
//#ifdef 1			// 1为真，就会被编译，0为假，就不会被编译
//	printf("hehe\n");
//#endif
//
//	return 0;
//}

//#define __DEBUG__
//int main()
//{
//	int i = 0;
//	int arr[10] = { 0 };
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//#ifdef __DEBUG__
//		printf("%d ", arr[i]);
//#endif
//	}
//
//	return 0;
//}

//#define __DEBUG__ 1
//int main()
//{
//#if __DEBUG__			// 1为真，就会被编译，0为假，就不会被编译
//	printf("hehe");
//#endif
//
//	return 0;
//}

//// 多分支的条件编译
//int main()
//{
//
//#if 1==1					//如果这里为真，执行完这里直接就结束了，下面代码即使为真也不会执行
//	printf("hehe\n");
//#elif 2==2					//如果上面代码为假，则会执行这里
//	printf("haha\n");
//#else						//如果上面都为假才会执行这里
//	printf("heihei\n");
//#endif
//
//	return 0;
//}


//// 判断是否被定义
//#define TEST
//#define HEHE
//
//int main()
//{
//	// 如果TEST定义了，下面参与编译
//#ifdef TEST
//	printf("test1\n");
//#endif
//
//#if defined(TEST)		// 这个和上面那种写法作用相同
//	printf("test2\n");
//#endif
//
//
//	// 如果HEHE不定义，下面参与编译
//#ifndef HEHE
//	printf("hehe1\n");
//#endif
//
//#if !defined(HEHE)		// 这个和上面那种写法作用相同
//	printf("hehe2\n");
//#endif
//
//	return 0;
//}

//// 嵌套指令
//#if defined(OS_UNIX)
//	#ifdef OPTION1
//		unix_version_option1();
//	#endif
//	#ifdef OPTION2
//		unix_version_option2();
//	#endif
//#elif defined(OS_MSDOS)
//	#ifdef OPTION3
//		unix_version_option3();
//	#endif
//#endif


//3.6 文件包含
//		我们已经知道，#include指令可以使另外一个文件被编译。就像它实际出现于#include指令的地方一样。
//		这种替换方式很简单：预处理器先删除这条指令，并用包含文件的内容替换。
//							这样一个源文件被包含10次，那实际被编译10次。

#include<stdlib.h>		//库文件的包含		C语言库中提供的函数的头文件，使用	<	>
#include"test.h"		//本地文件的包含	自定义的函数头文件，使用	“	”

// < > 和“”查找策略的区别：
//		“”先在源文件所在目录下查找，如果该头文件未找到，编译器就像查找库函数头文件一样在标准位置查找头文件。如果找不到就提示编译错误
//		< > 直接去库函数头文件所在的目录下查找


#pragma once			//防止头文件重复包含




//4 其他预处理指令
//#include<stddef.h>
//#define OFFSETOF(struct_name,mem_name) (size_t)&(((struct_name*)0)->mem_name)
//struct A
//{
//	char c1;
//	int i;
//	char c2;
//};
//int main()
//{
//	printf("%d\n", OFFSETOF(struct A, c1));
//	printf("%d\n", OFFSETOF(struct A, i));
//	printf("%d\n", OFFSETOF(struct A, c2));
//
//	return 0;
//}


//struct A
//{
//	char c1;
//	int i;
//	char c2;
//};
//int main()
//{
//	printf("%d\n", offsetof(struct A, c1));
//	printf("%d\n", offsetof(struct A, i));
//	printf("%d\n", offsetof(struct A, c2));
//
//	return 0;
//}



//// 作业		对齐数设置为4
//#pragma pack(4)
//struct A
//{
//	int a;
//	short b;
//	int c;
//	char d;
//};
//struct B
//{
//	int a;
//	short b;
//	char c;
//	int d;
//};
//int main()
//{
//	struct A sa = { 0 };
//	struct B sb = { 0 };
//	printf("%d\n", sizeof(sa));
//	printf("%d\n", sizeof(sb));
//
//	return 0;
//}
//#pragma pack()



//作业			atoi		测试
//int main()
//{
//	char* p = "1234";
//	int ret = atoi(p);		// 将字符串转化成一个整型
//	printf("%d\n", ret);
//	return 0;
//}

//// atoi 实现
//#include<ctype.h>
//#include<limits.h>
//
//enum State
//{
//	INVALID,		// 0
//	VALID			// 1
//};
//// state 记录的是 my_stoi 返回的值是合法转化的值，还是非法的状态
//enum State state = INVALID;
//
//int my_atoi(const char* s)
//{
//	int flag = 1;
//	// 空指针的问题
//	if (NULL == s)
//	{
//		return 0;
//	}
//	// 空字符串问题
//	if (*s == '\0')
//	{
//		return 0;
//	}
//	// 跳过空白字符
//	while (isspace(*s))		// isspace		#include<ctype.h>
//	{
//		s++;
//	}
//	//	+/-
//	if (*s == '+')
//	{
//		flag = 1;
//		s++;
//	}
//	else if (*s == '-')
//	{
//		flag = -1;
//		s++;
//	}
//	// 处理数字字符的转换
//	long long n = 0;
//	while (isdigit(*s))
//	{
//		n = n * 10 + flag * (*s - '0');
//		if (n > INT_MAX || n < INT_MIN)		// #include<limits.h>
//		{
//			return 0;
//		}
//		s++;
//	}
//	if (*s == '\0')
//	{
//		state = VALID;
//		return (int)n;
//	}
//	else
//	{
//		// 非数字字符的情况
//		return (int)n;
//	}
//}
//
//int main()
//{
//	// 1.空指针
//	// 2.空字符串
//	// 3.非数字字符
//	// 4.超出范围
//
//	const char* p = "    -1234";
//	int ret = my_atoi(p);
//	if (state == VALID)
//	{
//		printf("正常的转换：%d\n", ret);
//	}
//	else
//	{
//		printf("非法的转换：%d\n", ret);
//	}
//
//	return 0;
//}



//作业
//一个数组中只有两个数字是出现一次，其他所有数字都出现了两次
//编写一个函数找出这两个只出现一次的数字
//1 2 3 4 5 6 1 2 3 4

//void Find(int arr[], int sz, int* x, int* y)
//{
//	// 1.要把所有数字异或
//	int i = 0;
//	int ret = 0;
//	for (i = 0; i < sz; i++)
//	{
//		ret ^= arr[i];
//	}
//	// 2.计算ret的哪一位为1
//	// ret=3		011
//	int pos = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if (((ret >> i) & 1) == 1)
//		{
//			pos = i;
//			break;
//		}
//	}
//	// 把从低位到高位的第pos位为1，为0的放在另一组
//	int num1 = 0;
//	int num2 = 0;
//	for (i = 0; i < sz; i++)
//	{
//		if (((arr[i] >> pos) & 1) == 1)
//		{
//			num1 ^= arr[i];
//		}
//		else
//		{
//			num2 ^= arr[i];
//		}
//	}
//	*x = num1;
//	*y = num2;
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,1,2,3,4 };
//	// 找出这两个只出现一次的数字
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int x = 0;
//	int y = 0;
//	Find(arr, sz, &x, &y);
//	printf("%d %d\n", x, y);
//
//	return 0;
//}


//#define INT_PTR int*
//typedef int* int_ptr;
//
//INT_PTR a, b;		// a 的类型是 int*，b 的类型是 int
//int_ptr a, b;		// a b 的类型都是 int*



//头文件的包含
//类型的定义
//函数的申明



//作业
//// 写一个宏，可以将一个整数的二进制位的奇数位和偶数位交换
//#define SWAP(N) (((N & 0xaaaaaaaa) >> 1) + ((N & 0x55555555) << 1))
//
//int main()
//{
//	int num = 10;
//
//	int ret = SWAP(num);
//	printf("%d\n", ret);
//
//	return 0;
//}



//作业
//写一个宏,计算结构体中某变量相对首地址的偏移，并给出说明。
// offsetof	测试
//#include<stddef.h>
//struct A
//{
//	int a;
//	short b;
//	int c;
//	char d;
//};
//int main()
//{
//	printf("%d\n", offsetof(struct A, a));
//	printf("%d\n", offsetof(struct A, b));
//	printf("%d\n", offsetof(struct A, c));
//	printf("%d\n", offsetof(struct A, d));
//
//	return 0;
//}


//offsetof 实现
#define OFFSETOF(struct_name,mem_name) (int)&(((struct_name*)0)->mem_name)
//struct A
//{
//	int a;
//	short b;
//	int c;
//	char d;
//};
//int main()
//{
//	printf("%d\n", OFFSETOF(struct A, a));
//	printf("%d\n", OFFSETOF(struct A, b));
//	printf("%d\n", OFFSETOF(struct A, c));
//	printf("%d\n", OFFSETOF(struct A, d));
//	return 0;
//}
