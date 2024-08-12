#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;

class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d)
	{
		cout << "Date(const Date& d)" << endl;
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

//	bool operator<(const Date& x)
//	{
//		if (_year < x._year)
//		{
//			return true;
//		}
//		else if (_year == x._year && _month < x._month)
//		{
//			return true;
//		}
//		else if (_year == x._year && _month == x._month && _day < x._day)
//		{
//			return true;
//		}
//
//		return false;
//	}
//
//	// d4 = d1
//	// d1 = d1
//	//Date& operator=(const Date& d)
//	//{
//	//	if (this != &d)
//	//	{
//	//		_year = d._year;
//	//		_month = d._month;
//	//		_day = d._day;
//	//	}
//
//	//	return *this;
//	//}
//
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//bool operator<(const Date& x1, const Date& x2)
//{
//	if (x1._year < x2._year)
//	{
//		return true;
//	}
//	else if (x1._year == x2._year && x1._month < x2._month)
//	{
//		return true;
//	}
//	else if (x1._year == x2._year && x1._month == x2._month && x1._day < x2._day)
//	{
//		return true;
//	}
//
//	return false;
//}
//
//
//int main()
//{
//	Date d1(2023, 4, 26);
//	Date d2(2023, 6, 21);
//
//	//d1 < d2; // 转换成operator<(d1, d2);
//	//operator<(d1, d2);
//
//	d1 < d2; // 转换成d1.operator<(d2);
//	d1.operator<(d2);
//
//	if (d1 < d2)
//	{
//
//	}
//
//	//d1 - d2;  // 有意义
//	//d1 + d2;  // 没意义
//	// 是否要重载运算符，这个运算符对这个类是否有意义
//
//	return 0;
//}

//-------------------------------------------------------------------------------------

//int main()
//{
//	Date d1(2023, 4, 26);
//	Date d2(2023, 6, 21);
//	// 已经存在的两个对象之间复制拷贝        -- 运算符重载函数
//	d1 = d2;
//
//	// 用一个已经存在的对象初始化另一个对象  -- 构造函数
//	//Date d3(d1);
//
//	int i, j, k;
//	i = j = k = 0;
//
//	Date d5, d4;
//	d5 = d4 = d1;
//
//	d1 = d1;
//
//	return 0;
//}


//-------------------------------------------------------------------------------------

#include"Date.h"
//
//void TestDate1()
//{
//	Date d1(2023, 4, 26);
//	d1 += 100;
//	d1.Print();
//
//	Date d2(2023, 4, 26);
//	//Date d3(d2 + 100);
//	Date d3 = d2 + 100;
//	d2.Print();
//	d3.Print();
//
//	// 用一个已经存在的对象初始化另一个对象  -- 构造函数
//	Date d4 = d2;  // 等价于 Date d4(d2);
//
//	//已经存在的两个对象之间复制拷贝        -- 运算符重载函数
//	d4 = d1;
//
//	//int i = 0, j = 1;
//	//j += i += 10;
//}
//
//void TestDate2()
//{
//	Date d1(2023, 4, 26);
//	// 都要++，前置++返回++以后的对象，后置++返回++之前的对象
//	++d1; // d1.operator++()
//	d1++; // d1.operator++(0)
//
//	Date d2(2023, 4, 26);
//	Date d3(2023, 4, 26);
//
//	bool ret1 = d2 < d3;
//
//	int i = 1, j = 2;
//	bool ret2 = i < j;
//}
//
//void TestDate3()
//{
//	Date d1(2023, 5, 5);
//	d1 -= 50;
//	d1.Print();
//
//	Date d2(2023, 5, 5);
//	d2 -= 100;
//	d2.Print();
//
//	Date d3(2023, 5, 5);
//	d3 -= 1000;
//	d3.Print();
//
//	Date d4(2023, 5, 5);
//	d4 -= 10000;
//	d4.Print();
//}
//
//void TestDate4()
//{
//	Date d1(2023, 5, 5);
//	d1 += 100;
//	d1.Print();
//
//	Date d2(2023, 5, 5);
//	d2 += -100;
//	d2.Print();
//
//	Date d3(2023, 5, 5);
//	d3 -= -100;
//	d3.Print();
//}
//
//void TestDate5()
//{
//	Date d1(2023, 5, 5);
//	Date ret1 = d1--; // d1.operator--(&d1, 0);
//	ret1.Print();
//	d1.Print();
//
//	Date d2(2023, 5, 5);
//	Date ret2 = --d2; // d1.operator--(&d1);
//	ret2.Print();
//	d2.Print();
//}
//
//void TestDate6()
//{
//	Date d1(2023, 5, 5);
//	Date d2(1949, 10, 1);
//
//	cout << d1 - d2 << endl;
//	cout << d2 - d1 << endl;
//}

//-------------------------------------------------------------------------------------

void TestDate7()
{
	Date d1(2023, 5, 5);
	d1 += 100;

	// 流插入
	cout << d1; // operator<<(cout, d1);
	operator<<(cout, d1);

	//d1 << cout; // d1.operator<<(cout); 
	//d1.operator<<(cout);


	Date d2(2023, 5, 5);
	Date d3(1949, 10, 1);

	//d1 = d2 = d3;

	cout << d2 << d3 << d1;

	cin >> d1 >> d2;
	cout << d2 << d1;

	//Date d4(2023, 13, 1);
	//cout << d4;
}

//void TestDate8()
//{
// 
//	Date d1(2023, 5, 5);
// //void Print();()里面是Date* this
//	d1.Print();//->d1.Print(&d1);传递的是Date* this，权限的平移
//
//	const Date d2(2023, 5, 5);
// //void Print();()里面是Date* this
//	d2.Print();//->d2.Print(&d2);传递的是const Date* this，权限的放大。
// //只要把（）里面的Date* this改成const Date* this就是权限的缩小了
// //void Print() const;//const修饰了*this。之所以加在这里，是因为this指针不能显示的写。加上const后普通对象和const对象都能用了
// //const不是什么都能加的，要修改成员变量的函数不能加，比如+=
//
//	d1 + 100;
//	d2 + 100;
//
//	d1 < d2;
//	d2 < d1;
//}
//
//int main()
//{
//	TestDate8();
//
//	return 0;
//}