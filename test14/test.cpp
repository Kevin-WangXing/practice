/*

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <Windows.h>
#include <algorithm>

int maxCutting(int length)
{
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;

	int *products = new int[length + 1];
	memset(products, 0, sizeof(length + 1));

	products[0] = 0;
	products[1] = 1;
	products[2] = 2;
	products[3] = 3;

	int max = 0;
	for (int i = 4; i <= length; i++)
	{
		for (int j = 1; j <= i / 2; j++)
		{
			int product = products[j] * products[i - j];
			if (max < product)
				max = product;
			products[i] = max;
		}
	}

	max = products[length];
	delete[] products;

	return max;
}

void Test1()
{
	int result = maxCutting(50);
	printf("Test1 result: %d", result);
}

int main(int arg, char *args[])
{
	Test1();
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