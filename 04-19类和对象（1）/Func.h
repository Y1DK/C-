#pragma once
#include <iostream>
using namespace std;

//inline void f(int i);

inline void f(int i)
{
	cout << i << endl;
}

void test();

class Stack
{
public:
	// ��Ա����
	void Init(int defaultCapacity = 4);

	// �����涨��ĺ���Ĭ�Ͼ���inline
	void Push(int x)
	{
		//...
		a[top++] = x;
	}

	void Destroy()
	{
		free(a);
		a = nullptr;
		top = capacity;
	}

	int Top()
	{
		return a[top - 1];
	}

	// ....
//private:
	// ��Ա����
	int* a;         // ����
	int top;
	int capacity;
};