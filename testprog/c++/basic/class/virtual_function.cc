#include<iostream>
using namespace std;

/*
 * ���۴ؿ��ˤĤ���
 *   �������۴ؿ��Ǥϡ��ǥ��ȥ饯�������ѤǤ��ޤ���(��ǥ��ȥ饯���ξ�硢�������饹¦������������Ȥ�����§��¸�ߤ��뤿��)
 */
class Parent {
	public:
		virtual void print(){                        // (1) print()�ؿ�   virtual������ɤϴ��ܥ��饹�ǻ��ꤷ�ޤ���
			cout << "Parent::print()" << endl;
		}
} pobj;

class Child1 : public Parent {
	public:
		void print(){                                // (2) print()�ؿ�
			cout << "Child1::print()" << endl;
		}
} cobj1;

class Child2 : public Parent {
	public:
		void print(){                                // (3) print()�ؿ�
			cout << "Child2::print()" << endl;
		}
} cobj2;

int main(){
	// (1)��virtual����ꤷ�ʤ����ˤϡ�����Parent::print()��ɽ������뤳�Ȥˤʤ�ޤ���
	Parent *po1 = &pobj, *po2 = &cobj1, *po3 = &cobj2;
	po1->print();
	po2->print();
	po3->print();


	// �¹Ի��Х���ǥ��󥰤���
	Parent *po;
	unsigned char ch;
	cout << "Enter y/n?  >";
	cin >> ch;

	if( ch == 'y' ){
		po = &pobj;
	} else {
		po = &cobj1;
	}
	po->print();           // ���Ϥ��줿���Ƥ˱����ƽ��Ϥ���륯�饹���ۤʤ�ޤ����¹Ի��Х���ǥ��󥰤ȸƤӤޤ�������ѥ�����Х���ǥ��󥰤Ȥ��Фˤʤ��Ѹ�Ǥ���
	return 0;
}
