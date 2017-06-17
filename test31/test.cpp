#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <stack>

bool isPoporder(const int* pPush, const int* pPop, int length)
{
	bool bPossible = false;

	if (pPush != NULL && pPop != NULL && length > 0)
	{
		const int* pNextpush = pPush;
		const int* pNextPop = pPop;

		//printf("%d %d", *pNextpush, *pNextPop);
		std::stack<int> stackData;

		while (pNextPop - pPop < length)
		{
			//������ջ��ջ��Ԫ�ز���Ҫ������Ԫ��  ��ѹ��һЩ������ջ
			while (stackData.empty() || stackData.top() != *pNextPop)
			{
				//����������ֶ���ջ�ˣ��˳�ѭ��
				if (pNextPop - pPush == length)
					break;

				stackData.push(*pNextpush);

				pNextpush++;
			}

			if (stackData.top() != *pNextPop)
				break;

			stackData.pop();
			pNextPop++;
		}
		if (stackData.empty() && pNextPop - pPop == length)
			return true;
	}
	return false;
}

void Test(const char* testname, const int* pPush, const int* pPop, int length, bool expected)
{
	printf("%s begin.\n", testname);

	if (isPoporder(pPush, pPop, length) == expected)
		printf("Passed.\n");
	else
		printf("failed.\n");
}

void Test1()
{
	const int length = 5;
	const int push[length] = { 1, 2, 3, 4, 5 };
	const int pop[length] = { 4, 5, 3, 2, 1 };

	Test("test1", push, pop, 5, true);
}

void Test2()
{
	const int length = 5;
	const int push[length] = { 1, 2, 3, 4, 5 };
	const int pop[length] = { 4, 5, 2, 3, 1 };

	Test("test2", push, pop, 5, false);
}

void Test3()
{
	const int length = 1;
	const int push[length] = { 1 };
	const int pop[length] = { 4 };

	Test("test1", push, pop, 1, false);
}

int main()
{
	//Test1();
	//Test2();
	Test3();
	system("pause");
	return 0;
}