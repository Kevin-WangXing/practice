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

bool FindArray(int array[][4], int col, int row, int num)
{
	if (array == NULL)
		return false;

	int col1 = 0;
	int row1 = row - 1;

	while ((row1 >= 0) && col1 <= 3)
	{
		if (array[row1][col1] == num)
			return true;
		else if (array[row1][col1] > num)
		{
			row1--;
			continue;
		}
		else
			col1++;
	}
	return false;
}

void Test1()
{
	int array[][4] = { 1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15 };
	//int **array = { 1, 2 };
	int col = sizeof(array[0]) / sizeof(int);
	int row = sizeof(array) / col / sizeof(int);

	//printf("row %d col %d", row, col);
	bool result = FindArray(array, col, row, 1);
	if (result)
		printf("Find\n");
	else
		printf("No find");
}

int main(int arg, char *args[])
{
	Test1();
	system("pause");
	return 0;
}