/*
*  test1:赋值运算符函数
*   题目： 如下为类型CMyString的声明，请为该类型添加赋值运算符函数
class CMyString
{
public:
CMyString(char* pData = nullptr);
CMyString(const CMyString& str);
~CMyString(void);

private:
char *m_pData;
};
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <Windows.h>

class CMyString
{
public:
	CMyString(char* pData = nullptr);
	CMyString(const CMyString& str);
	~CMyString(void);

	CMyString& operator = (const CMyString& str);

	void Print();

private:
	char *m_pData;
};

CMyString::CMyString(char* pData)
{
	if (pData == NULL)
	{
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
	else
	{
		int length = strlen(pData);
		m_pData = new char[length + 1];
		strcpy(m_pData, pData);
	}
}

CMyString::CMyString(const CMyString& str)
{
	int length = strlen(str.m_pData);
	m_pData = new char[length + 1];
	strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString()
{
	delete[] m_pData;
}

CMyString& CMyString::operator=(const CMyString& str)
{
	if (this == &str)
	{
		return *this;
	}

	delete[] m_pData;
	m_pData = NULL;
	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);

	return *this;
}

//-------------测试代码---------------

void CMyString::Print()
{
	printf("%s\n", m_pData);
}
void Test1()
{
	printf("Test1 begin:\n");

	char* text = "Hello world";

	CMyString str1(text);
	CMyString str2;
	str2 = str1;

	printf("The Expected result is: %s\n", text);

	printf("The actul result is:");
	str2.Print();
}
//赋值给自己
void Test2()
{
	printf("Test2 begin:\n");

	char *test = "Hello world";
	CMyString str1(test);
	//CMyString str1 = "Hello world";
	str1 = str1;

	printf("The Expected result is: %s\n", test);

	printf("The actul result is:");
	str1.Print();
}

void Test3()
{
	printf("Test3 begin\n");

	char *test = "hello world";

	CMyString str1(test);
	CMyString str2, str3;
	str3 = str2 = str1;
	printf("The Expected result is: %s\n", test);

	printf("The actul result is:");
	str2.Print();

	printf("The Expected result is: %s\n", test);

	printf("The actul result is:");
	str3.Print();
}

int main(int arg, char *args[])
{
	Test1();
	Test2();
	Test3();
	system("pause");
	return 0;
}