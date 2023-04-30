#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


//P144-P155


//本章重点
//结构体
//	结构体类型的声明
//	结构体的自引用
//	结构体变量的定义和初始化
//	结构体内存对齐
//	结构体传参
//	结构体实现位段（位段的填充&可移植性）
//枚举
//	枚举类型的定义
//	枚举的优点
//	枚举的使用
//联合
//	联合类型的定义
//	联合的特点
//	联合大小的计算



//数组是一组相同类型的元素的集合
//结构体也是一些值的集合，结构的每个成员可以是不同类型

//结构的声明
//struct tag
//{
//	member - list;
//}variable - list;

//struct 是关键字， tag 是结构体的标签名 ，结合起来 struct tag 是结构体类型
//{member - list；} 里面放的是成员变量列表，variable - list变量列表


//生活中，对象是复杂的，比如书：
//书名，作者，出版社，定价，书号
//比如学生：名字，年龄，电话，性别，住址

//struct Book					//struct Book 是结构体类型
//{
//	char name[20];
//	int price;
//	char id[12];			//name，price，id 是结构体成员变量列表
//}b4,b5,b6;					//变量b4,b5,b6	和 main（）函数里面创建的b1，b2，b3一样，
							//但是区别在于b4,b5,b6是全局变量，b1，b2，b3是局部变量
//int main()
//{
//	struct Book b1;			//利用struct Book结构体类型创建变量b1，b2，b3
//	struct Book b2;			//b1，b2，b3是局部变量
//	struct Book b3;
//
//	return 0;
//}


//不完全声明
//匿名结构体类型
//struct						//可以不写标签名
//{
//	char c;
//	int i;
//	char ch;
//	double d;
//}s;							//通过结构体类型创建的全局变量来使用
//
//struct						//可以不写标签名
//{
//	char c;
//	int i;
//	char ch;
//	double d;
//}*ps;						//ps指针变量，指向结构体类型的地址
//
//int main()
//{
//	ps = &s;				//编译器会报错，虽然两个结构体一样，但是编译器任然会把这两个结构体当作是两个不同的结构体
//	return 0;
//}
//匿名结构体只能使用一次



//结构体的自引用			结构体里可以包含结构体
//struct A
//{
//	int i;
//	char c;
//};
//struct B
//{
//	char c;
//	struct A sa;			//一个结构体里可以包含另一个结构体
//	double d;
//};
//struct N
//{
//	int d;
//	struct N n;				//一个结构体里面不能包含自己，
//};

//数据结构
//数据在内存中存储的结构
//顺序表
//链表				数据域	指针域
//这两种统称线性数据结构
//树形：二叉树

//struct Node
//{
//	int d;
//	struct Node* next;		//一个结构体里面可以包含同类型指针，来达到自引用
//};




//结构体变量的定义和初始化
//struct S
//{
//	char c;
//	int i;
//}s1,s2;
//struct B
//{
//	double d;
//	struct S s;
//	char c;
//};
//
//int main()
//{
//	struct S s3 = { 'x',20 };
//	struct B sb = { 3.14,{"w",100},'q' };
//	//.
//	//->
//	printf("%lf %c %d %c\n", sb.d, sb.s.c, sb.s.i, sb.c);
//
//	return 0;
//}




//结构体内存对齐
//
//struct S
//{
//	int i;
//	char c;
//	double a;
//};
//struct S2
//{
//	char c1;
//	int i;
//	char c2;
//};
//struct S3
//{
//	char c1;
//	char c2;
//	int i;
//};
//struct S4
//{
//	double d;
//	char c;
//	int i;
//};
//struct S5
//{
//	char c1;
//	struct S4 s4;
//	double d;
//};
//int main()
//{
//	struct S s = { 0 };						//不完全初始化
//	printf("%d\n", sizeof(s));				//涉及结构体内存对齐的问题
//
//	struct S2 s2 = { 0 };
//	printf("%d\n", sizeof(s2));
//
//	struct S3 s3 = { 0 };
//	printf("%d\n", sizeof(s3));
//
//	struct S4 s4 = { 0 };
//	printf("%d\n", sizeof(s4));
//
//	struct S5 s5 = { 0 };
//	printf("%d\n", sizeof(s5));
//
//	return 0;
//}
//结构体的对齐规则：
//1.第一个成员在与结构体变量偏移量为0的地址处
//2.其他成员变量要对齐到某个数字（对齐数）的整数倍数的地址
//对齐数 = 编译器默认的一个对齐数 与 该成员大小的比较值
//VS中默认为8
//3.结构体总大小为最大对齐数（每个成员变量都有一个对齐数）的整数倍。
//4.如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数倍处，
//  结构体的整体大小就是所有最大对齐数（含嵌套结构体的对齐数）的整数倍

//1.结构体的第一个成员，放在结构体变量在内存中存储位置的0偏移处开始
//2.从第二个成员往后的所有成员，都放在一个对齐数（成员大小和默认对齐数的较小值）的整数的整数倍的地址处
//3.结构体的总大小是结构体的所有成员的对齐数中最大的那个对齐数的整数倍


//为什么存在内存对齐？
//大部分资料都是这么说的：
//1.平台原因（移植原因）：不是所有的硬件平台都能访问任意地址上的任意数据的；
//  某些硬件平台只能在某些地址处取某些特定类型的数据，否则抛出异常
//2.性能原因：数据结构（尤其是栈）应该尽可能地在自然边界上对齐。
//	原因在于，为了访问未对齐的内存，处理器需要作两次内存访问；而对齐的内存访问仅需要一次访问。

//总体来说：以空间换时间，虽然浪费了空间，但是节约了时间


//在设计结构体的时候，我们既要满足对齐，又要节省空间，应让占用空间小的成员尽量集中在一起




//修改默认对齐数
//默认对齐数是8
// 
//把默认对齐数改为2

//#pragma pack(2)				//把默认对齐数改为2
//struct S
//{
//	char c1;
//	int i;
//	char c2;
//};
//#pragma pack()				//把默认对齐数又改回来
//int main()
//{
//
//	printf("%d\n", sizeof(struct S));
//
//	return 0;
//}



//作业	offsetof	宏
//#include<stddef.h>
//struct S
//{
//	char c1;
//	int i;
//	char c2;
//};
//int main()
//{
//	printf("%d\n", offsetof(struct S, c1));			//offsetof() --> #include<stddef.h>
//	printf("%d\n", offsetof(struct S, i));
//	printf("%d\n", offsetof(struct S, c2));
//	return 0;
//}



//结构体传参
//struct S
//{
//	int data[1000];
//	int num;
//};
////结构体传参
//void print1(struct S s)					//改变这里面的参数，不会改变源参数
//{
//	printf("%d\n", s.num);
//}
////结构体地址传参
//void print2(struct S* ps)				//效率高，节省空间
//{
//	printf("%d\n", ps->num);
//}
//int main()
//{
//	struct S s = { {1,2,3,4},1000 };
//	print1(s);
//	print2(&s);
//	//printf("%d\n", sizeof(struct S));
//	return 0;
//}




//位段
//位段的声明和结构体是类似的，有两个不同：
//1.位段的成员必须是 int、unsigned int 或signed int		char
//2.位段的成员名后边有一个冒号和一个数字

//struct A
//{
//	//4个字节 - 32bit
//	int _a : 2;			//_a	占2个比特位
//	int _b : 5;			//_b	占5个比特位
//	int _c : 10;		//_c	占10个比特位
//	//4个字节 - 32bit
//	int _d : 30;		//_d	占30个比特位
//};
//int main()
//{
//	printf("%d", sizeof(struct A));			//2+5+10+30=47bit
//	return 0;
//}
//位段的内存分配
//1.位段的成员可以是int、 unsigned int、 signed int 或者char（属于整型家族）类型
//2.位段的空间上是按照需要以4个字节（int）或者1个字节（char）的方式来开辟的。
//3.位段涉及很多不确定因素，位段是不跨平台的，注重可移植性的程序应该避免使用位段。

//struct S
//{
//	char a : 3;
//	char b : 4;
//	char c : 5;
//	char d : 4;
//};
//int main()
//{
//	struct S s = { 0 };
//	s.a = 10;					//10 --> 1010	截取010放到开辟的一个新字节	-->	00000010
//	s.b = 12;					//12 --> 1100	上一个字节还能放得下，直接放进去 --> 01100010 -->6进制 --> 6 2
//								//一个字节内部从高位往地位放置
//	s.c = 3;					//3 --> 00011	上一个字节只剩1位，放不下，开辟一个新字节 -->00000011 -->16进制--> 0 3
//	s.d = 4;					//4 --> 0100	上一个字节只剩3位，放不下，开辟一个新字节 -->00000100 -->16进制--> 0 4
//								//最后存在内存中的是	01100010	00000011	00000100
//								//			16进制数为	6	2		0	3		0	4
//	//大小端讨论的是字节的顺序
//	printf("%d", sizeof(struct S));
//
//	return 0;
//}
//位段的跨平台问题
//1.int 位段被当作有符号数还是无符号数是不确定的。
//2.位段中最大位的数目不能确定。（16位机器最大16位，32位机器最大32，写成27，在16位机器会出问题。）
//3.位段中的成员在内存中从左向右分配，还是从右向左分配标准尚未定义
//4.当一个结构包含两个位段，第二个位段成员比较大，无法容纳于第一个位段剩余的位时，是舍弃剩余位还是利用，这是不确定的。

//总结：跟结构相比，位段可以达到同样的效果，但是可以很好的节省空间，但是有跨平台的问题存在。

//位段的应用




//枚举				顾名思义，一一列举

//声明枚举类型
//enum Color
//{
//	RED=5,			//这里赋初值，下面就会默认递增1.不赋初值，就会从0开始
//	GREEN,
//	BLUE			//枚举类型的可能取值，常量
//};
//#define RED 5
//#define GREEN 8
//#define BLUE 9
//int main()
//{
//	enum Cplor c = BLUE;
//
//	printf("%d\n", RED);
//	printf("%d\n", GREEN);
//	printf("%d\n", BLUE);
//	return 0;
//}
//枚举的优点
//我们可以使用#define定义常量，为什么非要使用枚举？枚举优点：
//1.增加代码的可读性和可维护性
//2.和#define定义的标识符比较，枚举有类型检查，更加严谨。
//3.防止了命名污染（封装）
//4.便于调试
//5.使用方便，一次可以定义多个常量


//void menu()
//{
//	printf("****************************\n");
//	printf("****	1.add	2.sub	****\n");
//	printf("****	3.mul	4.div	****\n");
//	printf("****		0.exit		****\n");
//	printf("****************************\n");
//}
////枚举类型就是一种类型
//enum Option
//{
//	EXIT,		//0
//	ADD,		//1
//	SUB,		//2
//	MUL,		//3
//	DIV			//4
//};
//int main()
//{
//	int input = 0;
//	do {
//		menu();
//		printf("请选择：\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case ADD:				//ADD	替换掉	1		增加程序的可读性
//			break;
//		case SUB:
//			break;
//		case MUL:
//			break;
//		case DIV:
//			break;
//		}
//	} while (input);
//	return 0;
//}




//联合体（共用体）
//联合体也是一种特殊的自定义类型
//这种类型定义的变量也包含一系列的成员，特征是这些成员公用同一块空间（所以联合也叫共用体）

//定义联合体	关键字		union
//union Un				//联合体类型的定义
//{
//	char c;
//	int i;
//};
//int main()
//{
//	union Un u = { 10 };			//创建联合体类型的变量
//
//	printf("%d\n", sizeof(u));		//占4个字节
//	printf("%p\n", &u);
//	printf("%p\n", &(u.c));
//	printf("%p\n", &(u.i));
//
//	return 0;
//}
//联合体特点
//联合体的成员是共用同一块内存空间的，
//这样一个联合体变量的大小，至少是最大成员的大小（因为联合体至少得有能力保存最大的那个成员）



//一般方法		判断大端小端
//int check_sys()
//{
//	int a = 1;
//	if ((*(char*)&a) == 1)
//	{
//		return 1;			//小端
//	}
//	else
//	{
//		return 0;			//大端
//	}
//}
//使用联合体方法
//int check_sys()
//{
//	union U
//	{
//		char c;
//		int i;
//	}u;
//	u.i = 1;
//	return u.c;
//	//返回1 就是小端
//	//返回0 就是大端
//}
//int main()
//{
//	int ret = check_sys();
//	if (ret == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//
//	return 0;
//}



//联合体大小的计算
//union Un
//{
//	char a[5];
//	int i;
//};
//int main()
//{
//	union Un u;
//	printf("%d\n", sizeof(u));
//	
//	return 0;
//}
//联合的大小至少是最大成员的大小
//当最大成员大小不是最大对齐数的整数倍的时候，就要对齐到最大对齐数的整数倍