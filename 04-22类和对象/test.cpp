#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

/***************************************************  类的作用域  *************************************************************/
/*
类定义了一个新的作用域，类的所有成员都在类的作用域中。在类体外定义成员时，需要使用 ::
作用域操作符指明成员属于哪个类域。
class Person
{
	public:
		void PrintPersonInfo();//声明
	private:
		char _name[20];
		char _gender[3];
		int  _age;
};
// 这里需要指定PrintPersonInfo是属于Person这个类域
void Person::PrintPersonInfo()
{
	cout << _name << " "<< _gender << " " << _age << endl;
 }
*/

/***************************************************  类的实例化  *************************************************************/
/*
用类类型创建对象的过程，称为类的实例化
1. 类是对对象进行描述的，是一个模型一样的东西，限定了类有哪些成员，定义出一个类并没
有分配实际的内存空间来存储它；比如：入学时填写的学生信息表，表格就可以看成是一个
类，来描述具体学生信息。
类就像谜语一样，对谜底来进行描述，谜底就是谜语的一个实例。
谜语："年纪不大，胡子一把，主人来了，就喊妈妈" 谜底：山羊

2. 一个类可以实例化出多个对象，实例化出的对象 占用实际的物理空间，存储类成员变量
int main()
{
	Person._age = 100;   // 编译失败：error C2059: 语法错误:“.”
	return 0;
}
Person类是没有空间的，只有Person类实例化出的对象才有具体的年龄。

3. 做个比方。类实例化出对象就像现实中使用建筑设计图建造出房子，类就像是设计图，只设
计出需要什么东西，但是并没有实体的建筑存在，同样类也只是一个设计，实例化出的对象
才能实际存储数据，占用物理空间

*/


/***************************************************  类对象模型  *************************************************************/
/*
1.如何计算类对象的大小
*/
//class A
//{
//public:
//	// 健身房 篮球场等等
//	void PrintA()
//	{
//		cout << _a << endl;
//	}
////private:
//	// 卧室，厨房等等
//	char _a;
//};

//int main()
//{
//	A aa1;
//	A aa2;
//	A aa3;
//	cout << sizeof(A) << endl;//打印1
//	cout << sizeof(aa1) << endl;//打印1
//
//	//把char _a;放到public
//	aa1._a = 1;//在这个对象指向的_a赋值
//	aa1.PrintA();//不去这个对象里面找
//
//	return 0;
//}

/*
问题：类中既可以有成员变量，又可以有成员函数，那么一个类的对象中包含了什么？如何计算
一个类的大小？

----------------------------------------------------------------------------------------
2.类对象的存储方式猜测

1.对象中包含类的各个成员
类成员变量：_name,_gender,_age

类成员函数：SetPersonInfo(),PrintPersonInfo()

缺陷：每个对象中成员变量是不同的，但是调用同一份函数，如果按照此种方式存储，当一
个类创建多个对象时，每个对象中都会保存一份代码，相同代码保存多次，浪费空间。那么
如何解决呢？

2.代码只保存一份，在对象中保存存放代码的地址

3.只保存成员变量，成员函数存放在公共的代码段

问题：对于上述三种存储方式，那计算机到底是按照那种方式来存储的？
我们再通过对下面的不同对象分别获取大小来分析看下
*/

// 类中既有成员变量，又有成员函数
//class A1 {
//public:
//	void f1(){}
//private:
//	int _a;
//};
//// 类中仅有成员函数
//class A2 {
//public:
//	void f2() {}
//};
//// 类中什么都没有---空类
//class A3
//{};
//int main()
//{
//	cout << sizeof(A1) << endl;//4
//
//	// 没有成员变量的类对象，需要1byte，是为了占位，表示对象存在
//	// 不存储有效数据
//	cout << sizeof(A2) << endl;//1
//	cout << sizeof(A3) << endl;//1
//
//	A2 aa1;
//	A2 aa2;
//	cout << &aa1 << endl;// 0000004624CFF874
//	cout << &aa2 << endl;// 0000004624CFF894
//
//	return 0;
//}
/*
sizeof(A1) :4
sizeof(A2) :1 
sizeof(A3) :1

结论：一个类的大小，实际就是该类中”成员变量”之和，当然要注意内存对齐
注意空类的大小，空类比较特殊，编译器给了空类一个字节来唯一标识这个类的对象。

*/


/********************************************************  7.3结构体内存对齐规则**************************************************/
/*
1. 第一个成员在与结构体偏移量为0的地址处。
2. 其他成员变量要对齐到某个数字（对齐数）的整数倍的地址处。
注意：对齐数 = 编译器默认的一个对齐数 与 该成员大小的较小值。
VS中默认的对齐数为8
3. 结构体总大小为：最大对齐数（所有变量类型最大者与默认对齐参数取最小）的整数倍。
4. 如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数倍处，结构体的整
体大小就是所有最大对齐数（含嵌套结构体的对齐数）的整数倍。

【面试题】
1. 结构体怎么对齐？ 为什么要进行内存对齐？
2. 如何让结构体按照指定的对齐参数进行对齐？能否按照3、4、5即任意字节对齐？
3. 什么是大小端？如何测试某台机器是大端还是小端，有没有遇到过要考虑大小端的场景

*/

/********************************************************  8.this指针  **************************************************/
/********************************************************  8.1 this指针的引出  **************************************************/
//我们先来定义一个日期类 Date

//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	// d1.Print();
//	// d2.Print();
//	void Print()
//	{
//		cout << this->_year << "-" << _month << "-" << _day << endl;
//	}
//	/*void Print(Date* const this1)
//	{
//		cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
//	}*/
//	
//
////private:
//	int _year;     // 年   声明
//	int _month;    // 月
//	int _day;      // 日
//};
//
//int main()
//{
//	Date d1, d2;
//	d1.Init(2022, 1, 11);
//	d2.Init(2022, 1, 12);
//	d1.Print();
//	//000000FEB5F5F708
//	//2022 - 1 - 11
//	d2.Print();
//	//000000FEB5F5F738
//	//2022 - 1 - 12
//
//	//Date::_year;//错误！上面是声明，没有你所需要的空间
//	//d1._year;//错误！这个是域作用限定符。这里的左边的d1不是域。对象里面访问只能是.
//
//	//下面两行会报错，想要使用的话要把void Print()变成void Print(Date* const this1)，并且把
//	//d1.Print();和d2.Print();注释掉，或者直接把注释掉的void Print(Date* const this1)给恢复
//	// 然后就会打印
//	
//	//this指向&d1
//	//d1.Print(&d1);//2022 - 1 - 11
//	//this指向&d2
//	//d2.Print(&d2);//2022 - 1 - 12
//
//    return 0;
//}

/*
对于上述类，有这样的一个问题：
Date类中有 Init 与 Print 两个成员函数，函数体中没有关于不同对象的区分，那当d1调用 Init 函
数时，该函数是如何知道应该设置d1对象，而不是设置d2对象呢？
C++中通过引入this指针解决该问题，即：C++编译器给每个“非静态的成员函数“增加了一个隐藏
的指针参数，让该指针指向当前对象(函数运行时调用该函数的对象)，在函数体中所有“成员变量”
的操作，都是通过该指针去访问。只不过所有的操作对用户是透明的，即用户不需要来传递，编
译器自动完成。

this指针存在哪里？对象，栈，堆，静态区，常量区？
this是形参，所以this指针是跟普通参数一样存在函数调用的栈帧里面，函数调用结束，this就销毁了
vs下面对this指针传递进行了优化，对象地址是放在ecx里面的，ecx存储this指针的值
*/

//void Print()
//{
//	// this不能在形参和实参显示传递，但是可以在函数内部显示使用
//	//this = nullptr;//不可以哦
//	cout << this << endl;
//	cout << this->_year << "-" << _month << "-" << _day << endl;
//}
//
//// 编译器会成员函数的处理
//void Print(Date* const this)
//{
//	cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
//}



/********************************************************  8.2 this指针的特性  **************************************************/
/*
1. this指针的类型：类类型* const，即成员函数中，不能给this指针赋值。
2. 只能在“成员函数”的内部使用
3. this指针本质上是“成员函数”的形参，当对象调用成员函数时，将对象地址作为实参传递给
this形参。所以对象中不存储this指针。
4. this指针是“成员函数”第一个隐含的指针形参，一般情况由编译器通过ecx寄存器自动传
递，不需要用户传递
*/
/*
【面试题】
1. this指针存在哪里？
this指针是一个隐含的指针，存在于每个非静态成员函数中。它指向调用该成员函数的对象本身。
this 指针是编译器在编译时自动添加的，用于访问对象的成员变量和成员函数。
它并不占用对象本身的内存空间，而是作为一个隐含的参数传递给成员函数。
2. this指针可以为空吗？
不可以
*/

// 1.下面程序编译运行结果是？ A、编译报错 B、运行崩溃 C、正常运行
//class A
//{
//public:
//	void Print()//this指针是空的，但是函数内没有对this指针解引用
//	{
//		cout << "Print()" << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	A* p = nullptr;
//	//p调用Print，不会发生解引用，因为Print的地址不在对象中，p会作为实参传递给this指针
//	p->Print();
//	return 0;
//}
//C

// 1.下面程序编译运行结果是？ A、编译报错 B、运行崩溃 C、正常运行
//class A
//{
//public:
//	void PrintA()//this指针是空的，但是函数内访问_a，本质上是访问this_a
//	{
//		cout << _a << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	A* p = nullptr;
//	//p调用Print，不会发生解引用，因为Print的地址不在对象中，p会作为实参传递给this指针
//	p->PrintA();
//	return 0;
//}
//B



/********************************************************  8.3. C语言和C++实现Stack的对比  **************************************************/
//1. C语言实现
//typedef int DataType;
//typedef struct Stack
//{
//    DataType* array;
//    int capacity;
//    int size;
//}Stack;
//void StackInit(Stack* ps)
//{
//    assert(ps);
//    ps->array = (DataType*)malloc(sizeof(DataType) * 3);
//    if (NULL == ps->array)
//    {
//        assert(0);
//        return;
//    }ps->capacity = 3;
//    ps->size = 0;
//}
//void StackDestroy(Stack* ps)
//{
//    assert(ps);
//    if (ps->array)
//    {
//        free(ps->array);
//        ps->array = NULL;
//        ps->capacity = 0;
//        ps->size = 0;
//    }
//}
//void CheckCapacity(Stack* ps)
//{
//    if (ps->size == ps->capacity)
//    {
//        int newcapacity = ps->capacity * 2;
//        DataType* temp = (DataType*)realloc(ps->array, newcapacity * sizeof(DataType));
//        if (temp == NULL)
//        {
//            perror("realloc申请空间失败!!!");
//            return;
//        }
//        ps->array = temp;
//        ps->capacity = newcapacity;
//    }
//}
//void StackPush(Stack* ps, DataType data)
//{
//    assert(ps);
//    CheckCapacity(ps);
//    ps->array[ps->size] = data;
//    ps->size++;
//}
//int StackEmpty(Stack* ps)
//{
//    assert(ps);
//    return 0 == ps->size;
//}
//void StackPop(Stack* ps)
//{
//    if (StackEmpty(ps))
//        return;
//    ps->size--;
//}
//DataType StackTop(Stack* ps)
//{
//    assert(!StackEmpty(ps));
//    return ps->array[ps->size - 1];
//}
//int StackSize(Stack* ps)
//{
//    assert(ps);
//    return ps->size;
//}
//int main()
//{
//    Stack s;
//    StackInit(&s);
//    StackPush(&s, 1);
//    StackPush(&s, 2);
//    StackPush(&s, 3);
//    StackPush(&s, 4);
//    printf("%d\n", StackTop(&s));
//    printf("%d\n", StackSize(&s));
//    StackPop(&s);
//    StackPop(&s);
//    printf("%d\n", StackTop(&s));
//    printf("%d\n", StackSize(&s));
//    StackDestroy(&s);
//    return 0;
//}

/*
可以看到，在用C语言实现时，Stack相关操作函数有以下共性：
1.每个函数的第一个参数都是Stack*
2.函数中必须要对第一个参数检测，因为该参数可能会为NULL
3.函数中都是通过Stack*参数操作栈的
4.调用时必须传递Stack结构体变量的地址
结构体中只能定义存放数据的结构，操作数据的方法不能放在结构体中，即数据和操作数据
的方式是分离开的，而且实现上相当复杂一点，涉及到大量指针操作，稍不注意可能就会出
错。
*/

//2. C++实现

//typedef int DataType;
//class Stack
//{
//public:
//	Stack(DataType* a, int n)
//	{
//		cout << "Stack(DataType* a, int n)" << endl;
//		_array = (DataType*)malloc(sizeof(DataType) * n);
//		if (NULL == _array)
//		{
//			perror("malloc申请空间失败!!!");
//			return;
//		}
//		memcpy(_array, a, sizeof(DataType) * n);
//
//		_capacity = n;
//		_size = n;
//	}
//
//	Stack(int capacity = 4)
//	{
//		cout << "Stack(int capacity = 4)" << endl;
//		_array = (DataType*)malloc(sizeof(DataType) * capacity);
//		if (NULL == _array)
//		{
//			perror("malloc申请空间失败!!!");
//			return;
//		}
//
//		_capacity = capacity;
//		_size = 0;
//	}
//
//	/*void Init()
//	{
//		_array = (DataType*)malloc(sizeof(DataType) * 4);
//		if (NULL == _array)
//		{
//			perror("malloc申请空间失败!!!");
//			return;
//		}
//
//		_capacity = 4;
//		_size = 0;
//	}*/
//
//	void Push(DataType data)
//	{
//		CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//
//	void Pop()
//	{
//		if (Empty())
//			return;
//		_size--;
//	}
//
//	DataType Top() { return _array[_size - 1]; }
//	int Empty() { return 0 == _size; }
//	int Size() { return _size; }
//
//	//void Destroy()
//	//{
//	//	if (_array)
//	//	{
//	//		free(_array);
//	//		_array = NULL;
//	//		_capacity = 0;
//	//		_size = 0;
//	//	}
//	//}
//
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//		if (_array)
//		{
//			free(_array);
//			_array = NULL;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//
//private:
//	void CheckCapacity()
//	{
//		if (_size == _capacity)
//		{
//			int newcapacity = _capacity * 2;
//			DataType* temp = (DataType*)realloc(_array, newcapacity * sizeof(DataType));
//			if (temp == NULL)
//			{
//				perror("realloc申请空间失败!!!");
//				return;
//			}
//			_array = temp;
//			_capacity = newcapacity;
//		}
//	}
//private:
//	DataType* _array;
//	int _capacity;
//	int _size;
//};
//
//int main()
//{
//	Stack s;
//	//s.Init();
//
//	s.Push(1);
//	s.Push(2);
//	s.Push(3);
//	s.Push(4);
//
//	printf("%d\n", s.Top());
//	printf("%d\n", s.Size());
//
//	s.Pop();
//	s.Pop();
//	printf("%d\n", s.Top());
//	printf("%d\n", s.Size());
//
//	//s.Destroy();
//	return 0;
//}

/*
C++中通过类可以将数据 以及 操作数据的方法进行完美结合，通过访问权限可以控制那些方法在
类外可以被调用，即封装，在使用时就像使用自己的成员一样，更符合人类对一件事物的认知。
而且每个方法不需要传递Stack*的参数了，编译器编译之后该参数会自动还原，即C++中 Stack *
参数是编译器维护的，C语言中需用用户自己维护。
*/


/********************************************************  类和对象（中）  **************************************************/
/********************************************************  1.类的6个默认成员函数  **************************************************/
/*
如果一个类中什么成员都没有，简称为空类。
空类中真的什么都没有吗？并不是，任何类在什么都不写时，编译器会自动生成以下6个默认成员函数。
默认成员函数：用户没有显式实现，编译器会生成的成员函数称为默认成员函数。

1.初始化和清理
构造函数主要完成初始化工作
析构函数主要完成清理工作

2.拷贝复制
拷贝构造是使用同类对象初始化创建对象
赋值重载主要是把一个对象赋值给另一个对象

3.取地址重载
主要是普通对象和const对象取地址，这两个很少会自己实现
*/


/********************************************************  2. 构造函数  **************************************************/
/********************************************************  2.1 概念  **************************************************/
//对于以下Date类：
//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1;
//	d1.Init(2022, 7, 5);
//	d1.Print();
//	Date d2;
//	d2.Init(2022, 7, 6);
//	d2.Print();
//	return 0;
//}

/*
对于Date类，可以通过 Init 公有方法给对象设置日期，但如果每次创建对象时都调用该方法设置
信息，未免有点麻烦，那能否在对象创建时，就将信息设置进去呢？
构造函数是一个特殊的成员函数，名字与类名相同,创建类类型对象时由编译器自动调用，以保证
每个数据成员都有 一个合适的初始值，并且在对象整个生命周期内只调用一次。
*/


/********************************************************  2.2 特性  **************************************************/
/*
构造函数是特殊的成员函数，需要注意的是，构造函数虽然名称叫构造，但是构造函数的主要任
务并不是开空间创建对象，而是初始化对象。
其特征如下：
1. 函数名与类名相同。
2. 无返回值。
3. 对象实例化时编译器自动调用对应的构造函数。
4. 构造函数可以重载。
*/
//class Date
//{
//public:
//	// 1.无参构造函数
//	Date()
//	{}
//
//	// 2.带参构造函数
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//void TestDate()
//{
//	Date d1; // 调用无参构造函数
//	Date d2(2015, 1, 1); // 调用带参的构造函数
//
//	// 注意：如果通过无参构造函数创建对象时，对象后面不用跟括号，否则就成了函数声明
//	// 以下代码的函数：声明了d3函数，该函数无参，返回一个日期类型的对象
//	Date d3();// warning C4930: “Date d3(void)”: 未调用原型函数(是否是有意用变量定义的?)
//}


//-------------------------------------------------------------------------------------
/*
5. 如果类中没有显式定义构造函数，则C++编译器会自动生成一个无参的默认构造函数，一旦
用户显式定义编译器将不再生成。
*/
//class Date
//{
//public:
//	/*
//	// 如果用户显式定义了构造函数，编译器将不再生成
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	 }
// */
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	// 将Date类中构造函数屏蔽后，代码可以通过编译，因为编译器生成了一个无参的默认构造函数
//	// 将Date类中构造函数放开，代码编译失败，因为一旦显式定义任何构造函数，编译器将不再生成
//	// 无参构造函数，放开后报错：error C2512: “Date”: 没有合适的默认构造函数可用
//	Date d1;
//	Date d2;
//
//	d1.Print();//-858993460--858993460--858993460
//	//d2.Print;//会报错
//
//	return 0;
//}
//-------------------------------------------------------------------------------------

class Date
{
public:
	// 无参构造函数和有参构造函数可以一起出现，构成函数重载
	// 但是无参调用存在歧义，到底调用谁，他不知道
	/*Date()
	{
		_year = 1;
		_month = 1;
		_day = 1;
	}*/

	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	// 内置类型
	// C++11支持，这里不是初始化，因为这里只是声明
	// 这里给的是默认的缺省值，给编译器生成默认构造函数用
	int _year = 1;
	int _month = 1;
	int _day = 1;

	// 自定义类型
	//Stack _st;
};

//1、一般情况下，有内置类型成员，就需要自己写构造函数，不能用编译器自己生成的。
//2、全部都是自定义类型成员，可以考虑让编译器自己生成

int main()
{
	// 构造函数的调用跟普通函数也不一样
	Date d1;
	//Date d1(); // 不可以这样写，会跟函数声明有点冲突，编译器不好识别
	d1.Print();//1 - 1 - 1//和private:里的没什么关系，但是如果把Date(int year = 1, int month = 1, int day = 1){}给注释了，就有关系了

	Date d2(2023, 11, 11);
	d2.Print();//2023 - 11 - 11
	
	Date d3(2000);
	d3.Print();//2000 - 1 - 1

	//Date d1;
	//d1.Date();
	//Date d2;
	//d2.Date(2023, 1, 1);

	return 0;
}


//-------------------------------------------------------------------------------------
/*
6. 关于编译器生成的默认成员函数，很多童鞋会有疑惑：不实现构造函数的情况下，编译器会
生成默认的构造函数。但是看起来默认构造函数又没什么用？d对象调用了编译器生成的默
认构造函数，但是d对象_year/_month/_day，依旧是随机值。也就说在这里编译器生成的
默认构造函数并没有什么用？？
解答：C++把类型分成内置类型(基本类型)和自定义类型。内置类型就是语言提供的数据类
型，如：int/char...，自定义类型就是我们使用class/struct/union等自己定义的类型，看看
下面的程序，就会发现编译器生成默认的构造函数会对自定类型成员_t调用的它的默认成员
函数。
*/
//class Time
//{
//public:
//	Time()
//	{
//		cout << "Time()" << endl;
//		_hour = 0;
//		_minute = 0;
//		_second = 0;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//class Date
//{
//private:
//	// 基本类型(内置类型)
//	int _year;
//	int _month;
//	int _day;
//	// 自定义类型
//	Time _t;
//};
//
//int main()
//{
//	Date d;
//	return 0;
//}

//-------------------------------------------------------------------------------------
/*
注意：C++11 中针对内置类型成员不初始化的缺陷，又打了补丁，即：内置类型成员变量在
类中声明时可以给默认值。
*/
//class Time
//{
//public:
//	Time()
//	{
//		cout << "Time()" << endl;
//		_hour = 0;
//		_minute = 0;
//		_second = 0;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//class Date
//{
//private:
//	// 基本类型(内置类型)
//	int _year = 1970;
//	int _month = 1;
//	int _day = 1;
//	// 自定义类型
//	Time _t;
//};

//int main()
//{
//	Date d;
//	return 0;
//}

//-------------------------------------------------------------------------------------
/*
7. 无参的构造函数和全缺省的构造函数都称为默认构造函数，并且默认构造函数只能有一个。
注意：无参构造函数、全缺省构造函数、我们没写编译器默认生成的构造函数，都可以认为
是默认构造函数。
*/
//class Date
//{
//public:
//	Date()
//	{
//		_year = 1900;
//		_month = 1;
//		_day = 1;
//	}
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//// 以下测试函数能通过编译吗？
//void Test()
//{
//	Date d1;//不能，因为创建的无参构造函数会和默认构造函数冲突，导致编译器无法识别使用哪个
//}

//-------------------------------------------------------------------------------------
结论：
1.一般情况下，构造函数都需要我们自己写
2.
a.内置类型成员都有缺省值，且初始化符合我们的要求
b.全是自定义类型的构造，且这些类型都定义为默认构造

//-------------------------------------------------------------------------------------
//结构体和类都可以用构造函数，析构函数
struct TreeNode
{
    TreeNode* _left;
    TreeNode* _right;
    int _val;

    TreeNode(int val = 0)
    {
	//这里面int val = 0;我们不给才会用这个，例如：TreeNode n0;
	//给了就不用这个0了，例如：TreeNode n1(1);TreeNode n2(2); 
        _left = nullptr;
        _right = nullptr;
        _val = val;
    }
};

int main() {
    TreeNode n0;
    TreeNode n1(1);
    TreeNode n2(2);
}
/*
n1 和 n2 是 TreeNode 类型的实例，它们通过构造函数初始化。
构造函数 TreeNode(int val = 0) 允许创建一个带有特定值的树节点，并将左右子节点初始化为 nullptr（即没有子节点）。

TreeNode n0; 创建了一个值为 0 的树节点，其左右子节点都为 nullptr。
TreeNode n1(1); 创建了一个值为 1 的树节点，其左右子节点都为 nullptr。
TreeNode n2(2); 创建了一个值为 2 的树节点，其左右子节点都为 nullptr。

这种写法是 C++ 中对象初始化的常见方式，允许在创建对象时直接设置其属性值。
在这个例子中，通过传递一个整数值给构造函数，可以设置树节点的 _val 成员变量。
*/
