#include<iostream>
using namespace std;

/*
 *  ��ݥ��饹�ˤĤ���
 */

// ��ݥ��饹�ϡ����Τ�̵���Τǥ��֥������Ȥ��뤳�Ȥ��Ǥ��ޤ���
class Parent {
	pubilc:
		// ��=0�פ��������Ƥ���Τ������̵�����Ȥ�ɽ���Ƥ��ơ����줬C++�Ǥ���ݥ᥽�åɤ�����Ǥ���
		virtual void print() = 0;               
};

class Child1 : public Parent {
	public:
		void print(){                              // Parent���饹��Ѿ�������ˤ�print()�᥽�åɤ�ɬ�����Τ��������ɬ�פ�����ޤ���
			cout << "Child1::print()" << endl;
		}
} obj1;

class Child2 : public Parent {
	public:
		void print(){                              // Parent���饹��Ѿ�������ˤ�print()�᥽�åɤ�ɬ�����Τ��������ɬ�פ�����ޤ���
			cout << "Child2::print()" << endl;
		}
} obj2;

int main(){
	Parent *po1 = &obj1, *po2 = &obj2;
	po1->print();
	po2->print();
	return 0;

}
