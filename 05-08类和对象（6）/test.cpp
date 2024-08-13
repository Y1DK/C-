#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
//#include<list>
using namespace std;

//class Date
//{
//public:
//	Date* operator&()
//	{
//		cout << "Date* operator&()" << endl;
//		//return this;
//		return nullptr;
//	}
//
//	const Date* operator&() const
//	{
//		cout << "const Date* operator&() const" << endl;
//
//		return this;
//	}
//private:
//	int _year = 1; // 年
//	int _month = 1; // 月
//	int _day = 1; // 日
//};
//
//int main()
//{
//	Date d1;
//	const Date d2;
//
//	cout << &d1 << endl;
//	cout << &d2 << endl;
//
//	return 0;
//}

//-------------------------------------------------------------------------------------

//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a = 0)" <<endl;
//	}
//private:
//	int _a;
//};
//
//class B
//{
//public:
//	// 初始化列表：对象的成员定义的位置
//	B(int a, int ref)
//		:_ref(ref)
//		,_n(1)
//		,_x(2)
//	{
//		//_n = 0;
//		//_ref = ref;
//	}
//
//private:
//	// 声明
//	A _aobj;	  // 自定义类型成员,没有默认构造函数
//
//	// 引用和const特征：必须在定义的时候初始化
//	int& _ref;	  // 引用
//	const int _n; // const
//
//	int _x = 1;  // 这里1是缺省值，缺省值是给初始化列表的
//};
//
//int main()
//{
//	// 对象整体定义
//	B bb1(10, 1); 
//	//B bb2(11, 2);
//
//
//	return 0;
//}

//-------------------------------------------------------------------------------------

//class A
//{
//public:
//	/*A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a = 0)" << endl;
//	}*/
//	A(int a)
//		:_a(a)
//	{
//		cout << "A(int a = 0)" << endl;
//	}
//private:
//	int _a;
//};
//
//class B
//{
//public:
//	// 初始化列表：对象的成员定义的位置
//	B(int a, int& ref)
//		:_ref(ref)
//		, _n(1)
//		, _x(2)
//		, _aobj(a)
//	{
//		//_n = 0;
//		//_ref = ref;
//	}
//
//private:
//	// 声明
//	A _aobj;	  // 没有默认构造函数
//
//	// 特征：必须在定义的时候初始化
//	int& _ref;	  // 引用
//	const int _n; // const
//
//	int _x = 1;  // 这里1是缺省值，缺省值是给初始化列表的
//};
//
//// 这里会发现下面的程序会崩溃掉？这里就需要我们以后讲的深拷贝去解决。
//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 10)
//	{
//		_array = (DataType*)malloc(capacity * sizeof(DataType));
//		if (nullptr == _array)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//
//		_size = 0;
//		_capacity = capacity;
//	}
//
//	void Push(const DataType& data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//
//	~Stack()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = nullptr;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//
//private:
//	DataType* _array;
//	size_t _size;
//	size_t _capacity;
//};
//
//class MyQueue
//{
//public:
//	MyQueue()
//	{}
//
//	MyQueue(int capacity)
//		:_pushst(capacity)
//		,_popst(capacity)
//	{}
//
//private:
//	Stack _pushst;
//	Stack _popst;
//};
//
//int main()
//{
//	// 对象整体定义
//	int n = 10;
//	B bb1(10, n);
//	//B bb2(11, 2);
//
//	MyQueue q1;
//	MyQueue q2(100);
//
//	return 0;
//}

//-------------------------------------------------------------------------------------

//class A
//{
//public:
//	/*A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a = 0)" << endl;
//	}*/
//	A(int a)
//		:_a(a)
//	{
//		cout << "A(int a = 0)" << endl;
//	}
//private:
//	int _a;
//};
//
//class B
//{
//public:
//	// 初始化列表：对象的成员定义的位置
//	B(int a, int& ref)
//		:_ref(ref)
//		, _n(1)
//		, _x(2)
//		, _aobj(a)
//	{
//		//_n = 0;
//		//_ref = ref;
//	}
//
//private:
//	// 声明
//	A _aobj;	  // 没有默认构造函数
//
//	// 特征：必须在定义的时候初始化
//	int& _ref;	  // 引用
//	const int _n; // const
//
//	int _x = 1;  // 这里1是缺省值，缺省值是给初始化列表的
//};
//
//// 这里会发现下面的程序会崩溃掉？这里就需要我们以后讲的深拷贝去解决。
//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 10)
//	{
//		_array = (DataType*)malloc(capacity * sizeof(DataType));
//		if (nullptr == _array)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//
//		_size = 0;
//		_capacity = capacity;
//	}
//
//	void Push(const DataType& data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//
//	~Stack()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = nullptr;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//
//private:
//	DataType* _array;
//	size_t _size;
//	size_t _capacity;
//};
//
//class MyQueue
//{
//public:
//	MyQueue()
//	{}
//
//	MyQueue(int capacity)
//		:_pushst(capacity)
//		,_popst(capacity)
//	{}
//
//private:
//	Stack _pushst;
//	Stack _popst;
//};
//
//int main()
//{
//	// 对象整体定义
//	int n = 10;
//	B bb1(10, n);
//	//B bb2(11, 2);
//
//	MyQueue q1;
//	MyQueue q2(100);
//
//	return 0;
//}


//-------------------------------------------------------------------------------------

//class A
//{
//public:
//	/*A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a = 0)" << endl;
//	}*/
//	A(int a)
//		:_a(a)
//	{
//		cout << "A(int a = 0)" << endl;
//	}
//private:
//	int _a;
//};
//
//class B
//{
//public:
//	// 初始化列表：对象的成员定义的位置
//	B(int a, int& ref)
//		:_ref(ref)
//		, _n(1)
//		, _x(2)
//		, _aobj(a)
//	{
//		//_n = 0;
//		//_ref = ref;
//	}
//
//private:
//	// 声明
//	A _aobj;	  // 没有默认构造函数
//
//	// 特征：必须在定义的时候初始化
//	int& _ref;	  // 引用
//	const int _n; // const
//
//	int _x = 1;  // 这里1是缺省值，缺省值是给初始化列表的
//};
//
//// 这里会发现下面的程序会崩溃掉？这里就需要我们以后讲的深拷贝去解决。
//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 10)
//	{
//		_array = (DataType*)malloc(capacity * sizeof(DataType));
//		if (nullptr == _array)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//
//		_size = 0;
//		_capacity = capacity;
//	}
//
//	void Push(const DataType& data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//
//	~Stack()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = nullptr;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//
//private:
//	DataType* _array;
//	size_t _size;
//	size_t _capacity;
//};
//
//class MyQueue
//{
//public:
//	MyQueue()
//	{}
//
//	MyQueue(int capacity)
//		:_pushst(capacity)
//		,_popst(capacity)
//	{}
//
//private:
//	Stack _pushst;
//	Stack _popst;
//};
//
//int main()
//{
//	// 对象整体定义
//	int n = 10;
//	B bb1(10, n);
//	//B bb2(11, 2);
//
//	MyQueue q1;
//	MyQueue q2(100);
//
//	return 0;
//}class A
//{
//public:
//	/*A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a = 0)" << endl;
//	}*/
//	A(int a)
//		:_a(a)
//	{
//		cout << "A(int a = 0)" << endl;
//	}
//private:
//	int _a;
//};
//
//class B
//{
//public:
//	// 初始化列表：对象的成员定义的位置
//	B(int a, int& ref)
//		:_ref(ref)
//		, _n(1)
//		, _x(2)
//		, _aobj(a)
//	{
//		//_n = 0;
//		//_ref = ref;
//	}
//
//private:
//	// 声明
//	A _aobj;	  // 没有默认构造函数
//
//	// 特征：必须在定义的时候初始化
//	int& _ref;	  // 引用
//	const int _n; // const
//
//	int _x = 1;  // 这里1是缺省值，缺省值是给初始化列表的
//};
//
//// 这里会发现下面的程序会崩溃掉？这里就需要我们以后讲的深拷贝去解决。
//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 10)
//	{
//		_array = (DataType*)malloc(capacity * sizeof(DataType));
//		if (nullptr == _array)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//
//		_size = 0;
//		_capacity = capacity;
//	}
//
//	void Push(const DataType& data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//
//	~Stack()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = nullptr;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//
//private:
//	DataType* _array;
//	size_t _size;
//	size_t _capacity;
//};
//
//class MyQueue
//{
//public:
//	MyQueue()
//	{}
//
//	MyQueue(int capacity)
//		:_pushst(capacity)
//		, _popst(capacity)
//	{
//		//_size = 1;
//	}
//
//private:
//	Stack _pushst;
//	Stack _popst;
//	int _size = 0;
//};
//
//int main()
//{
//	// 对象整体定义
//	int n = 10;
//	B bb1(10, n);
//	//B bb2(11, 2);
//
//	MyQueue q1;
//	MyQueue q2(100);
//
//	return 0;
//}

//class Stack
//{
//public:
//	Stack(int capacity = 10)
//		: _a((int*)malloc(capacity * sizeof(int)))
//		,_top(0)
//		,_capacity(capacity)
//	{
//		if (nullptr == _a)
//		{
//			perror("malloc申请空间失败");
//			exit(-1);
//		}
//
//		// 要求数组初始化一下
//		memset(_a, 0, sizeof(int) * capacity);
//	}
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};
//
//class A
//{
//public:
//	A(int a)
//		:_a1(a)
//		, _a2(_a1)
//	{}
//
//	void Print() {
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	int _a2;
//	int _a1;
//};
//
////A.输出1  1
////B.程序崩溃
////C.编译不通过
////D.输出1  随机值

//-------------------------------------------------------------------------------------
/********************************************************  1.3 explicit关键字  **************************************************/

//class AA
//{
//public:
//	AA(int row = 10, int col = 5)
//		:_row(row)
//		,_col(col)
//	{
//		_aa = (int**)malloc(sizeof(int*) * row);
//		for (int i = 0; i < row; i++)
//		{
//			_aa[i] = (int*)malloc(sizeof(int) * col);
//		}
//	}
//private:
//	int** _aa;
//	int _row;
//	int _col;
//};
//
//int main()
//{
//	A aa(1);
//	aa.Print();
//
//	Stack st;
//
//	return 0;
//}
//
//class A
//{
//public:
//	/*explicit A(int a)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}*/
//	
//	A(int a)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//
//	A(const A& aa)
//		:_a(aa._a)
//	{
//		cout << "A(const A& aa)" << endl;
//	}
//
//private:
//	int _a;
//};
//
//int main()
//{
//	A aa1(1);//调用构造函数
//	A aa2 = 2; // 隐式类型转换，整形转换成自定义类型]
//	// 2构造一个A的临时对象，临时对象再拷贝构造aa2 -->有的编译器优化后用2直接构造
//	
//	//A& aa3 = 2;// error C2440: “初始化”: 无法从“int”转换为“A &”
//	const A& aa3 = 2;
//
//
//	int i = 10;
//	double d = i;
//
//	return 0;
//}

//-------------------------------------------------------------------------------------
/********************************************************  隐式类型转换  **************************************************/

//class string
//{
//public:
//	string(const char* str)
//	{}
//};

//class list
//{
//public:
//	void push_back(const string& str)
//	{}
//};
//
//int main()
//{
//	string name1("张三");//构造
//	string name2 = "张三";//构造+拷贝构造+编译器优化
//
//	list lt1;
//	string name3("李四");
//	lt1.push_back(name3);
//
//	lt1.push_back("李四");//隐式类型转换
//
//	return 0;
//}

//-------------------------------------------------------------------------------------
/********************************************************  2. static成员  **************************************************/

//int _scount = 0;
//
//class A
//{
//public:
//	A() { ++_scount; }
//	A(const A& t) { ++_scount; }
//	~A() { --_scount; }
//	/*static int GetACount() { return _scount; }*/
//private:
//	/*static int _scount;*/
//};
//
//A aa0;
//
//void Func()
//{
//	static A aa2;
//	cout << __LINE__ << ":" << _scount << endl;
//
//	// 全局变量的劣势：任何地方都可以随意改变
//	_scount++;
//}
//
//int main()
//{
//	cout <<__LINE__<<":"<< _scount << endl;  // 1
//	A aa1;
//	
//	Func();  // 3
//	Func();  // 3
//
//	return 0;
//}

//-------------------------------------------------------------------------------------

class A
{
public:
	A() 
	{++_scount;}

	A(const A& t) 
	{++_scount;}

	~A() 
	{ --_scount;}


	void Func1()
	{
		// 非静态能否调用静态：可以
		//因为类里面不受访问限定符的限制
		GetACount();
	}

	void Func2()
	{
		++_a1;
	}

	// 没有this指针、指定类域和访问限定符就可以访问
	static int GetACount() 
	{ 
		// 静态能否调用非静态？
		// 不可以。非静态的成员函数调用需要传递this指针，没有this是静态成员函数的特点
		// Func2();

		//_a1++;
		return _scount;
	}
private:
	// 成员变量 -- 属于每个一个类对象，存储对象里面
	int _a1 = 1;
	int _a2 = 2;
//public:
	// 静态成员变量 -- 属于类，属于类的每个对象共享，存储在静态区
	static int _scount;
};

// 全局位置，类外面定义
int A::_scount = 0;

A aa0;

void Func()
{
	static A aa2;
	cout << __LINE__ << ":" << aa2.GetACount() << endl;

	// 全局变量的劣势：任何地方都可以随意改变
	//_scount++;
}

int main()
{
	cout <<__LINE__<<":"<< A::GetACount() << endl;  // 1
	A aa1;
	
	Func();  // 3
	Func();  // 3

	return 0;
}

//-------------------------------------------------------------------------------------

// 设计一个类，在类外面只能在栈上创建对象
// 设计一个类，在类外面只能在堆上创建对象
class A
{
public:
	static A GetStackObj()
	{
		A aa;
		return aa;
	}

	static A* GetHeapObj()
	{
		return new A;
	}
private:
	A()
	{}

private:
	int _a1 = 1;
	int _a2 = 2;
};

int main()
{
	//static A aa1;   //  静态区
	//A aa2;          //  栈 
	//A* ptr = new A; //  堆
	A::GetStackObj();
	A::GetHeapObj();

	return 0;
}