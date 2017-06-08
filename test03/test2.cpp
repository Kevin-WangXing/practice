/*

// ������3�����������޸������ҳ��ظ�������
// ��Ŀ����һ������Ϊn+1����������������ֶ���1��n�ķ�Χ�ڣ�������������
// ����һ���������ظ��ġ����ҳ�����������һ���ظ������֣��������޸������
// ���顣���磬������볤��Ϊ8������{2, 3, 5, 4, 3, 2, 6, 7}����ô��Ӧ��
// ������ظ�������2����3
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <Windows.h>
#include <algorithm>
int countRange(int *numbers, int length, int start, int end);
int FindDuplicate(int numbers[], int length)
{
	if (numbers == NULL || length <= 0 )
		return -1;
	for (int i = 0; i < length; i++)
	{
		if (numbers[i] < 1 || numbers[i] > length)
			return -1;
	}

	int start = 1;
	int end = length - 1;
	while (start <= end)
	{
		int middle = ((end - start) / 2) + start;
		int count = countRange(numbers, length, start, middle);
		if (start == end)
		{
			if (count > 1)
				return start;
			else
				break;
		}
		if (count > (middle - start + 1))
			end = middle;
		else
			start = middle + 1;
	}
	return -1;
}

int countRange(int *numbers, int length, int start, int end)
{
	if (numbers == NULL)
		return -1;
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (numbers[i] >= start && numbers[i] <= end)
			count++;
	}
	return count;
}

void Print(char *test, int numbers[], int length, int *duplication, int duplength)
{
	printf("%s begin:", test);
	int result = FindDuplicate(numbers, length);
	if (result == -1)
	{
			printf("no duplication");
			return;
}
	for (int i = 0; i < duplength; i++)
	{
		if (result == duplication[i])
		{
			printf("duplication %d\n", duplication[i]);
			return;
		}

	}
	printf("no duplication\n");
}

void Test1()
{
	int array[] = { 2, 3, 5, 4, 3, 2, 6, 7 };
	int duplication[] = { 2, 3 };
	Print("Test", array, sizeof(array) / sizeof(int), duplication, sizeof(duplication) / 4);
}

// һ���ظ�������
void test2()
{
	int numbers[] = { 3, 2, 1, 4, 4, 5, 6, 7 };
	int duplications[] = { 4 };
	Print("test2", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// �ظ�����������������С������
void test3()
{
	int numbers[] = { 1, 2, 3, 4, 5, 6, 7, 1, 8 };
	int duplications[] = { 1 };
	Print("test3", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// �ظ�����������������������
void test4()
{
	int numbers[] = { 1, 7, 3, 4, 5, 6, 8, 2, 8 };
	int duplications[] = { 8 };
	Print("test4", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// ������ֻ����������
void test5()
{
	int numbers[] = { 1, 1 };
	int duplications[] = { 1 };
	Print("test5", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// �ظ�������λ�����鵱��
void test6()
{
	int numbers[] = { 3, 2, 1, 3, 4, 5, 6, 7 };
	int duplications[] = { 3 };
	Print("test6", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// ����ظ�������
void test7()
{
	int numbers[] = { 1, 2, 2, 6, 4, 5, 6 };
	int duplications[] = { 2, 6 };
	Print("test7", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// һ�������ظ�����
void test8()
{
	int numbers[] = { 1, 2, 2, 6, 4, 5, 2 };
	int duplications[] = { 2 };
	Print("test8", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// û���ظ�������
void test9()
{
	int numbers[] = { 1, 2, 6, 4, 5, 3 };
	int duplications[] = { -1 };
	Print("test9", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// ��Ч������
void test10()
{
	int* numbers = nullptr;
	int duplications[] = { -1 };
	Print("test10", numbers, 0, duplications, sizeof(duplications) / sizeof(int));
}

int main(int arg, char *args[])
{
	Test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9(); 
	test10();
	system("pause");
	return 0;
}