/*

// ������9:�Ʋ���������
��Ŀ��дһ������������n����쳲�������Fibonacci�����еĵ�n�
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <Windows.h>
#include <algorithm>

#include "Queue.h"

void Test(char actual, char ecpected)
{
	if (actual == ecpected)
		printf("passed.\n");
	else
		printf("failed.\n");
}

int main(int arg, char *args[])
{
	CQueue<char> queue;

	queue.appendTail('a');
	queue.appendTail('b');
	queue.appendTail('c');

	char head = queue.deleteHead();
	Test(head, 'a');

	queue.appendTail('e');
	head = queue.deleteHead();
	Test(head, 'b');
	system("pause");
	return 0;
}