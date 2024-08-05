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
	// 成员函数
	void Init(int defaultCapacity = 4);

	// 类里面定义的函数默认就是inline
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
	// 成员变量
	int* a;         // 声明
	int top;
	int capacity;
};