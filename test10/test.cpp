/*

// 面试题9:菲波那切数列
题目：写一个函数，输入n，求斐波那契（Fibonacci）数列的第n项。
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <Windows.h>
#include <algorithm>

//递归实现
long long Fibonacci(unsigned int n)
{
	if (n <= 1)
		return n;
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}
//非递归
long long Fib(unsigned int n)
{
	int result[2] = { 0, 1 };
	if (n < 2)
		return result[n];

	long long fibone = 1;
	long long fibtwo = 0;
	long long fibresult = 0;
	for (unsigned int i = 2; i <= n; i++)
	{
		fibresult = fibone + fibtwo;
		fibtwo = fibone;
		fibone = fibresult;
		
	}
	return fibresult;
}

int main(int arg, char *args[])
{
	printf("digui %6d\n", Fibonacci(9));
	printf("fei   %6d\n", Fib(9));
	system("pause");
	return 0;
}