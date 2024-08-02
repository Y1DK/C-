#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

//int main() {
//	int a = 0;
//	int& b = a;
//	int& c = a;
//	return 0;
//}



//引用访问
// 不危险
//引用实体是 n
//ret现在是对Count函数返回的静态局部变量n的引用
//ret可以被视为引用变量名
//int& Count() {
//	static int n = 0;
//	n++;
//	return n;
//}
//
//int main() {
//	int ret = Count();
//	return 0;
//}

//引用访问
// 危险
//这个程序相当于做了一个野指针的访问，结果是不确定的
//int& Count() {
//	int n = 0;
//	n++;
//	return n;
//}
//这里把n的值给ret的时候，n已经被销毁了
//如果count函数结束，栈帧销毁后没有清理，那么ret的结果侥幸正确
//如果count函数结束，栈帧销毁后被清理，那么ret的结果是随机值
//int main() {
//	int ret = Count();
//	return 0;
//}

//int& Count(int x) {
//    int n = x;
//    //cout << &n << endl;
//    n++;
//    return n;
//}
//
//int main() {
//    int& ret = Count(10);
//    //cout << &ret << endl;
//
//    cout << ret << endl;//11/随机值
//    Count(20);
//    //rand();//调用函数后就是随机值了
//    cout << ret << endl;//21/随机值
//    return 0;
//}


//int& Count(int x) {
//    int n = x;
//    n++;
//    return n;
//}
//
//int main() {
//    int& ret = Count(10);
//    //cout << &ret << endl;
//
//    cout << ret << endl;//11/随机值
//    Count(20);
//    printf("SSSSSSSSSSS\n");//调用函数后就是随机值了
//    cout << ret << endl;//21/随机值
//    return 0;
//}

//int& Count(int& x) {
//    int n = x;
//    n++;
//
//    return n;
//}
//
//int main() {
//    int a = 0;
//    Count(a);
//    cout << a << endl;
//
//    int ret = Count(a);
//    cout << ret << endl;
//
//    //不安全
//    int& ret1 = Count(a);
//    printf("SSSSSSSSSSS\n");
//    cout << ret1 << endl;
//
//    return 0;
//}

/*
总结：
1.基本任意场景都可以引用传参
2.谨慎使用引用做返回值。
出了作用域，对象不在了，就不能引用返回。
对象还在就可以用引用返回。
*/



//int main() {
//	int a = 0;
//	int& b = a;
//	return 0;
//}
//
////权限不能放大
//int main() {
//	const int a = 0;
//	//int& b = a;//这里会出问题，因为a自己都不能改变
//  int c = a;//这个可以，这里c的改变不影响a
// 
//	return 0;
//}


//可以
//引用过程中，权限可以平移或者缩小
//int main() {
//	int x = 0;
//	int& y = x;
//	const int& z = x;
//	++x;//可以，因为这里缩小的不是x，缩小的是z作为别名的权限
//	//++z;//不可以
//
//	return 0;
//}

//int main() {
//	const int& m = 10;//这里是可以的，因为这里权限是不能被修改的，是权限的平移
//
//	double a = 1.11;
//	int b = a;//类型转换的时候会产生一个int类型的临时变量，也就是说这里给b的不是a而是临时变量。
//	//临时变量具有常性，相当于被const修饰了
//
//	//这里权限放大了，所以不可以
//	//int& c = a;//这里不行，因为
//
//	const int& c = a;//这里可以，
//
//	return 0;
//}

//辩证
//int func1() {
//	static int x = 0;
//	return x;
//}
//
//int& func2() {
//	static int x = 0;
//	return x;
//}
//
//int main() {
//	int ret1 = func1();//可以接收，这里就是拷贝
//	//int& ret1 = func1();//不可以接收，因为权限的放大。这里返回的其实不是x，而是一个临时变量，临时变量具有常性。
//	const int& ret1 = func1();//这样就可以了，这里是权限的平移
//
//	//ret2现在是对Count函数返回的静态局部变量n的引用
//	//ret2可以被视为引用变量名
//	int ret2 = func2();//可以，上面有例子
//	int& ret2 = func2();//可以，这里返回的是x的别名，是权限的平移
//	const int& ret2 = func2();//可以，这里是权限的缩小
//
//	return 0;
//}

//int main() {
//	int i = 1;
//	double j = 1.1;
//	if (j > i) {
//		//因为在运算符两边的两个变量的类型不同的时候，会发生提升，一般是小的向大的提升
//		//在这里i向j提升，会生成一个double的临时变量，然后和j比较
//		cout << "xxxxx" << endl;//打印：xxxxx
//	}
//
//	return 0;
//}

//int main() {
//	int a = 10;
//	
//	//语法层面：不开空间，是对a取别名
//	//底层汇编指令实现角度看：引用是类似指针的方式实现的
//	int& ra = a;
//	ra = 20;
//
//	//语法层面：开空间，存储a的地址
//	int* pa = &a;
//	*pa = 20;
//
//	return 0;
//}

#include <map>
#include <string>
#include <vector>

//int main() {
//	int a = 0;
//	int b = a;
//	
//	auto c = a;//根据右边表达式自动推导c的类型，c的类型是int
//
//	auto d = 1 + 1.11;//根据右边表达式自动推导d的类型，d的类型是double
//	//C++里面typeid可以打印类型
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//
//	//体会auto的价值
//	//下面仅供观看，以后讲到了再理解
//	vector<int> v;
//	//vector<int>::iterator it = v.begin();
//	auto it = v.begin();//代替上面一行代码，类型很长的时候用
//
//	return 0;
//}


int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };

	for (int i = 0; i < sizeof(arr) / sizeof(int); ++i)
		arr[i] *= 2;

	for (int* p = arr; p < arr + sizeof(arr) / sizeof(arr[0]); ++p)
		cout << *p << " ";
	cout << endl;

	// 适用于数组
	// 范围for 语法糖
	// 依次取arr数组中数据赋值给e
	// 自动迭代，自动判断结束
	// for (int x : arr)
	for (auto x : arr)
	{
		cout << x << " ";
	}
	cout << endl;

	// 修改数据
	//这里的引用是依次把arr[0],arr[1]...的别名给e
	for (auto& e : arr)
	{
		e *= 2;
	}

	for (auto e : arr)
	{
		cout << e << " ";
	}
	cout << endl;

	return 0;
}