#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void ChangeArray(int *array, int length)//只能检测 123456， 而124456就不行了
{
	int count2 = 0;
	for (int i = 0; i < length; i++)
	{
		if (array[i] % 2 == 0)
		{
			count2++;
		}
	}
	for (int i = 0; i < length; i++)
	{
		if (array[i] % 2 == 0)
		{
			int temp = array[i];
			for (int j = i ; j < length - 1; j++)
			{
				array[j ] = array[j + 1];
			}
			
		}
		
	}
}

//方法一
void ReorderOddEven(int *pData, unsigned int length)
{
	if (pData == NULL || length == 0)
	{
		return;
	}

	int *pBegin = pData;
	int *pEnd = pData + length - 1;

	while (pBegin < pEnd)
	{
		//第一个指针向后移动，知道遇到偶数
		while (pBegin < pEnd && (*pBegin & 0x1) != 0)
		{
			pBegin++;
		}
		//向前移动，知道遇到偶数
		while (pBegin < pEnd && (*pEnd & 0x1) == 0)
		{
			pEnd--;
		}

		if (pBegin < pEnd)
		{
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}

}


//方法二

void Reorder(int *pData, unsigned int length, bool(*func)(int));
bool isEven(int n);

void ReorderOddEvent_2(int *pData, unsigned int length)
{
	Reorder(pData, length, isEven);
}

void Reorder(int *pData, unsigned int length, bool(*func)(int))
{
	if (pData == NULL || length == 0)
	{
		return;
	}

	int *pBegin = pData;
	int *pEnd = pData + length - 1;

	while (pBegin < pEnd)
	{
		while (pBegin < pEnd && !func(*pBegin))
			pBegin++;

		while (pBegin < pEnd && func(*pEnd))
			pEnd--;
	}

	if (pBegin < pEnd)
	{
		int temp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = temp;
	}
}

bool isEvent(int n)
{
	return (n & 1) == 0;
}

int main()
{

	int array[6] = { 1, 2, 4, 4, 8, 6 };
	int length = sizeof(array) / sizeof(int);
	ReorderOddEven(NULL, 0);

	for (int i = 0; i < 6; i++)
	{
		printf("%d\t", array[i]);
	}

	system("pause");
	return 0;
}