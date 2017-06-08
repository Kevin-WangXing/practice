/*
面试题3（一）：找出数组中重复的数字
题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。
数组中某些数字是重复的，但不知道有几个数字重复了，
也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
那么对应的输出是重复的数字2或者3。
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