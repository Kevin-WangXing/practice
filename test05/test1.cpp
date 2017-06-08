/*

// 面试题5：替换空格
// 题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
// 则输出“We%20are%20happy.”。
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <Windows.h>
#include <algorithm>

void ReplaceSpace(char *input, int length)
{
	if (input == NULL || length <= 0)
		return;
	int originSrc = 0;
	int SpaceCount = 0;
	int i = 0;
	while (input[i] != '\0')
	{
		originSrc++;
		if (input[i] == ' ')
			SpaceCount++;
		i++;
	}

	int newSrc = originSrc + SpaceCount * 2;
	int count = newSrc;
	if (newSrc > length)
		return;

	while (originSrc >= 0 && newSrc > originSrc)
	{
		if (input[originSrc] == ' ')
		{
			input[newSrc--] = '0';
			input[newSrc--] = '2';
			input[newSrc--] = '%';
		}
		else
		{
			input[newSrc--] = input[originSrc];
		}
		originSrc--;
	}
	input[count++] = '\0';
}

void Test(char *testName, char str[], int length, char expected[])
{
	if (testName != NULL)
		printf("%s begin: ", testName);
	if (str == NULL && expected == NULL)
		printf("failed\n");
	ReplaceSpace(str, length);
	if (str != NULL && expected == NULL)
		return;
	if (expected == NULL)
		return;
	if (strcmp(str, expected) == 0)
	{
		printf("pased.\n");
		printf("%s\n", str);
	}
}

void Test1()
{
	const int length = 100;
	char src[length] = "We are happy.";
	Test("Test1", src, 100, "We%20are%20happy.");

	
}

// 空格在句子开头
void Test2()
{
	const int length = 100;

	char str[length] = " helloworld";
	Test("Test2", str, length, "%20helloworld");
}

// 空格在句子末尾
void Test3()
{
	const int length = 100;

	char str[length] = "helloworld ";
	Test("Test3", str, length, "helloworld%20");
}

// 连续有两个空格
void Test4()
{
	const int length = 100;

	char str[length] = "hello  world";
	Test("Test4", str, length, "hello%20%20world");
}

// 传入nullptr
void Test5()
{
	Test("Test5", nullptr, 0, nullptr);
}

// 传入内容为空的字符串
void Test6()
{
	const int length = 100;

	char str[length] = "";
	Test("Test6", str, length, "");
}

//传入内容为一个空格的字符串
void Test7()
{
	const int length = 100;

	char str[length] = " ";
	Test("Test7", str, length, "%20");
}

// 传入的字符串没有空格
void Test8()
{
	const int length = 100;

	char str[length] = "helloworld";
	Test("Test8", str, length, "helloworld");
}

// 传入的字符串全是空格
void Test9()
{
	const int length = 100;

	char str[length] = "   ";
	Test("Test9", str, length, "%20%20%20");
}

int main(int arg, char *args[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();
	Test8();
	Test9();

	system("pause");
	return 0;
}