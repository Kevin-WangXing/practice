/*

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <Windows.h>
#include <algorithm>

double PowerWithUnsignedExponent(double base, int exponent)
{
	double result = 1.0;
	for (int i = 1; i <= exponent; i++)
	{
		result *= base;
	}
	return result;
}

double PowerWithUnsignedExponent_1(double base, int exponent)
{
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;

	double result = PowerWithUnsignedExponent_1(base, exponent >> 1);
	result *= result;
	if ((exponent & 0x1) == 1)
		result *= base;

	return result;
}

double Power(double base, int exponent)
{
	if (base == 0.0  && exponent < 0)
	{
		printf("no meaning.\n");
		return 0.0;
	}
	if (exponent == 0 || base == 0.0)
		return 1.0;
	int FlagExponent = 0;//0 +  1 -

	if (exponent < 0)
	{
		FlagExponent = 1;
		exponent = -exponent;
	}
	double result = PowerWithUnsignedExponent_1(base, exponent);

	

	if (FlagExponent == 1)
		result = 1.0 / result;

	return result;
}

int main(int arg, char *args[])
{
	double result = Power(2, 4);
	printf("%f\n", result);
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