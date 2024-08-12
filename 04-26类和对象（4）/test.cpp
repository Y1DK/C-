﻿#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


/********************************************************  5.赋值运算符重载  **************************************************/
/********************************************************  5.1 运算符重载  **************************************************/

/*
C++为了增强代码的可读性引入了运算符重载，运算符重载是具有特殊函数名的函数，也具有其
返回值类型，函数名字以及参数列表，其返回值类型与参数列表与普通的函数类似。
函数名字为：关键字operator后面接需要重载的运算符符号。
函数原型：返回值类型 operator操作符(参数列表)

注意：
不能通过连接其他符号来创建新的操作符：比如operator@
重载操作符必须有一个类类型参数
用于内置类型的运算符，其含义不能改变，例如：内置的整型+，不 能改变其含义
作为类成员函数重载时，其形参看起来比操作数数目少1，因为成员函数的第一个参数为隐
藏的this
.* :: sizeof ?: . 注意以上5个运算符不能重载。这个经常在笔试选择题中出现。
*/

//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	Date(const Date& d)
//	{
//		cout << "Date(const Date& d)" << endl;
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//	//比较的结果就是这里的bool值
//	//这里实际上还是两个参数，因为这里面还有一个隐藏的参数this指针
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
//	 /*d4 = d1
//	 d1 = d1
//	Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//
//		return *this;
//	}*/
//
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};

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


//int main()
//{
//	Date d1(2023, 4, 26);
//	Date d2(2023, 6, 21);
//
//	//调用bool operator<(const Date& x1, const Date& x2)
//	//d1 < d2; // 转换成operator<(d1, d2);
//	//operator<(d1, d2);
//
//	//调用bool operator<(const Date& x)
//	//这里的bool operator<(const Date& x)之所以写成类的成员函数，是因为这样就可以访问私有域了。
//	d1 < d2; // 转换成d1.operator<(d2);
//	d1.operator<(d2);
//
//	/*if (d1 < d2)
//	{
//
//	}*/
//
//	//d1 - d2;  // 有意义
//	//d1 + d2;  // 没意义
//	// 是否要重载运算符，这个运算符对这个类是否有意义
//
//	return 0;
//}

//-------------------------------------------------------------------------------------

/*
5.2 赋值运算符重载
1. 赋值运算符重载格式
参数类型：const T&，传递引用可以提高传参效率
返回值类型：T&，返回引用可以提高返回的效率，有返回值目的是为了支持连续赋值
检测是否自己给自己赋值
返回*this ：要复合连续赋值的含义
2. 赋值运算符只能重载成类的成员函数不能重载成全局函数
原因：赋值运算符如果不显式实现，编译器会生成一个默认的。此时用户再在类外自己实现
一个全局的赋值运算符重载，就和编译器在类中生成的默认赋值运算符重载冲突了，故赋值
运算符重载只能是类的成员函数。
3. 用户没有显式实现时，编译器会生成一个默认赋值运算符重载，以值的方式逐字节拷贝。注
意：内置类型成员变量是直接赋值的，而自定义类型成员变量需要调用对应类的赋值运算符
重载完成赋值。

默认生成赋值重载和拷贝构造行为一样：
1.内置类型成员--值拷贝/浅拷贝
2.自定义类型成员会去调用他的赋值重载

Date和MyQueue不需要我们实现赋值重载
Data是内置类型成员--值拷贝/浅拷贝
MyQueue全是自定义类型，不需要我们实现赋值重载

Stack需要我们自己实现，因为默认生成的是浅拷贝
*/

//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	Date(const Date& d)
//	{
//		cout << "Date(const Date& d)" << endl;
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//	//赋值运算符重载
//	
//	//最简单版本的赋值运算符
//	//有一个问题：日期类是浅拷贝
//	/*
//	如果：main函数的时候这么写：
//	这里是可以的，因为0赋值给k，k赋值给j...
//	int i, j, k;
//	i = j = k = 0;
//
//	这么写就会出错啦
//	因为d1的返回值是void，这样就不能赋值给d4了
//	Date d5, d4;
//	d5 = d4 = d1;
//	
//	*/
//	/*void operator=(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//
//		return *this;
//	}*/
//
//	//d4 = d1;
//	//d1 = d1;
//	//这里就不调用拷贝构造了，因为这里是引用返回，不是传值返回
//	//传值返回，返回的是值的拷贝，所以要调用拷贝构造
//	//引用返回，返回的不是值的拷贝，返回的是它的别名，所以不调用拷贝构造
   //Date& operator=(const Date& d)//返回的是*this这个对象的别名，*this是d4
   //{
	  // if (this != &d)//以预防d1 = d1;的情况
	  // {
		 //  _year = d._year;
		 //  _month = d._month;
		 //  _day = d._day;
	  // }

	  // return *this;
   //}
//
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main()
//{
//	Date d1(2023, 4, 26);
//	Date d2(2023, 6, 21);
//	// 已经存在的两个对象之间复制拷贝 -- 运算符重载函数
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
//	//那如果出现这样的赋值呢？
//	//正常可能不会有，但是别人输错了呢？
//	d1 = d1;
//
//	return 0;
//}

//-------------------------------------------------------------------------------------

#include"Date.h"

void TestDate1()
{
	//+=
	Date d1(2023, 4, 26);
	d1 += 100;
	d1.Print();//2023-8-4

	//+
	//如果我i+100，i是不是不应该变？
	Date d2(2023, 4, 26);
	//Date d3(d2 + 100);
	Date d3 = d2 + 100;
	d2.Print();//2023-4-26
	d3.Print();//2023-8-4

	// 用一个已经存在的对象初始化另一个对象  -- 构造函数
	Date d4 = d2;  // 等价于 Date d4(d2);

	//已经存在的两个对象之间复制拷贝        -- 运算符重载函数
	d4 = d1;

	//int i = 0, j = 1;
	//j += i += 10;
}

void TestDate2()
{
	Date d1(2023, 4, 26);
	// 都要++，前置++返回++以后的对象，后置++返回++之前的对象
	++d1; // d1.operator++()
	d1++; // d1.operator++(0)
}

int main()
{
	TestDate1();
	TestDate2();

	return 0;
}
