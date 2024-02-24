#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<ctype.h>
#include<assert.h>


//P140-P143


//字符分类函数
/*
函数				如果他的参数符合下列条件就返回真
iscntrl				任何控制字符
isspace				空白字符：空格‘ ’，换页‘\f’，换行‘\n’，回车‘\r’，制表符‘\t’或者垂直制表符‘\v’
isdigit				十进制数字 0~9
isxdigit			十六进制数字，包括所有十进制数字，小写字母 a~f ，大写字母 A~F
islower				小写字母 a~z
isupper				大写字母 A~Z
isalpha				小写字母 a~z 或 A~Z
isalnum				字母或者数字，a~z ，A~Z ，0~9
ispunct				标点符号，任何不属于数字或者字母的图形字符（可打印）
isgraph				任何图形字符
isprint				任何可打印字符，包含图形字符和空白字符

*/

//#include <ctype.h>
//int main()
//{
//	int a = isspace(' ');
//	int b = isspace('w');
//	printf("%d\n", a);		// 8	非零
//	printf("%d\n", b);		// 0
//
//	// isdigit	如果是数字字符，返回非0的值（4），如果不是数字字符，返回0
//	int c = isdigit('3');
//	int d = isdigit('w');
//	printf("%d\n", c);		// 4	非零
//	printf("%d\n", d);		// 0
//
//	// islower	如果是小写字符，返回非0的值（2），如果不是小写字符，返回0
//	int ret = islower(ch);
//	printf("%d\n", ret);
//
//	char ch = 'a';
//	if (ch >= 'A' && ch <= 'Z')
//	{
//		// 这种判断是不是大写字符也可以
//	}
//
//	return 0;
//}



//字符转换函数
//int tolower (int c);
//int toupper (int c);

//int main()
//{
//	char arr[20] = { 0 };
//	scanf("%s", arr);
//
//	int i = 0;
//	while (arr[i] != '\0')
//	{
//		if (isupper(arr[i]))
//		{
//			arr[i] = tolower(arr[i]);
//			//printf("%c ", arr[i]);
//		}
//		printf("%c ", arr[i]);
//		i++;
//	}
//	printf("\n%s\n", arr);
//
//	return 0;
//}



//内存函数
//1.memcpy			内存拷贝
//2.memmove
//3.memmcmp
//4.memset


//memcpy		测试
void* memcpy(void* destination, const void* source, size_t num);		//void*		无具体类型，不挑类型

//int main()
//{
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[10] = { 0 };
//	// strcpy()			拷贝字符串的
//	// char* strcpy(char* dest,const char* src)
//	// strcpy 遇到 '\0' 就停止了
//
//	// 因此迫切需要内存拷贝，可以拷贝任何类型
//	memcpy(arr2, arr1, 20);
//
//	return 0;
//}

//memcpy	实现			memory copy
//memmove	可以处理内存重叠的情况
//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//	void* ret = dest;
//	assert(dest && src);
//
//	while(num--)
//	{
//		*(char*)dest = *(char*)src;		// (char*)	强制类型转换是一种临时状态
//		dest = (char*)dest + 1;			// 所以只能用这种方式
//		src = (char*)src + 1;
//	}
//	return ret;
//}
//
//int main()
//{
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[10] = { 0 };
//
//	//my_memcpy(arr2, arr1, 20);
//
//	//my_memcpy(arr1+2, arr1, 20);			//memcpy自己拷贝自己，如果有重叠的区域，会出现问题，
//	memmove(arr1+2, arr1, 20);				//memmove自己拷贝自己，如果有重叠的区域，能正常使用，
//
//	return 0;
//}

//int main()
//{
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	memmove(arr1+3, arr1, 20);
//
//	return 0;
//}

//// memmove	实现
//void* my_memmove(void* dest, const void* src, size_t num)
//{
//	void* ret = dest;
//	assert(dest && src);
//
//	if (dest < src)
//	{
//		// 前 --> 后
//		while (num--)
//		{
//			*(char*)dest = *(char*)src;		// (char*)	强制类型转换是一种临时状态
//			dest = (char*)dest + 1;			// 所以只能用这种方式
//			src = (char*)src + 1;
//		}
//	}
//	else
//	{
//		// 后 --> 前
//		while (num--)
//		{
//			*((char*)dest + num) = *((char*)src + num);
//		}
//	}
//	return ret;
//}
//
//int main()
//{
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[10] = { 0 };
//
//	//my_memcpy(arr2, arr1, 20);
//
//	//my_memcpy(arr1+2, arr1, 20);			// memcpy自己拷贝自己，如果有重叠的区域，会出现问题，
//	my_memmove(arr1 + 2, arr1, 20);			// memmove自己拷贝自己，如果有重叠的区域，能正常使用，
//
//	return 0;
//}

//memcpy - 只要实现了不重叠拷贝就可以了，而VS中的实现了既可以拷贝不重叠，也可以拷贝重叠内存



// memcmp			内存比较
// int memcmp(const void* ptr1, const void* ptr2, size_t num);
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8 };
//	int arr2[] = { 1,2,2 };
//
//	int ret = memcmp(arr1, arr2, 12);
//	// memcmp  和  strcmp 设计的很相似，相等返回 0 ，大于返回大于零的数字，小于返回小于零的数字
//
//	printf("%d\n", ret);
//
//	return 0;
//}

//// memcmp	模拟实现
//int my_memcmp(const void* ptr1, const void* ptr2, size_t num)
//{
//	char* p1 = (char*)ptr1;
//	char* p2 = (char*)ptr2;
//	while (num--)
//	{
//		if (*p1 != *p2)
//		{
//			return *p1 - *p2;
//		}
//		p1++;
//		p2++;
//	}
// 
//	return 0;
//}
//
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8 };
//	int arr2[] = { 1,2,2 };
//
//	int ret = my_memcmp(arr1, arr2, 12);
//	printf("%d\n", ret);
//
//	return 0;
//}

//memset			内存设置
//void* memset(void* ptr, int value, size_t num);		//将初始的ptr指向的内存块的num个单元，设置成value值
//int main()
//{
//	int arr[10] = { 0 };
//	memset(arr, 1, 20);			// memset 特点，以字节为单位设置内存的
//	return 0;
//}

////memset	模拟实现
//void* my_memset(void* ptr, int value, size_t num)
//{
//	assert(ptr);
//	char* ret = (char*)ptr;
//	while (num--)
//	{
//		*ret = (char)value;
//		ret++;
//	}
//	return ptr;
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	my_memset(arr, 1, 20);			// memset 特点，以字节为单位设置内存的
//
//	return 0;
//}