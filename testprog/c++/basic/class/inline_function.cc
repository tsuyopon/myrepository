#include<iostream>
using namespace std;

/*
 *  �ؿ��Υ���饤�󲽤�ԤäƤ��ޤ���
 *      �� ����ˤ�ꥪ���С��إåɤ򸽾ݤǤ��ޤ���inline�Ǥ��뤫�ɤ����ϥ���ѥ���ˤ��
 *  ���С��ؿ��Υ���饤�󲽤�ԤäƤ��ޤ���
 */

// ���С��ؿ��Υ���饤��
class MyClass{
	public:
		int memberfunc(int x){
			return x * x;
		}
} obj;

// �ؿ��Υ���饤��
inline int func(int x){
	return x * x;
}

int main(){
	// �ؿ��Υ���饤�󲽳�ǧ
	cout << func(10) << endl;

	// ���С��ؿ��Υ���饤�󲽳�ǧ
	cout << obj.memberfunc(20) << endl;

	return 0;
}

