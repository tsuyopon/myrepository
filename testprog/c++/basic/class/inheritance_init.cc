#include<iostream>
using namespace std;

/*
 * �Ѿ��򤷤Ƥ�����Υ��󥹥ȥ饯�����ǥ��ȥ饯���ˤĤ���
 */
class Parent {
	public:
		Parent(){
			cout << "Parent Class Constructor" << endl;
		}

		~Parent(){
			cout << "Parent Class Destructor" << endl;
		}
};

class Child : public Parent {
	public:
		Child(){
			cout << "Child Class Constructor" << endl;
		}
		~Child(){
			cout << "Child Class Destructor" << endl;
		}
} obj;

int main()
{
	// ���Ϥ���륳�󥹥ȥ饯�����ǥ��ȥ饯���ν������դ��뤳��
	return 0;
}
