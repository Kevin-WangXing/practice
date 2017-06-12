/*

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <Windows.h>
#include <algorithm>

//����ո���������֮��
int getDigitSum(int numbers)
{
	int sum = 0;
	while (numbers > 0)
	{
		sum = sum + numbers % 10;
		numbers /= 10;
	}
	return sum;
}

bool check(int threshold, int rows, int cols, int row, int col, bool *visited)
{
	if (row >= 0 && row < rows && col >= 0 && col < cols
		&& getDigitSum(row) + getDigitSum(col) <= threshold && !visited[row*cols + col])
		return true;
	return false;
}

int movingCountCore(int threshold, int rows, int cols, int row, int col, bool *visited)
{
	int count = 0;
	if (check(threshold, rows, cols, row, col, visited))
	{
		visited[row*cols + col] = true;

		count = 1 + movingCountCore(threshold, rows, cols, row - 1, col, visited)
			+ movingCountCore(threshold, rows, cols, row, col - 1, visited)
			+ movingCountCore(threshold, rows, cols, row + 1, col, visited)
			+ movingCountCore(threshold, rows, cols, row, col + 1, visited);
	}
	return count;

}

int movingCount(int threshold, int rows, int cols)
{
	if (threshold < 0 || rows <= 0 || cols <= 0)
		return 0;

	bool *visited = new bool[rows * cols];
	memset(visited, 0, rows*cols);

	for (int i = 0; i < rows*cols; i++)
		visited[i] = false;

	int count = movingCountCore(threshold, rows, cols, 0, 0, visited);
	delete[] visited;
	return count;
}

// ������ж���
void Test1()
{
	int result = movingCount(5, 10, 10);
	printf("test1 begin put: %d\n", result);//21
}

// ������ж���
void Test2()
{
	int result = movingCount(15, 20, 20);
	printf("test2 begin put: %d\n", result);//359
}
// ����ֻ��һ�У�������ֻ�ܵ��ﲿ�ַ���
void Test3()
{
	int result = movingCount(10, 1, 100);
	printf("test3 begin put: %d\n", result);//29
}

// ����ֻ��һ�У��������ܵ������з���
void Test4()
{
	int result = movingCount(10, 1, 10);
	printf("test4 begin put: %d\n", result);//10
}

// ����ֻ��һ�У�������ֻ�ܵ��ﲿ�ַ���
void Test5()
{
	int result = movingCount(15, 100, 1);
	printf("test5 begin put: %d\n", result);//79
}

// ����ֻ��һ�У��������ܵ������з���
void Test6()
{
	int result = movingCount(15, 10, 1);
	printf("test6 begin put: %d\n", result);//10
}

// ����ֻ��һ��һ��
void Test7()
{
	int result = movingCount(15, 1, 1);
	printf("test7 begin put: %d\n", result);//1
}

// ����ֻ��һ��һ��
void Test8()
{
	int result = movingCount(0, 1, 1);
	printf("test8 begin put: %d\n", result);//1
}

// �����˲��ܽ�������һ������
void Test9()
{
	int result = movingCount(-10, 10, 10);
	printf("test9 begin put: %d\n", result);//0
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