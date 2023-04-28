#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


//P144-P


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