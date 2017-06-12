/*

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <Windows.h>
#include <algorithm>

int NumberOf1(int num)
{
	int count = 0;
	unsigned int flag = 1;
	while (flag)
	{
		if (num & flag)
			count++;
		flag = flag << 1;
	}

	return count;
}

int NUmberOf(int n)
{
	int count = 0;
	while (n)
	{
		++count;
		n = (n - 1) & n;
	}
	return count;
}

int main(int arg, char *args[])
{
	NumberOf1(9);
	NUmberOf(9);
	//Test1();
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