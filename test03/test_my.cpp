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

bool findDuplication(int *numbers, int length, int *num)
{
	if (numbers == NULL || length == 0 || num == NULL)
		return false;

	for (int i = 0; i < length; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			if (numbers[i] == numbers[j])
			{
				*num = numbers[i];
				return true;
			}
		}
	}

	return false;
}

bool sort_test(int numbers[], int length, int *num)
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

int main1(int arg, char *args[])
{
	int array[] = { 2, 3, 1, 0, 2, 5, 3 };
	int num = 0;
	sort_test(array, 7, &num);
	printf("num = %d\n", num);
	system("pause");
	return 0;
}