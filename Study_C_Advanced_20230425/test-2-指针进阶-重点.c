#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//P106-P134

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
//	int(*p2)[10] = &arr;	// ����ָ���������������ĵ�ַ��
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
//��������������Ԫ�صĵ�ַ
//������2�����⣺
//1.sizeof���������� - ��������ʾ�������飬����������������С����λ���ֽ�
//2.&������ - ��������ʾ�������飬ȡ��������������ĵ�ַ

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
//		// pָ������ģ�*p��ʵ���൱��������������������������Ԫ�صĵ�ַ��*p�����Ͼ���������Ԫ�ص�ַ
//		// һά���鲻�Ǻܷ��㣬һ�㲻����ôд
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
//	// unsigned char 0~255
//	unsigned char a = 200;
//	// 00000000 00000000 00000000 11001000
//	//							  11001000
//	unsigned char b = 100;
//	// 00000000 00000000 00000000 01100100
//	//							  01100100
//	unsigned char c = 0;
//	// ��ӵ�ʱ��a��bҪ������������
//	// �޷���char������������λ��0
//	// a = 00000000 00000000 00000000 11001000
//	// b = 00000000 00000000 00000000 01100100
//	// c = 00000000 00000000 00000001 00101100
//	//								  00101100			�洢	��λ���������
//	c = a + b;
//	printf("%d %d\n", a + b, c);	// 300 44
//	return 0;
//}

////��ҵ����ӡ�������
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
//
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

//int test(const char* str)
//{
//	printf("test()\n");
//	return 0;
//}
//
//int main()
//{
//	// ����ָ�� - Ҳ��һ��ָ�룬��ָ������ָ��
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

// ����ʵ�ַ���
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

// ����ָ�뷽��
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




//qsort���� - ��������

////ð������
//void bubble_sort(int arr[], int sz)
//{
//	int i = 0;
//	int j = 0;
//
//	for (i = 0; i < sz - 1; i++)
//	{
//		int flag = 1;	// �����������ź����
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
//	//����
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

//qsort()�ǿ⺯�����������ͣ�ʲô���Ͷ���������		��������	�ַ�������	�ṹ������
/*
void qsort(
			void* base,				//void* ���޾������͵�ָ��		base �д�ŵ��Ǵ����������е�һ������ĵ�ַ
			size_t num,				//num   ��������Ԫ�صĸ���
			size_t size,			//size	������һ��Ԫ�صĴ�С
			int (*compar)(const void*, const void*)		//�����Ƚϴ����������е�2��Ԫ�صĺ���
);

*/

//int main()
//{
//	int a = 10;
//	char* pa = &a;	// warning �ӡ�int * ������char* �������Ͳ�����
//
//	void* pv = &a;	// void* ���޾������͵�ָ�룬���Խ����������͵ĵ�ַ
//	// void* ���޾������͵�ָ�룬���Բ��ܽ����ò�����Ҳ���� +- ��������
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
//	// �������ݵ�����
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	// ����
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//	// ��ӡ
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
//	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;			// ������д��������
//}
//
//int sort_by_name(const void* e1, const void* e2)
//{
//	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
//}
//
//void test2()
//{
//	// ʹ��qsort��������ṹ������
//	struct Stu s[] = { {"zhangsan",30},{"lisi",34},{"wangwu",20} };
//	int sz = sizeof(s) / sizeof(s[0]);
//
//	// ������������
//	qsort(s, sz, sizeof(s[0]), sort_by_age);
//	// ��������������
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





////ģ��qsortʵ��һ��ð�������ͨ���㷨
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
//	// ����
//	for (i = 0; i < sz - 1; i++)
//	{
//		int flag = 1;	// �����������ź����
//		// һ�˵�����
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
//			{
//				// ����
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
//	// �������ݵ�����
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	// ����
//	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);			// ʹ���Լ�����������
//	// ��ӡ
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
//	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;	// ������д��������
//}
//
//int sort_by_name(const void* e1, const void* e2)
//{
//	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
//}
//
//void test4()
//{
//	// ʹ���Լ��ĺ�������ṹ������
//	struct Stu s[] = { {"zhangsan",30},{"lisi",34},{"wangwu",20} };
//	int sz = sizeof(s) / sizeof(s[0]);
//
//	// ������������
//	bubble_sort(s, sz, sizeof(s[0]), sort_by_age);
//	// ��������������
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
//	void* p = &a;			//void �޾������ͣ���������ָ�򣬴����������
//	*p;						//err	���ǲ��ܽ�����		���ʼ����ֽڣ�
//	p++��					//err						���������ֽڣ�
//							//ֻ����ǿ��ת����Ӧ�����ͣ�����������
//	p = &ch;
//	return 0;
//}




//��ҵ		P124
//sizeof(�������� - ��������ʾ��������� - ���������������Ĵ�С
//&������ - ��������ʾ�������飬ȡ��������������ĵ�ַ
//����֮�⣬������������е�����������������Ԫ�صĵ�ַ
//int main()
//{
//	int a[] = { 1,2,3,4 };
//
//	printf("%d\n", sizeof(a));		//4*4=16
//	printf("%d\n", sizeof(a+0));	//4or8			a+0�ǵ�һ��Ԫ�صĵ�ַ��sizeof��a+0��������ǵ�һ����ַ�Ĵ�С
//	printf("%d\n", sizeof(*a));		//4				��Ԫ�ص�ַ�Ľ����ã����ǵ�һ��Ԫ�أ���һ��Ԫ����int����
//	printf("%d\n", sizeof(a+1));	//4or8			a+1�ǵڶ���Ԫ�صĵ�ַ
//	printf("%d\n", sizeof(a[1]));	//4				������ǵڶ���Ԫ�صĴ�С
//
//	printf("%d\n", sizeof(&a));		//4or8			ȡ��������ĵ�ַ����Ȼ������ĵ�ַ������Ҳ�ǵ�ַ��sizeof��&a���������һ����ַ�Ĵ�С
//	printf("%d\n", sizeof(*&a));	//4*4			&aȡ��ַȡ������������ĵ�ַ��*&a�����ã��ҵ�������������
//													//&ȡ��ַ��*�����ã��������Ϊ��Ч��Ч����sizeof��*&a��==sizeof��a��
//	printf("%d\n", sizeof(&a+1));	//4or8			&a+1������������������һ���ռ�ĵ�ַ������һ����ַ�Ĵ�С
//	printf("%d\n", sizeof(&a[0]));	//4or8			ȡ�����ǵ�һ��Ԫ�صĵ�ַ
//	printf("%d\n", sizeof(&a[0]+1));//4or8			ȡ�����ǵڶ���Ԫ�صĵ�ַ
//
//
//	char arr[] = { 'a','b','c','d','e','f' };
//	//ֻ���ַ�������\0��β���ַ���\0
//
//	printf("%d\n", sizeof(arr));		//6			6��Ԫ�أ�һ��Ԫ�ش�С1���ֽ�
//	printf("%d\n", sizeof(arr+0));		//4or8		�ַ���Ԫ�ص�ַ
//	printf("%d\n", sizeof(*arr));		//1			�����õ�һ��Ԫ�أ���С1���ֽ�
//	printf("%d\n", sizeof(arr[1]));		//1			�����õڶ���Ԫ�أ���С1���ֽ�
//	printf("%d\n", sizeof(&arr));		//4or8		�����ַ�����ĵ�ַ��
//	printf("%d\n", sizeof(&arr+1));		//4or8		�����ַ�������¸��ռ��ַ
//	printf("%d\n", sizeof(&arr[0]+1));	//4or8		�ڶ���Ԫ�صĵ�ַ
//	
//	printf("%d\n", strlen(arr));		//���Ȳ���		arr��Ԫ�ص�ַ		����û��\0,
//	printf("%d\n", strlen(arr+0));		//���Ȳ���		arr+0��Ԫ�ص�ַ		���������һ��
//	//printf("%d\n", strlen(*arr));		//err			*arr����ַ���������⣬��������
//	//printf("%d\n", strlen(arr[1]));		//err			arr[1]��b��ASC����98�����Ĳ��ǵ�ַ���������
//	printf("%d\n", strlen(&arr));		//���Ȳ���		&arr��������ĵ�ַ��strlen���ǿ����׵�ַ
//	printf("%d\n", strlen(&arr+1));		//���Ȳ���		&arr+1����һ����������ֵ		���ֵ-6
//	printf("%d\n", strlen(&arr[0]+1));	//���Ȳ���		���ֵ-1
//
//
//	char arr1[] = "abcdef";				//�ַ���������־�� \0 �����Խ�βĬ�Ϸ���\0
//	//[ a b c d e f \0 ]
//
//	printf("%d\n", sizeof(arr1));		//7				6��Ԫ�� +��\0��
//	printf("%d\n", sizeof(arr1 + 0));	//4or8			��Ԫ�ص�ַ
//	printf("%d\n", sizeof(*arr1));		//1				��һ��Ԫ�ش�С
//	printf("%d\n", sizeof(arr1[1]));	//1				�ڶ���Ԫ�صĴ�С
//	printf("%d\n", sizeof(&arr1));		//4or8			���������ַ
//	printf("%d\n", sizeof(&arr1+1));	//4or8			���������¸��ռ�ĵ�ַ
//	printf("%d\n", sizeof(&arr1[0]+1));	//4or8			�ڶ���Ԫ�صĵ�ַ
//
//	printf("%d\n", strlen(arr1));		//6				������\0���ͻ�ֹͣ
//	printf("%d\n", strlen(arr1 + 0));	//6
//	//printf("%d\n", strlen(*arr1));		//err			����һ��Ԫ��a��ASC����97����strlen������ַ�������
//	//printf("%d\n", strlen(arr1[1]));	//err			���ڶ���Ԫ��b��ASC����98����strlen������ַ�������
//	printf("%d\n", strlen(&arr1));		//6
//	printf("%d\n", strlen(&arr1+1));	//���ֵ
//	printf("%d\n", strlen(&arr1[0]+1));	//5
//
//
//	char* p = "abcdef";					//�ַ���������־�� \0 �����Խ�βĬ�Ϸ���\0
//	//[ a b c d e f \0 ]
//
//	printf("%d\n", sizeof(p));			//4or8			�ַ����ĵ�ַ
//	printf("%d\n", sizeof(p + 1));		//4or8			b�ĵ�ַ
//	printf("%d\n", sizeof(*p));			//1				a
//	printf("%d\n", sizeof(p[0]));		//1				p[0] --> *(p+0) ����a
//	printf("%d\n", sizeof(&p));			//4or8			
//	printf("%d\n", sizeof(&p+1));		//4or8
//	printf("%d\n", sizeof(&p[0]+1));	//4or8			p�ĵ�ַ
//
//	printf("%d\n", strlen(p));			//6				6��Ԫ��
//	printf("%d\n", strlen(p + 1));		//5				5��Ԫ��
//	//printf("%d\n", strlen(*p));			//err
//	//printf("%d\n", strlen(p[0]));		//err
//	printf("%d\n", strlen(&p));			//6				��
//	printf("%d\n", strlen(&p + 1));		//���ֵ
//	printf("%d\n", strlen(&p[0] + 1));	//5
//
//
//	int b[3][4] = { 0 };
//
//	printf("%d\n", sizeof(b));				//3*4*4=48			���������С
//	printf("%d\n", sizeof(b[0][0]));		//4					��һ�е�һ��Ԫ�ش�С
//	printf("%d\n", sizeof(b[0]));			//4*4=16			��һ��4��Ԫ�صĴ�С		b[0]�������Ϊ��һ�е�������
//	printf("%d\n", sizeof(b[0]+1));			//4or8				��һ�еĵڶ���Ԫ�صĵ�ַ
//	//b[0] ��Ϊ��������û�е�������sizeof�ڲ���Ҳû��ȡ��ַ������b[0]���ǵ�һ�е�һ��Ԫ�صĵ�ַ��b[0]+1�ǵ�һ�еڶ���Ԫ�صĵ�ַ
//	printf("%d\n", sizeof(*(b[0] + 1)));	//4					��һ�еڶ���Ԫ�صĵ�ַ������
//	printf("%d\n", sizeof(b + 1));			//4or8				b+1 ���ǵڶ��еĵ�ַ
//	//b��Ϊ��ά���������������û��ȡ��ַ��Ҳû�е�������sizeof�ڲ�������b�ͱ�ʾ��ά������Ԫ�صĵ�ַ������һ�еĵ�ַ
//	printf("%d\n", sizeof(*(b + 1)));		//4*4=16			�ڶ����ĸ�Ԫ�صĴ�С	*(b + 1) ==b[1]
//	//b + 1 ��ʾ�ڶ��еĵ�ַ��*(b + 1) ��ʾ�ڶ��е�Ԫ��
//	printf("%d\n", sizeof(&b[0]+1));		//4or8				b[0] ��һ����������&b[0] ��һ�е�ַ��&b[0]+1 �ڶ��е�ַ
//	printf("%d\n", sizeof(*(&b[0] + 1)));	//4*4				
//	printf("%d\n", sizeof(*b));				//4*4				��һ�е�ַ		�����һ�д�С
//	//b��Ϊ��ά��������û��ȡ��ַ��û�е�������sizeof�ڲ���b������Ԫ�ص�ַ������һ�еĵ�ַ������*b���ǵ�һ�У�
//	printf("%d\n", sizeof(b[3]));			//4*4				���ʽ��1.ֵ����	2.��������
//	//��û�м��㣬ֻ���Ʋ�		b[3] -->int [4]		b[3]��ʵ�ǵ�����������������еĻ�������ʹ�����ڣ�Ҳ��ͨ�����ͼ����С
//	//sizeof() �ڲ��ı��ʽ�ǲ�����ģ�
//
//	return 0;
//}


//int main()
//{
//	short s = 5;
//	int a = 4;
//	printf("%d\n", sizeof(s = a + 6));			//2			����������
//	printf("%d\n", s);							//5			sizeof() �ڲ��ı��ʽ�ǲ�����ģ�
//	return 0;
//}


//�ܽ᣺������������
//1.sizeof�������������������������ʾ�������飬���������������Ĵ�С
//2.&���������������������ʾ�������飬ȡ��������������ĵ�ַ
//3.����֮�����е�����������ʾ��Ԫ�صĵ�ַ


//��ҵ
//int main()
//{
//	int a[5] = { 1,2,3,4,5 };
//	int* ptr = (int*)(&a + 1);			  //&a ȡ������������ĵ�ַ��&a+1 ��������������һ���ռ�ĵ�ַ
//	printf("%d,%d", *(a + 1), *(ptr - 1));//������a������������ĸ��ַ,a+1���ǵڶ���Ԫ�صĵ�ַ,*(a+1)���ǵڶ���Ԫ�ص�ֵ
//										  //ptr�������¸��ռ���׵�ַ��ptr - 1�����������һ��Ԫ�صĵ�ַ
//
//	return 0;
//}


//��ҵ
//����ָ�����ͣ�������ָ�������
//struct Test
//{
//	int Num;
//	char* pcName;
//	short sDate;
//	char cha[2];
//	short sBa[4];
//}*p = (struct Test*)0x100000;
//// ����p��ֵ��0x100000.���±���ʽ��ֵ�ֱ�Ϊ���٣�
//// ��֪���ṹ��Test���͵ı�����С��20���ֽ�
//// x86
//
//int main()
//{
//	printf("%p\n", p + 0x1);						// +1��ʵ+����20���ֽ� 0x100000+0x1=0x100014
//	printf("%p\n", (unsigned long)p + 0x1);			// ǿ��ת����unsigned long���ӵľ���1��0x100001
//	printf("%p\n", (unsigned int*)p + 0x1);			// ǿ��ת����unsigned int*����1�ӵľ���4�ֽڣ�0x100004
//
//	return 0;
//}


//��ҵ
//int main()
//{
//	int a[4] = { 1,2,3,4 };
//	int* ptr1 = (int*)(&a + 1);
//	int* ptr2 = (int*)((int*)a + 1);
//	//(int*)a + 1 ��Ԫ��������1���ֽ�
//
//	printf("%x,%x", ptr1[-1], *ptr2);
//
//	return 0;
//}


//��ҵ
//int main()
//{
//	int a[3][2] = { (0,1),(2,3),(4,5) };			//������ʽ��С���ţ����������ű��ʽ�����Ϊ���һ�����ʽ
//	//����������ǣ�	1 3		5 0		0 0
//	int* p;
//	p = a[0];
//	printf("%d", p[0]);
//
//	return 0;
//}


//��ҵ
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


//��ҵ
//int main()
//{
//	int aa[2][5] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* ptr1 = (int*)(&aa + 1);						// &aaȡ���������ַ��&aa + 1��������������
//	int* ptr2 = (int*)(*(aa + 1));						// aaΪ��һ�е�ַ��aa + 1ָ��ڶ��С�
//														// *(aa + 1)�൱��aa[1]��Ҳ����6�ĵ�ַ
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));			// 10	5
//
//	return 0;
//}


//��ҵ
//int main()
//{
//	char* a[] = { "work","at","alibaba" };
//	char** pa = a;
//	pa++;
//	printf("%s\n", *pa);	// at
//
//	return 0;
//}



//��ҵ
//int main()
//{
//	char* c[] = { "ENTER","NEW","POINT","FIRST" };
//	char** cp[] = { c + 3,c + 2,c + 1,c };
//	char*** cpp = cp;
//
//	printf("%s\n", **++cpp);			//++cpp -->cp[1]�ĵ�ַ��*++cpp -->c+2 -->c[2]�ĵ�ַ��**++cpp -->c[2]�����ݣ�POINT
//	printf("%s\n", *-- * ++cpp + 3);	//++cpp -->cp[2]�ĵ�ַ��*++cpp -->c+1 -->c[1]�ĵ�ַ��--*++cpp  -->c[0]�ĵ�ַ,
//										//*--*++cpp -->ENTER��*--*++cpp+3 -->ER
//	printf("%s\n", *cpp[-2] + 3);		//cpp[-2] -->cp[0]������ -->c+3 -->c[3]�ĵ�ַ -->FORST�ĵ�ַ��
//										//*cpp[-2] -->c[3]������ -->FORST��*cpp[-2]+3 -->ST
//										//���У�cpp[-2] <==> *(cpp-2)
//	printf("%s\n", cpp[-1][-1] + 1);	//cpp[-1] <==> *(cpp-1)��cpp[-1][-1] <==> *(*(cpp-1)-1)��cpp[-1][-1]+1 <==>*(*(cpp-1)-1)+1
//										//cpp[-1] -->*(cpp-1) -->cp[1]������ -->c+2 -->c[2]�ĵ�ַ,
//										//cpp[-1][-1] -->*(*(cpp-1)-1) -->c[1]������ -->NEW
//										//cpp[-1][-1]+1 -->EW
//
//	//int i = 0;
//	//printf("%d\n", ++i);
//	//printf("%d\n", ++i);
//	//printf("%d\n", ++i);
//
//	return 0;
//}



//��ҵ
/*
int a=10;				//4���ֽڿռ�
int arr[10]={0};		//40���ֽڿռ�
һ�����������˾��޷�������

��̬�ڴ濪�٣�
p=malloc();
���룺malloc
ʹ��
�ͷţ�free(p);
p=NULL;

*/


//��ҵ		���Ͼ���
//��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ�����
//���д�����������ľ����в���ĳ�������Ƿ���ڡ�
//Ҫ��ʱ�临�Ӷ�С��o��N��

////1 2 3
////4 5 6
////7 8 9
//int main()
//{
//	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };		// N - ���ҵĴ�������������N�Σ�2N 3N
//	// N*N   N*(N-1)  --  o(N^2)					o(1) -- ָ���ǲ���N�Ǽ�����������Ϊ������
//	// ����һ�����֣�����˵�ң�7
//	//�����ķ���ʱ�临�Ӷ�o(N^2)��������Ҫ��
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
//	//����ҵ��ˣ�����1��û�ҵ�����0��
//	int i = 3;
//	int j = 3;
//
//	int ret = find_num(arr, &i, &j, k);
//	if (ret == 1)
//	{
//		printf("�ҵ���\n");
//		printf("Ԫ���±��ǣ�%d %d\n", i, j);
//	}
//	else
//	{
//		printf("�Ҳ���\n");
//	}
//	return 0;
//}


//����
//�ַ���
//���ݽṹ

// ����һ
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

// ������		������ת��
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
//	// 1. ����������
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



//��ҵ		�ַ�������
//��Ŀ���ݣ�ʵ��һ�����������������ַ����е�k���ַ���
//���磺ABCD����һ���ַ��õ�BCDA
//		ABCD���������ַ��õ�CDAB
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
////������		������ת��
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
//	reverse(str, str + k - 1);				//�������
//	reverse(str + k, str + sz - 1);			//�ұ�����
//	reverse(str, str + sz - 1);				//��������
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


//��ҵ
//дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1=AABCD��s2=BCDAA������1
//		����s1=abcd ��s2=ACBD�� ����0
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
//	strcat(arr, "world");			//strcat ����һ���ַ����ĺ���׷����һ���ַ���
//	printf("%s\n", arr);
//	//strcat(arr, arr);				//������������Լ�����׷���Լ�
//	strncat(arr, arr, 5);			//����������Ժ���׷���Լ���������������׷�Ӽ�λ
//	printf("%s\n", arr);
//	return 0;
//}

//����������Ĵ���Ľ�Ϊ��
//#include<assert.h>
//#include<stdlib.h>
//#include<string.h>
//int is_string_rotate(char* str1, char* str2)
//{
//	assert(str1);
//	assert(str2);
//
//	// ���Ȳ���ȣ��϶�������ת�õ�
//	if (strlen(str1) != strlen(str2))
//	{
//		return 0;
//	}
//	// 1. str1�ַ����ĺ���׷��һ��str1
//	int sz = strlen(str1);
//	strncat(str1, str1, sz);			// ��str1�ַ���������׷��һ��str1����
//	// printf("%s\n", str1);
//	// 2. �ж�str2�Ƿ�Ϊstr1���ִ�
//	char* ret = strstr(str1, str2);		// ������ִ������ص�ַ��������ǣ����ؿ�ָ��
//	/*if (ret == NULL)
//	{
//		return 0;
//	}
//	else
//	{
//		return 1;
//	}*/
//	//���ߣ�������ж����д�ɣ�
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
ָ��
һ��ָ��
����ָ��

����ָ��
�ַ�ָ��

����ָ��
����ָ��
�ص�����

*/

/*
����
һά����
��ά����

��������
�ַ�����

ָ������

*/

/*
ָ�����㣺
������
ָ��+-����
ָ��-ָ��
ָ��Ĺ�ϵ����

*/

/*
ָ�����ѧ��

���ݽṹ��
CPP -> Cʵ�ּ򵥵����ݽṹ
ָ��+�ṹ��+��̬����

*/

