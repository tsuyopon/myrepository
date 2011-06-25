#include<iostream>
using namespace std;

class Base {
	public:
		char *str;
		void print(){
			cout << "Base Class" << endl;
		}
};

class Derived : public Base {
	public:
		int i;
		void print(){
			cout << "Derived Class Extends Base Class" << endl;
		}
} obj;

void getRef(Base &obj){
	cout << obj.str << ": getRef()" << endl;
}

int main()
{
	obj.str = "hello";
	Base *po = &obj;              // ���饹���ݥ��󥿤��Ф����������饹�Υ��ɥ쥹�������Ǥ��ޤ�
	obj.print();                  // Derived���饹��print()���ƤӽФ���ޤ�
	po->print();                  // Base���饹��print()���ƤӽФ���ޤ�
	cout << po->str << endl;
	getRef(obj);                  // getRef�ΰ����Ȥ��Ƥϡ�Base���饹�����������Ǥ��������饹�Υ��֥������Ȥ����ꤵ��Ƥ��뤳�Ȥ����
	return 0;
}
