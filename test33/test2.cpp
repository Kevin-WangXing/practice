#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

//检测是不是前序
bool Verity(int sequence[], int length)
{
	if (sequence == NULL || length <= 0)
		return false;

	int root = sequence[0];
	int i = 1;
	for (i; i < length ; i++)
	{
		if (sequence[i] > root)
			break;
	}
	int j = i;
	for (j; j < length ; j++)
	{
		if (sequence[j] < root)
			return false;
	}

	bool left = true;
	if (i > 1)
		left = Verity(sequence + 1, i - 1);

	bool right = true;
	if (i < length)
		right = Verity(sequence + i, length - i);

	return (left && right);
}

//检测是不是后序
bool VeritySequenceOfBST(int sequence[], int length)
{
	if (sequence == NULL || length <= 0)
		return false;

	int root = sequence[length - 1];
	int i = 0;
	for (i; i < length - 1; i++)
	{
		if (sequence[i] > root)
			break;
	}
	int j = i;
	for (j; j < length - 1; j++)
	{
		if (sequence[j] < root)
			return false;
	}

	bool left = true;
	if (i > 0)
		left = VeritySequenceOfBST(sequence, i);

	bool right = true;
	if (i < length - 1)
		right = VeritySequenceOfBST(sequence + i, length - i - 1);

	return (left && right);
}

void Test(const char* testName, int sequenec[], int length, bool expected)
{
	if (testName != NULL)
		printf("BST %s begins: ", testName);

	if (VeritySequenceOfBST(sequenec, length) == expected)
		printf("Passed.\n");
	else
		printf("failed.\n");
}

void test(const char* testName, int sequenec[], int length, bool expected)
{

	if (testName != NULL)
		printf("qian %s begins: ", testName);

	if (Verity(sequenec, length) == expected)
		printf("Passed.\n");
	else
		printf("failed.\n");
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16

void Test_1()
{
	int data[] = { 10, 6, 4, 8, 14, 12, 16 };
	test("test1", data, sizeof(data) / sizeof(int), true);
}

void Test1()
{
	int data[] = { 4, 8, 6, 12, 16, 14, 10 };
	Test("test1", data, sizeof(data) / sizeof(int), true);
}

//           5
//          / \
//         4   7
//            /
//           6

void Test_2()
{
	int data[] = {5, 4, 7, 6};
	test("test2", data, sizeof(data) / sizeof(int), true);
}
void Test2()
{
	int data[] = { 4, 6, 7, 5 };
	Test("Test2", data, sizeof(data) / sizeof(int), true);
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1

void Test_3()
{
	int data[] = { 5, 4, 3, 2, 1 };
	test("test3", data, sizeof(data) / sizeof(int), true);
}
void Test3()
{
	int data[] = { 1, 2, 3, 4, 5 };
	Test("Test3", data, sizeof(data) / sizeof(int), true);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
void Test_4()
{
	int data[] = { 1, 2, 3, 4, 5};
	test("test4", data, sizeof(data) / sizeof(int), true);
}
void Test4()
{
	int data[] = { 5, 4, 3, 2, 1 };
	Test("Test4", data, sizeof(data) / sizeof(int), true);
}

// 树中只有1个结点

void Test_5()
{
	int data[] = { 5 };
	test("test3", data, sizeof(data) / sizeof(int), true);
}
void Test5()
{
	int data[] = { 5 };
	Test("Test5", data, sizeof(data) / sizeof(int), true);
}

void Test_6()
{
	int data[] = { 7, 4, 6, 5 };
	Test("Test6", data, sizeof(data) / sizeof(int), false);
}

void Test6()
{
	int data[] = { 7, 4, 6, 5 };
	Test("Test6", data, sizeof(data) / sizeof(int), false);
}

void Test7()
{
	int data[] = { 4, 6, 12, 8, 16, 14, 10 };
	Test("Test7", data, sizeof(data) / sizeof(int), false);
}

void Test8()
{
	Test("Test8", nullptr, 0, false);
}

int main()
{
	Test_1();
	Test_2();
	Test_3();
	Test_4();
	Test_5();
	Test_6();


	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();
	Test8();
	system("pause");
	return 0;
}