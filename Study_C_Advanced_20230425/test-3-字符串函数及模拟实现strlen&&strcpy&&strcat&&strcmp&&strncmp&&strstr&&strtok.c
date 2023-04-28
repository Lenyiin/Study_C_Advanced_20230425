#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>

//P135-P139


//�����ص㣺�ص���ܴ����ַ����ַ����Ŀ⺯����ʹ�ú�ע������
//���ַ�������
//	strlen
//���Ȳ������Ƶ��ַ�������
//	strcpy
//	strcat
//	strcmp
//���������Ƶ��ַ�����������
//	strncpy
//	strncat
//	strncmp
//�ַ�������
//	strstr
//	strtok
//������Ϣ����
//	strerror
//�ַ�����
//�ڴ��������
//	memcpy
//	memmove
//	memset
//	memcmp


//���Կ⺯��strlen
//int main()								//#include<stdio.h>
//{
//	char arr[] = "abc";
//	int len = strlen(arr);				//#include<string.h>
//	printf("%d\n", len);
//
//	char arr1[] = { 'a','b','c' };		//arr1�����ŵ�û�� \0 ���strlen������ȡ�ĳ���Ϊ���ֵ
//	int len1 = strlen(arr1);
//	printf("%d\n", len1);
//	return 0;
//}
//�ַ����ԡ�\0����Ϊ������־��strlen�������ص������ַ�����\0��ǰ����ֵ��ַ�����������"\0"����
//����ָ����ַ�������Ҫ��'\0'������
//ע�⺯���ķ���ֵΪsize_t�����޷��ŵġ�		size_t <==> unsigned int



//ģ��⺯��strlen
//����һ	�������汾
//int my_strlen(const char* str)			//��const ����ȫ
//{
//	assert(str != NULL);				//#include<assert.h>
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
////������	�ݹ�汾
////������	ָ��-ָ��
//int main()
//{
//	char arr[] = "abc";					//Ĭ�Ͻ�β��	/0
//	//char arr[] = { 'a','b','c' };
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}



//���Կ⺯��strcpy
char* strcpy(char* destination, const char* source);
//int main()
//{
//	char arr[20] = "########";
//	//arr = "hello";				//����д���Ǵ����
//	char* p = "hello";				//����д����������hello����h�ĵ�ַ�����pָ����
//	printf("%s\n", arr);
//	strcpy(arr, "hello");			//����hello�������arr������		'\0'��strcpy����ֹͣ����ֹ����
//	printf("%s\n", arr);
//
//	char arr1[] = { 'a','b','c' };	//����arr2��δ�洢 '\0'
//	strcpy(arr, arr1);				//'\0'��strcpy����ֹͣ����ֹ����		arr2�ַ�������'\0',���Բ�֪����ʱֹͣ
//	printf("%s\n", arr);
//
//	char* p1 = "hello world";
//	char arr2[5] = "####";
//	strcpy(arr2, p1);				//p1ָ����ʵ����ݴ���arr2���鳤�ȣ���Ȼ�����������ӡ����������ȴ���������
//	printf("%s\n", arr2);
//
//	char* str = "############";
//	strcpy(str, p);					//Ŀ���ַ�����������޸Ĳ��ܴ��룬��str�ǳ����ַ����������޸�
//	printf("%s\n", str);
//	return 0;
//}
//Դ�ַ��������ԡ�\0������
//�ὫԴ�ַ����еġ�\0��������Ŀ��ռ�
//Ŀ��ռ�����㹻����ȷ���ܴ��Դ�ַ���
//Ŀ��ռ����ɱ�
//ѧ��ģ��ʵ��




//strcat		�ַ���׷��
char* strcat(char* destination, const char* source);
//int main()
//{
//	char arr[20] = "hello ";		//����׷�Ӹ�world
//	strcat(arr, "world");			//�ַ���׷�ӣ����ӣ�
//	printf("%s\n", arr);
//
//	char arr2[] = " world";
//	strcat(arr, arr2);				//����ֱ�Ӵ����������ߴ����һ���ַ����ﴫ����
//	printf("%s\n", arr);
//	return 0;
//}
//Դ�ַ��������ԡ�\0������
//Ŀ��ռ�����㹻����������Դ�ַ���������
//Ŀ��ռ������޸�


//strcat ģ��ʵ��
//char* my_strcat(char* destination, const char* source)
//{
//	assert(destination != NULL);
//	assert(source != NULL);
//
//	char* ret = destination;
//	int i = 0;
//	while (*destination != '\0')
//	{
//		destination++;
//	}
//	while (*source != '\0')
//	{
//		*destination = *source;
//		destination++;
//		source++;
//	}
//	//*destination = '\0';
//
//	//�ڶ���whileѭ��Ҳ����д��
//	//while ((*destination++ = *source++) != '\0');		//һ�д���ֱ�Ӹ㶨
//
//	return ret;					//���ص���Ŀ��ռ����ʼ��ַ
//}
//int main()
//{
//	char arr1[20] = "hello ";
//	char arr2[] = "world";
//	my_strcat(arr1, arr2);
//	printf("%s\n", arr1);
//	printf("%s\n", my_strcat(arr1, arr2));		//��Ϊmy_strcat���ص���Ŀ���ַ�������ʼ��ַ�����Ҳ��������ʹ��
//
//	//my_strcat(arr1, arr1);
//	//�ӵײ��߼��Ͻ���strcat���������޷��Լ�׷���Լ�����Ϊ�ڵ�һ��׷�ӵ�ʱ���Ѿ���arr1��Ľ�����־��\0�������ǵ���
//	return 0;
//}



//strcmp	�ַ����ȽϺ���
int strcmp(const char* str1, const char* str2);
//int main()
//{
//	char* p = "obc";
//	char* q = "abcdef";
//	if (p > q)					//���ֱȽϲ��У������ڱȽϵ�ַ
//	{
//		printf(">\n");
//	}
//	else
//	{
//		printf("<=\n");
//	}
//
//	if ("obc" > "abcdef")		//���ֱȽ�Ҳ���У���Ҳ���ڱȽϡ�o���͡�a���ĵ�ַ�Ĵ�С
//	{
//
//	}
//
//	//strcmp	�ַ����Ƚϴ�С�ĺ���
//	int ret1 = strcmp("abbb", "abq");
//	printf("%d\n", ret1);					//С�ڷ��� -1
//
//	int ret2 = strcmp("aaa", "aaa");
//	printf("%d\n", ret2);					//���ڷ��� 0
//
//	int ret3 = strcmp("aqq", "abc");
//	printf("%d\n", ret3);					//���ڷ��� 1
//	return 0;
//}


//ģ��ʵ�� strcmp
//int my_strcmp(const char* s1, const char* s2)
//{
//	assert(s1 != NULL && s2 != NULL);
//
//	while (*s1 == *s2)
//	{
//		if (*s1 == '\0')
//		{
//			return 0;
//		}
//		s1++;
//		s2++;
//	}
//	if (*s1 > *s2)
//	{
//		return 1;
//	}
//	else
//	{
//		return -1;
//	}
//	//��һ��д����������if else��任��		return *s1-*s2;
//	//return *s1 - *s2;
//}
//int main()
//{
//	char* p = "abcdef";
//	char* q = "abbbb";
//	//char* q = "abcdef";
//	//char* q = "adaa";
//	int ret = my_strcmp(p, q);
//	if (ret > 0)
//	{
//		printf("%s > %s\n", p, q);
//	}
//	else if (ret == 0)
//	{
//		printf("%s = %s\n", p, q);
//	}
//	else
//	{
//		printf("%s < %s\n", p, q);
//	}
//
//	return 0;
//}


/*
strcpy
strcat
strcmp
���Ȳ������Ƶ��ַ���������һֱ������׷�ӡ��Ƚϣ����ֹͣ

*/

/*
strncpy
strncat
strncmp
���������Ƶ��ַ�������

*/


//strncpy   ����
//char strncpy(char* destination, const char* source, size_t num);

//int main()
//{
//	char arr1[20] = "abcdef";
//	char arr2[] = "qwer";
//
//	//strcpy(arr1, arr2);
//	strncpy(arr1, arr2, 2);
//
//	printf("%s\n", arr1);
//	return 0;
//}

//strncpy ʵ��
//char* my_strncpy(char* dest, const char* src, size_t count)
//{
//	char* start = dest;
//	while (count && (*dest++ = *src++) != '\0')
//		count--;
//	if (count)
//		while (--count)
//			*dest++='\0';
//	return start;
//}
//int main()
//{
//	char arr1[20] = "abcdef";
//	char arr2[] = "qwer";
//
//	//strcpy(arr1, arr2);
//	my_strncpy(arr1, arr2, 2);
//
//	printf("%s\n", arr1);
//	return 0;
//}



//strncat		׷���ַ���
char* strncat(char* destination, const char* source, size_t num);
//
//int main()
//{
//	char arr1[20] = "hello ";
//	char arr2[] = "world";
//
//	strncat(arr1, arr2, 6);
//	printf("%s\n", arr1);
//
//	return 0;
//}

//strncat	ʵ��
//char* my_strncat(char* front, const char* back, size_t count)
//{
//	char* start = front;
//	while (*front++);
//	front--;
//	while (count--)
//		if ((*front++ = *back++) == 0)
//			return start;
//	*front = '\0';
//	return start;
//}
//int main()
//{
//	char arr1[20] = "hello ";
//	char arr2[] = "world";
//
//	my_strncat(arr1, arr2, 6);
//	printf("%s\n", arr1);
//
//	return 0;
//}




//strncmp   �Ƚ�n���ַ�			����
//int main()
//{
//	char* p = "abcdef";
//	char* q = "abcqwert";
//	int ret1 = strcmp(p, q);
//	printf("%d\n", ret1);
//	if (ret1 > 0)
//	{
//		printf("%s > %s\n", p, q);
//	}
//	else if (ret1 == 0)
//	{
//		printf("%s = %s\n", p, q);
//	}
//	else
//	{
//		printf("%s < %s\n", p, q);
//	}
//
//	int ret2 = strncmp(p, q, 3);
//	printf("%d\n", ret2);
//	if (ret2 > 0)
//	{
//		printf("%s > %s\n", p, q);
//	}
//	else if (ret2 == 0)
//	{
//		printf("%s = %s\n", p, q);
//	}
//	else
//	{
//		printf("%s < %s\n", p, q);
//	}
//
//	return 0;
//}



//strstr	��һ���ַ����в�����һ���ַ���
//int main()
//{
//	char arr1[] = "abcdefabcdef";
//	char arr2[] = "bcd";
//	//��arr1�в����Ƿ����arr2����
//	char* ret = strstr(arr1, arr2);			//��arr1����arr2�ַ������ҵ��ˣ����ص�һ���ҵ���λ�ã�û�ҵ����ؿ�ָ��
//	if (ret == NULL)
//	{
//		printf("û�ҵ�\n");
//	}
//	else
//	{
//		printf("�ҵ��ˣ�%s\n", ret);
//	}
//	return 0;
//}


//strstrʵ��
//char* my_strstr(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//
//	const char* s1 = NULL;
//	const char* s2 = NULL;
//	const char* cp = str1;
//	while (*cp)
//	{
//		s1 = cp;
//		s2 = str2;
//		while (*s1&&*s2&&(*s1 == *s2))
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//		{
//			return (char*)cp;
//		}
//		cp++;
//	}
//	return NULL;
//}
//int main()
//{
//	char arr1[] = "abbbcdefabcdef";
//	char arr2[] = "bbc";
//	//��arr1�в����Ƿ����arr2����
//	char* ret = my_strstr(arr1, arr2);			//��arr1����arr2�ַ������ҵ��ˣ����ص�һ���ҵ���λ�ã�û�ҵ����ؿ�ָ��
//	if (ret == NULL)
//	{
//		printf("û�ҵ�\n");
//	}
//	else
//	{
//		printf("�ҵ��ˣ�%s\n", ret);
//	}
//	return 0;
//}


//KMP - �ַ��������㷨



//strtok		�и��ַ���
char* strtok(char* str, const char* sep);
//sep�����Ǹ��ַ����������������ָ������ַ�����
//��һ������ָ��һ���ַ�������������0�����߶����sep�ַ����е�һ�����߶���ָ����ָ�ı�ǡ�
//strtok�����ҵ�str�е���һ����ǣ���������\0��β������һ��ָ�������ǵ�ָ�롣
//ע��strtok������ı䱻�������ַ�����������ʹ��strtok�����зֵ��ַ���һ�㶼����ʱ���������ݲ��ҿ��޸�
//strtok�����ĵ�һ��������ΪNULL���������ҵ�str�е�һ����ǣ�strtok���������������ַ����е�λ�á�
//strtok�����ĵ�һ������ΪNULL����������ͬһ���ַ����б������λ�ÿ�ʼ��������һ����ǵ㡣
//����ַ����в����ڸ���ı�ǣ��򷵻�NULLָ�롣

//strtok		����
//int main()
//{
//	char arr[] = "zpw@bitedu.tech";
//	char* p = "@.";						//�ָ�������
//
//	char tmp[20] = { 20 };
//	strcpy(tmp, arr);					//����strtok�������޸ı�������������������ʱ����һ��
//
//	char* ret = NULL;
//	ret=strtok(tmp, p);					//��"zpw@bitedu.tech" --> "zpw\0bitedu.tech" ��������z��ַ
//	printf("%s\n", ret);
//
//	ret = strtok(NULL, p);				//bitedu.tech -->bitedu\0tech��������b��ַ
//	printf("%s\n", ret);
//
//	ret = strtok(NULL, p);				//tech -->����t��ַ
//	printf("%s\n", ret);
//
//	ret = strtok(NULL, p);				//����ַ����в����ڸ���ı�ǣ��򷵻�NULLָ��
//	printf("%s\n", ret);
//
//	return 0;
//}

//int main()
//{
//	char arr[] = "zpw@bitedu.tech hehe";
//	char* p = "@. ";						//�ָ�������
//
//	char tmp[30] = { 0 };
//	strcpy(tmp, arr);					//����strtok�������޸ı�������������������ʱ����һ��
//
//	char* ret = NULL;
//	
//	for (ret = strtok(tmp, p); ret != NULL; ret = strtok(NULL, p))
//	{
//		printf("%s\n", ret);
//	}
//
//	return 0;
//}





//strerror			
//ʹ�ÿ⺯����ʱ��
//���ÿ⺯��ʧ�ܵ�ʱ�򣬶������ô�����
//ȫ�ִ�����


//int errno;	//5

#include<errno.h>
//int main()
//{
//	printf("%s\n", strerror(0));
//	printf("%s\n", strerror(1));
//	printf("%s\n", strerror(2));
//	printf("%s\n", strerror(3));
//	printf("%s\n", strerror(4));
//	printf("%s\n", strerror(5));
//
//	FILE* pf = fopen("test.txt", "r");		//���ļ��ɹ����᷵��һ����Ч��ָ��
//											//���ļ�ʧ�ܣ��᷵��NULL
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));	//strerror --> #include<string.h>	errno --> #include<errno.h>
//		perror("foppen");					//�����������Ҫ������	errno
//											//�Ѹ������Զ�����Ϣ��ӡ�����ϣ����ٴ�ӡ������Ϣ
//		return 1;
//	}
//	//���ļ�
//	//
//	//�ر��ļ�
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//	return 0;
//}

//strerror			�Ѵ�����ת��Ϊ������Ϣ
//perror			ֱ�Ӵ�ӡ������Ϣ