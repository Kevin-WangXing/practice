
#pragma once
#include <stack>
#include <exception>

using namespace std;

template<typename T> class CQueue
{
public:
	CQueue(void);
	~CQueue(void);

	void appendTail(const T& mode);
	T deleteHead();

private:
	stack<T> stack1;
	stack<T> stack2;
};

template<typename T> CQueue<T>::CQueue(void)
{

}

template<typename T> CQueue<T>::~CQueue(void)
{

}
template<typename T> void CQueue<T>::appendTail(const T& mode)
{
	stack1.push(mode);
}
template<typename T> T CQueue<T>::deleteHead()
{
	if (stack2.size() <= 0)//此处很是关键，如果没有这个判断，在插入就会出错
	{
		while (stack1.size() > 0)
		{
			T& data = stack1.top();
			stack1.pop();
			stack2.push(data);
		}
	}

	if (stack2.size() == 0)
		printf("queue is empty");
	T head = stack2.top();
	stack2.pop();

	return head;
}