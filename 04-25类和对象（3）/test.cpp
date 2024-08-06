#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
#include<stdbool.h>

using namespace std;


/********************************************************  3.析构函数  **************************************************/
/********************************************************  3.1 概念  **************************************************/
/*
通过前面构造函数的学习，我们知道一个对象是怎么来的，那一个对象又是怎么没呢的？
析构函数：与构造函数功能相反，析构函数不是完成对对象本身的销毁，局部对象销毁工作是由
编译器完成的。而对象在销毁时会自动调用析构函数，完成对象中资源的清理工作。
*/

/********************************************************  3.2 特性  **************************************************/
/*
析构函数是特殊的成员函数，其特征如下：
1. 析构函数名是在类名前加上字符 ~。
2. 无参数无返回值类型。
3. 一个类只能有一个析构函数。若未显式定义，系统会自动生成默认的析构函数。
注意：析构函数没有入参，所以 不能重载
4. 对象生命周期结束时，C++编译系统系统自动调用析构函数。
*/
//class Stack
//{
//public:
//    Stack(size_t capacity = 3)
//    {
//        _array = (DataType*)malloc(sizeof(DataType) * capacity);
//        if (NULL == _array)
//        {
//            perror("malloc申请空间失败!!!");
//            return;
//        }
//        _capacity = capacity;
//        _size = 0;
//    }
//    void Push(DataType data)
//    {
//        // CheckCapacity();
//        _array[_size] = data;
//        _size++;
//    }
//    // 其他方法...
//    ~Stack()
//    {
//        if (_array)
//        {
//            free(_array);
//            _array = NULL;
//            _capacity = 0;
//            _size = 0;
//        }
//    }
//private:
//    DataType* _array;
//    int _capacity;
//    int _size;
//};
//void TestStack()
//{
//    Stack s;
//    s.Push(1);
//    s.Push(2);
//}

/*
5. 关于编译器自动生成的析构函数，是否会完成一些事情呢？下面的程序我们会看到，编译器
生成的默认析构函数，对自定类型成员调用它的析构函数。
*/
//class Time
//{
//public:
//    ~Time()
//    {
//        cout << "~Time()" << endl;
//    }
//private:
//    int _hour;
//    int _minute;
//    int _second;
//};

//class Date
//{
//private:
//    // 基本类型(内置类型)
//    int _year = 1970;
//    int _month = 1;
//    int _day = 1;
//    // 自定义类型
//    Time _t;
//};
//int main()
//{
//    Date d;
//    return 0;
//}

/*
 程序运行结束后输出：~Time()
 在main方法中根本没有直接创建Time类的对象，为什么最后会调用Time类的析构函数？
 因为：main方法中创建了Date对象d，而d中包含4个成员变量，其中_year, _month, _day三个是
 内置类型成员，销毁时不需要资源清理，最后系统直接将其内存回收即可；
 而_t是Time类对象，所以在d销毁时，要将其内部包含的Time类的_t对象销毁，所以要调用Time类的析构函数。
 但是：main函数中不能直接调用Time类的析构函数，实际要释放的是Date类对象，所以编译器会调用Date类的析构函
 数，而Date没有显式提供，则编译器会给Date类生成一个默认的析构函数，目的是在其内部调用Time
 类的析构函数，即当Date对象销毁时，要保证其内部每个自定义对象都可以正确销毁
 main函数中并没有直接调用Time类析构函数，而是显式调用编译器为Date类生成的默认析构函数
 注意：创建哪个类的对象则调用该类的析构函数，销毁那个类的对象则调用该类的析构函数
*/
/*
6. 如果类中没有申请资源时，析构函数可以不写，直接使用编译器生成的默认析构函数，比如Date类；
有资源申请时，一定要写，否则会造成资源泄漏，比如Stack类。
*/


/********************************************************  注意：  *****************************************************/
/*
1.一般情况下，有动态申请的资源，就需要显示所写的析构函数，来释放资源。
例如：栈需要写析构

2.没有动态申请的资源，不需要写析构函数。因为没有资源需要释放。
例如：
class Data{
private:
	int _year;
	int _month;
	int _day;
	int _arr[100];
};

3.需要释放资源的成员都是自定义类型，不需要写析构函数。
例如：
class MyQue{
private:
	Stack _pushst;
	Stack _popst;
};
因为默认生成的构造会自动调用默认构造函数
默认生成的析构会自动调用默认析构函数
*/



/********************************************************  4. 拷贝构造函数  **************************************************/
/********************************************************  4.1 概念  **************************************************/
/*
在现实生活中，可能存在一个与你一样的自己，我们称其为双胞胎。
那在创建对象时，可否创建一个与已存在对象一某一样的新对象呢？
拷贝构造函数：只有单个形参，该形参是对本类类型对象的引用(一般常用const修饰)，在用已存
在的类类型对象创建新对象时由编译器自动调用。
*/

/********************************************************  4.2 特征  **************************************************/
/*
拷贝构造函数也是特殊的成员函数，其特征如下：
1. 拷贝构造函数是构造函数的一个重载形式。
 d销毁时，要将其内部包含的Time类的_t对象销毁，所以要调用Time类的析构函数。
 但是：main函数 中不能直接调用Time类的析构函数，实际要释放的是Date类对象，
 所以编译器会调用Date类的析构函数，而Date没有显式提供，
 则编译器会给Date类生成一个默认的析构函数，目的是在其内部调用Time类的析构函数，
 即当Date对象销毁时，要保证其内部每个自定义对象都可以正确销毁
 main函数中并没有直接调用Time类析构函数，而是显式调用编译器为Date类生成的默认析构函数

 注意：创建哪个类的对象则调用该类的析构函数，销毁那个类的对象则调用该类的析构函数

2. 拷贝构造函数的参数只有一个且必须是类类型对象的引用，使用传值方式编译器直接报错，
因为会引发无穷递归调用。
*/
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	// d2(d1)
//	//Date(Date& d);// 正确写法
//
//	Date(const Date& d)
//	{
//		cout << "Date(Date& d)" << endl;
//		//注意：_year = d._year;这个里面的_year不是private:里面的int _year;
//		//_year = d._year;这个左边的_year是d2的_year，也就是this->_year，因为this指针是d2，也就是d2传给了this
//		//右边的d._year是d，也就是d1的_year
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//		/*d._year = _year;
//		d._month = _month;
//		d._day = _day;*/
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//class MyQueue
//{
//private:
//	/*Stack _pushst;
//	Stack _popst;*/
//};
//
//void func(int i){}
//
//void func(Date d) {}
//
//int main()
//{
//	// 可以不写，默认生成的拷贝构造就可以用
//	Date d1(2023, 4, 25);
//
//	Date d2(d1);//Data(Data& d)里面的d是d1的别名
//	//this指针是d2，也就是d2传给了this
//
//	//内置类型直接拷贝，void func(int i);
//	//直接把4个字节的10拷贝给i
//	func(10);
//
//	//自定义类型的拷贝，规定了要定义拷贝构造去拷贝
//	//void func(Date d){}会先调用Date(const Date& d);然后进入void func(Date d) 
//	//如果Date(const Date& d);改成了Date(Date d);那么就会出现无限递归，编译器会报错
//	func(d1);
//
//	
//
//	// 必须自己实现，实现深拷贝
//	/*Stack st1;
//	Stack st2(st1);*/
//
//
//	return 0;
//}


//-------------------------------------------------------------------------------------
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	Date(const Date& d);// 正确写法
//
//	//Date(const Date& d)   // 错误写法：编译报错，会引发无穷递归
//	//{
//	//	_year = d._year;
//	//	_month = d._month;
//	//	_day = d._day;
//	//}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	Date d2(d1);
//	return 0;
//}

/*
3. 若未显式定义，编译器会生成默认的拷贝构造函数。 默认的拷贝构造函数对象按内存存储按
字节序完成拷贝，这种拷贝叫做浅拷贝，或者值拷贝。

1):内置类型成员完成值拷贝/浅拷贝
2);自定义类型成员会调用它的拷贝构造

自定义类型指向浅拷贝会出现两个问题：
1.析构两次，报错
2.一个函数修改会影响另一个函数

1.Data和MyQueue都不需要写。因为MyQueue里面会调用Stack，而Stack需要自己实现。Stack的实现和MyQueue无关。
2.Stack需要自己实现
*/
//class Stack
//{
//public:
//	Stack(int capacity = 4)
//	{
//		cout << "Stack()" << endl;
//
//		_a = (int*)malloc(sizeof(int) * capacity);
//		if (nullptr == _a)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//
//		_capacity = capacity;		
//		_top = 0;
//	}
//
//	// st2(st1)
//	Stack(const Stack& st)
//	{
//		_a = (int*)malloc(sizeof(int) * st._capacity);
//		if (nullptr == _a)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//
//		memcpy(_a, st._a, sizeof(int) * st._top);
//		_top = st._top;
//		_capacity = st._capacity;
//	}
//
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//		free(_a);
//		_a = nullptr;
//		_capacity = _top = 0;
//	}
//
//private:
//	int* _a = nullptr;
//	int _top = 0;
//	int _capacity;
//};
//
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//class MyQueue
//{
//private:
//	Stack _pushst;
//	Stack _popst;
//};
//
//int main()
//{
//	//1):内置类型成员完成值拷贝/浅拷贝
//	// 可以不写，默认生成的拷贝构造就可以用
//	Date d1(2023, 4, 25);
//	Date d2(d1);//Data(Data& d)里面的d是d1的别名
//	//this指针是d2，也就是d2传给了this
//
//	//2);自定义类型成员会调用它的拷贝构造
//	//如果只传值，那么就会导致两个函数指向了同一个空间，析构函数调用的话就崩了
//	// 而且就算不析构函数也会出问题。比如给其中一个函数赋值会影响另一个函数
//	
//	// 所以必须调用拷贝构造函数
//	// 必须自己实现拷贝构造函数，实现深拷贝
//	//栈后进先出，后创建的先析构，st2先析构，st1后析构
//	//添加Stack(const Stack& st);前，会报错，因为st1和st2的析构函数指向了同一个空间，而一个空间无法释放两次
//	//添加Stack(const Stack& st);后，不报错了
//	//Stack(const Stack& st);就是我们自己实现的深拷贝
//	Stack st1;
//	Stack st2(st1);
//
//	return 0;
//}

/*
注意：在编译器生成的默认拷贝构造函数中，内置类型是按照字节方式直接拷贝的，而自定
义类型是调用其拷贝构造函数完成拷贝的。
4. 编译器生成的默认拷贝构造函数已经可以完成字节序的值拷贝了，还需要自己显式实现吗？
当然像日期类这样的类是没必要的。那么下面的类呢？验证一下试试？
*/

// 这里会发现下面的程序会崩溃掉？这里就需要我们以后讲的深拷贝去解决。
//typedef int DataType;
//class Stack
//{
//public:
//    Stack(size_t capacity = 10)
//    {
//        _array = (DataType*)malloc(capacity * sizeof(DataType));
//        if (nullptr == _array)
//        {
//            perror("malloc申请空间失败");
//            return;
//        }
//        _size = 0;
//        _capacity = capacity;
//    }
//    void Push(const DataType& data)
//    {
//        // CheckCapacity();
//        _array[_size] = data;
//        _size++;
//    }
//    ~Stack()
//    {
//        if (_array)
//        {
//            free(_array);
//            _array = nullptr;
//            _capacity = 0;
//            _size = 0;
//        }
//    }
//private:
//    DataType* _array;
//    size_t _size;
//    size_t _capacity;
//};
//int main()
//{
//    Stack s1;
//    s1.Push(1);
//    s1.Push(2);
//    s1.Push(3);
//    s1.Push(4);
//    Stack s2(s1);
//    return 0;
//}

/*
注意：类中如果没有涉及资源申请时，拷贝构造函数是否写都可以；一旦涉及到资源申请
时，则拷贝构造函数是一定要写的，否则就是浅拷贝。
 
5. 拷贝构造函数典型调用场景：
1.使用已存在对象创建新对象
2.函数参数类型为类类型对象
3.函数返回值类型为类类型对象

*/

//class Date
//{
//    public:
//    Date(int year, int minute, int day)
//    {
//        cout << "Date(int,int,int):" << this << endl;
//    }
//    Date(const Date& d)
//    {
//        cout << "Date(const Date& d):" << this << endl;
//    }
//    ~Date()
//    {
//        cout << "~Date():" << this << endl;
//    }
//    private:
//    int _year;
//    int _month;
//    int _day;
//};
//Date Test(Date d)
//{
//    Date temp(d);
//    return temp;
//}
//
//int main()
//{
//    Date d1(2022,1,13);
//    Test(d1);
//    return 0;
//}

//为了提高程序效率，一般对象传参时，尽量使用引用类型，返回时根据实际场景，能用引用尽量使用引用。

//-------------------------------------------------------------------------------------
/********************************************************  5.1运算符重载  **************************************************/

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

//private:
	int _year;
	int _month;
	int _day;
};

//bool Less(const Date& x1, const Date& x2) {}
//bool Func1(const Date& x1, const Date& x2)
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
//bool Func2(const Date& x1, const Date& x2)
//{
//	if (x1._year > x2._year)
//	{
//		return true;
//	}
//	else if (x1._year == x2._year && x1._month > x2._month)
//	{
//		return true;
//	}
//	else if (x1._year == x2._year && x1._month == x2._month && x1._day > x2._day)
//	{
//		return true;
//	}
//
//	return false;
//}

bool operator<(const Date& x1, const Date& x2)
{
	if (x1._year < x2._year)
	{
		return true;
	}
	else if (x1._year == x2._year && x1._month < x2._month)
	{
		return true;
	}
	else if (x1._year == x2._year && x1._month == x2._month && x1._day < x2._day)
	{
		return true;
	}

	return false;
}

bool operator>(const Date& x1, const Date& x2)
{
	if (x1._year > x2._year)
	{
		return true;
	}
	else if (x1._year == x2._year && x1._month > x2._month)
	{
		return true;
	}
	else if (x1._year == x2._year && x1._month == x2._month && x1._day > x2._day)
	{
		return true;
	}

	return false;
}

int main()
{
	Date d1(2025, 4, 25);
	Date d2(2023, 5, 25);

	//cout << Less(d1 , d2) << endl;

	//cout << Func1(d1, d2) << endl;
	//cout << Func2(d1, d2) << endl;

	// 为什么内置类型可以直接比较，自定义类型不可以直接比较？
	cout << (d1 < d2) << endl;
	cout << (operator<(d1, d2)) << endl;//和上面一行等价

	cout << (d1 > d2) << endl;
	cout << (operator>(d1, d2)) << endl;//和上面一行等价

	return 0;
}
