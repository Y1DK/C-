#define _CRT_SECURE_NO_WARNINGS 1
#include "Date.h"

//Date::Date是指定类域
Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}

bool Date::operator<(const Date& x)
{
	if (_year < x._year)
	{
		return true;
	}
	else if (_year == x._year && _month < x._month)
	{
		return true;
	}
	else if (_year == x._year && _month == x._month && _day < x._day)
	{
		return true;
	}

	return false;
}

bool Date::operator==(const Date& x)
{
	return _year == x._year
		&& _month == x._month
		&& _day == x._day;
}

// 复用
// d1 <= d2，就是*this < x || *this == x
bool Date::operator<=(const Date& x)
{
	return *this < x || *this == x;
}

bool Date::operator>(const Date& x)
{
	return !(*this <= x);
}

bool Date::operator>=(const Date& x)
{
	return !(*this < x);
}

bool Date::operator!=(const Date& x)
{
	return !(*this == x);
}

//获得天数
int Date::GetMonthDay(int year, int month)
{
	static int daysArr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	//if (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) && month == 2)
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) )
	{
		return 29;
	}
	else
	{
		return daysArr[month];
	}
}

//+=
Date& Date::operator+=(int day)
{
	_day += day;//把天加上
	//如果天数加上大于当前月天数
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		++_month;
		if (_month == 13)
		{
			++_year;
			_month = 1;
		}
	}
	//如果天数加上小于当前月天数，直接返回
	return *this;
}

// d1 + 100
//+
Date Date::operator+(int day)
{
	Date tmp(*this);//tmp是一个局部变量，是当前日期的副本
	tmp += day;
	return tmp;//传值返回

	/*
	Date tmp(*this);//拷贝构造
	tmp._day += day;
	while (tmp._day > GetMonthDay(tmp._year, tmp._month))
	{
		tmp._day -= GetMonthDay(tmp._year, tmp._month);
		++tmp._month;
		if (tmp._month == 13)
		{
			++tmp._year;
			tmp._month = 1;
		}
	}
	return tmp;//出了作用域tmp会被销毁，所以不能用传引用返回
	*/
}

// 前置++
Date& Date::operator++()
{
	*this += 1;
	return *this;
}

// 后置++
// 增加这个int参数不是为了接收具体的值，仅仅是占位，跟前置++构成重载，方便区分
Date Date::operator++(int)
{
	Date tmp = *this;
	*this += 1;

	return tmp;
}