/*

// ������9:�Ʋ���������
��Ŀ��дһ������������n����쳲�������Fibonacci�����еĵ�n�
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <Windows.h>
#include <algorithm>

//�ݹ�ʵ��
long long Fibonacci(unsigned int n)
{
	if (n <= 1)
		return n;
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}
//�ǵݹ�
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