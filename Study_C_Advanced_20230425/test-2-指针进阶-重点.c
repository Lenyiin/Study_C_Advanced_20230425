#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//P106-P

//��������־���
//1.��������Ǵ���
//2.����������ڴ�
//3.�����뻹�Ǵ���


//ָ��Ľ���
// 1.�ַ�ָ��
// 2.����ָ��
// 3.ָ������
// 4.���鴫�κ�ָ�봫��
// 5.����ָ��
// 6.����ָ������
// 7.ָ����ָ�������ָ��
// 8.�ص�����
// 9.ָ�������������Ľ���


//ָ�����
//1.ָ����Ǹ�������������ŵ�ַ����ַΨһ��ʶһ���ڴ�ռ䡣
//2.ָ��Ĵ�С�ǹ̶���4/8�ֽڣ�32λƽ̨/64λƽ̨����
//3.ָ���������ͣ�ָ������;�����ָ���+-�����Ĳ�����ָ������ò�����ʱ���Ȩ�ޡ�
//4.ָ������㡣



//�ַ�ָ��
//int main()
//{
//	char ch = 'q';
//	char* pc = &ch;
//
//	char* ps = "hello world";			//���ָ�ֵ�������ǽ�"hello world"����ַ��������ַ��ĵ�ַ�洢����ps��
//	printf("%c\n", *ps);
//	//*ps = "w";						err	�����ַ������ܸ�
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
//	if (str1 == str2)								//str1��str2��������ͬ���飬����ڲ�ͬ�Ŀռ䣬��ַ��ͬ
//	{
//		printf("str1 and str2 are same\n");
//	}
//	else
//	{
//		printf("str1 and str2 are not same\n");
//	}
//	if (str3 == str4)								//str3��str4�ǳ����ַ�������Ķ���"hello world"�����ַ���ַ
//	{
//		printf("str3 and str4 are same\n");
//	}
//	else
//	{
//		printf("str3 and str4 are not same\n");
//	}
//	return 0;
//}



//ָ�����飺�����������飬���ָ�������
//int main()
//{
//	//���� - �����д�ŵ���ָ�루��ַ��
//	//int* arr[3];			//�������ָ�������
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
//	int* arr1[10];			//����ָ�������
//	char* arr2[4];			//һ���ַ�ָ�������
//	char** arr3[5];			//�����ַ�ָ�������
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
//			printf("%d ", arr[i][j]);			//����д��Ҳ����
//		}
//		printf("\n");
//	}
//	return 0;
//}



//����ָ�룺��һ��ָ�룬ָ�������ָ��
//����ָ�� - ��ָ�����͵�ָ��
//�ַ�ָ�� - ��ָ���ַ���ָ��
//int main()
//{
//	int a = 10;
//	int* p = &a;			//����ָ��
//
//	char ch = 'w';
//	char* pc = &ch;			//�ַ�ָ��
//
//	int arr[10] = { 1,2,3 };
//	//arr���������ַ�����Ԫ�ص�ַ - arr[0]�ĵ�ַ
//	//&arrȡ����������ĵ�ַ
//	int(*parr)[10] = &arr;
//	//parr ����һ������ָ�� - ���д�ŵ�������ĵ�ַ
//
//	double* d[5];
//	double* (*pd)[5] = &d;		//pd����һ������ָ��
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
//��������������Ԫ�صĵ�ַ
//������2�����⣺
//1.sizeof���������� - ��������ʾ�������飬����������������С����λ���ֽ�
//2.&������ - ��������ʾ�������飬ȡ��������������ĵ�ַ

//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	int(*pa)[10] = &arr;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *((*pa) + i));			//һά���鲻�Ǻܷ��㣬һ�㲻����ôд
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
//	print2(arr, 3, 5);			//arr��������ʾ��Ԫ�صĵ�ַ
//	return 0;
//}


//int main()
//{
//	int arr[5];					//��������
//
//	int* parr1[10];				//����ָ�������
//
//	int(*parr2)[10];			//����ָ�룬��ָ���ܹ�ָ��һ�����飬����10��Ԫ�أ�ÿ��Ԫ�ص�������int
//
//	int(*parr3[10])[5];			//parr3��һ���洢����ָ������飬�������ܹ����10������ָ��
//								//ÿ������ָ���ܹ�ָ��һ�����飬����5��Ԫ�أ�ÿ��Ԫ����int����
//	return 0;
//}


//���������ָ�����
//һά���鴫��
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

//��ά���鴫��
//void test1(int arr[3][5])
//{
//
//}
//void test2(int arr[][]){}			//err	��ά���鴫�Σ������βε����ֻ��ʡ�Ե�һ��[]������
//void test3(int arr[][5])
//{
//
//}
//void test4(int* arr) {}				//err	��ά���������δ�������Ԫ�ص�ַ����һ�еĵ�ַ
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



//��ҵ
//int i;					//i��ȫ�ֱ���������ʼ����Ĭ����0
//int main()
//{
//	i--;
//	//sizeof���������������Ľ����������unsigned int
//	if (i > sizeof(i))			//�з��������޷������Ƚϵ�ʱ�򣬻��Ƚ��з�����ת��Ϊ�޷��������ٽ��бȽϡ�
//								//-1���޷�������������ɺܴ����
//	{
//		printf(">\n");
//	}
//	else
//	{
//		printf("<\n");
//	}
//	return 0;
//}


//��ҵ����Sn=a+aa+aaa+aaaa+aaaaa��ǰ5��֮�ͣ�����a��һ������
//���磺2+22+222+2222+22222
//int main()
//{
//	//��a���ǰn��֮�� - ���������
//	int a = 0;
//	int n = 0;
//	scanf("%d %d", &a, &n);
//	int i = 0;
//	int sum = 0;
//	int ret = 0;
//	for (i = 0; i < n; i++)
//	{
//		//���һ��
//		ret = ret * 10 + a;
//		sum = sum + ret;
//	}
//	printf("sum=%d\n", sum);
//	return 0;
//}


//��ҵ��дһ����������ӡarr��������ݣ���ʹ�������±꣬ʹ��ָ�롣
//arr��һ������һά����
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = arr;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//����1
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *p);
//		p++;
//	}
//	printf("\n");
//	//����2
//	int* pend = arr + sz - 1;
//	p = arr;
//	while (p <= pend)
//	{
//		printf("%d ", *p);
//		p++;
//	}
//	//֪��ѭ��������for����֪��ѭ��������while
//	printf("\n");
//	return 0;
//}


//��ҵ�����0~100000֮������еġ�ˮ�ɻ������������
//��ˮ�ɻ�������ָһ��nλ�������λ���ֵ�n�η�֮��ȷ�õ��ڸ�������
//�磺153=1^3+5^3+3^3,��153��һ����ˮ�ɻ�������
#include<math.h>
//int main()
//{
//	int i = 0;
//	for (i = 0; i <= 100000; i++)
//	{
//		//�ж�i�Ƿ�Ϊ������
//		//1.����i��λ�� - n
//		int j = i;
//		int n = 1;
//		while (j / 10)
//		{
//			n++;
//			j = j / 10;
//		}
//		//2.����i��ÿһλ��n�η�֮��
//		j = i;
//		int sum = 0;
//		while (j)
//		{
//			//pow��������η�����
//			sum = sum + pow(j % 10, n);
//			j = j / 10;
//		}
//		/*while (j)
//		{
//			sum = sum + (j % 10) ^ n;
//			j = j / 10;
//		}*/
//		//3.�ж�
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


//��ҵ��дһ��������������һ���ַ���������
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



//��ҵ����ӡ����
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


//��ҵ������ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Ժȶ�����ˮ�����ʵ�֣�
//int main()
//{
//	int money = 0;
//	scanf("%d", &money);
//	int total = money;
//	int empty = money;
//	//��ʼ�û�
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

//��ҵ������һ���������飬ʵ��һ��������
//�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�����ż��λ������ĺ�벿��
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
//		//��ǰ������һ��ż��
//		while ((left<right)&&(arr[left] % 2 == 1))			//����ʼ������ȫ��������ȫż�����ᵼ��Խ����ʣ�
//															//��˼��������������left<right
//		{
//			left++;
//		}
//		//�Ӻ���ǰ��һ������
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


//��ҵ
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
//	//��ӵ�ʱ��a��bҪ������������
//	//�޷���char������������λ��0
//	//a=00000000 00000000 00000000 11001000
//	//b=00000000 00000000 00000000 01100100
//	//c=00000000 00000000 00000001 00101100
//	//  00101100									�洢	��λ���������
//	c = a + b;
//	printf("%d %d\n", a + b, c);
//	return 0;
//}

//��ҵ����ӡ�������
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


//��ҵ��������
//5λ�˶�Ա�μ�10��̨��ˮ����������������Ԥ����������
//A˵��B�ڶ����ҵ���
//B˵���ҵڶ���E����
//C˵���ҵ�һ��D�ڶ�
//D˵��C����ҵ���
//E˵���ҵ��ģ�A��һ
//ÿλѡ�ֶ�˵����һ�룬����ȷ����������

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





//һ��ָ�봫��
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
//	//p��һ��ָ��
//	print(arr, sz);
//	return 0;
//}

//����ָ�봫��
//void test(int** ptr)
//{
//	**ptr = 20;
//}
//int main()
//{
//	int a = 10;
//	int* pa = &a;		//pa��һ��ָ��
//	int** ppa = &pa;	//ppa�Ƕ���ָ��
//
//	//�Ѷ���ָ����д���
//	test(ppa);
//	//����ָ�뻹���Դ���Щ
//	test(&pa);
//	printf("%d\n", a);
//
//	int* arr[10] = { 0 };
//	test(arr);				//�����һ��ָ�������Ҳ����
//	
//	return 0;
//}


/*
һ��ָ��
int*p;			����ָ�� - ָ�����͵�ָ��
char*pc;		�ַ�ָ�� - ָ���ַ���ָ��
void*pv;		�����͵�ָ��

����ָ��
char**p;		
int**p;

����ָ�룺ָ�������ָ��
int(*p)[4];

*/

/*
���飺
һά����
��ά����

ָ������ - ���ָ�������

*/


//����ָ�룺ָ������ָ�룡��ź�����ַ��ָ��
//int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int a = 10;
//	int* pa = &a;				//����ָ��
//
//	char ch = 'w';
//	char* pc = &ch;				//�ַ�ָ��
//
//	int arr[10] = { 0 };
//	int(*parr)[10] = &arr;		//ȡ������ĵ�ַ
//	//parr ��ָ�������ָ�� - ��ŵ�������ĵ�ַ
//
//	//����ָ�� - ��ź�����ַ��ָ��
//	printf("%p\n", &Add);		//&������ - ȡ���ľ��Ǻ����ĵ�ַ
//	printf("%p\n", Add);		//�������������ȫһ��
//	//������ !=& ������
//	//������ ==& ������
//
//	int (*pf)(int, int) = &Add;			//pf ����һ������ָ�����
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
//	int (*pf1)(int, int) = &Add;			//pf ����һ������ָ�����
//	int (*pf)(int, int) = Add;				//����Add��&Addһ����˼����ˣ�����ʽҲ����
//	//Add==pf
//
//	//�����ĵ���
//	int ret1=(*pf)(3, 5);
//	printf("%d\n", ret1);
//
//	int ret2=Add(3, 5);
//	printf("%d\n", ret2);
//
//	int ret3=pf(3, 5);						//������ͨ������ָ��ȥ���ú����ķ��������ԣ�ʵ����*Ϊ����
//	printf("%d\n", ret3);
//	//int ret3 = *pf(3, 5);	//err
//	return 0;
//}


//�Ķ�������Ȥ�Ĵ���
//int main()
//{
//	(*(void(*)())0)();
//	//����0��ַ���ĺ���
//	//�ú����޲Σ�����������void
//	//1.void(*)() - ����ָ������
//	//2.(void(*)())0 - ��0����ǿ������ת����������Ϊһ�������ĵ�ַ
//	//3.*(void(*)())0 - ��0��ַ�����˽����ò���
//	//4.(*(void(*)())0)() - ����0��ַ���ĺ���
//	//��c�����ȱ�ݡ�
//	return 0;
//}

//void (*signal(int, void(*)(int)))(int);
////1.signal�ͣ����Ƚ�ϣ�˵��signal�Ǻ�����
////2.signal�����ĵ�һ��������������int���ڶ��������������Ǻ���ָ��
////	�ú���ָ�룬ָ��һ������Ϊint������������void�ĺ���
////3.signal�����ķ�������Ҳ��һ������ָ��
////	�ú���ָ�룬ָ��һ������Ϊint������������void�ĺ���
////	signal��һ������������
//
////typedef - �����ͽ����ض���
//typedef void(*pfun_t)(int);			//��void(*)(int)�ĺ���ָ������������Ϊpfun_t
//typedef unsigned int uint;			//��unsigned int�ĺ�������������Ϊ uint
//
////��������signal�ĺ�����������д��
//pfun_t signal(int, pfun_t);




//����ָ������ - ��ź���ָ�������
// 
//����ָ��		int*
//����ָ������	int* arr[5]
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
//	int (*pfArr[2])(int, int) = { Add,Sub };		//pfArr ���Ǻ���ָ�����飬���ͬ���ͺ���ָ��
//
//	return 0;
//}





//����ָ���Ӧ��
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
//����ʵ�ַ���
//int main()
//{
//	int input = 0;
//	//������ - �������ͱ����ļӡ������ˡ���
//	do {
//		menu();
//		printf("��ӭʹ�ñ������������ѡ��\n");
//		int i = 0;
//		int j = 0;
//		scanf("%d", &input);
//		int ret = 0;
//		switch (input)
//		{
//		case 1:
//			printf("������������������\n");
//			scanf("%d %d", &i, &j);
//			ret = Add(i, j);
//			printf("%d\n\n", ret);
//			break;
//		case 2:
//			printf("������������������\n");
//			scanf("%d %d", &i, &j);
//			ret = Sub(i, j);
//			printf("%d\n\n", ret);
//			break;
//		case 3:
//			printf("������������������\n");
//			scanf("%d %d", &i, &j);
//			ret = Mul(i, j);
//			printf("%d\n\n", ret);
//			break;
//		case 4:
//			printf("������������������\n");
//			scanf("%d %d", &i, &j);
//			ret = Div(i, j);
//			printf("%d\n\n", ret);
//			break;
//		case 0:
//			printf("�����˳��������Ժ󡭡�\n");
//			break;
//		default:
//			printf("��������������������룺\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}

//����ָ�뷽��
//int main()
//{
//	int input = 0;
//	//������ - �������ͱ����ļӡ������ˡ���
//	do {
//		menu();
//		printf("��ӭʹ�ñ������������ѡ��\n");
//		int i = 0;
//		int j = 0;
//		scanf("%d", &input);
//		int ret = 0;
//
//		//pfArr���Ǻ���ָ������
//		//ת�Ʊ� - ��C��ָ�롷
//		int (*pfArr[5])(int, int) = { NULL,Add,Sub,Mul,Div };
//
//		if(input>=1&&input<=4)
//		{
//			printf("������������������\n");
//			scanf("%d %d", &i, &j);
//			ret = (pfArr[input])(i, j);
//			printf("%d\n\n", ret);
//		}
//		else if(input==0)
//		{
//			printf("�����˳��������Ժ󡭡�\n");
//			break;
//		}
//		else
//		{
//			printf("��������������������룺\n");
//		}
//		
//	} while (input);
//	return 0;
//}




//ָ����ָ�������ָ��
//����ָ������� - ����
//ȡ������ָ������ĵ�ַ

/*
��������
int arr[5];
int (*p1)[5]=&arr;

����ָ�������
int* arr[5];
int* (*p2)[5]=&arr;
p2��ָ������ָ�����顿��ָ��


����ָ������
&����ָ������
int(*p)(int,int);					//����ָ��
int(* p2[4])(int,int);				//����ָ�������
int(* (*p3)[4])(int,int)=&p2��		//ȡ�����Ǻ���ָ������ĵ�ַ
									//p3����һ��ָ�򡾺���ָ������顿��ָ��
*/

//int main()
//{
//	int arr[10];
//	//����Ԫ������ - int
//	//arr ����������� int [10]
//
//	return 0;
//}





//�ص�����
/*
�ص���������һ��ͨ������ָ����õĺ����������Ѻ�����ָ�루��ַ����Ϊ�������ݸ���һ��������
�����ָ�뱻������������ָ��ĺ���ʱ�����Ǿ�˵���ǻص��������ص����������ɸú�����ʵ�ַ�ʽֱ�ӵ��ã�
�������ض����¼�����������ʱ�������һ�����õģ����ڶԸ��¼�������������Ӧ��
*/

//�ص�����Ӧ��
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
//	printf("������������������\n");
//	scanf("%d %d", &i, &j);
//	return pf(i, j);
//}
//int main()
//{
//	int input = 0;
//	//������ - �������ͱ����ļӡ������ˡ���
//	do {
//		menu();
//		printf("��ӭʹ�ñ������������ѡ��\n");
//		int i = 0;
//		int j = 0;
//		scanf("%d", &input);
//		int ret = 0;
//		switch (input)
//		{
//		case 1:
//			ret = Calc(Add);				//�ص�����
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
//			printf("�����˳��������Ժ󡭡�\n");
//			break;
//		default:
//			printf("��������������������룺\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}