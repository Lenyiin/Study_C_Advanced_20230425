#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>


//P172-P


//�����ص�
//1.����ķ��뻷��
//2.�����ִ�л���
//3.��⣺C���Գ���ı���+����
//4.Ԥ������Ž���
//5.Ԥ����ָ��#define
//6.��ͺ����ĶԱ�
//7.Ԥ���������#��##�Ľ���
//8.�����
//9.Ԥ����ָ��#include
//10.Ԥ����ָ��#underf
//11.��������


//1.����ķ��뻷��
//1.1Ԥ����׶������ͷ�ļ��İ���#include��#define����ķ��źͺ���滻��ע��ɾ��		- �ı�����
//1.2����׶Σ���C���Դ���ת���ɻ����롣1.�﷨������2.�ʷ�������3.���������4.���Ż��ܡ�
//1.3���׶Σ��ѻ�����ת�����˻���ָ�������ָ���1.���ɷ��ű�readelf�����ܿ���
//1.4���ӽ׶Σ��Ѷ��Ŀ���ļ������ӿ�������ӡ�1.�ϲ��α�2.���ű�ĺϲ����ض�λ


//Linux	- ����ϵͳ
//vim	- �༭�� - �ǳ�ǿ��
//gcc	- ������


//2.3���л���
//����ִ�еĹ��̣�1.������������ڴ��С����в���ϵͳ�Ļ����У�һ������ɲ���ϵͳ��ɡ�
//					�ڶ����Ļ����У����������������ֹ����ţ�Ҳ������ͨ����ִ�д�������ֻ���ڴ�����ɡ�
//				  2.����ִ�б㿪ʼ�����ŵ���main������
//				  3.��ʼִ�г�����롣���ʱ�����ʹ��һ������ʱ��ջ��stack�����洢�����ľֲ������ͷ��ص�ַ��
//					����ͬʱҲ����ʹ�þ�̬��static���ڴ棬�洢�ھ�̬�ڴ��еı����ڳ��������ִ�й�����һֱ�������ǵ�ֵ��
//				  4.��ֹ����������ֹmain������Ҳ�п�����������ֹ��

//������Ա������������



//3.Ԥ�������
//3.1 Ԥ�������
//		__FILE__			���б����Դ�ļ�
//		__LINE__			�ĵ���ǰ���к�
//		__DATE__			�ĵ������������
//		__TIME__			�ĵ��������ʱ��
//		__STDC__			�����������ѭANSI C����ֵΪ1������δ����
//		__FUNCTION__		��ǰ���б���ĺ���

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
//3.2.1	#define�����ʶ��
//		#define�Ƕ�����ŵ�
//3.2.2 #define�����			����Ѳ����滻���ı���
//		ע�⣺�����б�������ű�����name���ڡ��������֮�����κοհ״��ڣ������б�ͻᱻ����Ϊstuff��һ����
//3.2.3 #define�滻����
//		�ڳ�������չ#define������źͺ�ʱ����Ҫ�漰�������衣
//		1.�ڵ��ú�ʱ�����ȶԲ������м�飬�����Ƿ�����κ���#define����ķ��š�����У��������ȱ��滻��
//		2.�滻�ı���󱻲��뵽������ԭ���ı���λ�á����ں꣬�����������ǵ�ֵ�滻��
//		3.����ٴζԽ���ļ�����ɨ�裬���������Ƿ�����κ���#define����ķ��š�����У����ظ�����������̡�
//		ע�⣺	1.�������#define�����п��Գ�������#define����ı����������ں꣬���ܳ��ֵݹ顣
//				2.��Ԥ����������#define����ķ��ŵ�ʱ���ַ������������ݲ���������
//3.2.4 #��##					���԰Ѳ������뵽�ַ�����
//		ʹ��#����һ���������ɶ�Ӧ���ַ���
//		##���԰�λ�������ߵķ��źϳ�һ�����ϣ�������궨��ӷ�����ı�Ƭ�δ�����ʶ����
//3.2.5 �������õĺ����
//		��������ں궨���г��ֳ���һ�ε�ʱ������������и����ã���ô����ʹ��������ʱ��Ϳ��ܳ���Σ�գ����²���Ԥ��ĺ����
//		�����þ��Ǳ��ʽ��ֵ��ʱ�����������Ч����
//3.2.6 ��ͺ����ĶԱ�
//		��ͨ����Ӧ����ִ�м򵥵����㡣���������������ҳ��ϴ��һ����
//	Ϊʲô���ú���������������
//		1.	���ڵ��ú����ʹӺ������صĴ�����ܱ�ʵ��ִ�����С�ͼ��㹤�������ʱ����ࡣ���Ժ�Ⱥ����ڳ���Ĺ�ģ���ٶȷ����ʤһ�
//		2.	����Ҫ���Ǻ����Ĳ��������������ض������͡����Ժ���ֻ�������ͺ��ʵı��ʽ��ʹ�á�
//			��֮�������������������͡������͡������͵ȿ�������>���Ƚϵ����͡����������޹صġ�
//	����Ⱥ��������Ƶĵط�
//		1.	ÿ��ʹ�ú��ʱ��һ�ݺ궨��Ĵ��뽫���뵽�����С����Ǻ�Ƚ϶̣�������ܴ�������ӳ���ĳ��ȡ�
//		2.	����û�����Ե�
//		3.	�����������޹أ�Ҳ�Ͳ����Ͻ�
//		4.	����ܻ������������ȼ������⣬���³������׳���
//		����ʱ������������������������顣���磺��Ĳ������Գ������ͣ����Ǻ�����������
//	����Լ��
//		һ�������������ͺ��ʹ���﷨�����ơ��������Ա���û�����������ֶ��ߡ�������ƽʱ��һ��ϰ���ǣ�
//			�Ѻ���ȫ����д
//			��������Ҫȫ����д



//#define M 1000
//#define reg register			//��register �����reg
//#define do_forever for(;;)		//����һ����ѭ��
//#define CASE break;case
//#define STR "hello world"
//#define print printf("���")	// Ҳ������ӷֺ�
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

//#define �����
//#define SQUARE(X) X*X				// Ϊ���Ͻ������Ӧ����д��	#define SQUARE(X) ����X��*��X����
//int main()
//{
//	printf("%d\n", SQUARE(3));		// ��δ���ᱻ�滻��	printf("%d\n", 3*3);
//
//	printf("%d\n", SQUARE(3+1));	// ��δ���ᱻ�滻��	printf("%d\n", 3+1*3+1);	�����7
//
//	return 0;
//}
// ��Ĳ����ǲ������κμ��㣬ֱ�Ӿʹ���ȥ��

//#define SQUARE(X) ((X)*(X))
//#define DOUBLE(X) (X)+(X)			// Ϊ���Ͻ������Ӧ����д��	#define DOUBLE(X) ��(X)+(X)��
//int main()
//{
//	printf("%d\n", 10*DOUBLE(4));	// ��δ���ᱻ�滻��	printf("%d\n", 10*(4+4));	�����44
//
//	printf("%d\n", SQUARE(3 + 1));	// ��δ���ᱻ�滻��	printf("%d\n", (3+1)*(3+1));�����16
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

//// ��Xǰ�����#��X�Ĳ��������滻�����������ǻ�ת����������Ӧ���ַ���
//#define PRINT(X,FORMAT) printf("the value of "#X" is "FORMAT"\n",X)
//
//int main()
//{
//	printf("hello world\n");
//	printf("hello " "world\n");	// д����ͬ�������������������ŵ��ַ�������Ȼ���ӵ�һ��
//
//	int a = 10;
//	PRINT(a,"%d");				// ��δ���ᱻ�滻��	printf("the value of "��a��" is %d\n",a)
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
//	printf("%d\n", CAT(class, 101));	// ��δ���ᱻ�滻��		printf("%d\n",  class101);
//										// ## �൱�ڰ���������������һ��
//
//	return 0;
//}


//// �������õĺ����
//#define MAX(X,Y) ((X)>(Y)?(X):(Y))
//int main()
//{
//	int a = 5;	// 6 7
//	int b = 4;	// 5
//	int m = MAX(a++, b++);
//	// ��δ���ᱻ�滻��	int m = ((a++)>(b++)?(a++):(b++));
//	//							6		5 > 4	�� 6
//
//	printf("m=%d\n", m);		// 6
//	printf("a=%d b=%d\n", a,b);	// 7 5
//
//	return 0;
//}



//#define MALLOC(num,type) (type*)malloc(num*sizeof(type))
//int main()
//{
//	int* p = MALLOC(10, int);	// �ⵥ����ᱻ�滻��	int* p = (int*)malloc(10 * sizeof(int));
//
//	return 0;
//}


//��������	inline		����˺���ŵ㣬�ͺ������ŵ�





//3.3 #undef		����ָ�������Ƴ�һ���궨��

//#define M 100
//int main()
//{
//	int a = M;
//
//	printf("%d\n", M);
//#undef M						//ȡ���궨��
//	return 0;
//}




//3.4 �����ж���
//		���C�ı������ṩ��һ���������������������ж�����š���������������̡�

//3.5 ��������
//		�ڱ���һ�������ʱ���������Ҫ��һ����䣨һ����䣩������߷����Ǻܷ���ġ���Ϊ��������������ָ�

//#define PRINT		// ���������������������Ϊ�棬�ͻᱻ���룬û���壬�����������Ϊ�٣��Ͳ��ᱻ����
//int main()
//{
//
//#ifdef PRINT
//	printf("hehe\n");
//#endif
//
//#ifdef 1			// 1Ϊ�棬�ͻᱻ���룬0Ϊ�٣��Ͳ��ᱻ����
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
//#if __DEBUG__			// 1Ϊ�棬�ͻᱻ���룬0Ϊ�٣��Ͳ��ᱻ����
//	printf("hehe");
//#endif
//
//	return 0;
//}

//// ���֧����������
//int main()
//{
//
//#if 1==1					//�������Ϊ�棬ִ��������ֱ�Ӿͽ����ˣ�������뼴ʹΪ��Ҳ����ִ��
//	printf("hehe\n");
//#elif 2==2					//����������Ϊ�٣����ִ������
//	printf("haha\n");
//#else						//������涼Ϊ�ٲŻ�ִ������
//	printf("heihei\n");
//#endif
//
//	return 0;
//}


//// �ж��Ƿ񱻶���
//#define TEST
//#define HEHE
//
//int main()
//{
//	// ���TEST�����ˣ�����������
//#ifdef TEST
//	printf("test1\n");
//#endif
//
//#if defined(TEST)		// �������������д��������ͬ
//	printf("test2\n");
//#endif
//
//
//	// ���HEHE�����壬����������
//#ifndef HEHE
//	printf("hehe1\n");
//#endif
//
//#if !defined(HEHE)		// �������������д��������ͬ
//	printf("hehe2\n");
//#endif
//
//	return 0;
//}

//// Ƕ��ָ��
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


//3.6 �ļ�����
//		�����Ѿ�֪����#includeָ�����ʹ����һ���ļ������롣������ʵ�ʳ�����#includeָ��ĵط�һ����
//		�����滻��ʽ�ܼ򵥣�Ԥ��������ɾ������ָ����ð����ļ��������滻��
//							����һ��Դ�ļ�������10�Σ���ʵ�ʱ�����10�Ρ�

#include<stdlib.h>		//���ļ��İ���		C���Կ����ṩ�ĺ�����ͷ�ļ���ʹ��	<	>
#include"test.h"		//�����ļ��İ���	�Զ���ĺ���ͷ�ļ���ʹ��	��	��

// < > �͡������Ҳ��Ե�����
//		��������Դ�ļ�����Ŀ¼�²��ң������ͷ�ļ�δ�ҵ���������������ҿ⺯��ͷ�ļ�һ���ڱ�׼λ�ò���ͷ�ļ�������Ҳ�������ʾ�������
//		< > ֱ��ȥ�⺯��ͷ�ļ����ڵ�Ŀ¼�²���


#pragma once			//��ֹͷ�ļ��ظ�����




//4 ����Ԥ����ָ��
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



//// ��ҵ		����������Ϊ4
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



//��ҵ			atoi		����
//int main()
//{
//	char* p = "1234";
//	int ret = atoi(p);		// ���ַ���ת����һ������
//	printf("%d\n", ret);
//	return 0;
//}

//// atoi ʵ��
//#include<ctype.h>
//#include<limits.h>
//
//enum State
//{
//	INVALID,		// 0
//	VALID			// 1
//};
//// state ��¼���� my_stoi ���ص�ֵ�ǺϷ�ת����ֵ�����ǷǷ���״̬
//enum State state = INVALID;
//
//int my_atoi(const char* s)
//{
//	int flag = 1;
//	// ��ָ�������
//	if (NULL == s)
//	{
//		return 0;
//	}
//	// ���ַ�������
//	if (*s == '\0')
//	{
//		return 0;
//	}
//	// �����հ��ַ�
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
//	// ���������ַ���ת��
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
//		// �������ַ������
//		return (int)n;
//	}
//}
//
//int main()
//{
//	// 1.��ָ��
//	// 2.���ַ���
//	// 3.�������ַ�
//	// 4.������Χ
//
//	const char* p = "    -1234";
//	int ret = my_atoi(p);
//	if (state == VALID)
//	{
//		printf("������ת����%d\n", ret);
//	}
//	else
//	{
//		printf("�Ƿ���ת����%d\n", ret);
//	}
//
//	return 0;
//}



//��ҵ
//һ��������ֻ�����������ǳ���һ�Σ������������ֶ�����������
//��дһ�������ҳ�������ֻ����һ�ε�����
//1 2 3 4 5 6 1 2 3 4

//void Find(int arr[], int sz, int* x, int* y)
//{
//	// 1.Ҫ�������������
//	int i = 0;
//	int ret = 0;
//	for (i = 0; i < sz; i++)
//	{
//		ret ^= arr[i];
//	}
//	// 2.����ret����һλΪ1
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
//	// �Ѵӵ�λ����λ�ĵ�posλΪ1��Ϊ0�ķ�����һ��
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
//	// �ҳ�������ֻ����һ�ε�����
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
//INT_PTR a, b;		// a �������� int*��b �������� int
//int_ptr a, b;		// a b �����Ͷ��� int*



//ͷ�ļ��İ���
//���͵Ķ���
//����������



//��ҵ
//// дһ���꣬���Խ�һ�������Ķ�����λ������λ��ż��λ����
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



//��ҵ
//дһ����,����ṹ����ĳ��������׵�ַ��ƫ�ƣ�������˵����
// offsetof	����
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


//offsetof ʵ��
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
