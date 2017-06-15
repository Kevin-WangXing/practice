#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

//A[.[B]][e|EC]
//1.ɨ��A C�Ƿ���+ - ����
bool scanInterger(const char** str);
//2.�ж��Ƿ�Ϊ0-9
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
		//����||��ԭ��
		//С������û��֤�鲿��  .123 = 0.123
		//С����������û������  13. = 13.0
		//ǰ�󶼿���������   12.12
		numeric = scanUnsignedInter(&str) || numeric;
	}
	if (*str == 'e' || *str == 'E')
	{
		++str;
		//��&&��ԭ��
		//��Eǰ��û�����ֵ�ʱ�䣬���ܱ�ʾ����  .e5
		//��E����û�����ֲ��ܱ�ʾ����    E5.
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