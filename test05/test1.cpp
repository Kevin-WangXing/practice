/*

// ������5���滻�ո�
// ��Ŀ����ʵ��һ�����������ַ����е�ÿ���ո��滻��"%20"���������롰We are happy.����
// �������We%20are%20happy.����
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

// �ո��ھ��ӿ�ͷ
void Test2()
{
	const int length = 100;

	char str[length] = " helloworld";
	Test("Test2", str, length, "%20helloworld");
}

// �ո��ھ���ĩβ
void Test3()
{
	const int length = 100;

	char str[length] = "helloworld ";
	Test("Test3", str, length, "helloworld%20");
}

// �����������ո�
void Test4()
{
	const int length = 100;

	char str[length] = "hello  world";
	Test("Test4", str, length, "hello%20%20world");
}

// ����nullptr
void Test5()
{
	Test("Test5", nullptr, 0, nullptr);
}

// ��������Ϊ�յ��ַ���
void Test6()
{
	const int length = 100;

	char str[length] = "";
	Test("Test6", str, length, "");
}

//��������Ϊһ���ո���ַ���
void Test7()
{
	const int length = 100;

	char str[length] = " ";
	Test("Test7", str, length, "%20");
}

// ������ַ���û�пո�
void Test8()
{
	const int length = 100;

	char str[length] = "helloworld";
	Test("Test8", str, length, "helloworld");
}

// ������ַ���ȫ�ǿո�
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