#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

//A[.[B]][e|EC]
//1.扫描A C是否有+ - 符号
bool scanInterger(const char** str);
//2.判断是否为0-9
bool scanUnsignedInter(const char** str);

bool scanInterger(const char** str)
{
	if (**str == '+' || **str == '-')
		++(*str);
	return scanUnsignedInter(str);
}

bool scanUnsignedInter(const char** str)
{
	const char* before = *str;
	while (**str != '\0' && **str >= '0' && **str <= '9')
		(*str)++;
	/*printf("d%d    %s\n", *str, *str);
	printf("d%d    %s\n", before, before);*/
	return *str > before;
}

bool isNumeric(const char* str)
{
	if (str == NULL)
	{
		printf("invalid input.\n");
		return false;
	}

	bool numeric = scanInterger(&str);

	if (*str == '.')
	{
		++str;
		//加上||的原因
		//小数可以没有证书部分  .123 = 0.123
		//小数点后面可以没有数字  13. = 13.0
		//前后都可以有数字   12.12
		numeric = scanUnsignedInter(&str) || numeric;
	}
	if (*str == 'e' || *str == 'E')
	{
		++str;
		//加&&的原因
		//当E前面没有数字的时间，不能表示数字  .e5
		//当E后面没有数字不能表示数字    E5.
		numeric = numeric&&scanInterger(&str);
	}

	return numeric && *str == '\0';
}


int main()
{

	const char *str = "12e";
	isNumeric(str);

	system("pause");
	return 0;
}