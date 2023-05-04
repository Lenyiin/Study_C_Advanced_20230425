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


//#define M 1000
//#define reg register			//将register 定义成reg
//#define do_forever for(;;)		//定义一个死循环
//#define CASE break;case
//
//int main()
//{
//	reg int num = 0;
//	int m = M;
//	printf("%d\n", m);
//
//	do_forever;
//
//	int n = 0;
//	switch (n)
//	{
//	case 1:
//	CASE 2:
//	CASE 3:
//	}
//
//	return 0;
//}

//#define 定义宏
//#define SQUARE(X) X*X						//为了严谨起见，应将宏写成	#define SQUARE(X) （（X）*（X））
//int main()
//{
//	printf("%d\n", SQUARE(3));				//这段代码会被替换成	printf("%d\n", 3*3);
//
//	printf("%d\n", SQUARE(3+1));			//这段代码会被替换成	printf("%d\n", 3+1*3+1);	结果是7
//
//	return 0;
//}
//宏的参数是不仅过任何计算，直接就传进去了

//#define DOUBLE(X) (X)+(X)					////为了严谨起见，应将宏写成	#define DOUBLE(X) （(X)+(X)）
//int main()
//{
//	printf("%d\n", 10*DOUBLE(4));			//这段代码会被替换成	printf("%d\n", 10*4+4);		结果是44
//
//	printf("%d\n", SQUARE(3 + 1));			//这段代码会被替换成	printf("%d\n", 3+1*3+1);	结果是7
//
//	return 0;
//}


//#define M 100
//#define MAX(X,Y) ((X)>(Y)?(X):(Y))
//int main()
//{
//	int max = MAX(101, M);
//	return 0;
//}


//#define PRINT(X,FORMAT) printf("the value of "#X" is "FORMAT"\n",X)
//int main()
//{
//	printf("hello world\n");
//	printf("hello " "world\n");			//写法不同，但是这两个“”引号的字符串会天然连接到一起
//
//	int a = 10;
//	PRINT(a,"%d");							//这段代码会被替换成	printf("the value of "“a”" is %d\n",a)
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

#define CAT(X,Y) X##Y
int main()
{
	int class101 = 100;
	printf("%d\n", CAT(class, 101));			//这段代码会被替换成		printf("%d\n",  class101);			## 相当于把两个符号连接在一起

	return 0;
}