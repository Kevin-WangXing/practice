/*

// ������9:�Ʋ���������
��Ŀ��дһ������������n����쳲�������Fibonacci�����еĵ�n�
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <Windows.h>
#include <algorithm>


int Minorder(int *numbers, int start, int end)
{
	int result = numbers[start];
	for (int i = start + 1; i <= end; i++)
	{
		if (result > numbers[i])
			result = numbers[i];
	}

	return result;
}

int FindMin(int *numbers, int length)
{
	if (numbers == NULL || length <= 0)
		return -1;

	int start = 0;
	int end = length - 1;
	int mid = start;
	while (numbers[start] >= numbers[end])
	{
		if (end - start == 1)
		{
			mid = end;
			break;
		}
		mid = (start + end) / 2;

		//����±�start��end ��mid ָ�������������ͬ����ֻ��˳�����
		if (numbers[start] == numbers[end] && numbers[mid] == numbers[start])
			return Minorder(numbers, start, end);
		
		if (numbers[mid] >= numbers[start])
			start = mid;
		if (numbers[mid] <= numbers[end])
			end = mid;
	}

	return numbers[mid];
}
//{ 3, 4, 5, 1, 2 };
//1 0 1 1 1.           1 1 1 0 1

int main(int arg, char *args[])
{
	int numbers[5] = { 1, 1, 1, 0, 1 };
	int result = FindMin(numbers, 5);
	printf("%d\n", result);
	system("pause");
	return 0;
}