#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "StackWithMin.h"


void Test(const char* testname, const StackWithMin<int>& stack, int expected)
{
	printf("%s begins: ", testname);

	if (expected == stack.Min())
		printf("passed.\n");
	else
		printf("failed.\n");
}

int main()
{
	
	StackWithMin<int> stack;
	stack.push(3);
	Test("Test1", stack, 3);

	stack.push(4);
	Test("Test2", stack, 3);

	stack.push(2);
	Test("Test3", stack, 2);

	stack.push(3);
	Test("Test4", stack, 2);

	stack.pop();
	Test("Test5", stack, 2);

	stack.pop();
	Test("Test6", stack, 3);

	stack.pop();
	Test("Test7", stack, 3);

	stack.push(0);
	Test("Test8", stack, 0);

	system("pause");
	return 0;
}