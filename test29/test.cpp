#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>


//打印数字
void PrintNumber(int num)
{
	printf("%d\t", num);
}

//打印每一圈
void PrintMatrixIncircle(int** numbers, int rows, int columns, int start)
{
	int endX = columns - start - 1;
	int endY = rows - start - 1;

	//从左到右打印一行
	for (int i = start; i <= endX; i++)
	{
		int number = numbers[start][i];
		PrintNumber(number);
	}

	//从上到下
	if (start < endY)
	{
		for (int i = start + 1; i <= endY; i++)
		{
			int num = numbers[i][endY];
			PrintNumber(num);
		}
	}

	//从右到左
	if (start < endY && start < endX)
	{
		for (int i = endX - 1; i >= start; i--)
		{
			int num = numbers[endY][i];
			PrintNumber(num);
		}
	}

	//从下到上
	if (endX > start && endY > start + 1)
	{
		for (int i = endY - 1; i > start; i--)
		{
			int num = numbers[i][start];
			PrintNumber(num);
		}
	}
}

void PrintMatrix(int** numbers, int rows, int columns)
{
	if (numbers == NULL || rows <= 0 || columns <= 0)
		return;
	int start = 0;
	//从起始坐标找规律得到终止条件
	while (rows > start * 2 && columns > start * 2)
	{
		PrintMatrixIncircle(numbers, rows, columns, start);
		start++;
	}

}

void Test1(int rows, int columns)
{
	printf("Test Begin: %d rows, %d columns.\n", rows, columns);
	if (rows < 1 || columns < 1)
		return;
	int **numbers = new int*[4];
	for (int i = 0; i < rows; i++)
	{
		numbers[i] = new int[columns];
		for (int j = 0; j < columns; j++)
		{
			numbers[i][j] = i * columns + j + 1;
			//printf("%d\t", numbers[i][j]);
		}
	}
	printf("\n");
	PrintMatrix(numbers, rows, columns);
	printf("\n");

	for (int i = 0; i < rows; i++)
		delete[](int*)numbers[i];

	delete[] numbers;
}

int main()
{
	
	Test1(4, 4);

	Test1(1, 1);

	Test1(1, 5);

	system("pause");
	return 0;
}