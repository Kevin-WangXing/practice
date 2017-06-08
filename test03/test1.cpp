/*
������3��һ�����ҳ��������ظ�������
��Ŀ����һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ�
������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�
Ҳ��֪��ÿ�������ظ��˼��Ρ����ҳ�����������һ���ظ������֡�
���磬������볤��Ϊ7������{2, 3, 1, 0, 2, 5, 3}��
��ô��Ӧ��������ظ�������2����3��
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <Windows.h>
#include <algorithm>



bool Findduplication(int numbers[], int length, int *num)
{
	if (numbers == NULL || length == 0 || num == NULL)
		return false;
	for (int i = 0; i < length; i++)
	{
		if (numbers[i] < 0 || numbers[i] > length - 1)
			return false;
	}

	for (int i = 0; i < length; i++)
	{
		while (numbers[i] != i)
		{
			if (numbers[i] == numbers[numbers[i]])
			{
				*num = numbers[i];
				return true;
			}

			int temp = numbers[i];
			numbers[i] = numbers[temp];
			numbers[temp] = temp;

			//swap(numbers[i], numbers[numbers[i]]);
		}
	}

	return false;
}



void Print(char *testName, int numbers[], int length, int *num, bool validArgument)
{
	printf("%s begin\n", testName);

	int duplication;

	bool validIuput = Findduplication(numbers, length, num);
	if (validIuput == validArgument)
	{
		if (validIuput)
		{
			printf("duplicayion %d\n", *num);
		}
		else
			printf("no duplication\n");
	}
	else
		printf("failed\n");
}

void Test()
{
	int array[] = { 2, 3, 1, 0, 2, 5, 3 };
	int num = 0;
	Print("Test", array, sizeof(array) / sizeof(int), &num, true);
	
}

void Test1()
{
	int array[] = { 2, 3, 1, 0, 4, 5, 6 };
	int num = 0;
	Print("Test", array, sizeof(array) / sizeof(int), &num, false);

}

int main(int arg, char *args[])
{
	Test1();
	system("pause");
	return 0;
}