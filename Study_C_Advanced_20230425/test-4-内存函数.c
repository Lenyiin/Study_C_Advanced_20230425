#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<ctype.h>
#include<assert.h>


//P140-P143


//�ַ����ຯ��
/*
����				������Ĳ����������������ͷ�����
iscntrl				�κο����ַ�
isspace				�հ��ַ����ո� ������ҳ��\f�������С�\n�����س���\r�����Ʊ����\t�����ߴ�ֱ�Ʊ����\v��
isdigit				ʮ�������� 0~9
isxdigit			ʮ���������֣���������ʮ�������֣�Сд��ĸ a~f ����д��ĸ A~F
islower				Сд��ĸ a~z
isupper				��д��ĸ A~Z
isalpha				Сд��ĸ a~z �� A~Z
isalnum				��ĸ�������֣�a~z ��A~Z ��0~9
ispunct				�����ţ��κβ��������ֻ�����ĸ��ͼ���ַ����ɴ�ӡ��
isgraph				�κ�ͼ���ַ�
isprint				�κοɴ�ӡ�ַ�������ͼ���ַ��Ϳհ��ַ�

*/

//#include <ctype.h>
//int main()
//{
//	int a = isspace(' ');
//	int b = isspace('w');
//	printf("%d\n", a);		// 8	����
//	printf("%d\n", b);		// 0
//
//	// isdigit	����������ַ������ط�0��ֵ��4����������������ַ�������0
//	int c = isdigit('3');
//	int d = isdigit('w');
//	printf("%d\n", c);		// 4	����
//	printf("%d\n", d);		// 0
//
//	// islower	�����Сд�ַ������ط�0��ֵ��2�����������Сд�ַ�������0
//	int ret = islower(ch);
//	printf("%d\n", ret);
//
//	char ch = 'a';
//	if (ch >= 'A' && ch <= 'Z')
//	{
//		// �����ж��ǲ��Ǵ�д�ַ�Ҳ����
//	}
//
//	return 0;
//}



//�ַ�ת������
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



//�ڴ溯��
//1.memcpy			�ڴ濽��
//2.memmove
//3.memmcmp
//4.memset


//memcpy		����
void* memcpy(void* destination, const void* source, size_t num);		//void*		�޾������ͣ���������

//int main()
//{
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[10] = { 0 };
//	// strcpy()			�����ַ�����
//	// char* strcpy(char* dest,const char* src)
//	// strcpy ���� '\0' ��ֹͣ��
//
//	// ���������Ҫ�ڴ濽�������Կ����κ�����
//	memcpy(arr2, arr1, 20);
//
//	return 0;
//}

//memcpy	ʵ��			memory copy
//memmove	���Դ����ڴ��ص������
//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//	void* ret = dest;
//	assert(dest && src);
//
//	while(num--)
//	{
//		*(char*)dest = *(char*)src;		// (char*)	ǿ������ת����һ����ʱ״̬
//		dest = (char*)dest + 1;			// ����ֻ�������ַ�ʽ
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
//	//my_memcpy(arr1+2, arr1, 20);			//memcpy�Լ������Լ���������ص������򣬻�������⣬
//	memmove(arr1+2, arr1, 20);				//memmove�Լ������Լ���������ص�������������ʹ�ã�
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

//// memmove	ʵ��
//void* my_memmove(void* dest, const void* src, size_t num)
//{
//	void* ret = dest;
//	assert(dest && src);
//
//	if (dest < src)
//	{
//		// ǰ --> ��
//		while (num--)
//		{
//			*(char*)dest = *(char*)src;		// (char*)	ǿ������ת����һ����ʱ״̬
//			dest = (char*)dest + 1;			// ����ֻ�������ַ�ʽ
//			src = (char*)src + 1;
//		}
//	}
//	else
//	{
//		// �� --> ǰ
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
//	//my_memcpy(arr1+2, arr1, 20);			// memcpy�Լ������Լ���������ص������򣬻�������⣬
//	my_memmove(arr1 + 2, arr1, 20);			// memmove�Լ������Լ���������ص�������������ʹ�ã�
//
//	return 0;
//}

//memcpy - ֻҪʵ���˲��ص������Ϳ����ˣ���VS�е�ʵ���˼ȿ��Կ������ص���Ҳ���Կ����ص��ڴ�



// memcmp			�ڴ�Ƚ�
// int memcmp(const void* ptr1, const void* ptr2, size_t num);
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8 };
//	int arr2[] = { 1,2,2 };
//
//	int ret = memcmp(arr1, arr2, 12);
//	// memcmp  ��  strcmp ��Ƶĺ����ƣ���ȷ��� 0 �����ڷ��ش���������֣�С�ڷ���С���������
//
//	printf("%d\n", ret);
//
//	return 0;
//}

//// memcmp	ģ��ʵ��
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

//memset			�ڴ�����
//void* memset(void* ptr, int value, size_t num);		//����ʼ��ptrָ����ڴ���num����Ԫ�����ó�valueֵ
//int main()
//{
//	int arr[10] = { 0 };
//	memset(arr, 1, 20);			// memset �ص㣬���ֽ�Ϊ��λ�����ڴ��
//	return 0;
//}

////memset	ģ��ʵ��
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
//	my_memset(arr, 1, 20);			// memset �ص㣬���ֽ�Ϊ��λ�����ڴ��
//
//	return 0;
//}