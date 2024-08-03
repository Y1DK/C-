#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;


#include"Func.h"

//int Add(int x, int y)
//{
//	return (x + y) * 10;
//}

//#define Add(int x, int y) return (x+y);//不可以
//#define Add(x, y) x+y//不可以，没括号
//#define Add(x, y) (x+y)//不可以
//#define Add(x, y) ((x)+(y))//可以
//
//int main()
//{
//	for (int i = 0; i < 10000; i++)
//	{
//		cout << Add(i, i + 1) << endl;
//	}
//
//	if (Add(10, 20))
//	{
//
//	}

//  #define Add(x, y) x+y//不可以，没括号
//	Add(10, 20) * 20;

//  #define Add(x, y) (x+y)
//	int a = 1, b = 2;
//	Add(a | b, a & b); // (a | b + a & b)//不可以，会出错。因为+号的优先级更高，会出现问题
//
//	return 0;
//}

// 宏函数 
// 优点-- 不需要建立栈帧，提高调用效率
// 缺点-- 复杂，容易出错、可读性差、不能调试


/***************************************************  内联函数  *************************************************************/
//以inline修饰的函数叫做内联函数，编译时C++编译器会在调用内联函数的地方展开，没有函数调
//用建立栈帧的开销，内联函数提升程序运行的效率。

// 适用于短小的,频繁调用的函数
// 对于长代码会出现代码膨胀
/*
比如，Func函数编译后是50行指令，如果有10000个位置调用Func
1.Func不是inline,合计多少行指令？
10000+50
2.Func是inline,合计多少行指令？
10000*50
*/

// inline对于编译器仅仅只是一个建议，最终是否成为inline，编译器自己决定
// 像类似函数就算加了inline，也会被否决掉
// 1、比较长的函数
// 2、递归函数

// 默认debug模式下，inline不会起作用，否则不方便调试了
/*
inline int Add(int x, int y)
{
	cout << "ssssssssssssssss" << endl;
	cout << "ssssssssssssssss" << endl;
	cout << "ssssssssssssssss" << endl;
	cout << "ssssssssssssssss" << endl;
	cout << "ssssssssssssssss" << endl;
	cout << "ssssssssssssssss" << endl;
	cout << "ssssssssssssssss" << endl;
	cout << "ssssssssssssssss" << endl;
	cout << "ssssssssssssssss" << endl;
	cout << "ssssssssssssssss" << endl;
	cout << "ssssssssssssssss" << endl;
	cout << "ssssssssssssssss" << endl;
	cout << "ssssssssssssssss" << endl;
	cout << "ssssssssssssssss" << endl;
	cout << "ssssssssssssssss" << endl;
	cout << "ssssssssssssssss" << endl;
	cout << "ssssssssssssssss" << endl;
	cout << "ssssssssssssssss" << endl;
	cout << "ssssssssssssssss" << endl;
	cout << "ssssssssssssssss" << endl;
	cout << "ssssssssssssssss" << endl;
	cout << "ssssssssssssssss" << endl;
	cout << "ssssssssssssssss" << endl;
	cout << "ssssssssssssssss" << endl;
	cout << "ssssssssssssssss" << endl;
	cout << "ssssssssssssssss" << endl;
	cout << "ssssssssssssssss" << endl;
	cout << "ssssssssssssssss" << endl;
	cout << "ssssssssssssssss" << endl;
	cout << "ssssssssssssssss" << endl;
	cout << "ssssssssssssssss" << endl;
	cout << "ssssssssssssssss" << endl;
	cout << "ssssssssssssssss" << endl;
	cout << "ssssssssssssssss" << endl;
	cout << "ssssssssssssssss" << endl;
	return (x + y) * 10;
}

int main()
{
	for (int i = 0; i < 10000; i++)
	{
		cout << Add(i, i + 1) << endl;
	}
}
*/

//#include "Func.h"
//
//int main()
//{
//	f(10);
//
//	return 0;
//}

/***************************************************  auto  *************************************************************/
/*
auto的使用细则
1. auto与指针和引用结合起来使用
用auto声明指针类型时，用auto和auto*没有任何区别，但用auto声明引用类型时则必须加&
2. 在同一行定义多个变量
当在同一行声明多个变量时，这些变量必须是相同的类型，否则编译器将会报错，因为编译器实际只对第一个类型进行推导，
然后用推导出来的类型定义其他变量。
void TestAuto()
{
    auto a = 1, b = 2;
    auto c = 3, d = 4.0;  // 该行代码会编译失败，因为c和d的初始化表达式类型不同
}

auto不能推导的场景
1. auto不能作为函数的参数
// 此处代码编译失败，auto不能作为形参类型，因为编译器无法对a的实际类型进行推导
void TestAuto(auto a)
{}

2. auto不能直接用来声明数组
void TestAuto()
{
    int a[] = {1,2,3};
    auto b[] = {4，5，6};
}

3. 为了避免与C++98中的auto发生混淆，C++11只保留了auto作为类型指示符的用法
4. auto在实际中最常见的优势用法就是跟以后会讲到的C++11提供的新式for循环，还有lambda表达式等进行配合使用。

*/

//int main()
//{
//	int x = 10;
//	auto a = &x;//根据右边推出左边a是指针
//	auto* b = &x;//根据左边来让右边必须是&x
//	auto& c = x;//指定是引用
//
//	int arr[] = { 1,2,3 };
//	for (auto& x : arr)
//	{
//		x++;
//	}
//
//	for (auto& x : arr)
//	{
//		cout << x << endl;
//	}
//
//	return 0;
//}

/***************************************************  指针空值nullptr(C++11)  *****************************************************/

//void f(int)
//{
//	cout << "f(int)" << endl;
//}
//
//void f(int*)
//{
//	cout << "f(int*)" << endl;
//}
//
//int main()
//{
//	f(0);
//	f(NULL);
//	f(nullptr);
//}

/***************************************************  类和对象  *************************************************************/
/*
C语言结构体中只能定义变量，在C++中，结构体内不仅可以定义变量，也可以定义函数。
比如：
之前在数据结构初阶中，用C语言方式实现的栈，结构体中只能定义变量；现在以C++方式实现，
会发现struct中也可以定义函数。
*/

struct Queue
{
	void Init()
	{

	}
};

//struct Stack
//class Stack
//{
//public:
//	// 成员函数
//	void Init(int defaultCapacity = 4)
//	{
//		a = (int*)malloc(sizeof(int) * capacity);
//		if (nullptr == a)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//
//		capacity = defaultCapacity;
//		top = 0;
//	}
//
//	void Push(int x)
//	{
//		//...
//		a[top++] = x;
//	}
//
//	void Destroy()
//	{
//		free(a);
//		a = nullptr;
//		top = capacity;
//	}
//
//	// ....
//private:
//	// 成员变量
//	int* a;
//	int top;
//	int capacity;
//};

//int main()
//{
//	Stack s;
//	s.Init(10);
//	s.Push(1);
//	s.Push(2);
//	s.Push(3);
//	cout << s.Top() << endl;
//	s.Destroy();
//	return 0;
//}

//上面结构体的定义，在C++中更喜欢用class来代替。 

//类的定义
//class className
//{
//	// 类体：由成员函数和成员变量组成
//
//}；  // 一定要注意后面的分号

/*
class为定义类的关键字，ClassName为类的名字，{}中为类的主体，注意类定义结束时后面分号不能省略。

类体中内容称为类的成员：类中的变量称为类的属性或成员变量; 类中的函数称为类的方法或者成员函数。

类的两种定义方式：
1. 声明和定义全部放在类体中，需注意：成员函数如果在类中定义，编译器可能会将其当成内联函数处理。
class Person
{
	public:
	//显示基本信息
	void showInfo()
	{
		cout << name sex age << endl;
	};
	public:
		char*_name; //姓名
		char* sex //性别
		int _age; //年龄
};

2. 类声明放在.h文件中，成员函数定义放在.cpp文件中，注意：成员函数名前需要加类名::
定义放在类的实现文件person.cpp中
#include"person.h"
//显示基本信息，实现:输出 名字、性别、年龄
voidPersonhowlnfo()
{
	cout << _name
	<<"_' sex < age << endl;
}
一般情况下，更期望采用第二种方式。注意：上课为了方便演示使用方式一定义类，大家后序工
作中尽量使用第二种。
*/

/*
class Date
{
public:
	void Init(int year)
	{
		// 这里的year到底是成员变量，还是函数形参？
		_year = year;//void Init()里面的_year是private里面的_year
	}
private:
	int _year; // year_
	int _month;//声明。对于变量不开空间就是声明。
	int _day;
};

// 所以一般都建议这样
class Date
{
	public:
		void Init(int year)
		{
			_year = year;
		}
	private:
		int _year;
};
// 或者这样
class Date
{
	public:
		void Init(int year)
		{
			mYear = year;
		}
	private:
		int mYear;
};
// 其他方式也可以的，主要看公司要求。一般都是加个前缀或者后缀标识区分就行。
*/



/***************************************************  类的访问限定符及封装  *************************************************************/

#include"Func.h"

// C++兼容c语言。 struct以前的用法都可以继续用
// 同时struct升级成了类

/*
1.访问限定符 
C++实现封装的方式：用类将对象的属性与方法结合在一块，让对象更加完善，通过访问权限选
择性的将其接口提供给外部的用户使用。

【访问限定符说明】
1. public修饰的成员在类外可以直接被访问
2. protected和private修饰的成员在类外不能直接被访问(此处protected和private是类似的)
3. 访问权限作用域从该访问限定符出现的位置开始直到下一个访问限定符出现时为止
4. 如果后面没有访问限定符，作用域就到 } 即类结束。
5. class的默认访问权限为private，struct为public(因为struct要兼容C)
注意：访问限定符只在编译时有用，当数据映射到内存后，没有任何访问限定符上的区别

【面试题】
问题：C++中struct和class的区别是什么？
解答：C++需要兼容C语言，所以C++中struct可以当成结构体使用。另外C++中struct还可以用来
定义类。和class定义类是一样的，区别是struct定义的类默认访问权限是public，class定义的类
默认访问权限是private。注意：在继承和模板参数列表位置，struct和class也有区别，后序给大
家介绍。
--------------------------------------------------------------------------------------------
2.封装
【面试题】
面向对象的三大特性：封装、继承、多态。

在类和对象阶段，主要是研究类的封装特性，那什么是封装呢？
封装：将数据和操作数据的方法进行有机结合，隐藏对象的属性和实现细节，仅对外公开接口来
和对象进行交互。

封装本质上是一种管理，让用户更方便使用类。比如：对于电脑这样一个复杂的设备，提供给用
户的就只有开关机键、通过键盘输入，显示器，USB插孔等，让用户和计算机进行交互，完成日
常事务。但实际上电脑真正工作的却是CPU、显卡、内存等一些硬件元件。

对于计算机使用者而言，不用关心内部核心部件，比如主板上线路是如何布局的，CPU内部是如
何设计的等，用户只需要知道，怎么开机、怎么通过键盘和鼠标与计算机进行交互即可。因此计
算机厂商在出厂时，在外部套上壳子，将内部实现细节隐藏起来，仅仅对外提供开关机、鼠标以
及键盘插孔等，让用户可以与计算机进行交互即可。

在C++语言中实现封装，可以通过类将数据以及操作数据的方法进行有机结合，通过访问权限来
隐藏对象内部实现细节，控制哪些方法可以在类外部直接被使用。

int main()
{
	// 类实例化对象/对象定义
	Stack st1;
	Stack st2;
	//st1.top = 1;//公有的情况下可以这样，因为开辟了空间

	// 不能,类访问top是声明，top不能存数据
	//Stack::top = 1;

	return 0;
}


*/

int main()
{
	// 类实例化对象/对象定义
	Stack st1;
	Stack st2;
	Stack st3;
	Stack st4;

	st1.top = 0;
	st1.Push(1);

	st2.top = 1;
	st2.Push(1);

	// 对象中只存储的成员变量，没有存储成员函数
	cout << sizeof(st1) << endl;//12

	return 0;
}