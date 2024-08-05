#define _CRT_SECURE_NO_WARNINGS 1
#include"Func.h"

//void f(int i)
//{
//	cout << i << endl;
//}
//
//void test()
//{
//	f(10);
//}

void Stack::Init(int defaultCapacity)
{
	a = (int*)malloc(sizeof(int) * capacity);
	if (nullptr == a)
	{
		perror("malloc");
		return;
	}

	capacity = defaultCapacity;
	top = 0;
}

