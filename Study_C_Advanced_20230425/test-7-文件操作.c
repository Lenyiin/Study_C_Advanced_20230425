#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>


//P167-P171


//本章重点
//1.为什么使用文件
//2.什么是文件
//3.文件的打开和关闭
//4.文件的顺序读写
//5.文件的随机读写
//6.文本文件和二进制文件
//7.文件读取结束的判定
//8.文件缓冲区


//1.为什么使用文件
//	学习结构体时写的通讯录，当通讯录运行起来的时候，可以给通讯录增加、删除数据，此时数据是存放在内存当中的，
//	当程序退出的时候，通讯录的数据自然就不存在了，当下次运行的时候，又需要重新录入。
//	但既然是通讯录，就应该把信息记录下来，只有我们自己选择删除数据的时候，数据才不复存在，这就涉及数据持久化的问题。
//	一般数据持久化的方法，把数据存放在磁盘文件、存放到数据库等方式。
//
//2.什么是文件
//	磁盘上的文件是文件
//	但是在程序设计中，我们一般谈的文件有两种：程序文件、数据文件（从文件功能的角度来分类的）
//2.1 程序文件：包括源程序文件（后缀为.c），目标文件（windows环境后缀为.obj），可执行文件（windows环境后缀为.exe）。
//2.2 数据文件：文件的内容不一定是程序，而是程序运行时读写的数据，比如程序运行需要从中读取数据的文件，或者输出内容的文件。
//2.3 文件名：	一个文件要有一个唯一的文件标识，以便用户识别和引用
//				文件名包含三部分：文件路径+文件名主干+文件名后缀
//
//3.文件的打开和关闭
//3.1 文件指针：缓冲文件系统中，关键的概念是“文件类型指针”，简称“文件指针”。
//				每个被使用的文件都在内存中开辟了一个相应的文件信息区，用来存放文件的相关信息（如文件的名字，文件状态及文件当前的位置等）。
//				这些信息是保存在一个结构体变量中的。该结构体类型是由系统申明的，取名FILE。
//	不同的C编译器的FILE类型包含的内容不完全相同，但是大同小异。
//	每当打开一个文件的时候，系统会根据文件的情况自动创建一个FILE结构的变量，并填充其中的信息，使用者不必关心细节。
//	一般都是通过一个FILE的指针来维护这个FILE结构的变量，这样使用起来更加方便。
//
//FILE*的指针变量的创建
//FILE* pf;		//文件指针变量
//定义pf是一个指向FILE类型数据的指针变量。可以使pf指向某个文件的文件信息区（是一个结构体变量）。通过该文件信息区中的信息就能访问该文件。
//也就是说，通过文件指针变量能够找到与他关联的文件。



//int main()
//{
//	FILE* pf = fopen("test.txt", "r");		// fopen("test.txt", "r")		这种叫相对路径打开
//	FILE* pf1 = fopen("D:\\C_code\\Study_C_Advanced_20230425\\test.dat", "r");
//	// fopen("D:\\C_code\\Study_C_Advanced_20230425\\test.dat", "r")		这种叫绝对路径打开		防止\成为转义字符，需要\\
//	if (pf1 == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	// 写文件
//
//	// 关闭文件
//	fclose(pf1);
//	pf1 = NULL;
//	return 0;
//}
/*
文件使用方式		含义												如果指定文件不存在

“r”（只读）		为了输入数据，打开一个已经存在的文本文件			出错
“w”（只写）		为了输出数据，打开一个文本文件						建立一个新的文件
“a”（追加）		向文本文件尾添加数据								建立一个新文件
“rb”（只读）		为了输入数据，打开一个二进制文件					出错
“wb”（只写）		为了输出数据，打开一个二进制文件					建立一个新的文件
“ab”（追加）		向一个二进制文件尾添加数据							出错
“r+”（读写）		为了读和写，打开一个文本文件						出错
“w+”（读写）		为了读和写，建立一个新文件							建立一个新的文件
“a+”（读写）		打开一个文件，在文件尾进行读写						建立一个新的文件
“rb+”（读写）		为了读和写，打开一个二进制文件						出错
“wb+”（读写）		为了读和写，新建一个一个新的二进制文件				建立一个新的文件
“ab+”（读写）		打开一个二进制文件，在文件尾进行读和写				建立一个新的文件
*/


//4.文件的顺序读写
/*
功能				函数名			适用于

字符输入函数		fgetc			所有输入流
字符输出函数		fputc			所有输出流
文本行输入函数		fgets			所有输入流
文本输出函数		fputs			所有输出流
格式化输入函数		fscanf			所有输入流
格式化输出函数		fprintf			所有输出流
二进制输入			fread			文件
二进制输出			fwrite			文件
*/

/*
					输入/读取		
	内存中程序						文件（硬盘）
					输出/写入		
*/
//int main()
//{
//	FILE* pf = fopen("test.dat", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//写文件
//	//fputc('h', pf);
//	//fputc('e', pf);
//	//fputc('l', pf);
//	//fputc('l', pf);
//	//fputc('o', pf);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//流：高度抽象的概念
//C语言程序，只要运行起来，就默认打开3个流：
//stdin		- 标准输入流 - 键盘
//stdout	- 标准输出流 - 屏幕
//stderr	- 标准错误流 - 屏幕

//// 向屏幕输出
//int main()
//{
//	fputc('h', stdout);
//	fputc('e', stdout);
//	fputc('l', stdout);
//	fputc('l', stdout);
//	fputc('o', stdout);
//	return 0;
//}

//// 使用fgetc在文件读取数据
//int main()
//{
//	FILE* pf = fopen("test.dat", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	// 读文件
//	int ret = fgetc(pf);
//	printf("%c\n", ret);
//	ret = fgetc(pf);
//	printf("%c\n", ret);
//	ret = fgetc(pf);
//	printf("%c\n", ret);
//	ret = fgetc(pf);
//	printf("%c\n", ret);
//	ret = fgetc(pf);
//	printf("%c\n", ret);
//
//	while ((ret = fgetc(pf)) != EOF)
//	{
//		printf("%c\n", ret);
//	}
//
//	// 关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}
//// EOF	-1

//// 使用fgetc从键盘读取数据
//int main()
//{
//	//读键盘
//	int ret = fgetc(stdin);
//	printf("%c\n", ret);
//	ret = fgetc(stdin);
//	printf("%c\n", ret);
//	ret = fgetc(stdin);
//	printf("%c\n", ret);
//	ret = fgetc(stdin);
//	printf("%c\n", ret);
//	ret = fgetc(stdin);
//	printf("%c\n", ret);
//
//	return 0;
//}


//// 写一行数据
//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	// 写文件 - 按照行来写
//	fputs("hello\n", pf);
//	fputs("world\n", pf);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//// 读一个数据
//int main()
//{
//	char arr[10] = "xxxxxxxxx";
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	// 读文件
//	fgets(arr, 4, pf);			// 虽然写了读4个，但是最多只会读3个，留一个存“\0“
//	printf("%s\n", arr);
//
//	fgets(arr, 4, pf);
//	printf("%s\n", arr);
//
//	fgets(arr, 4, pf);
//	printf("%s\n", arr);
//
//	// 关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}




//// 对格式化的数据进行写文件
//struct S
//{
//	char arr[10];
//	int age;
//	float sc;
//};
//
//int main()
//{
//	struct S s = { "zhangsan",25,55.5f };
//	// 对格式化的数据进行写文件
//	FILE* pf = fopen("test.txt", "w");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//	// 写文件
//	fprintf(pf, "%s %d %f", s.arr, s.age, s.sc);
//
//	// 关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


//// 对格式化的数据进行读文件
//struct S
//{
//	char arr[10];
//	int age;
//	float sc;
//};
// 
//int main()
//{
//	struct S s = { 0 };
//	// 对格式化的数据进行读文件
//	FILE* pf = fopen("test.txt", "r");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//	// 读文件
//	fscanf(pf, "%s %d %f", s.arr, &(s.age), &(s.sc));
//
//	// 打印
//	printf("%s %d %f\n", s.arr, s.age, s.sc);
//	
//	// 关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}



//// 二进制的写
//struct S
//{
//	char arr[10];
//	int age;
//	float sc;
//};
//int main()
//{
//	struct S s = { "zhangsan",25,55.5f };
//	// 二进制的形式写
//	FILE* pf = fopen("test.txt", "wb");	// 二进制的形式写
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	// 写文件
//	fwrite(&s, sizeof(struct S), 1, pf);
//
//	// 关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//// 二进制的读
//struct S
//{
//	char arr[10];
//	int age;
//	float sc;
//};
// 
//int main()
//{
//	struct S s = { 0 };
//	// 二进制的形式读
//	FILE* pf = fopen("test.txt", "rb");	// 二进制的形式读
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	// 读文件
//	fread(&s, sizeof(struct S), 1, pf);
//
//	printf("%s %d %f\n", s.arr, s.age, s.sc);
//
//	// 关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}



//4.1 对比一组函数
	//scanf/fscanf/sscanf
	//printf/fprintf/sprintf

//scanf		针对标准输入的格式化的输入语句 - stdin
//fscanf	针对所有输入流的格式化的输入语句 - stdout/文件
//sscanf	从一个字符串中读取一个格式化的数据
//
//printf	针对标准输出的格式化输出语句 - stdin
//fprintf	针对所有输出流的格式化输出语句 - stdout/文件
//sprintf	把一个格式化的数据，转换成字符串

//struct S
//{
//	char arr[10];
//	int age;
//	float score;
//};
//int main()
//{
//	struct S s = { "zhangsan",25,55.5f };
//	struct S tmp = { 0 };
//
//	char buf[100] = { 0 };
//	// sprintf 把一个格式化的数据，转换成字符串
//	sprintf(buf, "%s %d %f", s.arr, s.age, s.score);
//	// "zhangsan 25 55.500000"
//	printf("字符串：%s\n", buf);
//
//	// 从buf字符串中还原出一个结构体数据
//	sscanf(buf, "%s %d %f", tmp.arr, &(tmp.age), &(tmp.score));
//	printf("格式化：%s %d %f\n", tmp.arr, tmp.age, tmp.score);
//
//	return 0;
//}


//5.文件的随机读写
//5.1 fseek	根据文件指针的位置和偏移量来定位文件指针
//5.2 ftell 返回文件指针相对于起始位置的偏移量
//5.3 rewind 让文件指针回到起始位置

//int main()
//{
//	FILE* pf = fopen("test3.txt", "r");	// abcdef
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	// 读取文件
//	int ch = fgetc(pf);			// a
//	printf("%c\n", ch);
//	ch = fgetc(pf);				// b
//	printf("%c\n", ch);
//	ch = fgetc(pf);				// c
//	printf("%c\n", ch);			// 顺序读写
//
//	// 调整文件指针
//	fseek(pf, -2, SEEK_CUR);	// 指针往前偏移一位，又指向了d
//	ch = fgetc(pf);				// b
//	printf("%c\n", ch);			
//
//	fseek(pf, 2, SEEK_CUR);		// 指针往后偏移2位，指向了e
//	ch = fgetc(pf);				// e
//	printf("%c\n", ch);
//
//	fseek(pf, -3, SEEK_END);	// 指针从最后往前偏移3位，指向了d
//	ch = fgetc(pf);				// d
//	printf("%c\n", ch);
//
//	fseek(pf, 3, SEEK_SET);		// 指针从起始位置往后偏移3位，指向了d
//	ch = fgetc(pf);				// d
//	printf("%c\n", ch);
//
//	int ret = ftell(pf);		// ftell 返回文件指针相对于起始位置的偏移量
//	printf("%d\n", ret);		// 4
//
//	ch = fgetc(pf);				// e
//	printf("%c\n", ch);
//
//	ret = ftell(pf);			// ftell 返回文件指针相对于起始位置的偏移量
//	printf("%d\n", ret);		// 5
//
//	ch = fgetc(pf);				// f
//	printf("%c\n", ch);
//
//	ch = fgetc(pf);				// f是文件里存的最后一个数据，再往后读取会越界，但是不会报错
//	printf("%c\n", ch);
//
//	// 让文件指针回到起始位置
//	rewind(pf);
//	ret = ftell(pf);			// ftell 返回文件指针相对于起始位置的偏移量
//	printf("%d\n", ret);		// 0
//	ch = fgetc(pf);
//	printf("%c\n", ch);			// a
//	ret = ftell(pf);			// ftell 返回文件指针相对于起始位置的偏移量
//	printf("%d\n", ret);		// 1
//
//	// 关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}



//6.文本文件和二进制文件
	//根据数据的组织形式，数据文件被称为文本文件或者二进制文件。
	//数据在内存中以二进制的形式存储，如果不加以转换的输出到外存，就是二进制文件。
	//如果要求在外存上以ASCⅡ码的形式存储，则需要在存储前转换。以ASCⅡ码的形式存储的文件就是文本文件。
	//一个数据在内存中是怎么存储的呢？
	//字符一律以ASCⅡ码的形式存储，数值型数据既可以用ASCⅡ码的形式存储，也可以使用二进制形式存储。
	//如有整数10000，如果以ASCⅡ码的形式存储，则磁盘中占用5个字节（每个字符一个字节），如果以二进制的形式存储，则4个字节。

//int main()
//{
//	int a = 10000;
//	FILE* pf = fopen("test1.txt", "wb");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	// 写文件
//	fwrite(&a, sizeof(int), 1, pf);
//
//	// 关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}



//7.文件读取结束的判定
//7.1 被错误使用的feof
		//在文件读取过程中，不能使用feof函数的返回值直接用来判断文件的是否结束
		//而是应用于当文件读取结束的时候，判断是读取失败结束，还是遇到文件尾结束。
		//1.文本文件读取是否结束，判断返回值是否为EOF（fgetc），或者NULL（fgets）
		//	例如：	fgetc判断是否为EOF				fgetc函数在读取结束的时候，会返回EOF；正常读取的时候，返回的是读取到的字符ASCⅡ码值
		//			fgets判断返回值是否为NULL		fgets函数在读取结束的时候，会返回NULL；正常读取的时候，返回存放字符串的空间起始地址
		//2.二进制文件的读取结束判断，判断返回值是否小于实际要读的个数
		//	例如： fread函数在读取的时候，返回的是实际读取到的完整元素的个数；如果发现读取到的完整的元素的个数小于指定的元素个数，这就是最后一次读取了。


//// 写代码，把test1.txt文件拷贝一份，生成test2.txt
//int main()
//{
//	FILE* pfread = fopen("test1.txt", "r");
//	if (pfread == NULL)
//	{
//		return 1;
//	}
//	FILE* pfwrite = fopen("test2.txt", "w");
//	if (pfwrite == NULL)
//	{
//		fclose(pfread);
//		pfread = NULL;
//		return 1;
//	}
//	// 文件打开成功
//
//	// 读写文件
//	int ch = 0;
//	// fgetc 当读取失败的时候或者遇到了文件结束的时候，都会返回EOF
//	while ((ch = fgetc(pfread))!=EOF)
//	{
//		// 写文件
//		fputc(ch, pfwrite);
//	}
//
//	// 判断文件读取结束的原因
//	if (feof(pfread))
//	{
//		printf("遇到文件结束标志，文件正常结束\n");
//	}
//	else if (ferror(pfread))
//	{
//		printf("文件读取失败结束\n");
//	}
//
//	// 关闭文件
//	fclose(pfread);
//	pfread = NULL;
//	fclose(pfwrite);
//	pfwrite = NULL;
//
//	return 0;
//}



//8.文件缓冲区
//	ANSIC标准采用“缓冲文件系统”处理的数据文件的，所谓缓冲文件系统是指系统自动地在内存中为程序中每一个正在使用地文件开辟一块“文件缓冲区”。
//	从内存向磁盘输出数据会先送到内存中的缓冲区，装满缓冲区后才一起送到磁盘上。
//	如果从磁盘向计算机读入数据，则从磁盘文件中读取数据输入到内存缓冲区（充满缓冲区），然后再从缓冲区逐个地将数据送到程序数据区（程序变量等）。
//	缓冲区的大小根据C编译系统决定的

//#include<windows.h>
//int main()
//{
//	FILE* pf = fopen("test3.txt", "w");
//	fputs("abcdef", pf);					//先将代码放在输出缓冲区
//
//	printf("睡眠10秒 - 已经写数据了，打开test3.txt文件，发现没内容\n");
//	Sleep(10000);
//	printf("刷新缓冲区\n");
//	fflush(pf);								//刷新缓冲区时，才将输出缓冲区的数据写到文件（磁盘）
//
//	printf("再睡眠10秒 - 此时，再次打开test3.txt文件，文件有内容了\n");
//	Sleep(10000);
//
//	fclose(pf);								//注：fclose在关闭文件的时候，也会刷新缓冲区
//	pf = NULL;
//
//	return 0;
//}