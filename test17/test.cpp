/*

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <Windows.h>
#include <algorithm>

void PrintNumbers(char* numbers)
{
	bool isBeginning0 = true;
	int nLength = strlen(numbers);

	for (int i = 0; i < nLength; i++)
	{
		if (isBeginning0 && numbers[i] != '0')
			isBeginning0 = false;
		if (!isBeginning0)
			printf("%c", numbers[i]);
	}

	printf("\t");
}

//方法一
bool increment(char *numbers)
{
	bool isoverflow = false;
	int nTakeover = 0;
	int Length = strlen(numbers);

	for (int i = Length - 1; i >= 0; i--)
	{
		int nSum = numbers[i] - '0' + nTakeover;
		if (i == Length - 1)
			nSum++;
		if (nSum >= 10)
		{
			if (i == 0)
				isoverflow = true;
			else
			{
				nSum -= 10;
				nTakeover = 1;
				numbers[i] = '0' + nSum;
			}
		}
		else
		{
			numbers[i] = '0' + nSum;
			break;
		}
	}

	return isoverflow;
}

void PrintToMaxOfNDigits_1(int n)
{
	if (n <= 0)
		return;
	char *numbers = new char[n + 1];
	memset(numbers, '0', n);
	numbers[n] = '\0';
	while (!increment(numbers))
	{
		//PrintNumbers(numbers);
		int nLength = strlen(numbers);
		for (int i = 0; i < nLength; i++)
		{
			printf("%c", numbers[i]);
		}
		printf("\t");
	}

	delete[] numbers;
}

//方法二
void PrintToMaxOfNDigitsRecursively(char* numbers, int length, int index)
{
	if (index == length - 1)
	{
		PrintNumbers(numbers);
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		numbers[index + 1] = i + '0';
		PrintToMaxOfNDigitsRecursively(numbers, length, index + 1);
	}
}

void PrintToMaxOfNDigits_2(int n)
{
	if (n <= 0)
		return;

	char* numbers = new char[n + 1];
	memset(numbers, '0', n);
	numbers[n] = '\0';

	for (int i = 0; i < 10; i++)
	{
		numbers[0] = i + '0';
		PrintToMaxOfNDigitsRecursively(numbers, n, 0);
	}
	delete[] numbers;
}


int main(int arg, char *args[])
{
	
	PrintToMaxOfNDigits_2(3);
	//Test2();
	//Test3();
	//Test4();
	//Test5();
	//Test6();
	//Test7();
	//Test8();
	//Test9();
	system("pause");
	return 0;
}