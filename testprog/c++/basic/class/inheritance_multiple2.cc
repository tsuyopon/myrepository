#include<iostream>
using namespace std;

/*
 *  ¿�ŷѾ��ˤĤ���
 *    ( B-1,B-2 -> C�Ȥʤ�����Ū�Ѿ��ξ��)
 */

class Parent {
	public:
		Parent(){
			cout << "Parent" << endl;
		}
};

class Parent2 {
	public:
		Parent2(){
			cout << "Parent2" << endl;
		}
};

class Child : public Parent, public Parent2 {    // 2�Ĥ�Ѿ����Ƥ��뤳�Ȥ�����
	public:
		Child(){
			cout << "Child" << endl;
		}
};

int main(){
	Child obj;
	return 0;
}
