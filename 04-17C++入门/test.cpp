#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

//int main() {
//	int a = 0;
//	int& b = a;
//	int& c = a;
//	return 0;
//}



//���÷���
// ��Σ��
//����ʵ���� n
//ret�����Ƕ�Count�������صľ�̬�ֲ�����n������
//ret���Ա���Ϊ���ñ�����
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

//���÷���
// Σ��
//��������൱������һ��Ұָ��ķ��ʣ�����ǲ�ȷ����
//int& Count() {
//	int n = 0;
//	n++;
//	return n;
//}
//�����n��ֵ��ret��ʱ��n�Ѿ���������
//���count����������ջ֡���ٺ�û��������ôret�Ľ��������ȷ
//���count����������ջ֡���ٺ�������ôret�Ľ�������ֵ
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
//    cout << ret << endl;//11/���ֵ
//    Count(20);
//    //rand();//���ú�����������ֵ��
//    cout << ret << endl;//21/���ֵ
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
//    cout << ret << endl;//11/���ֵ
//    Count(20);
//    printf("SSSSSSSSSSS\n");//���ú�����������ֵ��
//    cout << ret << endl;//21/���ֵ
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
//    //����ȫ
//    int& ret1 = Count(a);
//    printf("SSSSSSSSSSS\n");
//    cout << ret1 << endl;
//
//    return 0;
//}

/*
�ܽ᣺
1.�������ⳡ�����������ô���
2.����ʹ������������ֵ��
���������򣬶������ˣ��Ͳ������÷��ء�
�����ھͿ��������÷��ء�
*/



//int main() {
//	int a = 0;
//	int& b = a;
//	return 0;
//}
//
////Ȩ�޲��ܷŴ�
//int main() {
//	const int a = 0;
//	//int& b = a;//���������⣬��Ϊa�Լ������ܸı�
//  int c = a;//������ԣ�����c�ĸı䲻Ӱ��a
// 
//	return 0;
//}


//����
//���ù����У�Ȩ�޿���ƽ�ƻ�����С
//int main() {
//	int x = 0;
//	int& y = x;
//	const int& z = x;
//	++x;//���ԣ���Ϊ������С�Ĳ���x����С����z��Ϊ������Ȩ��
//	//++z;//������
//
//	return 0;
//}

//int main() {
//	const int& m = 10;//�����ǿ��Եģ���Ϊ����Ȩ���ǲ��ܱ��޸ĵģ���Ȩ�޵�ƽ��
//
//	double a = 1.11;
//	int b = a;//����ת����ʱ������һ��int���͵���ʱ������Ҳ����˵�����b�Ĳ���a������ʱ������
//	//��ʱ�������г��ԣ��൱�ڱ�const������
//
//	//����Ȩ�޷Ŵ��ˣ����Բ�����
//	//int& c = a;//���ﲻ�У���Ϊ
//
//	const int& c = a;//������ԣ�
//
//	return 0;
//}

//��֤
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
//	int ret1 = func1();//���Խ��գ�������ǿ���
//	//int& ret1 = func1();//�����Խ��գ���ΪȨ�޵ķŴ����ﷵ�ص���ʵ����x������һ����ʱ��������ʱ�������г��ԡ�
//	const int& ret1 = func1();//�����Ϳ����ˣ�������Ȩ�޵�ƽ��
//
//	//ret2�����Ƕ�Count�������صľ�̬�ֲ�����n������
//	//ret2���Ա���Ϊ���ñ�����
//	int ret2 = func2();//���ԣ�����������
//	int& ret2 = func2();//���ԣ����ﷵ�ص���x�ı�������Ȩ�޵�ƽ��
//	const int& ret2 = func2();//���ԣ�������Ȩ�޵���С
//
//	return 0;
//}

//int main() {
//	int i = 1;
//	double j = 1.1;
//	if (j > i) {
//		//��Ϊ����������ߵ��������������Ͳ�ͬ��ʱ�򣬻ᷢ��������һ����С����������
//		//������i��j������������һ��double����ʱ������Ȼ���j�Ƚ�
//		cout << "xxxxx" << endl;//��ӡ��xxxxx
//	}
//
//	return 0;
//}

//int main() {
//	int a = 10;
//	
//	//�﷨���棺�����ռ䣬�Ƕ�aȡ����
//	//�ײ���ָ��ʵ�ֽǶȿ�������������ָ��ķ�ʽʵ�ֵ�
//	int& ra = a;
//	ra = 20;
//
//	//�﷨���棺���ռ䣬�洢a�ĵ�ַ
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
//	auto c = a;//�����ұ߱��ʽ�Զ��Ƶ�c�����ͣ�c��������int
//
//	auto d = 1 + 1.11;//�����ұ߱��ʽ�Զ��Ƶ�d�����ͣ�d��������double
//	//C++����typeid���Դ�ӡ����
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//
//	//���auto�ļ�ֵ
//	//��������ۿ����Ժ󽲵��������
//	vector<int> v;
//	//vector<int>::iterator it = v.begin();
//	auto it = v.begin();//��������һ�д��룬���ͺܳ���ʱ����
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

	// ����������
	// ��Χfor �﷨��
	// ����ȡarr���������ݸ�ֵ��e
	// �Զ��������Զ��жϽ���
	// for (int x : arr)
	for (auto x : arr)
	{
		cout << x << " ";
	}
	cout << endl;

	// �޸�����
	//��������������ΰ�arr[0],arr[1]...�ı�����e
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